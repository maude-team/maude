//
//	Class for modules
//
#ifndef _module_hh_
#define _module_hh_
#include "namedEntity.hh"
#include "lineNumber.hh"
#include "badFlag.hh"
#include "sort.hh"
#include "connectedComponent.hh"
#include "symbol.hh"

class Module : public NamedEntity, public LineNumber, public BadFlag
{
  NO_COPYING(Module);

public:
  enum Status
  {
    OPEN,
    SORT_SET_CLOSED,
    SIGNATURE_CLOSED,
    FIX_UPS_CLOSED,
    THEORY_CLOSED
  };

  Module(int id);
  virtual ~Module();

  virtual void closeSortSet();
  virtual void closeSignature();
  virtual void closeFixUps();
  virtual void closeTheory();
  Status getStatus() const;
  const Vector<Sort*>& getSorts() const;
  const Vector<Symbol*>& getSymbols() const;
  const Vector<ConnectedComponent*>& getConnectedComponents() const;
  const Vector<SortConstraint*>& getSortConstraints() const;
  const Vector<Equation*>& getEquations() const;
  const Vector<Rule*>& getRules() const;
  void insertSort(Sort* sort);
  void insertSymbol(Symbol* symbol);
  void insertSortConstraint(SortConstraint* sortConstraint);
  void insertEquation(Equation* equation);
  void insertRule(Rule* rule);
  void insertLateSymbol(Symbol*s);
  void clearMemo();  // clear memo table for each symbol
  virtual void reset();  // clear misc caches for each symbol
  void resetRules();  // reset round robin counter for each symbol

#ifdef DUMP
  void dump(ostream& s);
#endif

private:
  void indexSortConstraints();
  void indexEquation(Equation* eq);
  void indexEquations();
  void indexRules();

  Status status;
  Vector<Sort*> sorts;
  Vector<ConnectedComponent*> connectedComponents;
  Vector<Symbol*> symbols;
  Vector<SortConstraint*> sortConstraints;
  Vector<Equation*> equations;
  Vector<Rule*> rules;
};

inline Module::Status
Module::getStatus() const
{
  return status;
}

inline const Vector<Sort*>&
Module::getSorts() const
{
  return sorts;
}

inline const Vector<ConnectedComponent*>&
Module::getConnectedComponents() const
{
  return connectedComponents;
}

inline const Vector<Symbol*>&
Module::getSymbols() const
{
  return symbols;
}

inline const Vector<SortConstraint*>&
Module::getSortConstraints() const
{
  return sortConstraints;
}

inline const Vector<Equation*>&
Module::getEquations() const
{
  return equations;
}

inline const Vector<Rule*>&
Module::getRules() const
{
  return rules;
}

inline void
Module::insertSort(Sort* sort)
{
  Assert(status == OPEN, cerr << "bad status");
  sort->setModuleInfo(this, sorts.length());
  sorts.append(sort);
}

inline void
Module::insertSymbol(Symbol* symbol)
{
  Assert(status < SIGNATURE_CLOSED, cerr << "bad status");
  symbol->setModuleInfo(this, symbols.length());
  symbols.append(symbol);
}

#endif
