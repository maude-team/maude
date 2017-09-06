//
//	Implementation for class FreeUnarySymbol.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "symbol.hh"

//      core class definitions
#include "rewritingContext.hh"

//	free theory class definitions
#include "freeDagNode.hh"
#include "freeTernarySymbol.hh"

FreeTernarySymbol::FreeTernarySymbol(int id)
  : FreeSymbol(id, 3)
{
}

bool
FreeTernarySymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  static_cast<FreeDagNode*>(subject)->internal[0]->reduce(context);
  static_cast<FreeDagNode*>(subject)->internal[1]->reduce(context);
  static_cast<FreeDagNode*>(subject)->internal[2]->reduce(context);
  return discriminationNet.applyReplace(subject, context);
}
