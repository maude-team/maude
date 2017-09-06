//
//      Implementation for class ACU_BaseDagNode.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_Persistent.hh"
#include "ACU_Theory.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_ExtensionInfo.hh"

//	ACU Red-Black class definitions
#include "ACU_TreeDagNode.hh"

int
ACU_BaseDagNode::getSize() const
{
  return isTree() ?
    safeCast(const ACU_TreeDagNode*, this)->getTree().getSize() :
    safeCast(const ACU_DagNode*, this)->argArray.length();

}

ExtensionInfo*
ACU_BaseDagNode::makeExtensionInfo()
{
  return new ACU_ExtensionInfo(this);
}
