/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//      Implementation for class CompletenessCheckerSymbol.
//

#include "completenessCheckerSymbol.hh"

#include <ceta/ceta.hh>
#include <sstream>
#include <cstring>

class AutoWrapBuffer;
class ConditionFragment;
class ConditionState;
class DagRoot;
class ImportTranslation;
class Label;
class LhsAutomaton;
class LocalBinding;
class MatchSearchState;
class MemoryCell;
class MixfixParser;
class ModuleCache;
class ModuleExpression;
class Pattern;
class PreEquation;
class PreModule;
class QuotedIdentifierSymbol;
class RawDagArgumentIterator;
class Renaming;
class RewriteSearchState;
class RhsBuilder;
class SearchState;
class StrategyExpression;
class Subproblem;
class Substitution;
class TermBag;
class UnificationProblem;
class VariableInfo;
class View;
class MemoMap;

#include "rawArgumentIterator.hh"
#include "rewriteSequenceSearch.hh"

#include "metaModule.hh"

#include "ACU_Symbol.hh"
#include "binarySymbol.hh"
#include "bindingMacros.hh"
#include "equation.hh"
#include "freeDagNode.hh"
#include "metaLevel.hh"
#include "metaLevelOpSymbol.hh"
#include "pointerMap.hh"
#include "rewritingContext.hh"
#include "sortConstraint.hh"
#include "symbolMap.hh"
#include "userLevelRewritingContext.hh"


CompletenessCheckerSymbol::CompletenessCheckerSymbol(int id, int nrArgs)
  : FreeSymbol(id, nrArgs),
    metaLevel(NULL),
    shareWith(NULL),
    nilSymbol(NULL),
    unionSymbol(NULL),
    unverifiableOpSymbol(NULL),
    unverifiableMbSymbol(NULL),
    counterexampleOpSymbol(NULL),
    counterexampleMbSymbol(NULL)
{
}

CompletenessCheckerSymbol::~CompletenessCheckerSymbol()
{
  if (shareWith == NULL)
    delete metaLevel;
}

/**
 * Extract the ith argument from term.  Returns NULL if there is no ith
 * argument.
 */
static
Term* get_arg(Term* term, size_t i) {
  auto_ptr<RawArgumentIterator> iargs(term->arguments());
  while ((iargs.get() != NULL) && iargs->valid() && (i != 0)) {
    iargs->next();
    --i;
  }
  return ((iargs.get() != NULL) && iargs->valid())
       ? iargs->argument()
       : NULL;
}

/**
 * Given a term f(t1, t2, ...) this attempts to get the symbol t2 from the
 * term.  It returns NULL if the attempt fails because there is no second
 * argument or for some other reason.
 */
static
Symbol* get_state_symbol(Term* term) {
  Term* arg = get_arg(term, 1);
  return (arg != NULL) ? arg->symbol() : NULL;
}

/** Returns true if term is linear, i.e., contains no repeated variables. */
static bool is_linear(MixfixModule* m, Term* term) {
  typedef std::pair<int, Sort*> var_ref_t;
  std::vector<Term*> term_stack;
  std::set<var_ref_t> variables;

  term_stack.push_back(term);
  bool result = true;
  while (result && !term_stack.empty()) {
    Term* t = term_stack.back();
    term_stack.pop_back();
    Symbol* s = t->symbol();
    switch (m->getSymbolType(s).getBasicType()) {
    case SymbolType::VARIABLE:
      {
        var_ref_t rec(safeCast(const VariableTerm*, t)->id(),
                      safeCast(VariableSymbol*, s)->getSort());
        if (!variables.insert(rec).second)
          result = false;
      }
    default:
      {
        // Add arguments to stack.
        auto_ptr<RawArgumentIterator> i(t->arguments());
        while ((i.get() != NULL) && i->valid()) {
          term_stack.push_back(i->argument());
          i->next();
        }
      }
    }
  }
  return result;
}

/** Returns true if sort constraint should be considered a constructor. */
static
bool is_ctor(const MetaModule* m, const SortConstraint* mb) {
  int metadata = m->getMetadata(MixfixModule::MEMB_AX, mb);
  return (metadata == NONE) || (strcmp(Token::name(metadata), "dfn") != 0);
}

/** 
 * Returns true if every constructor membership is linear and unconditional.
 */
static
bool every_ctor_membership_is_linear(MetaModule* m) {
  bool result = true;
  const Vector<SortConstraint*>& mbs = m->getSortConstraints();
  typedef Vector<SortConstraint*>::const_iterator iter;
  for (iter i = mbs.begin(); result && i != mbs.end(); ++i) {
    const SortConstraint* mb = *i;
    if (!mb->isBad() && is_ctor(m, mb)) {
      // Check that membership has linear lhs and is unconditional.
      result = is_linear(m, mb->getLhs()) && !mb->hasCondition();
    }
  }
  return result;
}

template<typename Key, typename KeyOther, typename Data>
static 
const Data& get_val(const std::map<Key, Data>& map, const KeyOther& key) {
  typedef typename std::map<Key, Data>::const_iterator iter;
  iter i = map.find(key);
  if (i == map.end())
    throw std::logic_error("Attempt to get value in map without key");
  return i->second;
}


