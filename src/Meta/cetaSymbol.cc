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
//      Implementation for class CetaSymbol.
//

#include "cetaSymbol.hh"

#include <boost/none.hpp>
#include <ceta/ceta.hh>

// Forward declarations needed for imports.
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

// Imports grouped in order they must be imported.
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
#include "rule.hh"
#include "symbolMap.hh"




//      interface class definitions
//#include "rewritingContext.hh"
//#include "rule.hh"
//#include "rawArgumentIterator.hh"
//
//class StrategyExpression;
//#include "metaModule.hh"
//#include "metaLevel.hh"
//
//#include <memory>
//#include <stdexcept>
//#include "userLevelRewritingContext.hh"
//#include "equation.hh"

CetaSymbol::CetaSymbol(int id, int nrArgs)
  : FreeSymbol(id, nrArgs),
    metaLevel(NULL),
    shareWith(NULL),
    emptySymbol(NULL),
    acceptingTermSymbol(NULL),
    invalidInputSymbol(NULL),
    qidSetSymbol(NULL)
{
}

CetaSymbol::~CetaSymbol()
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

static
void sig_warning(const std::string& msg) {
  cerr << msg << endl;
}

/** Parses connected components into kinds. */
class component_parser_t {
public:
  /** Type of iterator that points to Ceta kinds. */
  typedef set<ceta::kind_t>::const_iterator kind_iterator;

  /** Constructs a new parser built from parsing the provided components. */
  component_parser_t(const Vector<ConnectedComponent*>& components) {
    typedef Vector<ConnectedComponent*>::const_iterator iter;
    for (iter i = components.begin(); i != components.end(); ++i)
      parse(*i);
  }

  /**
   * Attempts to parse connected component and associate it to a kind if
   * it is the connected component for a tree or state.
   */
  void parse(const ConnectedComponent* c) {
    // Determine if this connected component and get name of kind if so.
    string sort = Token::name(c->sort(0)->id());
    boost::optional<string> name = parse_tree(sort);
    if (!name) {
      name = parse_state(sort);
    }

    if (!name) {
      if (!is_bool(c))
        sig_warning("Could not parse kind \"" + sort + "\" so skipping.");
      return;
    }

    string_kind_map_t::const_iterator ikind = sk_map_.find(*name);
    if (ikind == sk_map_.end()) {
      ceta::kind_t kind(*name);
      ikind = sk_map_.insert(make_pair(*name, kind)).first;
      kind_set_.insert(kind);
    }
  }

  /** Returns true if connected component is the builtin Bool component. */
  bool is_bool(const ConnectedComponent* c) const {
    string sort = Token::name(c->sort(0)->id());
    return sort == "Bool";
  }

  /** Returns an iterator that points to first kind found in automaton. */
  kind_iterator begin(void) const {
    return kind_set_.begin();
  }
  /**
   * Returns an iterator that points one past the last kind found in
   * automaton.
   */
  kind_iterator end(void) const {
    return kind_set_.end();
  }

  /**
   * Returns the kind associated to the connected component if it is a
   * parsed state component and boost::none otherwise.
   */
  boost::optional<ceta::kind_t>
  find_state_kind(const ConnectedComponent* c) const {
    string sort = Token::name(c->sort(0)->id());
    boost::optional<std::string> name = parse_state(sort);
    if (!name)
      return boost::none;
    string_kind_map_t::const_iterator i = sk_map_.find(*name);
    if (i == sk_map_.end())
      return boost::none;
    return i->second;
  }

  /**
   * Returns the kind associated to the connected component if it is a
   * parsed tree component and boost::none otherwise.
   */
  boost::optional<ceta::kind_t>
  find_tree_kind(const ConnectedComponent* c) const {
    string sort = Token::name(c->sort(0)->id());
    boost::optional<std::string> name = parse_tree(sort);
    if (!name)
      return boost::none;
    string_kind_map_t::const_iterator i = sk_map_.find(*name);
    if (i == sk_map_.end())
      return boost::none;
    return i->second;
  }
private:
  /**
   * Returns the name of the kind if component is for a tree declaration, and
   * boost::none otherwise.
   */
  static
  boost::optional<std::string>
  parse_tree(const string& sort) {
    size_t len = sort.length();
    if ((len >= 4) && (sort.substr(len - 4) == "Tree")) {
      return sort.substr(0, len - 4);
    } else {
      return boost::none;
    }
  }

