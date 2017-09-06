//
//      Class for modules created on the fly at the meta level.
//
#ifndef _metaModule_hh_
#define _metaModule_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "importModule.hh"
#include "metaOpCache.hh"


class MetaModule : public ImportModule, public MetaOpCache
{
  NO_COPYING(MetaModule);

public:
  MetaModule(int name, ModuleType moduleType, Parent* parent);

  void addComplexSymbol(int type, int index, DagNode* fixUpInfo);
  void addComplexSymbol(int type,
			int index,
			DagNode* fixUpInfo,
			const Vector<Sort*>& domainAndRange);
  bool removeComplexSymbol(int& type,
			   int& index,
			   DagNode*& fixUpInfo,
			   Vector<Sort*>& domainAndRange);

private:
  struct ComplexSymbol
  {
    int type;
    int index;
    DagNode* fixUpInfo;
    Vector<Sort*> domainAndRange;
  };

  Vector<ComplexSymbol> complexSymbols;
};

#endif
