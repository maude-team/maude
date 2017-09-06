//
//      Implementation for class ModelCheckerSymbol.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "temporal.hh"
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "builtIn.hh"
#include "higher.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "dagArgumentIterator.hh"
#include "substitution.hh"
#include "rewritingContext.hh"
#include "symbolMap.hh"
#include "dagNodeSet.hh"
#include "rule.hh"

//      free theory class definitions
#include "freeDagNode.hh"

//      built in class definitions
#include "bindingMacros.hh"

//	temporal class definitions
#include "logicFormula.hh"

//HACK
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"

//      higher class definitions
#include "modelCheckerSymbol.hh"

ModelCheckerSymbol::ModelCheckerSymbol(int id)
  : TemporalSymbol(id, 2)
{
  satisfiesSymbol = 0;
  qidSymbol = 0;
  unlabeledSymbol = 0;
  deadlockSymbol = 0;
  transitionSymbol = 0;
  transitionListSymbol = 0;
  nilTransitionListSymbol = 0;
  counterexampleSymbol = 0;
}

bool
ModelCheckerSymbol::attachData(const Vector<Sort*>& opDeclaration,
			const char* purpose,
			const Vector<const char*>& data)
{
  if (strcmp(purpose, "ModelCheckerSymbol") == 0)
    return data.length() == 0;
  return  TemporalSymbol::attachData(opDeclaration, purpose, data);
}

bool
ModelCheckerSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  BIND_SYMBOL(purpose, symbol, satisfiesSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, qidSymbol, QuotedIdentifierSymbol*);
  BIND_SYMBOL(purpose, symbol, unlabeledSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, deadlockSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, transitionSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, transitionListSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, nilTransitionListSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, counterexampleSymbol, Symbol*);
  return TemporalSymbol::attachSymbol(purpose, symbol);
}

bool
ModelCheckerSymbol::attachTerm(const char* purpose, Term* term)
{
  BIND_TERM(purpose, term, trueTerm);
  return TemporalSymbol::attachTerm(purpose, term);
}

void
ModelCheckerSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  ModelCheckerSymbol* orig = safeCast(ModelCheckerSymbol*, original);
  COPY_SYMBOL(orig, satisfiesSymbol, map, Symbol*);
  COPY_SYMBOL(orig, qidSymbol, map, QuotedIdentifierSymbol*);
  COPY_SYMBOL(orig, unlabeledSymbol, map, Symbol*);
  COPY_SYMBOL(orig, deadlockSymbol, map, Symbol*);
  COPY_SYMBOL(orig, transitionSymbol, map, Symbol*);
  COPY_SYMBOL(orig, transitionListSymbol, map, Symbol*);
  COPY_SYMBOL(orig, nilTransitionListSymbol, map, Symbol*);
  COPY_SYMBOL(orig, counterexampleSymbol, map, Symbol*);

  COPY_TERM(orig, trueTerm, map);
  TemporalSymbol::copyAttachments(original, map);
}

void
ModelCheckerSymbol::postInterSymbolPass()
{
  PREPARE_TERM(trueTerm);
  TemporalSymbol::postInterSymbolPass();
}

void
ModelCheckerSymbol::reset()
{
  trueTerm.reset();  // so true dag can be garbage collected
  TemporalSymbol::reset();  // parents reset() tasks
}

void
ModelCheckerSymbol::dump(const StateTransitionGraph3& states, const list<int>& path)
{
  cout << "begin{StateList}\n";
  for (list<int>::const_iterator i = path.begin(); i != path.end(); i++)
    {
      cout << states.getStateDag(*i) << '\n';
    }
  cout << "end{StateList}\n";
}

DagNode*
ModelCheckerSymbol::makeTransition(const StateTransitionGraph3& states, int stateNr, int targetNr)
{
  static Vector<DagNode*> args(2);

  args[0] = states.getStateDag(stateNr);
  const StateTransitionGraph3::ArcMap& fwdArcs = states.getStateFwdArcs(stateNr);
  StateTransitionGraph3::ArcMap::const_iterator i = fwdArcs.find(targetNr);
  if (i == fwdArcs.end())
    args[1] = deadlockSymbol->makeDagNode();
  else
    {
      int id = (*(i->second.begin()))->getLabel().id();
      args[1] = (id == NONE) ? unlabeledSymbol->makeDagNode() :
	new QuotedIdentifierDagNode(qidSymbol, id);
    }
 return transitionSymbol->makeDagNode(args);
}

