//
//      Class for a set of 32 flags.
//
#ifndef _flagSet_hh_
#define _flagSet_hh_

class FlagSet
{
public:
  FlagSet(int initFlags = 0);

  bool getFlag(int flag) const;
  bool oneOrMoreSet(int activeFlags) const;
  bool allSet(int activeFlags) const;

  void clearFlags(int activeFlags);
  void setFlags(int activeFlags);

private:
  int flags;
};

inline
FlagSet::FlagSet(int initFlags)
{
  flags = initFlags;
}

inline bool
FlagSet::getFlag(int flag) const
{
  return flags & flag;
}

inline bool
FlagSet::oneOrMoreSet(int activeFlags) const
{
  return flags & activeFlags;
}

inline bool
FlagSet::allSet(int activeFlags) const
{
  return (flags & activeFlags) == activeFlags;
}

inline void
FlagSet::clearFlags(int activeFlags)
{
  flags &= ~activeFlags;
}

inline void
FlagSet::setFlags(int activeFlags)
{
  flags |= activeFlags;
}

#endif
