//
//      Implementation for class ConfigSymbol.
//
#ifdef __GNUG__
#pragma implementation
#endif
#include <list>
#include <map>

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"
#include "ACU_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "argumentIterator.hh"
#include "rewritingContext.hh"
#include "rule.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_Term.hh"

//	object system class definitions
#include "configSymbol.hh"

struct ConfigSymbol::MessageQueue
{
  void markReachableNodes();

  DagNode* object;
  list<DagNode*> messages;
};

void
ConfigSymbol::MessageQueue::markReachableNodes()
{
  object->mark();
  for (list<DagNode*>::iterator i = messages.begin(); i != messages.end(); i++)
    (*i)->mark();
}

struct ConfigSymbol::dagNodeLt
{
  bool operator()(const DagNode* d1, const DagNode* d2)
    {
      return d1->compare(d2) < 0;
    }
};

class ConfigSymbol::ObjectMap
 : public map<DagNode*, MessageQueue, dagNodeLt>,
   private SimpleRootContainer
{
  void markReachableNodes();
};

void
ConfigSymbol::ObjectMap::markReachableNodes()
{
  for (ObjectMap::iterator i = begin(); i != end(); i++)
    (*i).second.markReachableNodes();
}

ConfigSymbol::ConfigSymbol(int id, const Vector<int>& strategy, bool memoFlag, Term* identity)
  : ACU_Symbol(id, strategy, memoFlag, identity)
{
}

void
ConfigSymbol::addObjects(NatSet& objSymbols)
{
  objectSymbols.insert(objSymbols);
}

void
ConfigSymbol::addMessages(NatSet& msgSymbols)
{
  messageSymbols.insert(msgSymbols);
}

bool
ConfigSymbol::checkArgs(Term* pattern, Term*& object, Term*& message)
{
  if (pattern->symbol() != this)
    return false;
  object = 0;
  message = 0;
  Term* name = 0;
  for (ArgumentIterator a(*pattern); a.valid(); a.next())
    {
      Term* arg = a.argument();
      int si = arg->symbol()->getIndexWithinModule();
      if (objectSymbols.contains(si))
	{
	  if (object != 0)
	    return false;
	  object = arg;
	}
      else if (messageSymbols.contains(si))
	{
	  if (message != 0)
	    return false;
	  message = arg;
	}
      else
	return false;
      ArgumentIterator n(*arg);
      if (!(n.valid()))
	return false;
      if (name == 0)
	name = n.argument();
      else
	{
	  if (!(name->equal(n.argument())))
	    return false;
	}
    }
  Assert(object != 0 && message != 0, cerr << "object-message check error");
  return true;
}

void
ConfigSymbol::compileRules()
{
  ACU_Symbol::compileRules();  // to get l->r sharing correct

  const Vector<Rule*>& rules = getRules();
  int nrRules = rules.length();
  for (int i = 0; i < nrRules; i++)
    {
      Rule* rl = rules[i];
      Term* object;
      Term* message;
      if (checkArgs(rl->getLhs(), object, message))
	{
	  int nrAutomatonPairs =  automatonPairs.length();
	  automatonPairs.expandBy(1);
	  AutomatonPair& ap = automatonPairs[nrAutomatonPairs];
	  NatSet boundUniquely;
	  bool dummy;
	  ap.objectAutomaton = object->compileLhs(false, *rl,  boundUniquely, dummy);
	  ap.messageAutomaton = message->compileLhs(false, *rl,  boundUniquely, dummy);
	  ap.ruleIndex = i;

	  cout << "***obj-msg rule*** " << rules[i] << endl;
	}
    }
}

DagNode*
ConfigSymbol::ruleRewrite(DagNode* subject, RewritingContext& context)
{
  ACU_DagNode* s = safeCast(ACU_DagNode*, subject);
  int nrArgs = s->nrArgs();
  int nrObjects = 0;
  int nrMessages = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* d = s->getArgument(i);
      int symbolNr = d->symbol()->getIndexWithinModule();
      if (objectSymbols.contains(symbolNr))
	++nrObjects;  // can't be multiple objects with same name
      else if (messageSymbols.contains(symbolNr))
	nrMessages += s->getMultiplicity(i);
    }
  
  cout << "saw " << nrObjects << " objects and " << nrMessages << " messages\n";

  return ACU_Symbol::ruleRewrite(subject, context);
}
