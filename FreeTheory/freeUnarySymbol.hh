//
//	Class for unary symbols belonging to the free theory.
//	Sole purpose of this class is to provide a optimized eqRewrite() for unary 
//	free function symbols that have the standard strategy.
//
#ifndef _freeUnarySymbol_hh_
#define _freeUnarySymbol_hh_
#include "freeSymbol.hh"

class FreeUnarySymbol : public FreeSymbol
{
public:
  FreeUnarySymbol(int id);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
};

#endif