typedef std::map<const ConnectedComponent*, ceta::kind_t> comp_kind_map_t;
typedef std::map<ceta::kind_t, ceta::state_t> kind_state_map_t;
typedef std::map<const ConnectedComponent*, ceta::state_t> comp_state_map_t;

void parse_kinds(MetaModule* m, comp_kind_map_t& ck_map) {
  const Vector<ConnectedComponent*>& cv = m->getConnectedComponents();
  typedef Vector<ConnectedComponent*>::const_iterator iter;
  for (iter i = cv.begin(); i != cv.end(); ++i) {
    ConnectedComponent* c = *i;
    //std::cerr << "Kind: " << Token::name(c->sort(0)->id()) << std::endl;
    string name = Token::name(c->sort(0)->id());
    ceta::kind_t k(name);
    ck_map.insert(std::make_pair(c, k));
  }
}

void add_kinds(const comp_kind_map_t& ck_map, ceta::theory_t& theory) {
  typedef comp_kind_map_t::const_iterator iter;
  for (iter i = ck_map.begin(); i != ck_map.end(); ++i)
    add_kind(theory, i->second);
}

static void write_symbol(MetaModule* m, Symbol* s) {
  std::cerr << "Symbol: " << s << " ";
  switch (m->getSymbolType(s).getBasicType()) {
  case SymbolType::STANDARD: std::cerr << "Standard"; break;
  case SymbolType::VARIABLE: std::cerr << "Variable"; break;
  case SymbolType::SORT_TEST: std::cerr << "Sort Test"; break;
  case SymbolType::SYSTEM_TRUE: std::cerr << "System_true"; break;
  case SymbolType::SYSTEM_FALSE: std::cerr << "System_false"; break;
  case SymbolType::BUBBLE: std::cerr << "BUBBLE"; break;
  case SymbolType::FLOAT: std::cerr << "FLOAT"; break;
  case SymbolType::STRING: std::cerr << "STRING"; break;
  case SymbolType::BRANCH_SYMBOL:
    std::cerr << "BRANCH_SYMBOL";
    break;
  case SymbolType::EQUALITY_SYMBOL: std::cerr << "Equality_symbol"; break;
  case SymbolType::FLOAT_OP: std::cerr << "Float_op"; break;
  case SymbolType::STRING_OP: std::cerr << "STRING_OP"; break;
  case SymbolType::QUOTED_IDENTIFIER:
    std::cerr << "QUOTED_IDENTIIFIER";
    break;
  case SymbolType::QUOTED_IDENTIFIER_OP:
    std::cerr << "QUOTED_IDENTIIFIER_OP";
    break;


  case SymbolType::META_LEVEL_OP_SYMBOL:
    std::cerr << "META_LEVEL_OP_SYMBOL";
    break;
  case SymbolType::LOOP_SYMBOL:
    std::cerr << "LOOP_SYMBOL";
    break;
  case SymbolType::SUCC_SYMBOL:
    std::cerr << "SUCC_SYMBOL";
    break;
  case SymbolType::MINUS_SYMBOL:
    std::cerr << "MINUS_SYMBOL";
    break;
  case SymbolType::NUMBER_OP_SYMBOL:
    std::cerr << "NUMBER_OP_SYMBOL";
    break;
  case SymbolType::ACU_NUMBER_OP_SYMBOL:
    std::cerr << "ACU_NUMBER_OP_SYMBOL";
    break;
  case SymbolType::CUI_NUMBER_OP_SYMBOL:
    std::cerr << "CUI_NUMBER_OP_SYMBOL";
    break;
  case SymbolType::DIVISION_SYMBOL:
    std::cerr << "DIVISION_SYMBOL";
    break;

  default:
    std::cerr << "Other";
  }
  std::cerr << " : ";
  for (int i = 0; i < s->arity(); ++i)
    std::cerr << Token::name(s->domainComponent(i)->sort(0)->id()) << " ";
  std::cerr << "-> " << Token::name(s->rangeComponent()->sort(0)->id())
            << std::endl;
}

typedef std::map<Symbol*, ceta::op_t> symbol_op_map_t;
typedef std::map<ceta::op_t, Symbol*> op_symbol_map_t;

static
ceta::op_t make_op(Symbol* s, const comp_kind_map_t& ck_map) {
  string name = Token::name(s->id());
  std::vector<ceta::kind_t> inputs;
  inputs.reserve(s->arity());
  for (int i = 0; i < s->arity(); ++i)
    inputs.push_back(get_val(ck_map, s->domainComponent(i)));
  ceta::kind_t output(get_val(ck_map, s->rangeComponent()));
  return ceta::op_t(name, inputs.begin(), inputs.end(), output);
}

