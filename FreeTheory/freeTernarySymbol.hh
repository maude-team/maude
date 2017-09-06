//
//	Class for ternary symbols belonging to the free theory.
//	Sole purpose of this class is to provide a optimized eqRewrite() for ternary
//	free function symbols that have the standard strategy.
//
#ifndef _freeTernarySymbol_hh_
#define _freeTernarySymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "freeSymbol.hh"

class FreeTernarySymbol : public FreeSymbol
{
public:
  FreeTernarySymbol(int id);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
};

#endif
