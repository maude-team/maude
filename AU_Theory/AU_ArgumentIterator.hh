//
//  Class for argument iterator for AU terms.
//
#ifndef _AU_ArgumentIterator_hh_
#define _AU_ArgumentIterator_hh_
#include "rawArgumentIterator.hh"
#include "AU_Term.hh"

class AU_ArgumentIterator : public RawArgumentIterator
{
public:
  AU_ArgumentIterator(const Vector<AU_Term::Tuple>& arguments);

  bool valid() const;
  Term* argument() const;
  void next();

private:
  const Vector<AU_Term::Tuple>& argArray;
  int position;
};

inline
AU_ArgumentIterator::AU_ArgumentIterator(const Vector<AU_Term::Tuple>& arguments)
  : argArray(arguments)
{
  position = 0;
}

#endif
