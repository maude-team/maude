//
//	Abstract class for table of rules indexed under some symbol.
//
#ifndef _ruleTable_hh_
#define _ruleTable_hh_

class RuleTable
{
public:
  RuleTable();
  void offerRule(Rule* rule);
  const Vector<Rule*>& getRules() const;
  bool ruleFree() const;
  virtual void compileRules();
  virtual DagNode* ruleRewrite(DagNode* subject, RewritingContext& context);
  virtual void resetRules();
  
protected:
  virtual bool acceptRule(Rule* rule) = 0;
  DagNode* applyRules(DagNode* subject,
		      RewritingContext& context,
		      ExtensionInfo* extensionInfo);

private:
  Vector<Rule*> rules;
  int nextRule;		// for rule fairness
};

inline const Vector<Rule*>&
RuleTable::getRules() const
{
  return rules;
}

inline void
RuleTable::offerRule(Rule* rule)
{
  if (acceptRule(rule))
    rules.append(rule);
}

inline bool
RuleTable::ruleFree() const
{
  return rules.isNull();
}

inline void
RuleTable::resetRules()
{
  nextRule = 0;
}

#endif
