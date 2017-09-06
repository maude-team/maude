//
//      Implementation for class CopyRhsAutomaton.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "substitution.hh"
#include "variableInfo.hh"
#include "copyRhsAutomaton.hh"

CopyRhsAutomaton::CopyRhsAutomaton(int originalIndex, int copyIndex)
  : originalIndex(originalIndex),
    copyIndex(copyIndex)
{
}

void
CopyRhsAutomaton::remapIndices(VariableInfo& variableInfo)
{
  originalIndex = variableInfo.remapIndex(originalIndex);
  copyIndex = variableInfo.remapIndex(copyIndex);
}

DagNode*
CopyRhsAutomaton::construct(Substitution& matcher)
{
  DagNode* orig = matcher.value(originalIndex);
  //cerr << "CopyRhsAutomaton::construct " << orig << endl;
  DagNode* n = orig->copyEagerUptoReduced();
  orig->clearCopyPointers();
  matcher.bind(copyIndex, n);
  return n;
}

void
CopyRhsAutomaton::replace(DagNode* old, Substitution& matcher)
{
  DagNode* orig = matcher.value(originalIndex);
  DagNode* n = orig->copyEagerUptoReduced();
  orig->clearCopyPointers();
  n->overwriteWithClone(old);
}

#ifdef DUMP
void
CopyRhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{CopyRhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "originalIndex = " << originalIndex <<
    "\tcopyIndex = " << copyIndex << '\n';
  s << Indent(indentLevel) << "End{CopyRhsAutomaton}\n";
}
#endif