static
void populate_symbol_op_map(MetaModule* m,
                            const comp_kind_map_t& ck_map,
                            ceta::theory_t& theory,
                            symbol_op_map_t& so_map,
                            op_symbol_map_t& os_map) {
  const Vector<Symbol*>& sv = m->getSymbols();
  typedef Vector<Symbol*>::const_iterator iter;
  for (iter i = sv.begin(); i != sv.end(); ++i) {
    Symbol* s = *i;
    //write_symbol(m, s);
    int type = m->getSymbolType(s).getBasicType();
    bool add_symbol = (type != SymbolType::VARIABLE);
    if (add_symbol) {
      ceta::op_t op(make_op(s, ck_map));
      add_op(theory, op);
      so_map.insert(std::make_pair(s, op));
      os_map.insert(std::make_pair(op, s));
    }
  }
}

/** Returns the set of axioms parsed out of the operator. */
static
ceta::axiom_set_t axioms(const MetaModule* m, 
                         const symbol_op_map_t& so_map,
                         Symbol* sym) {
  ceta::axiom_set_t result = ceta::none();
  SymbolType st = m->getSymbolType(sym);
  if (st.hasFlag(SymbolType::ASSOC))
    result |= ceta::assoc();
  if (st.hasFlag(SymbolType::COMM))
    result |= ceta::comm();

  bool left_id  = st.hasFlag(SymbolType::LEFT_ID);
  bool right_id = st.hasFlag(SymbolType::RIGHT_ID);

  if (left_id || right_id) {
    // Get identity operator for symbol.
    const BinarySymbol* bin_sym = safeCast(BinarySymbol*, sym);
    Symbol* id_sym = bin_sym->getIdentity()->symbol();
    ceta::op_t id_op = get_val(so_map, id_sym);
    // Add identity to result
    if (id_sym->arity() != 0) {
      IssueWarning(std::string("Identity symbol \"")
                 + Token::name(id_sym->id())
                 + "\" is being ignored as the completeness checker only "
                 + " supports constant identities.");
    } else if (left_id && right_id) {
      result |= ceta::id(id_op);
    } else if (left_id) {
      result |= ceta::left_id(id_op);
    } else {
      result |= ceta::right_id(id_op);
    }
  }
  return result;
}

static void set_axioms(const MetaModule* m,
                       const symbol_op_map_t& so_map,
                       ceta::theory_t& theory) {
  typedef symbol_op_map_t::const_iterator iter;
  for (iter i = so_map.begin(); i != so_map.end(); ++i)
    set_axioms(theory, i->second, axioms(m, so_map, i->first));
}

static
void populate_kind_states(const comp_kind_map_t& ck_map,
                          char prefix,
                          ceta::ta_t& ta,
                          comp_state_map_t& qstates,
                          kind_state_map_t* qkind_states) {
  typedef comp_kind_map_t::const_iterator iter;
  for (iter i = ck_map.begin(); i != ck_map.end(); ++i) {
    const ConnectedComponent* c = i->first;
    ceta::kind_t k = i->second;
    ceta::state_t qs(k, prefix + name(k));
    add_state(ta, qs);
    qstates.insert(std::make_pair(c, qs));
    if (qkind_states)
      qkind_states->insert(std::make_pair(k, qs));
  }
}

static
void add_rrules_for_op(const comp_state_map_t& qstates,
                       const comp_state_map_t& rstates,
                       Symbol* s,
                       const ceta::op_t& op,
                       ceta::ta_t& ta) {

  std::vector<ceta::state_t> lhs_states;
  lhs_states.reserve(s->arity());
  for (int i = 0; i < s->arity(); ++i)
    lhs_states.push_back(get_val(qstates, s->domainComponent(i)));


  ceta::state_t qout = get_val(qstates, s->rangeComponent());
  add_rule(ta, ceta::rule_t(op, lhs_states.begin(), lhs_states.end(), qout));

  ceta::state_t rout = get_val(rstates, s->rangeComponent());
  typedef std::vector<ceta::state_t>::iterator iter;
  iter ilhs = lhs_states.begin();
  for (int i = 0; i < s->arity(); ++i) {
    const ceta::state_t& old_state = *ilhs;
    *ilhs = get_val(rstates, s->domainComponent(i));
    add_rule(ta, 
             ceta::rule_t(op, lhs_states.begin(), lhs_states.end(), rout));
    *ilhs = old_state;
    ++ilhs;
  }
}

static
void add_rrules(const symbol_op_map_t& so_map,
                const comp_state_map_t& qstates,
                const comp_state_map_t& rstates,
                ceta::ta_t& ta) {
  typedef symbol_op_map_t::const_iterator iter;
  for (iter i = so_map.begin(); i != so_map.end(); ++i) {
    Symbol* s = i->first;
    ceta::op_t op = i->second;
    add_rrules_for_op(qstates, rstates, s, op, ta);
  }
}

typedef std::map<Sort*, ceta::state_t> sort_state_map_t;

static
void add_sort_states_for_kind(const ConnectedComponent* c,
                              const ceta::kind_t& k,
                              const std::string& prefix,
                              ceta::ta_t& ta,
                              sort_state_map_t& ss_map) {
  int sort_count = c->nrSorts();
  for (int i = 1; i < sort_count; ++i) {
    Sort* sort = c->sort(i);
    ceta::state_t state(k, prefix + Token::name(sort->id())); 
    add_state(ta, state);
    ss_map.insert(std::make_pair(sort, state));
  }
}

