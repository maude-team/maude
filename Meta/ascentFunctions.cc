bool
MetaLevelOpSymbol::metaUpMbs(FreeDagNode* subject, RewritingContext& context)
{
  int moduleName;
  bool flat;
  if (metaLevel->downQid(subject->getArgument(0), moduleName) &&
      metaLevel->downBool(subject->getArgument(1), flat))
    {
      if (PreModule* pm = interpreter.getModule(moduleName))
	{
	  PointerMap qidMap;
	  return context.builtInReplace(subject,
					metaLevel->upMbs(flat, pm->getFlatModule(), qidMap));
	}
    }
  return false;
}

bool
MetaLevelOpSymbol::metaUpEqs(FreeDagNode* subject, RewritingContext& context)
{
  int moduleName;
  bool flat;
  if (metaLevel->downQid(subject->getArgument(0), moduleName) &&
      metaLevel->downBool(subject->getArgument(1), flat))
    {
      if (PreModule* pm = interpreter.getModule(moduleName))
	{
	  PointerMap qidMap;
	  return context.builtInReplace(subject,
					metaLevel->upEqs(flat, pm->getFlatModule(), qidMap));
	}
    }
  return false;
}

bool
MetaLevelOpSymbol::metaUpRls(FreeDagNode* subject, RewritingContext& context)
{
  int moduleName;
  bool flat;
  if (metaLevel->downQid(subject->getArgument(0), moduleName) &&
      metaLevel->downBool(subject->getArgument(1), flat))
    {
      if (PreModule* pm = interpreter.getModule(moduleName))
	{
	  PointerMap qidMap;
	  return context.builtInReplace(subject,
					metaLevel->upRls(flat, pm->getFlatModule(), qidMap));
	}
    }
  return false;
}
