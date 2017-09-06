//
//	Class for rewriting equations
//
#ifndef _equation_hh_
#define _equation_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "preEquation.hh"
#include "rhsBuilder.hh"

class Equation : public PreEquation
{
public:
  Equation(int label,
	   Term* lhs,
	   Term* rhs,
	   bool owise = false,
	   const Vector<ConditionFragment*>& condition = noCondition);
  ~Equation();

  Term* getRhs() const;
  void check();
  void preprocess();
  void compile(bool compileLhs);
  const RhsBuilder& getRhsBuilder() const;
  int fastNrVariables() const;

  bool isOwise() const;

private:
  enum Flags
  {
    OWISE = 4
  };

  int traceBeginTrial(DagNode* subject, RewritingContext& context) const;
  //
  //	To qualify for "fast" treatment an equation must:
  //	(1) be unconditional
  //
  //	In this case we set fast to PreEquation::nrVariables; otherwise
  //	we set fast to DEFAULT.
  //
  int fast;
  Term* rhs;
  RhsBuilder builder;
};

inline bool
Equation::isOwise() const
{
  return getFlag(OWISE);
}

inline int
Equation::fastNrVariables() const
{
  return fast;
}

inline Term*
Equation::getRhs() const
{
  return rhs;
}

inline const RhsBuilder&
Equation::getRhsBuilder() const
{
  return builder;
}

//
//      Output function for Equation must be defined by library user.
//
ostream& operator<<(ostream& s, const Equation* equation);

#endif
