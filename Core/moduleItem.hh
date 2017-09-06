//
//	Class for objects that are numbered within a module.
//	This provides with
//	  (1) a way of getting back to the module containing an object; and
//	  (2) a number that is useful for indexing.
//
#ifndef _moduleItem_hh_
#define _moduleItem_hh_

class ModuleItem
{
public:
  void setModuleInfo(Module* module, int indexWithinModule);
  Module* getModule() const;
  int getIndexWithinModule() const;

private:
  Module* parentModule;
  int indexWithinParent;
};

inline void
ModuleItem::setModuleInfo(Module* module, int indexWithinModule)
{
  parentModule = module;
  indexWithinParent = indexWithinModule;
}

inline Module*
ModuleItem::getModule() const
{
  return parentModule;
}

inline int
ModuleItem::getIndexWithinModule() const
{
  return indexWithinParent;
}

#endif
