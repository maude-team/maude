//
//	Wrapper around raw argument iterators to provide cleaner interface
//
#ifndef _argumentIterator_hh_
#define _argumentIterator_hh_
#include "rawArgumentIterator.hh"

class ArgumentIterator
{
public:
  ArgumentIterator(Term& t);
  ~ArgumentIterator();
  bool valid() const;
  Term* argument() const;
  void next();

private:
  RawArgumentIterator* argumentIterator;
};

inline
ArgumentIterator::ArgumentIterator(Term& t)
{
  argumentIterator = t.arguments();
}

inline
ArgumentIterator::~ArgumentIterator()
{
  delete argumentIterator;
}

inline bool
ArgumentIterator::valid() const
{
  return (argumentIterator != 0) && argumentIterator->valid();
}

inline Term*
ArgumentIterator::argument() const
{
  return argumentIterator->argument();
}

inline void
ArgumentIterator::next()
{
  argumentIterator->next();
}

#endif
