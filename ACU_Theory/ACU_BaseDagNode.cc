//
//      Implementation for class ACU_BaseDagNode.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_Theory.hh"
#include "ACU_RedBlack.hh"

//      interface class definitions
//#include "term.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
//#include "ACU_DagArgumentIterator.hh"
#include "ACU_ExtensionInfo.hh"
//#include "ACU_Subproblem.hh"

//	ACU Red-Black class definitions
#include "ACU_TreeDagNode.hh"
#include "ACU_RedBlackNode.hh"
//#include "ACU_FastIter.hh"

int
ACU_BaseDagNode::getSize() const
{
  return isTree() ?
    safeCast(const ACU_TreeDagNode*, this)->getRoot()->getSize() :
    safeCast(const ACU_DagNode*, this)->argArray.length();

}

ExtensionInfo*
ACU_BaseDagNode::makeExtensionInfo()
{
  return new ACU_ExtensionInfo(this);
}
