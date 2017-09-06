//
//      Implementation for class NA_Symbol.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      NA theory class definitions
#include "NA_Symbol.hh"

NA_Symbol::NA_Symbol(int id)
  : Symbol(id, 0)
{
}

Term*
NA_Symbol::makeTerm(const Vector<Term*>& /* args */)
{
  Assert(false, cerr << "makeTerm() not useable on non-algebraic symbol " << this);
  return 0;
}

DagNode* 
NA_Symbol::makeDagNode(const Vector<DagNode*>& /* args */)
{
  Assert(false, cerr << "makeDagNode() not useable on non-algebraic symbol " << this);
  return 0;
}

bool
NA_Symbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  return applyReplace(subject, context, 0);
}

void
NA_Symbol::computeBaseSort(DagNode* subject)
{
  subject->setSortIndex(traverse(0, 0));
}

void
NA_Symbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  fastComputeTrueSort(subject, context);
}

void
NA_Symbol::stackArguments(DagNode* /* subject */,
			  Vector<RedexPosition>& /* stack */,
			  int /* parentIndex */)
{
}
