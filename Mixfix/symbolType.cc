//
//      Implementation for class SymbolType.
//

//      utility stuff
#include "macros.hh"

//	front end class definitions
#include "symbolType.hh"

bool
SymbolType::compatible(SymbolType other) const
{
  return (info & ~CTOR) == (other.info & ~CTOR);
}

bool
SymbolType::dittoProblem() const
{
  return (info & DITTO) &&
    (getBasicType() != STANDARD ||
     (getFlags() & ~CTOR) != DITTO);
}

int
SymbolType::specialNameToBasicType(const char* name)
{
#define MACRO(HookName, SymbolFlag) \
  if (strcmp(name, #HookName) == 0) return SymbolFlag; else
#include "specialSymbolTypes.cc"
#undef MACRO
    return 0;
}
