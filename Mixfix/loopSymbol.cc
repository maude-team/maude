//
//      Implementation for class LoopSymbol.
//
#ifdef __GNUG__
#pragma implementation
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"
//#include "stringTable.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "AU_Theory.hh"
#include "NA_Theory.hh"
#include "mixfix.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "rawDagArgumentIterator.hh"
#include "rawArgumentIterator.hh"
#include "term.hh"

//      core class definitions
#include "dagArgumentIterator.hh"
#include "argumentIterator.hh"
#include "substitution.hh"
#include "rewritingContext.hh"
#include "symbolMap.hh"

//      free theory class definitions
#include "freeDagNode.hh"

//      AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"

//      built in class definitions
#include "bindingMacros.hh"

//      front end class definitions
#include "token.hh"
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"
#include "loopSymbol.hh"
#include "token.hh"

const Vector<int> LoopSymbol::eagerStrategy;

LoopSymbol::LoopSymbol(int id)
  : FreeSymbol(id, 3, eagerStrategy)
{
  qidSymbol = 0;
  nilQidListSymbol = 0;
  qidListSymbol = 0;
}

bool
LoopSymbol::attachData(const Vector<Sort*>& opDeclaration,
		       const char* purpose,
		       const Vector<const char*>& data)
{
  if (strcmp(purpose, "LoopSymbol") == 0)
    return data.length() == 0;
  return  FreeSymbol::attachData(opDeclaration, purpose, data);
}

bool
LoopSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  BIND_SYMBOL(purpose, symbol, qidSymbol, QuotedIdentifierSymbol*);
  BIND_SYMBOL(purpose, symbol, nilQidListSymbol, Symbol*);
  BIND_SYMBOL(purpose, symbol, qidListSymbol, AU_Symbol*);
  return FreeSymbol::attachSymbol(purpose, symbol);
}

void
LoopSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  LoopSymbol* orig = safeCast(LoopSymbol*, original);
  COPY_SYMBOL(orig, qidSymbol, map, QuotedIdentifierSymbol*);
  COPY_SYMBOL(orig, nilQidListSymbol, map, Symbol*);
  COPY_SYMBOL(orig, qidListSymbol, map, AU_Symbol*);
  FreeSymbol::copyAttachments(original, map);
}

DagNode*
LoopSymbol::injectInput(DagNode* loopNode, const Vector<Token>& bubble)
{
  static Vector<DagNode*> args(3);

  FreeDagNode* f = static_cast<FreeDagNode*>(loopNode);
  args[0] = createQidList(bubble);
  args[1] = f->getArgument(1);
  args[2] = new FreeDagNode(nilQidListSymbol);
  return makeDagNode(args);
}

DagNode*
LoopSymbol::createQidList(const Vector<Token>& ids)
{
  int nrIds = ids.length();
  if (nrIds == 0)
    return new FreeDagNode(nilQidListSymbol);
  if (nrIds == 1)
    return new QuotedIdentifierDagNode(qidSymbol, ids[0].code());
  Vector<DagNode*> args(nrIds);
  for (int i = 0; i < nrIds; i++)
    args[i] = new QuotedIdentifierDagNode(qidSymbol, Token::backQuoteSpecials(ids[i].code()));
  return qidListSymbol->makeDagNode(args);
}

bool
LoopSymbol::extractOutput(DagNode* loopNode, Vector<int>& bubble)
{
  FreeDagNode* f = static_cast<FreeDagNode*>(loopNode);
  return extractQidList(f->getArgument(2), bubble);
}

bool
LoopSymbol::extractQid(DagNode* metaQid, int& id)
{
  if (metaQid->symbol() == qidSymbol)
    {
      id =
	Token::unBackQuoteSpecials(static_cast<QuotedIdentifierDagNode*>(metaQid)->getIdIndex());
      return true;
    }
  return false;
}

bool
LoopSymbol::extractQidList(DagNode* metaQidList, Vector<int>& ids)
{
  ids.contractTo(0);
  Symbol* mq = metaQidList->symbol();
  int id;
  if (mq == qidListSymbol)
    {
      AU_DagNode* a = static_cast<AU_DagNode*>(metaQidList);
      int nrArgs = a->nrArgs();
      for (int i = 0; i < nrArgs; i++)
	{
	  if (!extractQid(a->getArgument(i), id))
	    return false;
	  ids.append(id);
	}
    }
  else if (extractQid(metaQidList, id))
    ids.append(id);
  else if (mq != nilQidListSymbol)
    return false;
  return true;
}
