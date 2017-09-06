//
//      Class for structs shared between FreeLhsAutomaton and FreeRemainder.
//
#ifndef _freeLhsStructs_hh_
#define _freeLhsStructs_hh_

class FreeLhsStructs
{
protected:
  struct FreeVariable
    {
      int position;
      int argIndex;
      int varIndex;
      Sort* sort;
    };
 
  struct BoundVariable
    {
      int position;
      int argIndex;
      int varIndex;
    };
 
  struct GroundAlien
    {
      int position;
      int argIndex;
      Term* alien;
    };
 
  struct NonGroundAlien
    {
      int position;
      int argIndex;
      LhsAutomaton* automaton;
    };
};

#endif

