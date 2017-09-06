//
//      Implementation for class MetaModule.
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
#include "higher.hh"
#include "mixfix.hh"

//	front end class definitions
#include "metaModule.hh"


MetaModule::MetaModule(int name, ModuleType moduleType, Parent* parent)
  : ImportModule(name, moduleType, parent)
{
}

void
MetaModule::addComplexSymbol(int type, int index, DagNode* fixUpInfo)
{
  int nrComplexSymbols = complexSymbols.length();
  complexSymbols.expandBy(1);
  ComplexSymbol& cs = complexSymbols[nrComplexSymbols];
  cs.type = type;
  cs.index =  index;
  cs.fixUpInfo = fixUpInfo;
}

void
MetaModule::addComplexSymbol(int type,
			     int index,
			     DagNode* fixUpInfo,
			     const Vector<Sort*>& domainAndRange)
{
  int nrComplexSymbols = complexSymbols.length();
  complexSymbols.expandBy(1);
  ComplexSymbol& cs = complexSymbols[nrComplexSymbols];
  cs.type = type;
  cs.index = index;
  cs.fixUpInfo = fixUpInfo;
  cs.domainAndRange = domainAndRange;  // deep copy
}

bool
MetaModule::removeComplexSymbol(int& type,
				int& index,
				DagNode*& fixUpInfo,
				Vector<Sort*>& domainAndRange)
{
  int nrComplexSymbols = complexSymbols.length();
  if (nrComplexSymbols == 0)
    return false;
  --nrComplexSymbols;
  ComplexSymbol& cs = complexSymbols[nrComplexSymbols];
  type = cs.type;
  index = cs.index;
  fixUpInfo = cs.fixUpInfo;
  domainAndRange = cs.domainAndRange;  // deep copy
  complexSymbols.contractTo(nrComplexSymbols);
  return true;
}
