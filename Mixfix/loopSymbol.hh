//
//      Class for symbols for built in loop operation.
//
#ifndef _loopSymbol_hh_
#define _loopSymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "freeSymbol.hh"

class LoopSymbol : public FreeSymbol
{
public:
  LoopSymbol(int id);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  void copyAttachments(Symbol* original, SymbolMap* map);

  bool extractOutput(DagNode* loopNode, Vector<int>& bubble);
  DagNode* injectInput(DagNode* loopNode, const Vector<Token>& bubble);

private:
  NO_COPYING(LoopSymbol);

  DagNode* createQidList(const Vector<Token>& ids);
  bool extractQid(DagNode* metaQid, int& id);
  bool extractQidList(DagNode* metaQidList, Vector<int>& ids);

  static const Vector<int> eagerStrategy;

  QuotedIdentifierSymbol* qidSymbol;
  Symbol* nilQidListSymbol;
  AU_Symbol* qidListSymbol;
};

#endif
