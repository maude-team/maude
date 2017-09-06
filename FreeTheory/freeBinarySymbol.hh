//
//	Class for binary symbols belonging to the free theory.
//	Sole purpose of this class is to provide a optimized eqRewrite() for binary
//	free function symbols that have the standard strategy.
//
#ifndef _freeBinarySymbol_hh_
#define _freeBinarySymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "freeSymbol.hh"

class FreeBinarySymbol : public FreeSymbol
{
public:
  FreeBinarySymbol(int id);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
};

#endif
