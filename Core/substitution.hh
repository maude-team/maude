//
//	Class for substitutions
//
#ifndef _substitution_hh_
#define _substitution_hh_
#ifdef __GNUG__
#pragma interface
#endif

class Substitution
{
public:
  Substitution();
  Substitution(int size);  // for local substitutions in lhs automata

  static void notify(int size);

  void clear(int size);
  void finished();
  DagNode* value(int index) const;
  void bind(int index, DagNode* value);
  void copy(const Substitution& original);
  LocalBinding* operator-(const Substitution& original) const;

  int nrFragileBindings();

private:
  Substitution(const Substitution& original);
  static int allocateSize;

  Vector<DagNode*> values;
  int copySize;
};

inline
Substitution::Substitution() : values(allocateSize)
{
  copySize = 0;
}

inline
Substitution::Substitution(int size) : values(size)
{
  copySize = size;
}

inline void
Substitution::notify(int size)
{
  if (size > allocateSize)
    {
      DebugAdvisory("allocateSize increased from " <<
		    allocateSize << " to " << size);
      allocateSize = size;
    }
}

inline void
Substitution::clear(int size)
{
  Assert(size >= 0, cerr << "-ve size");
  Assert(size <= allocateSize, cerr << "size > notified");
  //
  //	We alway clear at least 1 value in order to get a faster loop
  //	since the case size = 0 occurs very infrequently, and clearing
  //	1 value in this case does no harm.
  //
  Vector<DagNode*>::iterator i = values.begin();
  Vector<DagNode*>::iterator e = i + size;
  do
    *i = 0;
  while (++i < e);  // i > e possible if size = 0
  copySize = size;
}

inline DagNode*
Substitution::value(int index) const
{
  Assert(index >= 0, cerr << "-ve index");
  Assert(index < allocateSize, cerr << "index too big");
  return values[index];
}

inline void
Substitution::bind(int index, DagNode* value)
{
  Assert(index >= 0, cerr << "-ve index");
  Assert(index < allocateSize, cerr << "index too big");
  values[index] = value;
}

inline int
Substitution::nrFragileBindings()
{
  return copySize;
}

inline void
Substitution::finished()
{
  copySize = 0;
}

inline void
Substitution::copy(const Substitution& original)
{
  Assert(copySize == original.copySize, cerr << "size mismatch (" << copySize <<
	 " vs " << original.copySize << ')');
  int size = copySize;
  if (size > 0)
    {
      Vector<DagNode*>::iterator dest = values.begin();
      Vector<DagNode*>::const_iterator source = original.values.begin();
      do
	{
	  *dest = *source;
	  ++dest;
	  ++source;
	}
      while (--size > 0);
    }
}

#endif
