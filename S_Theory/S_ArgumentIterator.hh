//
//	Class for argument iterator for S_Terms.
//
#ifndef _S_ArgumentIterator_hh_
#define _S_ArgumentIterator_hh_
#include "rawArgumentIterator.hh"

class S_ArgumentIterator : public RawArgumentIterator
{
public:
  S_ArgumentIterator(Term* arg);
  //
  //    Functions required by theory interface.
  //
  bool valid() const;
  Term* argument() const;
  void next();

private:
  Term* arg;
};

inline
S_ArgumentIterator::S_ArgumentIterator(Term* arg)
  : arg(arg)
{
}

#endif
