//
//      Class for disjunctions of subproblems.
//
#ifndef _subproblemDisjunction_hh_
#define _subproblemDisjunction_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "subproblem.hh"

class SubproblemDisjunction : public Subproblem
{
public:
  SubproblemDisjunction();
  ~SubproblemDisjunction();

  void addOption(LocalBinding* difference,
		 Subproblem* subproblem,
		 ExtensionInfo* extensionInfo);
  bool solve(bool findFirst, RewritingContext& solution);

private:
  struct Option
    {
      LocalBinding* difference;
      Subproblem* subproblem;
      ExtensionInfo* extensionInfo;
    };
  
  ExtensionInfo* realExtensionInfo;
  Vector<Option> options;
  int selectedOption;
};

#endif