  /**
   * Returns the name of the kind if component is a state declaration,
   * and boost::none otherwise.
   */
  static
  boost::optional<std::string>
  parse_state(const string& sort) {
    size_t len = sort.length();
    if ((len >= 5) && (sort.substr(len - 5) == "State")) {
      return sort.substr(0, len - 5);
    } else if ((len >= 3) && (sort.substr(len - 3) == "Lit")) {
      return sort.substr(0, len - 3);
    } else if ((len >= 6) && (sort.substr(len - 6) == "LitSet")) {
      return sort.substr(0, len - 6);
    } else {
      return boost::none;
    }
  }

  /** Type of map from strings to kinds. */
  typedef map<string, ceta::kind_t> string_kind_map_t;
  /** Set of kinds parsed so far. */
  typedef set<ceta::kind_t> set_t;
  /** Mapping from kind names to kinds. */
  string_kind_map_t sk_map_;
  /** Set of kinds parsed so far. */
  set_t kind_set_;
};

/**
 * Stores the result of parsing each symbol in the automaton and classifies
 * symbols based on whether they correspond to an operator declaration, a
 * state declaration, an acceptance predicate, and a state set union
 * operator.
 */
class symbol_parser_t {
public:
  /** Type of iterator that points to operators parsed from symbols. */
  typedef std::set<ceta::op_t>::const_iterator op_iterator;
  /** Type of iterator that points to states parsed from symbols. */
  typedef std::set<ceta::state_t>::const_iterator state_iterator;

  symbol_parser_t(MetaLevel* meta_level, MetaModule* module,
                  ACU_Symbol* qid_set_symbol)
    : meta_level_(meta_level),
      module_(module),
      qid_set_symbol_(qid_set_symbol) {
  }

  /**
   * Attempt to parse the symbol.
   * The symbol could either be: an operator declaration, a state
   * declaration, a tree-state pair _:_, a literal complementation symbol !_,
   * a literal union symbol _;_, or an accept predicate accept,
   * */
  void parse(const component_parser_t& comp_parser, Symbol* sym) {
    // Indicates if symbol is successfully parsed.
    bool parsed = false;
    string name = Token::name(sym->id());
    const ConnectedComponent* rcomp = sym->rangeComponent();
    boost::optional<ceta::op_t> op = parse_op(comp_parser, sym);
    // If sym could only be an operator declaration.
    if (op) {
      op_sym_map_.insert(make_pair(*op, sym));
      sym_op_map_.insert(make_pair(sym, *op));
      ops_.insert(*op);
      parsed = true;
    // If sym is a constant it could only parse as a state declaration.
    } else if (sym->arity() == 0) {
      boost::optional<ceta::kind_t> okind
              = comp_parser.find_state_kind(rcomp);
      if (okind) {
        if (name != "none") {
          ceta::state_t state(*okind, name);
          state_sym_map_.insert(make_pair(state, sym));
          sym_state_map_.insert(make_pair(sym, state));
          states_.insert(state);
        }
        parsed = true;
      }
    // If sym looks like tree-state pair.
    } else if (name ==  "_:_") {
      parsed = true;
    // If sym looks like literal complementation symbol.
    } else if (name == "!_") {
      parsed = true;
    // If sym looks like state union operator.
    } else if ((name == "_;_")
            && (sym->arity() == 2)
            && (sym->domainComponent(0) == rcomp)
            && (sym->domainComponent(1) == rcomp)) {
      boost::optional<ceta::kind_t> okind
            = comp_parser.find_state_kind(rcomp);
      if (okind) {
        union_sym_map_.insert(
                make_pair(*okind, static_cast<BinarySymbol*>(sym)));
        parsed = true;
      }
    // If sym looks like an accept predicate symbol.
    } else if (name == "accept") {
      parsed = true;
    }
    string output_name = Token::name(sym->rangeComponent()->sort(0)->id());
    // If output is Bool, just assume this is a builtin Maude operator.
    if (output_name == "Bool")
      parsed = true;

    if (!parsed) {
      sig_warning("Could not identify symbol \"" + name
                  + "\" with output kind \""
                  + Token::name(sym->rangeComponent()->sort(0)->id())
                  + "\" so skipping.");
    }
  }