static
void populate_sort_states(const comp_kind_map_t& ck_map,
                          const std::string& prefix, 
                          ceta::ta_t& ta,
                          sort_state_map_t& ss_map) {
  typedef comp_kind_map_t::const_iterator iter;
  for (iter i = ck_map.begin(); i != ck_map.end(); ++i)
    add_sort_states_for_kind(i->first, i->second, prefix, ta, ss_map);
}

/** Adds subsort rules to automaton. */
void add_subsort_rules(const sort_state_map_t& ss_map, ceta::ta_t& ta) {
  typedef sort_state_map_t::const_iterator map_iter;
  for (map_iter i = ss_map.begin(); i != ss_map.end(); ++i) {
    const Sort* sort = i->first;
    const ceta::state_t& state = i->second;
    const Vector<Sort*>& subsorts = sort->getSubsorts();
    typedef Vector<Sort*>::const_iterator sort_iter;
    for (sort_iter j = subsorts.begin(); j != subsorts.end(); ++j)
      add_erule(ta, ceta::erule_t(get_val(ss_map, *j), state));
  }
}

/** Add states in qstates to ss_map using sort(0) for each kind. */
void add_kind_states(const comp_state_map_t& qstates,
                     sort_state_map_t& ss_map) {
  typedef comp_state_map_t::const_iterator iter;
  for (iter i = qstates.begin(); i != qstates.end(); ++i) {
    const ConnectedComponent* c = i->first;
    const ceta::state_t& s = i->second;
    ss_map.insert(std::make_pair(c->sort(0), s));
  }
}

typedef std::pair<Symbol*, int> opdecl_ref_t;
typedef std::map<ceta::state_t, opdecl_ref_t> state_decl_map_t;

/**
 * Creates a new op rule, and adds it's right hand side to sd_map if the
 * op declaration is ordinary and defined.
 */
static
ceta::rule_t make_op_rule(const sort_state_map_t& ctor_states,
                          const ceta::op_t& op,
                          const OpDeclaration& d,
                          const ceta::state_t& rhs) {
  const Vector<Sort*>& drv = d.getDomainAndRange();
  size_t arity = input_count(op);
  std::vector<ceta::state_t> lhs;
  lhs.reserve(arity);
  for (size_t i = 0; i != arity; ++i)
    lhs.push_back(get_val(ctor_states, drv[i]));
  return ceta::rule_t(op, lhs.begin(), lhs.end(), rhs);
}

static
ceta::state_t make_defined_op_state(const ceta::kind_t& k, 
                                    const opdecl_ref_t& ref,
                                    ceta::ta_t& ta,
                                    state_decl_map_t& sd_map) {
  std::ostringstream s;
  s << 'o' << sd_map.size();
  ceta::state_t result = ceta::state_t(k, s.str());
  add_state(ta, result);
  sd_map.insert(std::make_pair(result, ref));
  return result;
}

typedef std::map<ceta::state_t, const SortConstraint*> state_mb_map_t;

static
ceta::state_t make_defined_mb_state(const ceta::kind_t& k, 
                                    const SortConstraint* mb,
                                    ceta::ta_t& ta,
                                    state_mb_map_t& sm_map) {
  std::ostringstream s;
  s << 'm' << sm_map.size();
  ceta::state_t result = ceta::state_t(k, s.str());
  add_state(ta, result);
  sm_map.insert(std::make_pair(result, mb));
  return result;
}

static
void add_op_rules(MetaModule* m,
                  const symbol_op_map_t& so_map,
                  const sort_state_map_t& ctor_states,
                  const boost::optional<sort_state_map_t>&
                    sort_states,
                  const comp_state_map_t& rstates,
                  ceta::ta_t& ta,
                  state_decl_map_t& sd_map) {
  typedef symbol_op_map_t::const_iterator so_iter;
  for (so_iter i = so_map.begin(); i != so_map.end(); ++i) {
    Symbol* s = i->first;
    ceta::op_t op = i->second;
    bool is_special = m->getSymbolType(s).hasSpecial();
    const Vector<OpDeclaration>& ov = s->getOpDeclarations();
    typedef Vector<OpDeclaration>::const_iterator decl_iter;
    size_t index = 0;
    size_t arity = input_count(op);
    opdecl_ref_t ref(s, 0);
    for (decl_iter j = ov.begin(); j != ov.end(); ++j) {
      const OpDeclaration& d = *j;
      Sort* rhs_sort = d.getDomainAndRange()[arity];
      if (d.isConstructor()) {
        ceta::state_t rhs = get_val(ctor_states, rhs_sort);
        add_rule(ta, make_op_rule(ctor_states, op, d, rhs));
        if (sort_states) {
          ceta::state_t rhs2 = get_val(*sort_states, rhs_sort);
          add_rule(ta, make_op_rule(*sort_states, op, d, rhs2));
        }
      } else if (is_special) {
        ceta::state_t rhs = get_val(rstates, s->rangeComponent());
        add_rule(ta, make_op_rule(ctor_states, op, d, rhs));
      } else {
        ceta::state_t rhs
                = make_defined_op_state(output(op), ref, ta, sd_map);
        if (sort_states) {
          add_rule(ta, make_op_rule(*sort_states, op, d, rhs));
        } else {
          add_rule(ta, make_op_rule(ctor_states, op, d, rhs));
        }
      }
      ++(ref.second);
    }
  }
}

