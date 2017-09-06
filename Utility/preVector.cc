//
//      Implementation for class PreVector.
//
#include "macros.hh"
#include "preVector.hh"

void
PreVector::initAllocate(size_t atLeastBytes)
{
  atLeastBytes += TAG_SIZE + sizeof(VectorHeader);
  size_t i = MIN_SIZE + TAG_SIZE;
  while (i < atLeastBytes)
    i *= 2;
  i -= TAG_SIZE;
  VectorHeader* n = static_cast<VectorHeader*>(operator new[](i));
  n->allocatedBytes = i - sizeof(VectorHeader);
  ptr = n + 1;
}