DagNode*
ModelCheckerSymbol::makeTransitionList(const StateTransitionGraph3& states,
				       const list<int>& path,
				       int lastTarget)
{
  Vector<DagNode*> args;
  if (path.empty())
    return nilTransitionListSymbol->makeDagNode(args);
  const list<int>::const_iterator e = path.end();
  for (list<int>::const_iterator i = path.begin();;)
    {
      int stateNr = *i;
      if (++i == e)
	{
	  args.append(makeTransition(states, stateNr, lastTarget));
	  break;
	}
      else
	args.append(makeTransition(states, stateNr, *i));
    }
  return (args.length() == 1) ? args[0] : transitionListSymbol->makeDagNode(args);
}

DagNode*
ModelCheckerSymbol::makeCounterexample(const StateTransitionGraph3& states,
				       const ModelChecker2& mc)
{
  Vector<DagNode*> args(2);
  int junction = mc.getCycle().front();
  args[0] = makeTransitionList(states, mc.getLeadIn(), junction);
  args[1] = makeTransitionList(states, mc.getCycle(), junction);
  return counterexampleSymbol->makeDagNode(args);
}

bool
ModelCheckerSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  //
  //	Compute normalization of negated formula.
  //
  FreeDagNode* d = safeCast(FreeDagNode*, subject);
  RewritingContext* newContext = context.makeSubcontext(negate(d->getArgument(1)));
  newContext->reduce();
#ifdef TDEBUG
  cout << "Negated formula: " << newContext->root() << endl;
#endif
  //
  //	Convert Dag into a LogicFormula.
  //
  SystemAutomaton system;
  LogicFormula formula;
  int top = build(formula, system.propositions, newContext->root());
  if (top == NONE)
    {
      IssueAdvisory("negated LTL formula " << QUOTE(newContext->root()) <<
		    " did not reduce to a valid negative normal form.");
      return TemporalSymbol::eqRewrite(subject, context);
    }
  context.addInCount(*newContext);
#ifdef TDEBUG
  cout << "top = " << top << endl;
  formula.dump(cout);
#endif
  //
  //	Do the model check using a ModelChecker2 object.
  //
  system.satisfiesSymbol = satisfiesSymbol;
  system.parentContext = &context;
  system.trueTerm = trueTerm.getDag();
  RewritingContext* sysContext = context.makeSubcontext(d->getArgument(0));
  system.systemStates = new StateTransitionGraph3(sysContext);
  ModelChecker2 mc(system, formula, top);
  bool result = mc.findCounterexample();
  int nrSystemStates = system.systemStates->getNrStates();
  Verbose("ModelCheckerSymbol: Examined " << nrSystemStates <<
	  " system state" << pluralize(nrSystemStates) << '.');
#ifdef TDEBUG
  if (result == true)
    {
      dump(*(system.systemStates), mc.getLeadIn());
      dump(*(system.systemStates), mc.getCycle());
    }
#endif
  delete newContext;
  DagNode* resultDag = result ? makeCounterexample(*(system.systemStates), mc)
    : trueTerm.getDag();
  context.addInCount(*sysContext);
  delete system.systemStates;  // deletes sysContext via ~StateTransitionGraph3()
  return context.builtInReplace(subject, resultDag);
}

int
ModelCheckerSymbol::SystemAutomaton::getNextState(int stateNr, int transitionNr)
{
  int n = systemStates->getNextState(stateNr, transitionNr);
  if (n == NONE && transitionNr == 0)
    return stateNr; // fake a self loop for deadlocked state
  return n;
}

bool
ModelCheckerSymbol::SystemAutomaton::checkProposition(int stateNr, int propositionIndex) const
{
  Vector<DagNode*> args(2);
  args[0] = systemStates->getStateDag(stateNr);
  args[1] = propositions.index2DagNode(propositionIndex);
  RewritingContext* testContext = 
    parentContext->makeSubcontext(satisfiesSymbol->makeDagNode(args));
  testContext->reduce();  
  bool result = trueTerm->equal(testContext->root());
  parentContext->addInCount(*testContext);
  delete testContext;
  return result;
}
