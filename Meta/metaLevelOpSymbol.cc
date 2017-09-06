//
//      Implementation for class MetaLevelOpSymbol.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "pointerMap.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "higher.hh"
#include "freeTheory.hh"
#include "AU_Theory.hh"
#include "ACU_Theory.hh"
#include "NA_Theory.hh"
#include "builtIn.hh"
#include "mixfix.hh"
 
//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "rawDagArgumentIterator.hh"
#include "rawArgumentIterator.hh"
#include "term.hh"
#include "extensionInfo.hh"

//      core class definitions
#include "variableInfo.hh"
#include "variableSymbol.hh"
#include "preEquation.hh"
#include "substitution.hh"
#include "rewritingContext.hh"
#include "module.hh"
#include "label.hh"
#include "rule.hh"
#include "symbolMap.hh"

//	higher class definitions
#include "pattern.hh"
#include "rewriteSearchState.hh"
#include "matchSearchState.hh"
#include "rewriteSequenceSearch.hh"

//      free theory class definitions
#include "freeNet.hh"
#include "freeSymbol.hh"
#include "freeDagNode.hh"

//      variable class definitions
#include "variableDagNode.hh"

//      built in class definitions
#include "succSymbol.hh"
#include "bindingMacros.hh"
 
//      front end class definitions
#include "userLevelRewritingContext.hh"
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"
#include "quotedIdentifierOpSymbol.hh"
#include "metaModule.hh"
#include "metaLevel.hh"
#include "metaLevelOpSymbol.hh"
#include "fileTable.hh"
#include "preModule.hh"
#include "interpreter.hh"
#include "visibleModule.hh"
#include "main.hh"  // HACK shouldn't access global variables

//	our stuff
#include "descentFunctions.cc"
#include "ascentFunctions.cc"
#include "metaMatch.cc"
#include "metaSearch.cc"

MetaLevelOpSymbol::MetaLevelOpSymbol(int id, int nrArgs)
  : FreeSymbol(id, nrArgs)
{
  shareWith = 0;
  metaLevel = 0;
}

MetaLevelOpSymbol::~MetaLevelOpSymbol()
{
  if (shareWith == 0)
    delete metaLevel;
}

bool
MetaLevelOpSymbol::okToBind()
{
  if (shareWith != 0)
    return false;
  if (metaLevel == 0)
    metaLevel = new MetaLevel;
  return true;
}

bool
MetaLevelOpSymbol::attachData(const Vector<Sort*>& /* opDeclaration */,
			      const char* /* purpose */,
			      const Vector<const char*>& data)
{
  if (data.length() == 1)
    {
      const char* opName = data[0];
#define MACRO(SymbolName, NrArgs) \
      if (arity() == NrArgs && strcmp(opName, #SymbolName) == 0) \
	descentFunction = &MetaLevelOpSymbol::SymbolName; else
#include "descentSignature.cc"
#undef MACRO
        return false;
      return true;
    }
  return false;
}

bool
MetaLevelOpSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  if (metaLevel == 0)
    BIND_SYMBOL(purpose, symbol, shareWith, MetaLevelOpSymbol*);
  return okToBind() && metaLevel->bind(purpose, symbol);
}

bool
MetaLevelOpSymbol::attachTerm(const char* purpose, Term* term)
{
  return okToBind() && metaLevel->bind(purpose, term);
}

void
MetaLevelOpSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  if (shareWith == 0 && metaLevel == 0)
    {
      MetaLevelOpSymbol* orig = safeCast(MetaLevelOpSymbol*, original);
      descentFunction = orig->descentFunction;
      MetaLevelOpSymbol* sw = orig->shareWith;
      if (sw != 0)
	{
	  metaLevel = 0;
	  shareWith = (map == 0) ? sw : static_cast<MetaLevelOpSymbol*>(map->translate(sw));
	}
      else
	{
	  metaLevel = new MetaLevel(orig->metaLevel, map);
	  shareWith = 0;
	}
    }
}

void
MetaLevelOpSymbol::postInterSymbolPass()
{
  if (shareWith == 0)
    metaLevel->postInterSymbolPass();
  else
    metaLevel = shareWith->metaLevel;
}

void
MetaLevelOpSymbol::reset()
{
  if (shareWith == 0 && metaLevel != 0)
    metaLevel->reset();
}

DagNode*
MetaLevelOpSymbol::term2Dag(Term* t)
{
  NatSet eagerVariables;
  Vector<int> problemVariables;
  t->markEager(0, eagerVariables, problemVariables);
  DagNode* r = t->term2Dag();
  return r;
}

bool
MetaLevelOpSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "Bad symbol");
  if (metaLevel == 0)
    metaLevel = shareWith->metaLevel;
  FreeDagNode* d = static_cast<FreeDagNode*>(subject);
  int nrArgs = arity();
  for (int i = 0; i < nrArgs; i++)
    d->getArgument(i)->reduce(context);
  return (this->*descentFunction)(d, context) || FreeSymbol::eqRewrite(subject, context);
}
