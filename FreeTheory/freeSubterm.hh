//
//	Class for subterms occurring under free skeleton.
//
#ifndef _freeSubterm_hh_
#define _freeSubterm_hh_

class FreeSubterm
{
public:
  enum Type
  {
    FREE_VARIABLE,
    BOUND_VARIABLE,
    GROUND_ALIEN,
    NON_GROUND_ALIEN
  };

  FreeSubterm() {}  // needed for Vector<FreeSubterm>
  FreeSubterm(Type type, int positionIndex);

  Type type() const;
  int positionIndex() const;

private:
  Type subtermType;
  int subtermPositionIndex;
};

inline
FreeSubterm::FreeSubterm(Type type, int positionIndex)
{
  subtermType = type;
  subtermPositionIndex = positionIndex;
}

inline FreeSubterm::Type
FreeSubterm::type() const
{
  return subtermType;
}

inline int
FreeSubterm::positionIndex() const
{
  return subtermPositionIndex;
}

#endif
