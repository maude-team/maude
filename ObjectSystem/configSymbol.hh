//
//      Class for symbols for object-message configurations.
//
#ifndef _configSymbol_hh_
#define _configSymbol_hh_
#include "natSet.hh"
#include "ACU_Symbol.hh"

class ConfigSymbol : public ACU_Symbol
{
public:
  ConfigSymbol(int id, const Vector<int>& strategy, bool memoFlag, Term* identity = 0);
  //
  //	Override normal rule rewriting behavior.
  //
  virtual void compileRules();
  virtual DagNode* ruleRewrite(DagNode* subject, RewritingContext& context);
  //
  //	Functions particular to ConfigSymbol.
  //
  void addObjects(NatSet& objSymbols);
  void addMessages(NatSet& msgSymbols);

private:
  struct AutomatonPair
  {
    LhsAutomaton* objectAutomaton;
    LhsAutomaton* messageAutomaton;
    int ruleIndex;
  };

  struct MessageQueue;
  struct dagNodeLt;
  class ObjectMap;

  bool checkArgs(Term* pattern, Term*& object, Term*& message);

  NatSet objectSymbols;
  NatSet messageSymbols;
  Vector<AutomatonPair> automatonPairs;
};

#endif
