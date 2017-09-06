//
//	Base class for state information used in solving condition fragments.
//
//	The only thing we need to be able to do to objects of derived classes
//	through this interface is delete them if we don't want further solutions.
//
#ifndef _conditionState_hh_
#define _conditionState_hh_
#ifdef __GNUG__
#pragma interface
#endif

class ConditionState
{
public:
  virtual ~ConditionState() {};
};

#endif
