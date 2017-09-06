//
//      Class for flag indicating that an object is in a bad (unusable) state.
//
//	Badness is permanent. Remaining flags are available to derived classes.
//
#ifndef _badFlag_hh_
#define _badFlag_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "flagSet.hh"

class BadFlag : public FlagSet
{
public:
  bool isBad() const;
  void markAsBad();

private:
  enum
  {
    BAD = 1
  };
};

inline bool
BadFlag::isBad() const
{
  return getFlag(BAD);
}

inline void
BadFlag::markAsBad()
{
  setFlags(BAD);
}

#endif
