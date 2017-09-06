//
//      Class for cache of MetaModules.
//
#ifndef _metaModuleCache_hh_
#define _metaModuleCache_hh_
#include "importModule.hh"

class MetaModuleCache : public ImportModule::Parent
{
  NO_COPYING(MetaModuleCache);

public:
  MetaModuleCache(int maxSize = 4);
  ~MetaModuleCache();

  MetaModule* find(DagNode* dag);
  void insert(DagNode* dag, MetaModule* module);
  void flush();

private:
  struct Pair
  {
    void clear();

    DagRoot* dag;
    MetaModule* module;
  };

  void regretToInform(ImportModule* doomedModule);
  MetaModule* moveToFront(int chosen);

  const int maxSize;
  Vector<Pair> cache;
};

#endif
