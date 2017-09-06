//
//      Class for operator level strategies.
//
#ifndef _strategy_hh_
#define _strategy_hh_
#include "natSet.hh"

class Strategy
{
public:
  Strategy();

  void setStrategy(const Vector<int>& userStrategy, int nrArgs, bool memoFlag);
  virtual void setFrozen(const NatSet& frozen);
  const Vector<int>& getStrategy() const;
  const NatSet& getFrozen() const;
  bool hasFrozenArguments() const;
  bool standardStrategy() const;
  bool unevaluatedArguments() const;
  bool eagerArgument(int argNr) const;
  bool evaluatedArgument(int argNr) const;

protected:
  static const Vector<int> standard;

private:
  Bool stdStrategy;
  Bool unevalArgs;
  Vector<int> strategy;
  NatSet eager;
  NatSet evaluated;
  NatSet frozen;
};

inline const NatSet&
Strategy::getFrozen() const
{
  return frozen;
}

inline const Vector<int>&
Strategy::getStrategy() const
{
  return strategy;
}

inline bool
Strategy::standardStrategy() const
{
  return stdStrategy;
}

inline bool
Strategy::unevaluatedArguments() const
{
  return unevalArgs;
}

inline bool
Strategy::eagerArgument(int argNr) const
{
  return stdStrategy || eager.contains(argNr);
}

inline bool
Strategy::evaluatedArgument(int argNr) const
{
  return stdStrategy || evaluated.contains(argNr);
}

#endif
