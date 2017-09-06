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
  ConfigSymbol(int id,
	       const Vector<int>& strategy,
	       bool memoFlag,
	       Term* identity = 0);
  //
  //	Override normal rule rewriting behavior.
  //
  void compileRules();
  DagNode* ruleRewrite(DagNode* subject, RewritingContext& context);
  void resetRules();
  //
  //	Functions particular to ConfigSymbol.
  //
  void addObjects(NatSet& objSymbols);
  void addMessages(NatSet& msgSymbols);

private:
  struct symbolLt
  {
    bool operator()(const Symbol* d1, const Symbol* d2)
    {
      return d1->compare(d2) < 0;
    }
  };

  struct RuleSet
  {
    Vector<Rule*> rules;
    Vector<Rule*>::const_iterator next;
  };

  typedef map<Symbol*, RuleSet, symbolLt> RuleMap;

  struct MessageQueue;
  struct dagNodeLt;
  class ObjectMap;
  struct Remainder;

  bool checkArgs(Term* pattern, Term*& object, Term*& message);
  DagNode* objMsgRewrite(Symbol* messageSymbol,
			 DagNode* subject,
			 RewritingContext& context);
  DagNode* retrieveObject(DagNode* rhs, DagNode* name, Remainder& remainder);
  DagNode* leftOverRewrite(DagNode* subject,
			   RewritingContext& context,
			   ExtensionInfo* extensionInfo);

  NatSet objectSymbols;
  NatSet messageSymbols;
  RuleMap ruleMap;
  RuleSet leftOver;
};

#endif
