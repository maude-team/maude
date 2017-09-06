//
//      Implementation for class AU_LhsAutomaton.
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
#include "variable.hh"
#include "AU_Theory.hh"

//      interface class definitions
#include "associativeSymbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "variableSymbol.hh"
#include "variableTerm.hh"
#include "variableInfo.hh"
#include "subproblemSequence.hh"
#include "subproblemDisjunction.hh"
#include "subproblemAccumulator.hh"
#include "disjunctiveSubproblemAccumulator.hh"
#include "substitution.hh"
#include "localBinding.hh"
#include "variableAbstractionSubproblem.hh"
#include "equalitySubproblem.hh"


//	AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_LhsAutomaton.hh"
#include "AU_Subproblem.hh"
#include "AU_ExtensionInfo.hh"

#include "AU_GreedyMatcher.cc"
#include "AU_Matcher.cc"
#include "AU_CollapseMatcher.cc"
#include "AU_FullMatcher.cc"

AU_LhsAutomaton::AU_LhsAutomaton(AU_Symbol* symbol,
				 bool matchAtTop,
				 bool collapsePossible,
				 LhsAutomaton* uniqueCollapseAutomaton,
				 int nrVariables)
  : topSymbol(symbol),
    matchAtTop(matchAtTop),
    collapsePossible(collapsePossible),
    uniqueCollapseAutomaton(uniqueCollapseAutomaton),
    local(nrVariables),
    scratch(nrVariables)
{
  wholeLowerBound = 0;
  wholeUpperBound = matchAtTop ? UNBOUNDED : 0;
  flexLowerBound = 0;
  flexUpperBound = matchAtTop ? UNBOUNDED : 0;
}

AU_LhsAutomaton::~AU_LhsAutomaton()
{
  delete uniqueCollapseAutomaton;
  int nrRigid = rigidPart.length();
  for (int i = 0; i < nrRigid; i++)
    {
      Subterm& r = rigidPart[i];
      if (r.type == NON_GROUND_ALIEN)
	delete r.alienAutomaton;
    }
  int nrFlex = flexPart.length();
  for (int i = 0; i < nrFlex; i++)
    {
      Subterm& f = flexPart[i];
      if (f.type == VARIABLE)
	delete f.variable.abstracted;
      else if (f.type == NON_GROUND_ALIEN)
	delete f.alienAutomaton;
    }
}

void
AU_LhsAutomaton::updateWholeBounds(int min, int max)
{
  wholeLowerBound += min;
  wholeUpperBound = uplus(wholeUpperBound, max);
}

void
AU_LhsAutomaton::updateFlexBounds(int min, int max)
{
  flexLowerBound += min;
  flexUpperBound = uplus(flexUpperBound, max);
}

void
AU_LhsAutomaton::addRigidVariable(const VariableTerm* variable, bool leftEnd, bool idPossible)
{
  Sort* s = variable->getSort();
  int upperBound = topSymbol->sortBound(s);
  bool takeIdentity = idPossible && topSymbol->takeIdentity(s);
  updateWholeBounds(takeIdentity ? 0 : 1, upperBound);

  int nrRigid = rigidPart.length();
  rigidPart.expandBy(1);
  Subterm& r = rigidPart[nrRigid];
  r.type = VARIABLE;
  r.leftEnd = leftEnd;
  r.variable.index =  variable->getIndex();
  r.variable.sort = s;
  r.variable.upperBound = upperBound;
  r.variable.takeIdentity = takeIdentity;
  r.variable.awkward = false;
  r.variable.abstracted = 0;
}

void
AU_LhsAutomaton::addRigidGroundAlien(Term* alien, bool leftEnd)
{
  updateWholeBounds(1, 1);
  int nrRigid = rigidPart.length();
  rigidPart.expandBy(1);
  Subterm& r = rigidPart[nrRigid];
  r.type = GROUND_ALIEN;
  r.leftEnd = leftEnd;
  r.groundAlien = alien;
}