  /** Returns an iterator that points to first operator parsed. */
  op_iterator ops_begin(void) const {
    return ops_.begin();
  }

  /** Returns an iterator that points one past the last operator parsed. */
  op_iterator ops_end(void) const {
    return ops_.end();
  }

  /** Returns the set of axioms parsed out of the operator. */
  ceta::axiom_set_t axioms(const MetaModule* m, const ceta::op_t& op) const {
    op_sym_map_t::const_iterator i = op_sym_map_.find(op);
    ceta::axiom_set_t result = ceta::none();

    if (i != op_sym_map_.end()) {
      Symbol* sym = i->second;
      SymbolType st = m->getSymbolType(sym);
      if (st.hasFlag(SymbolType::ASSOC))
        result |= ceta::assoc();
      if (st.hasFlag(SymbolType::COMM))
        result |= ceta::comm();

      bool left_id  = st.hasFlag(SymbolType::LEFT_ID);
      bool right_id = st.hasFlag(SymbolType::RIGHT_ID);

      if (left_id || right_id) {
        // Get identity operator for symbol.
        const BinarySymbol* bin_sym = static_cast<BinarySymbol*>(sym);
        Symbol* id_sym = bin_sym->getIdentity()->symbol();
        boost::optional<ceta::op_t> id_op = find_op(id_sym);

        // Add identity to result
        if (id_sym->arity() != 0) {
          sig_warning(string("Identity symbol \"")
                    + Token::name(id_sym->id())
                    + "\" is not a constant so skipping.");
        } else if (! id_op) {
          sig_warning(string("Identity symbol \"")
                    + Token::name(id_sym->id())
                    + "\" is not a known tree operator so skipping.");
        } else if (left_id && right_id) {
          result |= ceta::id(*id_op);
        } else if (left_id) {
          result |= ceta::left_id(*id_op);
        } else {
          result |= ceta::right_id(*id_op);
        }
      }
    }
    return result;
  }

  /** Returns an iterator that points to first state parsed. */
  state_iterator states_begin(void) const {
    return states_.begin();
  }

  /** Returns an iterator that points one past the last state parsed. */
  state_iterator states_end(void) const {
    return states_.end();
  }

  /**
   * Returns the Ceta operator corresponding to symbol if one exists, and
   * returns boost::none otherwise.
   */
  boost::optional<ceta::op_t> find_op(const Symbol* sym) const {
    sym_op_map_t::const_iterator i = sym_op_map_.find(sym);
    if (i != sym_op_map_.end()) {
      return i->second;
    } else {
      return boost::none;
    }
  }

  /**
   * Returns the Ceta state corresponding to symbol if one exists, and
   * returns boost::none otherwise.
   */
  boost::optional<ceta::state_t> find_state(const Symbol* sym) const {
    sym_state_map_t::const_iterator i = sym_state_map_.find(sym);
    if (i != sym_state_map_.end()) {
      return i->second;
    } else {
      return boost::none;
    }
  }

  /**
   * Creates a dagnode representing a set of states that were constructed
   * during parsing.
   */
  DagNode* create_set_dagnode(const ceta::kind_t& kind,
                              const set<ceta::state_t>& states) const {
    PointerMap qidMap;
    PointerMap dagNodeMap;
    // Build set arguments
    Vector<DagNode*> args;
    typedef set<ceta::state_t>::const_iterator state_iter;
    for (state_iter i = states.begin(); (i != states.end()); ++i) {
      state_sym_map_t::const_iterator isym = state_sym_map_.find(*i);
      if (isym != state_sym_map_.end()) {
        DagNode* cur_arg = isym->second->makeDagNode();
        cur_arg->symbol()->computeBaseSort(cur_arg);
        cur_arg = meta_level_->upDagNode(cur_arg, module_, qidMap, dagNodeMap);
        args.append(cur_arg);
      }
    }

    // Build final result based on number of arguments.
    if (args.size() == 0) {
      return qid_set_symbol_->getIdentityDag();
    } else if (args.size() == 1) {
      return args[0];
    } else {
      return qid_set_symbol_->makeDagNode(args);
    }
  }

