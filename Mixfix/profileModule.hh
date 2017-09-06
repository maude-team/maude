//
//      Class for modules with profiling information.
//
#ifndef _profileModule_hh_
#define _profileModule_hh_
#include "module.hh"

class ProfileModule : public Module
{
  NO_COPYING(ProfileModule);

public:
  ProfileModule(int name);

  void clearProfile();
  void profileMbRewrite(DagNode* redex, const SortConstraint* mb);
  void profileEqRewrite(DagNode* redex, const Equation* eq, int type);
  void profileRlRewrite(DagNode* redex, const Rule* rl);
  void profileMbConditionStart(const SortConstraint* mb);
  void profileEqConditionStart(const Equation* eq);
  void profileRlConditionStart(const Rule* rl);
  void profileFragment(const PreEquation* preEquation, int fragmentIndex, bool success);
  void showProfile(ostream& s) const;

private:
  struct SymbolProfile
  {
    SymbolProfile();
      
    Int64 nrBuiltinMbRewrites;
    Int64 nrBuiltinEqRewrites;
    Int64 nrBuiltinRlRewrites;
    Int64 nrMemoRewrites;
  };

  struct FragmentProfile
  {
    FragmentProfile();

    Int64 nrSuccesses;
    Int64 nrFailures;
  };

  struct StatementProfile
  {
    StatementProfile();
    void updateFragmentInfo(int index, bool success);

    Int64 nrRewrites;
    //
    //	Only maintained for conditional statements.
    //
    Int64 nrConditionStarts;
    Vector<FragmentProfile> fragmentInfo;
  };

  static void showSymbol(ostream& s, Symbol* op);
  static void showFragmentProfile(ostream& s,
				  const Vector<FragmentProfile>& fragmentInfo,
				  Int64 nrFirsts);

  Vector<SymbolProfile> symbolInfo;
  Vector<StatementProfile> mbInfo;
  Vector<StatementProfile> eqInfo;
  Vector<StatementProfile> rlInfo;
};

#endif
