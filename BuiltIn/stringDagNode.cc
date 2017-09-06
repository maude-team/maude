//
//      Implementation for class StringDagNode.
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
#include "NA_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      built in class definitions
#include "stringSymbol.hh"
#include "stringDagNode.hh"

StringDagNode::StringDagNode(StringSymbol* symbol, const crope& value)
  : NA_DagNode(symbol),
    value(value)
{
  Assert(sizeof(crope) <= DagNode::nrWords * sizeof(DagNode::Word),
	 cerr << "crope too big for internal storage");
  setCallDtor();  // need our dtor called when garbage collected to destruct crope
}

size_t
StringDagNode::getHashValue()
{
  int hashValue = 0;
  for (crope::const_iterator i(value.begin()); i != value.end(); i++)
    hashValue = (hashValue << 1) + *i;
  return hash(symbol()->getHashValue(), hashValue);
}

int
StringDagNode::compareArguments(const DagNode* other) const
{
  return value.compare(static_cast<const StringDagNode*>(other)->value);
}
 
void
StringDagNode::overwriteWithClone(DagNode* old)
{
  (void) new(old) StringDagNode(static_cast<StringSymbol*>(symbol()), value);
}

DagNode*
StringDagNode::makeClone()
{
  return new StringDagNode(static_cast<StringSymbol*>(symbol()), value);
}
