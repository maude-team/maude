//
//  Class for argument iterators in the free theory
//
#ifndef _freeArgumentIterator_hh_
#define _freeArgumentIteraror_hh_
#ifdef __GNUG__
#pragma interface
#endif

class FreeArgumentIterator : public RawArgumentIterator 
{
public:
  FreeArgumentIterator(const Vector<Term*>* args);

  bool valid() const;
  Term* argument() const;
  void next();

private:
  const Vector<Term*>* argArray;
  int position;
};

inline
FreeArgumentIterator::FreeArgumentIterator(const Vector<Term*>* args)
{
  argArray = args;
  position = 0;
}

#endif
