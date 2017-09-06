//
//      Class to hold database of modules.
//
#ifndef _moduleDatabase_hh_
#define _moduleDatabase_hh_
#include <map>
#include "intSet.hh"

class ModuleDatabase
{
  NO_COPYING(ModuleDatabase);

public:
  ModuleDatabase(){}
  ~ModuleDatabase();

  bool insertModule(int name, PreModule* module);  // true if existing module displaced
  PreModule* getModule(int name) const;  // 0 if doesn't exist
  bool deleteModule(int name);  // true if module deleted

  void setInclude(Token name, bool polarity);
  void setOmodInclude(Token name, bool polarity);
  const IntSet& getIncludes() const;
  const IntSet& getOmodIncludes() const;

private:
  typedef map<int, PreModule*> ModuleMap;

  ModuleMap moduleMap;
  IntSet defaultIncludes;
  IntSet defaultOmodIncludes;
};

inline const IntSet&
ModuleDatabase::getIncludes() const
{
  return defaultIncludes;
}

inline const IntSet&
ModuleDatabase::getOmodIncludes() const
{
  return defaultOmodIncludes;
}

#endif
