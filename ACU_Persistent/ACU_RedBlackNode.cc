//
//      Implementation for class ACU_RedBlackNode.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//	ACU red-black class definitions
#include "ACU_RedBlackNode.hh"
#include "ACU_Stack.hh"

//	our parts
#include "ACU_Insert.cc"
#include "ACU_Delete.cc"
#include "ACU_Rebalance.cc"
#include "ACU_Copy.cc"
#include "ACU_Find.cc"

ACU_RedBlackNode*
ACU_RedBlackNode::blackNode(ACU_RedBlackNode* key,
			    ACU_RedBlackNode* left,
			    ACU_RedBlackNode* right)
{
  return new ACU_RedBlackNode(key->getDagNode(),
			      key->getMultiplicity(),
			      left,
			      right);
}

#ifdef CHECK_TREE

bool
ACU_RedBlackNode::checkRedBlackProperty()
{
  int height;
  if (!checkRedBlackProperty(height) || isRed())
    {
      cerr << "Red-Black Violation\n";
      dump(cerr, 0);
      return false;
    }
  return true;
}

bool
ACU_RedBlackNode::checkRedBlackProperty(int& height)
{
  bool ok = true;
  height = 0;
  if (ACU_RedBlackNode* l = getLeft())
    {
      ok = l->checkRedBlackProperty(height);
      if (getDagNode()->compare(l->getDagNode()) <= 0)
	{
	  cerr << "order violation " << getDagNode() <<
	    " <= " << l->getDagNode() << endl;
	  ok = false;
	}
    }
  int rHeight = 0;
  if (ACU_RedBlackNode* r = getRight())
    {
      ok = r->checkRedBlackProperty(rHeight) && ok;
      if (getDagNode()->compare(r->getDagNode()) >= 0)
	{
	  cerr << "order violation " << getDagNode() <<
	    " >= " << r->getDagNode() << endl;
	  ok = false;
	}
    }
  if (height != rHeight)
    {
      cerr << "black height violation " << height <<
	" != " << rHeight << endl;
      ok = false;
    }
  if (!isRed())
    ++height;
  return ok;
}

#endif

void
ACU_RedBlackNode::dump(ostream& s, int indent)
{
  s << Indent(indent) <<
    "address = " << this <<
    "\tdagNode = " << getDagNode() <<
    "\tmultiplicity = " << getMultiplicity() <<
    "\tcolor = " << (isRed() ? "red" : "black") << endl;

  s << Indent(indent) << "left = ";
  if (ACU_RedBlackNode* l = getLeft())
    {
      s << '\n';
      l->dump(s, indent + 1);
    }
  else
    s << "null\n";

  s << Indent(indent) << "right = ";
  if (ACU_RedBlackNode* r = getRight())
    {
      s << '\n';
      r->dump(s, indent + 1);
    }
  else
    s << "null\n";
}
