//
//      Class for local bindings within matching subproblems.
//
#ifndef _localBinding_hh_
#define _localBinding_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "simpleRootContainer.hh"
#undef assert  //HACK

class LocalBinding : private SimpleRootContainer
{
  NO_COPYING(LocalBinding);

public:
  LocalBinding(int maxSize);

  void addBinding(int index, DagNode* value);
  bool assert(Substitution& substitution);
  void retract(Substitution& substitution);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel) const;
  void dump(ostream& s, const VariableInfo* variableInfo = 0) const;
#endif

private:
  struct Binding
  {
    bool active;
    int variableIndex;
    DagNode* value;
  };

  void markReachableNodes();

  Vector<Binding> bindings;
};

#endif