void
AU_LhsAutomaton::addRigidNonGroundAlien(LhsAutomaton* automaton, bool leftEnd)
{
  updateWholeBounds(1, 1);
  int nrRigid = rigidPart.length();
  rigidPart.expandBy(1);
  Subterm& r = rigidPart[nrRigid];
  r.type = NON_GROUND_ALIEN;
  r.leftEnd = leftEnd;
  r.alienAutomaton = automaton;
}

void
AU_LhsAutomaton::addFlexVariable(const VariableTerm* variable, int shiftFactor, bool idPossible)
{
  Sort* s = variable->getSort();
  int upperBound = topSymbol->sortBound(s);
  bool takeIdentity = idPossible && topSymbol->takeIdentity(s);
  int lowerBound = takeIdentity ? 0 : 1;
  updateWholeBounds(lowerBound, upperBound);
  updateFlexBounds(lowerBound, upperBound);

  int nrFlex = flexPart.length();
  flexPart.expandBy(1);
  Subterm& f = flexPart[nrFlex];
  f.type = VARIABLE;
  f.shiftFactor = shiftFactor;
  f.variable.index =  variable->getIndex();
  f.variable.sort = s;
  f.variable.upperBound = upperBound;
  f.variable.takeIdentity = takeIdentity;
  f.variable.awkward = matchAtTop && !idPossible && topSymbol->takeIdentity(s);
  f.variable.abstracted = 0;
}

void
AU_LhsAutomaton::addFlexAbstractionVariable(int index,
					    Sort* sort,
					    int upperBound,
					    bool takeIdentity,
					    bool awkward,
					    LhsAutomaton* abstracted)
{
  int lowerBound = takeIdentity ? 0 : 1;
  updateWholeBounds(lowerBound, upperBound);
  updateFlexBounds(lowerBound, upperBound);

  int nrFlex = flexPart.length();
  flexPart.expandBy(1);
  Subterm& f = flexPart[nrFlex];
  f.type = VARIABLE;
  f.shiftFactor = UNDEFINED;
  f.variable.index = index;
  f.variable.sort = sort;
  f.variable.upperBound = upperBound;
  f.variable.takeIdentity = takeIdentity;
  f.variable.awkward = awkward;
  f.variable.abstracted = abstracted;
}

void
AU_LhsAutomaton::addFlexGroundAlien(Term* alien, int shiftFactor)
{
  updateWholeBounds(1, 1);
  updateFlexBounds(1, 1);
  int nrFlex = flexPart.length();
  flexPart.expandBy(1);
  Subterm& f = flexPart[nrFlex];
  f.type = GROUND_ALIEN;
  f.shiftFactor = shiftFactor;
  f.groundAlien = alien;
}

void
AU_LhsAutomaton::addFlexNonGroundAlien(LhsAutomaton* automaton, int shiftFactor)
{
  updateWholeBounds(1, 1);
  updateFlexBounds(1, 1);
  int nrFlex = flexPart.length();
  flexPart.expandBy(1);
  Subterm& f = flexPart[nrFlex];
  f.type = NON_GROUND_ALIEN;
  f.shiftFactor = shiftFactor;
  f.alienAutomaton = automaton;
}

void
AU_LhsAutomaton::complete(MatchStrategy strategy)
{
  int nrFixed = 0;
  for(int i = flexPart.length() - 1; i >= 0; i--)
    {
      Subterm& f = flexPart[i];
      if (f.shiftFactor < 0)
	{
	  f.blockLength = NOT_FIXED;
	  nrFixed = 0;
	}
      else
	f.blockLength = ++nrFixed;
    }
  matchStrategy = strategy;
}

