//
//      Class for modules that can be printed out.
//
#ifndef _visibleModule_hh_
#define _visibleModule_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "importModule.hh"

class VisibleModule : public ImportModule
{
  NO_COPYING(VisibleModule);

public:
  VisibleModule(int name, ModuleType moduleType, Parent* parent = 0);

  void showSummary(ostream& s);
  void showKinds(ostream& s) const;
  void showSortsAndSubsorts(ostream& s) const;
  void showModule(ostream& s, bool all) const;
  void showOps(ostream& s, bool indent, bool all) const;
  void showVars(ostream& s, bool indent) const;
  void showMbs(ostream& s, bool indent, bool all) const;
  void showEqs(ostream& s, bool indent, bool all) const;
  void showRls(ostream& s, bool indent, bool all) const;

private:
  void showSorts1(ostream& s, bool indent, bool all) const;
  void showSubsorts(ostream& s, bool indent, bool all) const;
  void showDecls(ostream& s, bool indent, Symbol* symbol, bool all) const;
  void showAttributes(ostream& s, Symbol* symbol, bool ctor = false) const;
};

#endif
