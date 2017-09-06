//
//      Implementation for class MetadataStore.
//

//      utility stuff
#include "macros.hh"

//      forward declarations
//#include "interface.hh"
#include "core.hh"

//      core class definitions
#include "moduleItem.hh"

//	front end class definitions
#include "metadataStore.hh"

void
MetadataStore::insertMetadata(ItemType itemType, ModuleItem* item, int metadata)
{
  if (metadata != NONE)
    metadataMap[itemType | item->getIndexWithinModule()] = metadata;
}

int
MetadataStore::getMetadata(ItemType itemType, const ModuleItem* item) const
{
  MetadataMap::const_iterator i = metadataMap.find(itemType | item->getIndexWithinModule());
  if (i == metadataMap.end())
    return NONE;
  return (*i).second;
}