  /** Create dagnode for representing a ceta::term_t. */
  DagNode* create_term_dagnode(const ceta::term_t& term) const {
    // Create dagnodes for subterms
    typedef ceta::term_t::subterm_iterator iter;
    Vector<DagNode*> args(subterm_count(term));
    size_t cur_idx = 0;
    for (iter i = subterms_begin(term); i != subterms_end(term); ++i) {
      args[cur_idx] = create_term_dagnode(*i);
      ++cur_idx;
    }

    DagNode* result
            = op_sym_map_.find(root(term))->second->makeDagNode(args);
    result->symbol()->computeBaseSort(result);
    return result;
  }
private:
  /**
   * Returns true if every component in domain and range is a tree
   * component.  This implies the symbol could only be parsed an operator
   * declaration.
   */
  boost::optional<ceta::op_t>
  parse_op(const component_parser_t& parser, const Symbol* sym) {
    boost::optional<ceta::kind_t> okind
            = parser.find_tree_kind(sym->rangeComponent());
    if (!okind)
      return boost::none;

    bool valid = okind;
    std::vector<ceta::kind_t> ikinds;
    ikinds.reserve(sym->arity());
    for (int i = 0; valid && (i < sym->arity()); ++i) {
      boost::optional<ceta::kind_t> k
            = parser.find_tree_kind(sym->domainComponent(i));
      if (k) {
        ikinds.push_back(*k);
      } else {
        valid = false;
      }
    }
    if (!valid)
      return boost::none;

    return ceta::op_t(Token::name(sym->id()), ikinds.begin(), ikinds.end(),
                      *okind);
  }
  typedef map<ceta::op_t, Symbol*> op_sym_map_t;
  typedef map<const Symbol*, ceta::op_t> sym_op_map_t;
  typedef map<ceta::state_t, Symbol*> state_sym_map_t;
  typedef map<const Symbol*, ceta::state_t> sym_state_map_t;
  typedef map<ceta::kind_t, BinarySymbol*> union_sym_map_t;

  /** Pointer to meta level for tree automaton. */
  MetaLevel* meta_level_;
  /** Pointer to module defining tree automaton. */
  MetaModule* module_;
  /** Pointer to symbol for qid set union operator. */
  ACU_Symbol* qid_set_symbol_;

  std::set<ceta::op_t> ops_;
  op_sym_map_t op_sym_map_;
  sym_op_map_t sym_op_map_;

  std::set<ceta::state_t> states_;
  state_sym_map_t state_sym_map_;
  sym_state_map_t sym_state_map_;
  union_sym_map_t union_sym_map_;
};

/** Parses Maude equations into Ceta predicates. */
class equation_parser_t {
public:
  /** Constructs a new parser built from parsing the provided equations. */
  equation_parser_t(const component_parser_t& comp_parser,
                    const symbol_parser_t& symbol_parser,
                    const Vector<Equation*>& eqs) {
    typedef Vector<Equation*>::const_iterator iter;
    for (iter i = eqs.begin(); i != eqs.end(); ++i)
      parse(comp_parser, symbol_parser, *i);
  }

  /**
   * Attempts to parse a rule in Maude's equation into a regular or epsilon
   * transition rule.
   */
  void parse(const component_parser_t& comp_parser,
             const symbol_parser_t& symbol_parser,
             const Equation* eq) {
    bool parsed = false;
    Term* lhs = eq->getLhs();
    if (string(Token::name(lhs->symbol()->id())) == "accept") {
      Term* set = get_arg(lhs, 0);
      // Get kind of set.
      boost::optional<ceta::kind_t> k
              = comp_parser.find_state_kind(set->getComponent());
      if (k && (set != NULL)) {
        // Construct state predicate out of set.
        ceta::state_predicate_t p = parse_predicate(symbol_parser, *k, set);

        map_t::iterator i = map_.find(*k);
        // If a predicate for kind has already been assigned.
        if (i != map_.end()) {
          // Union with existing assigned predicate.
          i->second |= p;
        // Otherwise
        } else {
          // Assign new predicate to this kind.
          map_.insert(make_pair(*k, p));
        }
      }
    }
    // If a component is a boolean, assume equation is imported from BOOL.
    if (comp_parser.is_bool(lhs->getComponent()))
      parsed = true;
    if (!parsed)
      sig_warning("Could not parse equation so skipping.");
  }

