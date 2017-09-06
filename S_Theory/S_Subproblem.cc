//
//      Implementation for class S_Subproblem.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "S_Theory.hh"

//      interface class definitions
//#include "dagNode.hh"
//#include "subproblem.hh"

//      core class definitions
#include "variableInfo.hh"
#include "substitution.hh"
#include "rewritingContext.hh"
#include "localBinding.hh"

//	S theory class definitions
#include "S_Symbol.hh"
#include "S_DagNode.hh"
#include "S_ExtensionInfo.hh"
#include "S_Subproblem.hh"

S_Subproblem::S_Subproblem(S_DagNode* subject,
			   const mpz_class& leftOver,
			   int varIndex,
			   Sort* varSort,
			   S_ExtensionInfo* extensionInfo)
  : subject(subject),
    leftOver(leftOver),
    varIndex(varIndex),
    varSort(varSort),
    extensionInfo(extensionInfo)
{
  Assert(leftOver > 0, cerr << "only makes sense with leftOver > 0");
  Assert(extensionInfo != 0, cerr << "only makes sense with extensionInfo");
}

bool
S_Subproblem::solve(bool findFirst, RewritingContext& solution)
{
  if (findFirst)
    {
      S_DagNode* d = new S_DagNode(subject->symbol(), leftOver, subject->getArgument());
      solution.bind(varIndex, d);  // to protect new dagnode
      if (d->checkSort(varSort, solution))
	{
	  extensionInfo->setMatchedWhole(true);
	  extensionInfo->setUnmatched(0);
	  return true;
	}
    }
  for (;;)
    {
      const mpz_class& unmatched = extensionInfo->getUnmatched();
      int result  = cmp(leftOver, unmatched);
      Assert(result >= 0, cerr << "unmatched > diff");
      if (result == 0)
	break;  // fail
      
      mpz_class newUnmatched = unmatched + 1;
      extensionInfo->setUnmatched(newUnmatched);

      mpz_class t = leftOver - newUnmatched;
      DagNode* arg = subject->getArgument();
      DagNode* d = (t == 0) ? arg : (new S_DagNode(subject->symbol(), t, arg));
      solution.bind(varIndex, d);  // to protect potentially new dagnode

      if (d->checkSort(varSort, solution))
	{
	  extensionInfo->setMatchedWhole(false);
	  return true;
	}
    }
  return false;
}

#ifdef DUMP
void
S_Subproblem::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{S_Subproblem}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "subject = " << subject << '\n';
  s << Indent(indentLevel) << "leftOver = " << leftOver << '\n';
  s << Indent(indentLevel) << "varIndex = " << varIndex <<
    " \"" << variableInfo.index2Variable(varIndex) << "\"\n";
  s << Indent(indentLevel) << "varSort = " << varSort << '\n';
  s << Indent(indentLevel) << "extensionInfo = " << extensionInfo << '\n';
  s << Indent(indentLevel - 1) << "End{S_Subproblem}\n";
}
#endif
