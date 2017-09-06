//
//	Class for keeping track of metadata attached to ModuleItems.
//
#ifndef _metadataStore_hh_
#define _metadataStore_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <map>

class MetadataStore
{
public:
  enum ItemType
  {
    MEMB_AX = 0x10000000,
    EQUATION = 0x20000000,
    RULE = 0x30000000
  };

  void insertMetadata(ItemType itemType, ModuleItem* item, int metadata);
  int getMetadata(ItemType itemType, const ModuleItem* item) const;

private:
  typedef map<int, int> MetadataMap;
  MetadataMap metadataMap;
};

#endif
