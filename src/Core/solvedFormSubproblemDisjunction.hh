/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2007 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//      Class for disjunctions of subproblems.
//
#ifndef _solvedFormSubproblemDisjunction_hh_
#define _solvedFormSubproblemDisjunction_hh_
#include "subproblem.hh"
#include "simpleRootContainer.hh"

class SolvedFormSubproblemDisjunction : public Subproblem, private SimpleRootContainer
{
public:
  SolvedFormSubproblemDisjunction(int nrBindings);
  ~SolvedFormSubproblemDisjunction();

  void addOption(LocalBinding* difference,
		 Subproblem* subproblem,
		 ExtensionInfo* extensionInfo = 0);
  bool unificationSolve(bool findFirst, UnificationContext& solution);

private:
  struct Option
    {
      LocalBinding* difference;
      Subproblem* subproblem;
      ExtensionInfo* extensionInfo;
    };
  
  void markReachableNodes();

  ExtensionInfo* realExtensionInfo;
  Vector<Option> options;
  int selectedOption;

  Substitution savedSubstitution;
  Subproblem* assertionSubproblem;
};

#endif