typedef std::vector<ceta::state_t> state_vector_t;

/** This class represents a rule rule lhs. */
class rulelhs_t {
public:
  rulelhs_t(const ceta::op_t& op, const state_vector_t& states)
    : op_(op),
      states_(states) {
  }

  /** Returns true if this rulelhs is less than o lhs_ */
  bool operator<(const rulelhs_t& o) const {
    return (op_ < o.op_)
        || ((op_ == o.op_) && (states_ < o.states_));
  }

  const ceta::op_t& op(void) const {
    return op_;
  }

  state_vector_t::const_iterator begin(void) const {
    return states_.begin();
  }

  state_vector_t::const_iterator end(void) const {
    return states_.end();
  }
private:
  ceta::op_t op_;
  state_vector_t states_;
};

typedef std::map<rulelhs_t, ceta::state_t> lhs_state_map_t;

static
const ceta::state_t&
get_term_state(MetaModule* m,
               const symbol_op_map_t& so_map,
               const sort_state_map_t& sort_states,
               Term* t,
               ceta::ta_t& ta,
               lhs_state_map_t& ls_map);

static
rulelhs_t get_term_rulelhs(MetaModule* m,
                           const symbol_op_map_t& so_map,
                           const sort_state_map_t& sort_states,
                           Term* t,
                           ceta::ta_t& ta,
                           lhs_state_map_t& ls_map) {
  Symbol* s = t->symbol();
  state_vector_t lhs_states;
  auto_ptr<RawArgumentIterator> i(t->arguments());
  while ((i.get() != NULL) && i->valid()) {
    lhs_states.push_back(
          get_term_state(m, so_map, sort_states, i->argument(), ta, ls_map));
    i->next();
  }
  return rulelhs_t(get_val(so_map, s), lhs_states);
}

static
const ceta::state_t&
get_term_state(MetaModule* m,
               const symbol_op_map_t& so_map,
               const sort_state_map_t& sort_states,
               Term* t,
               ceta::ta_t& ta,
               lhs_state_map_t& ls_map) {
  Symbol* s = t->symbol();
  switch (m->getSymbolType(s).getBasicType()) {
  case SymbolType::VARIABLE:
    {
      Sort* sort = safeCast(VariableSymbol*, s)->getSort();
      return get_val(sort_states, sort);
    }
  default:
    {
      rulelhs_t lhs 
            = get_term_rulelhs(m, so_map, sort_states, t, ta, ls_map);
      typedef lhs_state_map_t::const_iterator iter;
      iter i = ls_map.find(lhs);
      if (i == ls_map.end()) {
        ceta::kind_t k = output(lhs.op());
        std::ostringstream s;
        s << 't' << ls_map.size();
        ceta::state_t rhs = ceta::state_t(k, s.str());
        add_state(ta, rhs);
        add_rule(ta, ceta::rule_t(lhs.op(), lhs.begin(), lhs.end(), rhs));
        i = ls_map.insert(std::make_pair(lhs, rhs)).first;
      }
      return i->second;
    }
  }
}

void add_term_rules(MetaModule* m,
                    const symbol_op_map_t& so_map,
                    const sort_state_map_t& sort_states,
                    Term* t,
                    const ceta::state_t& rhs,
                    ceta::ta_t& ta,
                    lhs_state_map_t& ls_map) {
  Symbol* s = t->symbol();
  switch (m->getSymbolType(s).getBasicType()) {
  case SymbolType::VARIABLE:
    {
      Sort* sort = safeCast(VariableSymbol*, s)->getSort();
      const ceta::state_t& lhs = get_val(sort_states, sort);
      add_erule(ta, ceta::erule_t(lhs, rhs));
    }
  default:
    {
      rulelhs_t lhs
            = get_term_rulelhs(m, so_map, sort_states, t, ta, ls_map);
      add_rule(ta, ceta::rule_t(lhs.op(), lhs.begin(), lhs.end(), rhs));
    }
  }
}

void add_eq_rules(MetaModule* m, 
                  const symbol_op_map_t& so_map,
                  const sort_state_map_t& ctor_states,
                  const comp_state_map_t& rstates,
                  ceta::ta_t& ta,
                  lhs_state_map_t& ls_map) {
  const Vector<Equation*>& eqs = m->getEquations();
  typedef Vector<Equation*>::const_iterator iter;
  for (iter i = eqs.begin(); i != eqs.end(); ++i) {
    const Equation* eq = *i;
    // Only add rules for equations if it is left-linear and unconditional.
    if (!eq->isBad() 
            && is_linear(m, eq->getLhs())
            && !eq->hasCondition()) {
      Term* t = eq->getLhs();
      const ceta::state_t& rhs = get_val(rstates, t->getComponent());
      add_term_rules(m, so_map, ctor_states, t, rhs, ta, ls_map);
    }
  }
}