  /** Returns predicate that has been parsed for given kind. */
  const ceta::state_predicate_t predicate(const ceta::kind_t& kind) const {
    map_t::const_iterator i = map_.find(kind);
    if (i != map_.end()) {
      return i->second;
    } else {
      return ceta::state_predicate_t(kind, false);
    }
  }
private:

  /**
   * Returns sign and state associated with literal or boost::none if it can
   * not be parsed.
   */
  static
  boost::optional< std::pair<bool, ceta::state_t> >
  parse_lit(const symbol_parser_t& symbol_parser, Term* lit) {
    //TODO Detect errors in parse.
    bool sign = lit->symbol()->arity() == 0;
    if (sign == false)
      lit = get_arg(lit, 0);
    if (lit == 0) return boost::none;

    boost::optional<ceta::state_t> state
            = symbol_parser.find_state(lit->symbol());
    if (!state) return boost::none;
    return make_pair(sign, *state);
  }

  /**
   * Extracts a state predicate from a single equation in Maude's tree
   * automaton representation.
   *
   * @param sym_state_map Mapping from Maude symbols to states in the
   *                      automaton.
   * @param eq Equation from Maude's term metarepresentation.  We assume the
   *           syntax has already been checked.
   */
  static
  ceta::state_predicate_t
  parse_predicate(const symbol_parser_t& symbol_parser,
                  ceta::kind_t k, Term* set) {
    auto_ptr<RawArgumentIterator> iargs(set->arguments());
    ceta::state_predicate_t result(k, true);
    while ((iargs.get() != NULL) && iargs->valid()) {
      boost::optional< std::pair<bool, ceta::state_t> > lit
        = parse_lit(symbol_parser, iargs->argument());
      if (lit) {
        result &= (lit->first ? lit->second : ! lit->second);
      }
      iargs->next();
    }
    return result;
  }

  typedef std::map<ceta::kind_t, ceta::state_predicate_t> map_t;
  map_t map_;
};


/** Parses Maude rules into Ceta transitions. */
class rule_parser_t {
public:
  /**
   * Type of iterator that points to epsilon rules parsed from
   * representation rules.
   */
  typedef std::set<ceta::erule_t>::const_iterator erule_iterator;
  /**
   * Type of iterator that points to regular rules parsed from
   * representation rules.
   */
  typedef std::set<ceta::rule_t>::const_iterator rule_iterator;

  /** Constructs a new parser built from parsing the provided rules. */
  rule_parser_t(const symbol_parser_t& parser, const Vector<Rule*>& rules) {
    typedef Vector<Rule*>::const_iterator iter;
    for (iter i = rules.begin(); i != rules.end(); ++i)
      parse(parser, *i);
  }

  /**
   * Attempts to parse a rule in Maude's automaton into a regular or
   * epsilon transition rule.
   */
  void parse(const symbol_parser_t& symbol_parser, const Rule* rule) {
    Term* lhs = rule->getLhs();
    Term* rhs = rule->getRhs();

    // Indicates if rule has been successfully parsed.
    bool parsed = false;

    boost::optional<ceta::op_t> op = symbol_parser.find_op(lhs->symbol());
    if (op) {
      boost::optional<ceta::state_t> rhs_state
        = symbol_parser.find_state(get_state_symbol(rhs));
      bool should_add = op && rhs_state;

      vector<ceta::state_t> lhs_states;
      auto_ptr<RawArgumentIterator> iargs(lhs->arguments());

      while (should_add && (iargs.get() != NULL) && iargs->valid()) {
        Symbol* state_sym = get_state_symbol(iargs->argument());
        boost::optional<ceta::state_t> cur_state
                = symbol_parser.find_state(state_sym);
        if (cur_state) {
          lhs_states.push_back(*cur_state);
        } else {
          should_add = false;
        }
        iargs->next();
      }
      if (should_add) {
        rules_.insert(
                ceta::rule_t(*op, lhs_states.begin(), lhs_states.end(),
                             *rhs_state));
        parsed = true;
      }
    // Otherwise may be erule (of form State => State)
    } else {
      boost::optional<ceta::state_t> lhs_state
              = symbol_parser.find_state(lhs->symbol());
      boost::optional<ceta::state_t> rhs_state
              = symbol_parser.find_state(rhs->symbol());
      if (lhs_state && rhs_state) {
        erules_.insert(ceta::erule_t(*lhs_state, *rhs_state));
        parsed = true;
      }
    }
    if (!parsed)
      sig_warning("Could not parse transition rule so skipping.");
  }

