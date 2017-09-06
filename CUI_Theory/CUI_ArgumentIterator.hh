//
//	Class for argument iterator for CUI terms.
//
#ifndef _CUI_ArgumentIterator_hh_
#define _CUI_ArgumentIterator_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rawArgumentIterator.hh"

class CUI_ArgumentIterator : public RawArgumentIterator
{
public:
  CUI_ArgumentIterator(const Vector<Term*>& arguments);

  bool valid() const;
  Term* argument() const;
  void next();

private:
  const Vector<Term*>& argArray;
  int position;
};

inline
CUI_ArgumentIterator::CUI_ArgumentIterator(const Vector<Term*>& arguments)
  : argArray(arguments)
{
  position = 0;
}

#endif