static
void add_mb_rules(MetaModule* m, 
                  const symbol_op_map_t& so_map,
                  const sort_state_map_t& ctor_states,
                  const boost::optional<sort_state_map_t>& sort_states,
                  const comp_state_map_t& rstates,
                  ceta::ta_t& ta,
                  lhs_state_map_t& ls_map,
                  state_mb_map_t& sm_map) {
  const Vector<SortConstraint*>& mbs = m->getSortConstraints();
  typedef Vector<SortConstraint*>::const_iterator iter;
  for (iter i = mbs.begin(); i != mbs.end(); ++i) {
    const SortConstraint* mb = *i;
    // Skip "bad" memberships
    if (mb->isBad()) continue;
    Term* t = mb->getLhs();
    bool mb_is_ctor = is_ctor(m, mb);
    if (mb_is_ctor) {
      // If mb is left-linear and unconditional
      if (!mb->hasCondition() && is_linear(m, t)) {
        ceta::state_t rhs = get_val(ctor_states, mb->getSort());
        add_term_rules(m, so_map, ctor_states, t, rhs, ta, ls_map);
      }
      // If sort_states is assigned, add any membership rules for it.
      if (sort_states) {
        ceta::state_t rhs = get_val(*sort_states, mb->getSort());
        add_term_rules(m, so_map, *sort_states, t, rhs, ta, ls_map);
      }
    } else { // Defined
      ceta::op_t op = get_val(so_map, t->symbol());
      ceta::kind_t k = output(op);
      const sort_state_map_t& used_sort_states 
          = sort_states ? *sort_states : ctor_states;
      ceta::state_t rhs = make_defined_mb_state(k, mb, ta, sm_map);
      add_term_rules(m, so_map, used_sort_states, t, rhs, ta, ls_map);
    }
  }
}

static
ceta::ta_t make_ta(MetaModule* m,
                   op_symbol_map_t& os_map,
                   sort_state_map_t& ctor_states,
                   state_decl_map_t& sd_map,
                   state_mb_map_t& sm_map,
                   kind_state_map_t& rkind_states) {
  ceta::theory_t theory;
  // Extract kinds
  comp_kind_map_t ck_map;
  parse_kinds(m, ck_map);
  add_kinds(ck_map, theory);
  symbol_op_map_t so_map;
  populate_symbol_op_map(m, ck_map, theory, so_map, os_map);
  set_axioms(m, so_map, theory);

  ceta::ta_t ta(theory);
  comp_state_map_t qstates;
  comp_state_map_t rstates;
  populate_kind_states(ck_map, 'q', ta, qstates, NULL);
  populate_kind_states(ck_map, 'r', ta, rstates, &rkind_states);
  // Add rules involving qstates and rstates.
  add_rrules(so_map, qstates, rstates, ta);
  //std::cerr << ta << std::endl;
  // Build sort states
  populate_sort_states(ck_map, "c", ta, ctor_states);
  //std::cerr << ta << std::endl;
  add_subsort_rules(ctor_states, ta);
  add_kind_states(qstates, ctor_states);
  boost::optional<sort_state_map_t> sort_states;
  if (!every_ctor_membership_is_linear(m)) {
    sort_states = sort_state_map_t();
    populate_sort_states(ck_map, "s", ta, *sort_states);
    add_subsort_rules(*sort_states, ta);
    add_kind_states(qstates, *sort_states);
  }
  //std::cerr << ta << std::endl;
  add_op_rules(m, so_map, ctor_states, sort_states, rstates, ta, sd_map);

  lhs_state_map_t ls_map;
  // Add equation rules
  add_eq_rules(m, so_map, ctor_states, rstates, ta, ls_map);
  // Add membership rules
  add_mb_rules(m, so_map, ctor_states, sort_states, rstates,
               ta, ls_map, sm_map);
  return ta;
}

DagNode* make_term_dagnode(const op_symbol_map_t& os_map,
                           const ceta::term_t& term) {
  // Create dagnodes for subterms
  typedef ceta::term_t::subterm_iterator iter;
  Vector<DagNode*> args(subterm_count(term));
  size_t cur_idx = 0;
  for (iter i = subterms_begin(term); i != subterms_end(term); ++i) {
    args[cur_idx] = make_term_dagnode(os_map, *i);
    ++cur_idx;
  }

  DagNode* result = get_val(os_map, root(term))->makeDagNode(args);
  result->symbol()->computeBaseSort(result);
  return result;
}

