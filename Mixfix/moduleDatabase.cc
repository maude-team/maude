//
//      Implementation for class ModuleDatabase.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "mixfix.hh"

//	front end class definitions
#include "preModule.hh"
#include "moduleDatabase.hh"

ModuleDatabase::~ModuleDatabase()
{
#ifndef NO_ASSERT
  //
  //	Cleaning up makes for a slow exit, but it helps catch
  //	dangling pointers and leaked memory when debugging.
  //
  /* NEED TO FIX
  const ModuleMap::const_iterator e = moduleMap.end();
  for (ModuleMap::const_iterator i = moduleMap.begin(); i != e; ++i)
    delete i->second;
  */
#endif
}

bool
ModuleDatabase::insertModule(int name, PreModule* module)
{
  pair<ModuleMap::iterator, bool> p = moduleMap.insert(ModuleMap::value_type(name, module));
  if (p.second)
    return false;
  IssueAdvisory("redefining module " << QUOTE(module) << '.');
  delete p.first->second;
  p.first->second = module;
  return true;
}

PreModule*
ModuleDatabase::getModule(int name) const
{
  const ModuleMap::const_iterator t = moduleMap.find(name);
  return (t == moduleMap.end()) ? 0 : t->second;
}

bool
ModuleDatabase::deleteModule(int name)
{
  const ModuleMap::iterator t = moduleMap.find(name);
  if (t == moduleMap.end())
    return false;
  delete t->second;
  moduleMap.erase(t);
  return true;
}

void
ModuleDatabase::setInclude(Token name, bool polarity)
{
  int code = name.code();
  if (polarity)
    defaultIncludes.insert(code);
  else
    defaultIncludes.subtract(code);
}

void
ModuleDatabase::setOmodInclude(Token name, bool polarity)
{
  int code = name.code();
  if (polarity)
    defaultOmodIncludes.insert(code);
  else
    defaultOmodIncludes.subtract(code);
}