  /** Returns an iterator that points to first epsilon rule parsed. */
  erule_iterator erules_begin(void) const {
    return erules_.begin();
  }

  /**
   * Returns an iterator that points one past the last epsilon rule parsed.
   */
  erule_iterator erules_end(void) const {
    return erules_.end();
  }

  /** Returns an iterator that points to first rule parsed. */
  rule_iterator rules_begin(void) const {
    return rules_.begin();
  }

  /** Returns an iterator that points one past the last rule parsed. */
  rule_iterator rules_end(void) const {
    return rules_.end();
  }
private:
  std::set<ceta::erule_t> erules_;
  std::set<ceta::rule_t> rules_;
};

bool CetaSymbol::setReachability(FreeDagNode* subject,
                                                RewritingContext& context) {
  MetaModule* m = metaLevel->downModule(subject->getArgument(0));

  DagNode* result;
  if (m != NULL) {
    m->protect();
    try {
      ceta::theory_t theory;
      // Parse connected components into Ceta kinds.
      component_parser_t comp_parser(m->getConnectedComponents());
      // Add all kinds in map to theory.
      typedef component_parser_t::kind_iterator kind_iter;
      for (kind_iter i = comp_parser.begin(); i != comp_parser.end(); ++i)
        add_kind(theory, *i);

      // Parse symbols in meta level.
      symbol_parser_t symbol_parser(metaLevel, m, qidSetSymbol);
      int sym_count = m->getNrUserSymbols();
      for (int i = m->getNrImportedSymbols(); i != sym_count; ++i)
        symbol_parser.parse(comp_parser, m->getSymbols()[i]);
      typedef symbol_parser_t::op_iterator op_iter;
      op_iter ops_end = symbol_parser.ops_end();
      // Add operator to theories.
      // Note that we add all the operators before setting axioms, to
      // to guaranteeing each identity operator has already been added to
      // theory.
      for (op_iter i = symbol_parser.ops_begin(); i != ops_end; ++i)
        add_op(theory, *i);
      // Set all axioms.
      for (op_iter i = symbol_parser.ops_begin(); i != ops_end; ++i)
        set_axioms(theory, *i, symbol_parser.axioms(m, *i));

      ceta::ta_t ta(theory);

      typedef symbol_parser_t::state_iterator state_iter;
      state_iter states_begin = symbol_parser.states_begin();
      state_iter states_end = symbol_parser.states_end();
      // Add states to automaton.
      for (state_iter i = states_begin; i != states_end; ++i)
        add_state(ta, *i);

      // Parse equations
      equation_parser_t eq_parse(comp_parser, symbol_parser,
                                 m->getEquations());
      for (kind_iter i = comp_parser.begin(); i != comp_parser.end(); ++i)
        set_predicate(ta, eq_parse.predicate(*i));

      // Parse rules.
      rule_parser_t rule_parser(symbol_parser, m->getRules());
      typedef rule_parser_t::erule_iterator erule_iter;
      erule_iter erules_end = rule_parser.erules_end();
      // Add epsilon transitions to automaton.
      for (erule_iter i = rule_parser.erules_begin(); i != erules_end; ++i)
        add_erule(ta, *i);
      typedef rule_parser_t::rule_iterator rule_iter;
      rule_iter rules_end = rule_parser.rules_end();
      // Add transitions to automaton.
      for (rule_iter i = rule_parser.rules_begin(); i != rules_end; ++i)
        add_rule(ta, *i);

      // Test emptiness
      ceta::test_result_t test_result = test_emptiness(ta);

      // If empty return empty symbol
      if (test_result) {
        result = emptySymbol->makeDagNode();
      // Otherwise return counterexample and reachable set.
      } else {
        ceta::term_t counter = ceta::counterexample(test_result);

        DagNode* term_dag = symbol_parser.create_term_dagnode(counter);

        DagNode* set_dag = symbol_parser.create_set_dagnode(kind(counter),
                                          ceta::reachable_set(test_result));
        Vector<DagNode*> args(2);
        PointerMap qidMap;
        PointerMap dagNodeMap;
        args[0] = metaLevel->upDagNode(term_dag, m, qidMap, dagNodeMap);
        args[1] = set_dag;
        result = acceptingTermSymbol->makeDagNode(args);
      }
    } catch (domain_error &e) {
      std::cerr << "Error creating tree automaton" << std::endl;
      sig_warning(e.what());
      result = invalidInputSymbol->makeDagNode();
    }
    m->unprotect();
  } else {
    std::cerr << "Could not parse Maude module" << std::endl;
    result = invalidInputSymbol->makeDagNode();
  }
  return context.builtInReplace(subject, result);
}

