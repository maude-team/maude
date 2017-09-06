//
//	Class for occurrence of subterm in/under free skeleton.
//
#ifndef _freeOccurrence_hh_
#define _freeOccurrence_hh_

class FreeOccurrence
{
public:
  FreeOccurrence() {}  // needed for Vector<FreeOccurrence>
  FreeOccurrence(int position, int argIndex, Term* term);

  int position() const;
  int argIndex() const;
  Term* term() const;

private:
  int pos;
  int arg;
  Term* trm;
};

inline
FreeOccurrence::FreeOccurrence(int position, int argIndex, Term* term)
{
  pos = position;
  arg = argIndex;
  trm = term;
}

inline int
FreeOccurrence::position() const
{
  return pos;
}

inline int
FreeOccurrence::argIndex() const
{
  return arg;
}

inline Term*
FreeOccurrence::term() const
{
  return trm;
}

#endif
