//
//	Abstract base class for raw argument iterators.
//
#ifndef _rawArgumentIterator_hh_
#define _rawArgumentIterator_hh_

class RawArgumentIterator
{
public:
  virtual ~RawArgumentIterator() {}
  virtual bool valid() const = 0;
  virtual Term* argument() const = 0;
  virtual void next() = 0;
};

#endif
