DagNode*
MetaLevel::upMbs(bool flat, ImportModule* m, PointerMap& qidMap)
{
  static Vector<DagNode*> args;

  const Vector<SortConstraint*>& mbs = m->getSortConstraints();
  int nrMbs = flat ? mbs.length() : m->getNrOriginalMembershipAxioms();
  if (nrMbs == 0)
    return emptyMembAxSetSymbol->makeDagNode();
  else if (nrMbs == 1)
    return upMb(mbs[0], m, qidMap);

  args.resize(nrMbs);
  for (int i = 0; i < nrMbs; i++)
    args[i] = upMb(mbs[i], m, qidMap);
  return membAxSetSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upMb(const SortConstraint* mb, MixfixModule* m, PointerMap& qidMap)
{
  static Vector<DagNode*> args(4);

  args[0] = upTerm(mb->getLhs(), m, qidMap);
  args[1] = upType(mb->getSort(), qidMap);
  const Vector<ConditionFragment*>& condition = mb->getCondition();
  if (condition.empty())
    {
      args.resize(3);
      args[2] = upStatementAttributes(m, MixfixModule::MEMB_AX, mb, qidMap);
      return mbSymbol->makeDagNode(args);
    }
  args.resize(4);
  args[2] = upCondition(condition, m, qidMap);
  args[3] = upStatementAttributes(m, MixfixModule::MEMB_AX, mb, qidMap);
  return cmbSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upEqs(bool flat, ImportModule* m, PointerMap& qidMap)
{
  static Vector<DagNode*> args;

  const Vector<Equation*>& equations = m->getEquations();
  int nrEquations = flat ? equations.length() : m->getNrOriginalEquations();
  if (nrEquations == 0)
    return emptyEquationSetSymbol->makeDagNode();
  else if (nrEquations == 1)
    return upEq(equations[0], m, qidMap);

  args.resize(nrEquations);
  for (int i = 0; i < nrEquations; i++)
    args[i] = upEq(equations[i], m, qidMap);
  return equationSetSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upEq(const Equation* equation, MixfixModule* m, PointerMap& qidMap)
{
  static Vector<DagNode*> args(4);

  args[0] = upTerm(equation->getLhs(), m, qidMap);
  args[1] = upTerm(equation->getRhs(), m, qidMap);
  const Vector<ConditionFragment*>& condition = equation->getCondition();
  if (condition.empty())
    {
      args.resize(3);
      args[2] = upStatementAttributes(m, MixfixModule::EQUATION, equation, qidMap);
      return eqSymbol->makeDagNode(args);
    }
  args.resize(4);
  args[2] = upCondition(condition, m, qidMap);
  args[3] = upStatementAttributes(m, MixfixModule::EQUATION, equation, qidMap);
  return ceqSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upRls(bool flat, ImportModule* m, PointerMap& qidMap)
{
  static Vector<DagNode*> args;

  const Vector<Rule*>& rules = m->getRules();
  int nrRules = flat ? rules.length() : m->getNrOriginalRules();
  if (nrRules == 0)
    return emptyRuleSetSymbol->makeDagNode();
  else if (nrRules == 1)
    return upRl(rules[0], m, qidMap);

  args.resize(nrRules);
  for (int i = 0; i < nrRules; i++)
    args[i] = upRl(rules[i], m, qidMap);
  return ruleSetSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upRl(const Rule* rule, MixfixModule* m, PointerMap& qidMap)
{
  static Vector<DagNode*> args(4);

  args[0] = upTerm(rule->getLhs(), m, qidMap);
  args[1] = upTerm(rule->getRhs(), m, qidMap);
  const Vector<ConditionFragment*>& condition = rule->getCondition();
  if (condition.empty())
    {
      args.resize(3);
      args[2] = upStatementAttributes(m, MixfixModule::RULE, rule, qidMap);
      return rlSymbol->makeDagNode(args);
    }
  args.resize(4);
  args[2] = upCondition(condition, m, qidMap);
  args[3] = upStatementAttributes(m, MixfixModule::RULE, rule, qidMap);
  return crlSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upStatementAttributes(MixfixModule* m,
				 MixfixModule::ItemType type,
				 const PreEquation *pe,
				 PointerMap& qidMap)
{
  Vector<DagNode*> args;

  int id = pe->getLabel().id();
  if (id != NONE)
    {
      Vector<DagNode*> args2(1);
      args2[0] = upQid(id, qidMap);
      args.append(labelSymbol->makeDagNode(args2));
    }
  int metadata = m->getMetadata(type, pe);
  if (metadata != NONE)
    {
      Vector<DagNode*> args2(1);
      args2[0] = new StringDagNode(stringSymbol, Token::codeToRope(metadata));
      args.append(metadataSymbol->makeDagNode(args2));
    }
  const Equation* eq = dynamic_cast<const Equation*>(pe);
  if (eq != 0 && eq->isOwise())
    {
      Vector<DagNode*> args2;
      args.append(owiseSymbol->makeDagNode(args2));
    }

  switch (args.length())
    {
    case 0:
      return emptyAttrSetSymbol->makeDagNode(args);
    case 1:
      return args[0];
    }
  return attrSetSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upLabel(const Label& label, PointerMap& qidMap)
{
  static const char emptyString[1] = {'\0'};

  int id = label.id();
  if (id == NONE)
    id = Token::encode(emptyString);
  return upQid(id, qidMap);
}

DagNode*
MetaLevel::upCondition(const Vector<ConditionFragment*>& condition,
		       MixfixModule* m,
		       PointerMap& qidMap)
{
  static Vector<DagNode*> args;
 
  int nrFragments = condition.length();
  if (nrFragments == 1)
    return upConditionFragment(condition[0], m, qidMap);

  args.resize(nrFragments);
  for (int i = 0; i < nrFragments; i++)
    args[i] = upConditionFragment(condition[i], m, qidMap);
  return conjunctionSymbol->makeDagNode(args);
}

DagNode*
MetaLevel::upConditionFragment(const ConditionFragment* fragment,
			       MixfixModule* m,
			       PointerMap& qidMap)
{
  static Vector<DagNode*> args(2);
  Symbol* s;

  if (const EqualityConditionFragment* e =
      dynamic_cast<const EqualityConditionFragment*>(fragment))
    {
      args[0] = upTerm(e->getLhs(), m, qidMap);
      args[1] = upTerm(e->getRhs(), m, qidMap);
      s = equalityConditionSymbol;
    }
  else if (const SortTestConditionFragment* t =
	   dynamic_cast<const SortTestConditionFragment*>(fragment))
    {
      args[0] = upTerm(t->getLhs(), m, qidMap);
      args[1] = upType(t->getSort(), qidMap);
      s = sortTestConditionSymbol;
    }
  else if(const AssignmentConditionFragment* a =
	  dynamic_cast<const AssignmentConditionFragment*>(fragment))
    {
      args[0] = upTerm(a->getLhs(), m, qidMap);
      args[1] = upTerm(a->getRhs(), m, qidMap);
      s = matchConditionSymbol;
    }
  else if(const RewriteConditionFragment* r =
	  dynamic_cast<const RewriteConditionFragment*>(fragment))
    {
      args[0] = upTerm(r->getLhs(), m, qidMap);
      args[1] = upTerm(r->getRhs(), m, qidMap);
      s = rewriteConditionSymbol;
    }
  else
    CantHappen("bad condition fragment");
  return s->makeDagNode(args);
}