bool
CetaSymbol::okToBind() {
  if (shareWith != NULL)
    return false;
  if (metaLevel == NULL)
    metaLevel = new MetaLevel;
  return true;
}

bool
CetaSymbol::attachData(const Vector<Sort*>& opDeclaration,
			              const char* purpose,
			              const Vector<const char*>& data) {
  NULL_DATA(purpose, CetaSymbol, data);
  return FreeSymbol::attachData(opDeclaration, purpose, data);
}

bool
CetaSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  if (metaLevel == NULL)
    BIND_SYMBOL(purpose, symbol, shareWith, MetaLevelOpSymbol*);
  BIND_SYMBOL(purpose, symbol, emptySymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, acceptingTermSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, invalidInputSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, qidSetSymbol, ACU_Symbol*);

  return (okToBind() && metaLevel->bind(purpose, symbol)) ? true :
    FreeSymbol::attachSymbol(purpose, symbol);
}

bool
CetaSymbol::attachTerm(const char* purpose, Term* term)
{
  return (okToBind() && metaLevel->bind(purpose, term)) ? true :
    FreeSymbol::attachTerm(purpose, term);
}

void
CetaSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  if (shareWith == NULL && metaLevel == NULL) {
    CetaSymbol* orig
            = safeCast(CetaSymbol*, original);
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
    emptySymbol = safeCast(Symbol*, map->translate(orig->emptySymbol));
    acceptingTermSymbol
            = safeCast(Symbol*, map->translate(orig->acceptingTermSymbol));
    invalidInputSymbol
            = safeCast(Symbol*, map->translate(orig->invalidInputSymbol));
    qidSetSymbol
            = safeCast(ACU_Symbol*, map->translate(orig->qidSetSymbol));
  }
  FreeSymbol::copyAttachments(original, map);
}

void
CetaSymbol::getSymbolAttachments(Vector<const char*>& purposes,
					Vector<Symbol*>& symbols)
{
  if (shareWith == NULL)
    metaLevel->getSymbolAttachments(purposes, symbols);
  else
    {
      purposes.append("shareWith");
      symbols.append(shareWith);
    }
  APPEND_SYMBOL(purposes, symbols, emptySymbol);
  APPEND_SYMBOL(purposes, symbols, acceptingTermSymbol);
  APPEND_SYMBOL(purposes, symbols, invalidInputSymbol);
  APPEND_SYMBOL(purposes, symbols, qidSetSymbol);
  FreeSymbol::getSymbolAttachments(purposes, symbols);
}

void
CetaSymbol::getTermAttachments(Vector<const char*>& purposes,
				      Vector<Term*>& terms)
{
  if (shareWith == NULL)
    metaLevel->getTermAttachments(purposes, terms);
  FreeSymbol::getTermAttachments(purposes, terms);
}

void
CetaSymbol::postInterSymbolPass()
{
  if (shareWith == NULL)
    metaLevel->postInterSymbolPass();
  else
    metaLevel = shareWith->getMetaLevel();
}

void
CetaSymbol::reset()
{
  if (shareWith == NULL && metaLevel != NULL)
    metaLevel->reset();
}

bool
CetaSymbol::eqRewrite(DagNode* subject,
                                     RewritingContext& context)
{
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
