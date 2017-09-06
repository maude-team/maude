//
//	Class for accumulating disjunctions of subproblems
//
#ifndef _disjunctiveSubproblemAccumulator_hh_
#define _disjunctiveSubproblemAccumulator_hh_
#ifdef __GNUG__
#pragma interface
#endif

class DisjunctiveSubproblemAccumulator
{
public:
  DisjunctiveSubproblemAccumulator(Substitution& global);
  ~DisjunctiveSubproblemAccumulator();

  bool empty() const;
  void addOption(Substitution& local,
		 Subproblem* subproblem,
		 ExtensionInfo* extensionInfo);
  bool extract(Substitution& solution,
	       Subproblem*&returnedSubproblem,
	       ExtensionInfo* extensionInfo);

private:
  bool first;
  Substitution& global;
  LocalBinding* firstDifference;
  Subproblem* firstSubproblem;
  ExtensionInfo* firstExtensionInfo;
  SubproblemDisjunction* disjunction;
};

inline
DisjunctiveSubproblemAccumulator::DisjunctiveSubproblemAccumulator(Substitution& global)
  : global(global)
{
  first = true;
}

inline bool
DisjunctiveSubproblemAccumulator::empty() const
{
  return first;
}

#endif
