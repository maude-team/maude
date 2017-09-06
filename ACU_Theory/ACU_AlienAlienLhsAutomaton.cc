//
//      Implementation for class ACU_AlienAlienLhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "indent.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_Theory.hh"

//      interface class definitions
#include "associativeSymbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "subproblem.hh"

//      core class definitions
#include "variableInfo.hh"
#include "substitution.hh"

//      variable class definitions
#include "variableSymbol.hh"
#include "variableTerm.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_ExtensionInfo.hh"
#include "ACU_AlienAlienLhsAutomaton.hh"

ACU_AlienAlienLhsAutomaton::ACU_AlienAlienLhsAutomaton(ACU_Symbol* topSymbol,
						       Symbol* firstSymbol,
						       LhsAutomaton* firstAutomaton,
						       Symbol* secondSymbol,
						       LhsAutomaton* secondAutomaton,
						       int nrVariables)
  : topSymbol(topSymbol),
    firstSymbol(firstSymbol),
    firstAutomaton(firstAutomaton),
    secondSymbol(secondSymbol),
    secondAutomaton(secondAutomaton),
    local(nrVariables),
    local2(nrVariables)
{
}

ACU_AlienAlienLhsAutomaton::~ACU_AlienAlienLhsAutomaton()
{
  delete firstAutomaton;
  delete secondAutomaton;
}

bool
ACU_AlienAlienLhsAutomaton::match(DagNode* subject,
				  Substitution& solution,
				  Subproblem*& returnedSubproblem,
				  ExtensionInfo* extensionInfo)
{
  if (subject->symbol() != topSymbol)
    return false;
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  int nrArgs = s->argArray.length();
  ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
  bool totalIsTwo = false;
  if (nrArgs <= 2)
    {
      int total = s->argArray[0].multiplicity;
      if (nrArgs == 2)
	total += s->argArray[1].multiplicity;
      totalIsTwo = (total == 2);
    }
  if (!totalIsTwo && e == 0)
    return false;

  int i = s->findFirstOccurrence(firstSymbol);
  if (i >= nrArgs)
    return false;
  int j = s->findFirstOccurrence(secondSymbol);
  if (j >= nrArgs)
    return false;
  LhsAutomaton* a = firstAutomaton;
  DagNode* d = s->argArray[i].dagNode;
  for(;;)
    {
      local.copy(solution);
      if (a->match(d, local, returnedSubproblem))
	{
	  if (returnedSubproblem == 0)
	    {
	      a = secondAutomaton;
	      d = s->argArray[j].dagNode;
	      for(;;)
		{
		  if (j != i || s->argArray[i].multiplicity > 1)
		    {
		      local2.copy(local);
		      if (a->match(d, local2, returnedSubproblem))
			{
			  if (returnedSubproblem == 0)
			    {
			      solution.copy(local2);
			      if (e != 0)
				{
				  e->setValidAfterMatch(true);
				  if (totalIsTwo)
				    e->setMatchedWhole(true);
				  else
				    {
				      e->setMatchedWhole(false);
				      e->reset();
				      for (int k = 0; k < nrArgs; k++)
					{
					  int m = s->argArray[k].multiplicity;
					  if (k == i)
					    --m;
					  if (k == j)
					    --m;
					  e->setUnmatched(k, m);
					}
				    }
				}
			      return true;
			    }
			  goto undecided;
			}
		    }
		  ++j;
		  if (j >= nrArgs)
		    return false;
		  d = s->argArray[j].dagNode;
		  if (d->symbol() != secondSymbol)
		    return false;
		}
	    }
	  break;
	}
      ++i;
      if (i >= nrArgs)
	return false;
      d = s->argArray[i].dagNode;
      if (d->symbol() != firstSymbol)
	return false;
    }
undecided:
  delete returnedSubproblem;
  return fullMatch(subject, solution, returnedSubproblem, extensionInfo);
}

#ifdef DUMP
void
ACU_AlienAlienLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{ACU_AlienAlienLhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "topSymbol = \"" << topSymbol;
  s << Indent(indentLevel) << "firstSymbol = \"" << firstSymbol <<
    "\"\tfirstAutomaton =\n";
  firstAutomaton->dump(s, variableInfo, indentLevel);
  s << Indent(indentLevel) << "secondSymbol = \"" << secondSymbol <<
    "\"\tsecondAutomaton =\n";
  secondAutomaton->dump(s, variableInfo, indentLevel);
  HeuristicLhsAutomaton::dump(s, variableInfo, indentLevel);
  s << Indent(indentLevel - 1) << "End{ACU_AlienAlienLhsAutomaton}\n";
}
#endif
