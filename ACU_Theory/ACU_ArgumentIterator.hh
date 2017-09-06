//
//	Class for argument iterator for ACU terms
//
#ifndef _ACU_ArgumentIterator_hh_
#define _ACU_ArgumentIterator_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rawArgumentIterator.hh"

class ACU_ArgumentIterator : public RawArgumentIterator
{
public:
  ACU_ArgumentIterator(const Vector<ACU_Term::Pair>* arguments);

  bool valid() const;
  Term* argument() const;
  void next();

private:
  const Vector<ACU_Term::Pair>* argArray;
  int position;
  int multiplicityRemaining;
};

inline
ACU_ArgumentIterator::ACU_ArgumentIterator(const Vector<ACU_Term::Pair>* arguments)
{
  argArray = arguments;
  position = 0;
  multiplicityRemaining = (*arguments)[0].multiplicity;
}

#endif