//TODO: Improve name
bool CompletenessCheckerSymbol::setReachability(FreeDagNode* subject,
                                                RewritingContext& context) {
  MetaModule* m = metaLevel->downModule(subject->getArgument(0));
  if (m == NULL) 
    return false;

  if (m->getNrParameters() != 0) {
    IssueWarning(
            "Completeness checker only supports unparameterized theories");
    return false;
  }

  m->protect();
  op_symbol_map_t os_map;
  sort_state_map_t ctor_states;
  state_decl_map_t sd_map;
  state_mb_map_t sm_map;
  kind_state_map_t rstates;

  ceta::ta_t ta = make_ta(m, os_map, ctor_states, sd_map, sm_map, rstates);
  
  std::set<ceta::state_t> pos_states;
  // Add each defined state to pos_states.
  {
    typedef state_decl_map_t::const_iterator diter;
    for (diter i = sd_map.begin(); i != sd_map.end(); ++i)
      pos_states.insert(i->first);
    typedef state_mb_map_t::const_iterator miter;
    for (miter i = sm_map.begin(); i != sm_map.end(); ++i)
      pos_states.insert(i->first);
  } 

  std::set<ceta::state_t> neg_states;
  // Add each constructor state to neg_states.
  {
    typedef sort_state_map_t::const_iterator iter;
    for (iter i = ctor_states.begin(); i != ctor_states.end(); ++i)
      neg_states.insert(i->second);
  }
  // Add each reducible state to neg_state.
  {
    typedef kind_state_map_t::const_iterator iter;
    for (iter i = rstates.begin(); i != rstates.end(); ++i)
      neg_states.insert(i->second);
  }

  typedef std::map<opdecl_ref_t, DagNode*> opdecl_counterexample_map_t;
  typedef std::map<SortConstraint*, DagNode*> mb_counterexample_map_t;
  opdecl_counterexample_map_t oc_map;
  mb_counterexample_map_t mc_map;
  ceta::subset_constructor_t sc(ta, pos_states, neg_states);
  while (!sc.is_complete() 
          && !UserLevelRewritingContext::interrupted()) {
    sc.work();
    while (sc.has_next()) {
      const std::set<ceta::state_t>& set = sc.next_set();
      const ceta::term_t& term = sc.next_term();
      //std::cerr << "Next: " << set << " " << term << std::endl;
      ceta::kind_t k = kind(term);
      // Get reducible state for kind.
      ceta::state_t rstate = get_val(rstates, k);
      // If set does not contain reducible state.
      if (set.count(rstate) == 0) {
        typedef std::set<ceta::state_t>::const_iterator iter;
        // For each state in set
        for (iter i = set.begin(); i != set.end(); ++i) {
          ceta::state_t state = *i;
          // Check if state is defined operator or membership state.
          typedef state_decl_map_t::const_iterator sd_iter;
          if (ceta::name(state)[0] == 'o') { 
            const opdecl_ref_t& ref = get_val(sd_map, state);
            Symbol* symbol = ref.first;
            int index = ref.second;
            const OpDeclaration& d = symbol->getOpDeclarations()[index];
            // Sort of rhs of operator.
            Sort* sort = d.getDomainAndRange()[symbol->arity()];
            // If ctor state associate to sort is not in set.
            if (set.count(get_val(ctor_states, sort)) == 0) {
              typedef opdecl_counterexample_map_t::iterator oc_iter;
              oc_iter oci = oc_map.find(ref);
              // If we haven't yet found a counterexample.
              if ((oci == oc_map.end()) || (oci->second == NULL)) {
                //TODO
                // Check whether counterexample is correct.
                // Counterexample is correct if term is not reducible, term
                //   really has sort in module, and does not have sort in
                //   constructor module.
                DagNode* dn = make_term_dagnode(os_map, term);
                Sort* dn_sort = dn->getSort();
                // Check that node's sort is leq than sort
                bool correct_counterexample = leq(dn_sort, sort);
                if (correct_counterexample) {
                  if (oci != oc_map.end()) {
                    oci->second = dn;
                  } else {
                    oc_map.insert(std::make_pair(ref, dn));
                  }
                } else if (oci == oc_map.end()) {
                  oc_map.insert(
                          std::make_pair(ref, static_cast<DagNode*>(NULL)));
                }
              }
            }
          } else if (ceta::name(state)[0] == 'm') { 
            const SortConstraint* mb = get_val(sm_map, state);
            //TODO: Handle defined membership
          }
        }
      }
      sc.pop_next();
    }
  }
  Vector<DagNode*> results;
  {
    typedef opdecl_counterexample_map_t::const_iterator iter;
    for (iter i = oc_map.begin(); i != oc_map.end(); ++i) {
      Symbol* symbol = i->first.first;
      int index = i->first.second;
      DagNode* dn = i->second;
      if (dn != NULL) {
        // Add counterexample to results.
        Vector<DagNode*> cargs(2);
        PointerMap qidMap;
        PointerMap dagNodeMap;
        // Up op declaration .
        cargs[0] = metaLevel->upOpDecl(m, symbol, index, qidMap);
        // Generate counterexample dag node.
        cargs[1] = metaLevel->upDagNode(dn, m, qidMap, dagNodeMap);
        results.append(counterexampleOpSymbol->makeDagNode(cargs));
      } else {
        Vector<DagNode*> cargs(1);
        PointerMap qidMap;
        // Up op declaration.
        cargs[0] = metaLevel->upOpDecl(m, symbol, index, qidMap);
        results.append(unverifiableOpSymbol->makeDagNode(cargs));
      }
    }
  }
  //TODO; Add membership failures.
  (void) m->unprotect();
  if (UserLevelRewritingContext::interrupted()) {
    return false;
  } else if (results.size() == 0) {
    return context.builtInReplace(subject, nilSymbol->makeDagNode());
  } else if (results.size() == 1) {
    return context.builtInReplace(subject, results[0]);
  } else {
    return context.builtInReplace(subject,
        unionSymbol->makeDagNode(results));
  }
}

