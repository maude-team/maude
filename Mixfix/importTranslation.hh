//
//	Class to translate symbols from imported module to importing module.
//
#ifndef _importTranslation_hh_
#define _importTranslation_hh_
#include "symbolMap.hh"
#include "pointerMap.hh"

class ImportTranslation : public SymbolMap
{
  NO_COPYING(ImportTranslation);

public:
  ImportTranslation(ImportModule* importer);
  Symbol* translate(Symbol* symbol);
  Sort* translate(const Sort* sort);
  ConnectedComponent* translate(const ConnectedComponent* component);

private:
  ImportModule* const importer;
  PointerMap directMap;
};

inline ConnectedComponent*
ImportTranslation::translate(const ConnectedComponent* component)
{
  return translate(component->sort(1))->component();
}

#endif
