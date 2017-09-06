//
//      Implementation for class ImportTranslation.
//
#ifdef __GNUG__
#pragma implementation
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "mixfix.hh"

//      interface class definitions
#include "term.hh"

//	variable class definitions
#include "variableSymbol.hh"

//	built in class definitions
#include "sortTestSymbol.hh"

//	front end class definitions
#include "importModule.hh"
#include "importTranslation.hh"

ImportTranslation::ImportTranslation(ImportModule* importer)
  : importer(importer)
{
}

Sort*
ImportTranslation::translate(const Sort* sort)
{
  if (sort->index() == Sort::ERROR_SORT)
    return translate(sort->component())->sort(Sort::ERROR_SORT);
  Sort* s = importer->findSort(sort->id());
  Assert(s != 0, cerr << "no translation for sort " << sort <<
	 " in " << importer);
  return s;
}

Symbol*
ImportTranslation::translate(Symbol* symbol)
{
  Symbol* s = static_cast<Symbol*>(directMap.getMap(symbol));
  if (s != 0)
    return s;
  Symbol* importerVersion = 0;
  switch (static_cast<MixfixModule*>(symbol->getModule())->getSymbolType(symbol).getBasicType())
    {
    case SymbolType::VARIABLE:
      {
	Sort* sort = translate(safeCast(VariableSymbol*, symbol)->getSort());
	importerVersion = importer->instantiateVariable(sort);
	break;
      }
    case SymbolType::SORT_TEST:
      {
	SortTestSymbol* t = safeCast(SortTestSymbol*, symbol);
	importerVersion = importer->instantiateSortTest(translate(t->sort()), t->eager());
	break;
      }
    default:
      {
	int nrArgs = symbol->arity();
	static Vector<ConnectedComponent*> domainComponents;
	domainComponents.resize(nrArgs);
	for (int i = 0; i < nrArgs; i++)
	  domainComponents[i] = translate(symbol->domainComponent(i));
	ConnectedComponent* rangeComponent = translate(symbol->rangeComponent());
	importerVersion = importer->findSymbol(symbol->id(), domainComponents, rangeComponent);
	break;
      }
    }
  Assert(importerVersion != 0, cerr << "no translation for " << symbol <<
	 " in " << importer);
  directMap.setMap(symbol, importerVersion);
  return importerVersion;
}