#ifdef DUMP
void
AU_LhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{AU_LhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "topSymbol = \"" << topSymbol <<
    "\"\tmatchAtTop = " << matchAtTop <<
    "\tcollapsePossible = " << collapsePossible <<
    "\tmatchStrategy = " << matchStrategy << '\n';
  if (uniqueCollapseAutomaton != 0)
    {
      s << Indent(indentLevel) << "uniqueCollapseAutomaton =\n";
      uniqueCollapseAutomaton->dump(s, variableInfo, indentLevel + 1);
    }
  s << Indent(indentLevel) << "wholeLowerBound = " << wholeLowerBound <<
    "\twholeUpperBound = " << wholeUpperBound << '\n';
  s << Indent(indentLevel) << "flexLowerBound = " << flexLowerBound <<
    "\tflexUpperBound = " << flexUpperBound << '\n';

  s << Indent(indentLevel) << "rigidPart:\n";
  ++indentLevel;
  for (int i = 0; i < rigidPart.length(); i++)
    {
      Subterm& r = rigidPart[i];
      s << Indent(indentLevel) << "type = " << r.type << "\tleftEnd = " << r.leftEnd;
      switch (r.type)
	{
	case VARIABLE:
	  {
	    s << "\tindex = " << r.variable.index <<
	      " \"" << variableInfo.index2Variable(r.variable.index) << "\"\n";
	    s << Indent(indentLevel) << "sort = " << r.variable.sort <<
	      "\tupperBound = " << r.variable.upperBound <<
	      "\ttakeIdentity = " << r.variable.takeIdentity << '\n';
	    break;
	  }
	case GROUND_ALIEN:
	  {
	    s << "\tgroundAlien = " << r.groundAlien << '\n';
	    break;
	  }
	case NON_GROUND_ALIEN:
	  {
	    s << "\talienAutomaton =\n";
	    r.alienAutomaton->dump(s, variableInfo, indentLevel + 1);
	    break;
	  }
	}
    }

  s << Indent(indentLevel - 1) << "flex part:\n";
  for (int i = 0; i < flexPart.length(); i++)
    {
      Subterm& f = flexPart[i];
      s << Indent(indentLevel) << "type = " << f.type <<
	"\tshiftFactor = " << f.shiftFactor <<
	"\tblockLength = " << f.blockLength;
      switch (f.type)
	{
	case VARIABLE:
	  {
	    s << "\tindex = " << f.variable.index;
	    if (f.variable.abstracted == 0)
	      s << " \"" << variableInfo.index2Variable(f.variable.index) << '"';
	    s << '\n' << Indent(indentLevel) << "sort = " << f.variable.sort <<
	      "\tupperBound = " << f.variable.upperBound <<
	      "\ttakeIdentity = " << bool(f.variable.takeIdentity) <<
	      "\tawkward = " << bool(f.variable.awkward) << '\n';
	    if (f.variable.abstracted != 0)
	      {
		s << Indent(indentLevel) << "abstracted = " << '\n';
		f.variable.abstracted->dump(s, variableInfo, indentLevel + 1);
	      }
	    break;
	  }
	case GROUND_ALIEN:
	  {
	    s << "\tgroundAlien = " << f.groundAlien << '\n';
	    break;
	  }
	case NON_GROUND_ALIEN:
	  {
	    s << "\talienAutomaton =\n";
	    f.alienAutomaton->dump(s, variableInfo, indentLevel + 1);
	    break;
	  }
	}
    }

  s << Indent(indentLevel - 2) << "End{AU_LhsAutomaton}\n";
}

ostream& operator<<(ostream& s, AU_LhsAutomaton::MatchStrategy strategy)
{
  static const char* const names[] = {"GROUND_OUT",
                                      "LONE_VARIABLE",
				      "FAST_LONE_VARIABLE",
                                      "GREEDY",
                                      "FULL"};
  s << names[strategy];
  return s;
}

ostream& operator<<(ostream& s, AU_LhsAutomaton::SubtermType type)
{
  static const char* const names[] = {"VARIABLE",
                                      "GROUND_ALIEN",
                                      "NON_GROUND_ALIEN"};
  s << names[type];
  return s;
}
#endif
