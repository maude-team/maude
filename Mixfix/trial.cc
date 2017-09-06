//
//	Code for tracing trails of conditional mbs/eqs/rls.
//
int UserLevelRewritingContext::trialCount = 0;

int
UserLevelRewritingContext::traceBeginEqTrial(DagNode* subject, const Equation* equation)
{
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileEqConditionStart(equation);
    }
  if (handleDebug(subject, equation))
    return UNDEFINED;
  if (!localTraceFlag || !traceEqFlag || dontTrace(subject, equation))
    return UNDEFINED;
  cout << header << "trial #" << ++trialCount << '\n';
  if (equation == 0)
    cout << "(built-in equation for symbol " << subject->symbol() << ")\n";
  else
    {
      cout << equation << '\n';
      if (traceSubstitutionFlag)
	printSubstitution(*this, *equation);
    }
  return trialCount;
}

int
UserLevelRewritingContext::traceBeginRuleTrial(DagNode* subject, const Rule* rule)
{
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileRlConditionStart(rule);
    }
  if (handleDebug(subject, rule))
    return UNDEFINED;
  if (!localTraceFlag || !traceRuleFlag || dontTrace(subject, rule))
    return UNDEFINED;
  cout << header << "trial #" << ++trialCount << '\n';
  if (rule == 0)
    cout << "(built-in rule for symbol " << subject->symbol() << ")\n";
  else
    {
      cout << rule << '\n';
      if (traceSubstitutionFlag)
	printSubstitution(*this, *rule);
    }
  return trialCount;
}

int
UserLevelRewritingContext::traceBeginScTrial(DagNode* subject, const SortConstraint* sc)
{
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileMbConditionStart(sc);
    }
  if (handleDebug(subject, sc))
    return UNDEFINED;
  if (!localTraceFlag || !traceScFlag || dontTrace(subject, sc))
    return UNDEFINED;
  cout << header << "trial #" << ++trialCount << '\n';
  if (sc == 0)
    cout << "(built-in membership axiom for symbol " << subject->symbol() << ")\n";
  else
    {
      cout << sc << '\n';
      if (traceSubstitutionFlag)
	printSubstitution(*this, *sc);
    }
  return trialCount;
}

void
UserLevelRewritingContext::traceEndTrial(int trialRef, bool success)
{
  if (!abortFlag && trialRef != UNDEFINED)
    cout << header << (success ? "success #" : "failure #") << trialRef << '\n';
}

void
UserLevelRewritingContext::traceExhausted(int trialRef)
{
  if (!abortFlag && trialRef != UNDEFINED)
    cout << header << "exhausted (#" << trialRef << ")\n";
}

void
UserLevelRewritingContext::traceBeginFragment(int trialRef,
					      const PreEquation* preEquation,
					      int fragmentIndex,
					      bool firstAttempt)
{
  if (abortFlag || trialRef == UNDEFINED)
    return;
  ConditionFragment* fragment = (preEquation->getCondition())[fragmentIndex];
  cout << header;
  if (!firstAttempt)
    cout << "re-";
  cout << "solving condition fragment" << '\n' << fragment << '\n';
}

void
UserLevelRewritingContext::traceEndFragment(int trialRef,
					    const PreEquation* preEquation,
					    int fragmentIndex,
					    bool success)
{
  if (interpreter.getFlag(Interpreter::PROFILE))
    {
      safeCast(ProfileModule*, root()->symbol()->getModule())->
	profileFragment(preEquation, fragmentIndex, success);
    }
  if (abortFlag || trialRef == UNDEFINED)
    return;

  //ImportModule* module = safeCast(ImportModule*, preEquation->getLhs()->symbol()->getModule());
  // module->profileEndFragment(preEquation, fragmentIndex);

  //safeCast(MixfixModule*, preEquation->getLhs()->symbol()->getModule())->
  //  profileEndFragment(preEquation, fragmentIndex);

  ConditionFragment* fragment = (preEquation->getCondition())[fragmentIndex];
  if (success)
    {
      cout << header << "success for condition fragment" << '\n' << fragment << '\n';
      if (traceSubstitutionFlag)
	printSubstitution(*this, *preEquation);
    }
  else
    cout << header << "failure for condition fragment" << '\n' << fragment << '\n';
}