bool
CompletenessCheckerSymbol::okToBind() {
  if (shareWith != NULL)
    return false;
  if (metaLevel == NULL)
    metaLevel = new MetaLevel;
  return true;
}

bool
CompletenessCheckerSymbol::attachData(const Vector<Sort*>& opDeclaration,
			              const char* purpose,
			              const Vector<const char*>& data) {
  NULL_DATA(purpose, CompletenessCheckerSymbol, data);
  return FreeSymbol::attachData(opDeclaration, purpose, data);
}

bool
CompletenessCheckerSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  if (metaLevel == NULL)
    BIND_SYMBOL(purpose, symbol, shareWith, MetaLevelOpSymbol*);
  BIND_SYMBOL(purpose, symbol, nilSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, unionSymbol, ACU_Symbol*);
  BIND_SYMBOL(purpose, symbol, unverifiableOpSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, unverifiableMbSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, counterexampleOpSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, counterexampleMbSymbol, Symbol*);
  return (okToBind() && metaLevel->bind(purpose, symbol)) ? true :
    FreeSymbol::attachSymbol(purpose, symbol);
}

bool
CompletenessCheckerSymbol::attachTerm(const char* purpose, Term* term)
{
  return (okToBind() && metaLevel->bind(purpose, term)) ? true :
    FreeSymbol::attachTerm(purpose, term);
}

void
CompletenessCheckerSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  if (shareWith == NULL && metaLevel == NULL)
    {
      CompletenessCheckerSymbol* orig
              = safeCast(CompletenessCheckerSymbol*, original);
      MetaLevelOpSymbol* sw = orig->shareWith;
      if (sw != NULL) {
	metaLevel = NULL;
	shareWith = (map == NULL)
                  ? sw
                  : safeCast(MetaLevelOpSymbol*, map->translate(sw));
      } else {
	metaLevel = new MetaLevel(orig->metaLevel, map);
	shareWith = NULL;
      }
      nilSymbol = safeCast(Symbol*, map->translate(orig->nilSymbol));
      unionSymbol = safeCast(ACU_Symbol*, map->translate(orig->unionSymbol));
      unverifiableOpSymbol = safeCast(Symbol*,
          map->translate(orig->unverifiableOpSymbol));
      unverifiableMbSymbol = safeCast(Symbol*,
          map->translate(orig->unverifiableMbSymbol));
      counterexampleOpSymbol = safeCast(Symbol*,
          map->translate(orig->counterexampleOpSymbol));
      counterexampleMbSymbol = safeCast(Symbol*,
          map->translate(orig->counterexampleMbSymbol));
    }
  FreeSymbol::copyAttachments(original, map);
}

void
CompletenessCheckerSymbol::getSymbolAttachments(Vector<const char*>& purposes,
					Vector<Symbol*>& symbols)
{
  if (shareWith == NULL)
    metaLevel->getSymbolAttachments(purposes, symbols);
  else
    {
      purposes.append("shareWith");
      symbols.append(shareWith);
    }
  APPEND_SYMBOL(purposes, symbols, nilSymbol);
  APPEND_SYMBOL(purposes, symbols, unionSymbol);
  APPEND_SYMBOL(purposes, symbols, unverifiableOpSymbol);
  APPEND_SYMBOL(purposes, symbols, unverifiableMbSymbol);
  APPEND_SYMBOL(purposes, symbols, counterexampleOpSymbol);
  APPEND_SYMBOL(purposes, symbols, counterexampleMbSymbol);
  FreeSymbol::getSymbolAttachments(purposes, symbols);
}

void
CompletenessCheckerSymbol::getTermAttachments(Vector<const char*>& purposes,
				      Vector<Term*>& terms)
{
  if (shareWith == NULL)
    metaLevel->getTermAttachments(purposes, terms);
  FreeSymbol::getTermAttachments(purposes, terms);
}

void
CompletenessCheckerSymbol::postInterSymbolPass()
{
  if (shareWith == NULL)
    metaLevel->postInterSymbolPass();
  else
    metaLevel = shareWith->getMetaLevel();
}

void
CompletenessCheckerSymbol::reset()
{
  if (shareWith == NULL && metaLevel != NULL)
    metaLevel->reset();
}

bool
CompletenessCheckerSymbol::eqRewrite(DagNode* subject,
                                     RewritingContext& context) {
  Assert(this == subject->symbol(), "Bad symbol");
  if (metaLevel == NULL)
    metaLevel = shareWith->getMetaLevel();
  FreeDagNode* d = safeCast(FreeDagNode*, subject);
  int nrArgs = arity();
  for (int i = 0; i < nrArgs; i++)
    d->getArgument(i)->reduce(context);
  return setReachability(d, context)
      || FreeSymbol::eqRewrite(subject, context);
}
