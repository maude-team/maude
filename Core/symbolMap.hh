//
//      Abstract base class for maps from symbols to symbols.
//
#ifndef _symbolMap_hh_
#define _symbolMap_hh_

class SymbolMap
{
public:
  virtual Symbol* translate(Symbol* symbol) = 0;
};

#endif
