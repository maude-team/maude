void
PreModule::addVarDecl(Token varName)
{
  if (!lastSawOpDecl)
    {
      int nrOpDefs = opDefs.length();
      opDefs.expandBy(1);
      opDefs[nrOpDefs].symbolType.setBasicType(SymbolType::VARIABLE);
    }
  int nrOpDecls = opDecls.length();
  opDecls.expandBy(1);
  opDecls[nrOpDecls].prefixName = varName;
  opDecls[nrOpDecls].defIndex = opDefs.length() - 1;
  lastSawOpDecl = true;
}

void
PreModule::addOpDecl(const Vector<Token>& opName)
{
  if (!lastSawOpDecl)
    opDefs.expandBy(1);

  int nrOpDecls = opDecls.length();
  opDecls.expandBy(1);
  opDecls[nrOpDecls].prefixName.makePrefixName(opName);
  opDecls[nrOpDecls].defIndex = opDefs.length() - 1;
  lastSawOpDecl = true;
}

void
PreModule::addType(bool kind, const Vector<Token>& tokens)
{
  OpDef& opDef = opDefs[opDefs.length() - 1];
  opDef.types.expandBy(1);
  Type& type = opDef.types[opDef.types.length() - 1];
  type.kind = kind;
  type.tokens = tokens;  // deep copy
  lastSawOpDecl = false;
}

void
PreModule::convertSortsToKinds()
{
  Assert(!lastSawOpDecl, "missing sort specs");
  OpDef& opDef = opDefs[opDefs.length() - 1];
  int nrTypes = opDef.types.length();
  for (int i = 0; i < nrTypes; i++)
    {
      if (opDef.types[i].kind)
	{
	  IssueWarning(LineNumber(opDef.types[i].tokens[0].lineNumber()) <<
		       ": superfluous [] notation in operation declaration");
	}
      else
	opDef.types[i].kind = true;
    }
}

void
PreModule::setIdentity(const Vector<Token>& identity)
{
  opDefs[opDefs.length() - 1].identity = identity;  // deep copy
}

void
PreModule::setFlag(int flag)
{
  OpDef& opDef = opDefs[opDefs.length() - 1];
  opDef.symbolType.setFlags(flag);
}

void
PreModule::setPrec(Token precTok)
{
  const char* string = precTok.name();
  char* pointer;
  long prec = strtol(string, &pointer, 10);
  if (pointer != string && *pointer == '\0' &&
      prec >= MixfixModule::MIN_PREC && prec <= MixfixModule::MAX_PREC)
    {
      OpDef& opDef = opDefs[opDefs.length() - 1];
      opDef.prec = prec;
      opDef.symbolType.setFlags(SymbolType::PREC);
    }
  else
    {
      IssueWarning(LineNumber(precTok.lineNumber()) <<
		   ": bad value " << QUOTE(string) << " for prec attribute.");
    }
}

void
PreModule::setGather(const Vector<Token>& gather)
{
  int length = gather.length();
  OpDef& opDef = opDefs[opDefs.length() - 1];
  if (length != opDef.types.length() - 1)
    {
      IssueWarning(LineNumber(gather[0].lineNumber()) <<
		   ": bad gather length.");
      return;
    }
  for (int i = 0; i < length; i++)
    {
      const char* string = gather[i].name();
      if (string[0] != '\0' && string[1] == '\0')
	{
	  switch(string[0])
	    {
	    case '&':
	      opDef.gather.append(MixfixModule::GATHER_AMP);
	      continue;
	    case 'E':
	      opDef.gather.append(MixfixModule::GATHER_E);
	      continue;
	    case 'e':
	      opDef.gather.append(MixfixModule::GATHER_e);
	      continue;
	    }
	}
      IssueWarning(LineNumber(gather[i].lineNumber()) <<
		   ": bad value " << QUOTE(string) <<
		   " in gather attribute. Recovering by ignoring gather attribute.");
      opDef.gather.clear();  // for safety
      return;
    }
  opDef.symbolType.setFlags(SymbolType::GATHER);
}

bool
PreModule::checkFormatString(const char* string)
{
  if (string[0] == 'd' && string[1] == '\0')
    return true;
  for(;;)
    {
      switch (*string++)
	{
	case '\0':
	  return true;
	case '+':
	case '-':
	case 's':
	case 't':
	case 'n':
	case 'i':
#define MACRO(m, t)	case m:
#include "ansiEscapeSequences.cc"
#undef MACRO
	case 'o':
	  continue;
	default:
	  return false;
	}
    }
}

void
PreModule::setFormat(const Vector<Token>& format)
{
  int length = format.length();
  OpDef& opDef = opDefs[opDefs.length() - 1];
  for (int i = 0; i < length; i++)
    {
      const char* string = format[i].name();
      if (checkFormatString(string))
	opDef.format.append(format[i].code());
      else
	{
	  IssueWarning(LineNumber(format[i].lineNumber()) <<
		       ": bad value " << QUOTE(string) <<
		       " in format attribute. Recovering by ignoring format attribute.");
	  opDef.format.clear();  // for safety
	  return;
	}
    }
  opDef.symbolType.setFlags(SymbolType::FORMAT);
}

void
PreModule::setFrozen(const Vector<Token>& frozen)
{
  int length = frozen.length();
  OpDef& opDef = opDefs[opDefs.length() - 1];
  int maxArgPos = opDef.types.length() - 1;
  if (length == 0)
    {
      if (maxArgPos == 0)
	{
	  IssueWarning("cannot have frozen attribute for constant.");
	  return;
	}
      for (int i = 0; i < maxArgPos; i++)
	opDef.frozen.insert(i);
    }
  else
    {
      for (int i = 0; i < length; i++)
	{
	  const char* string = frozen[i].name();
	  char* pointer;
	  long argPos = strtol(string, &pointer, 10);
	  if (pointer != string && *pointer == '\0' &&
	      argPos >= 1 && argPos <= maxArgPos)
	    {
	      WarningCheck(!(opDef.frozen.contains(argPos - 1)),
			   LineNumber(frozen[i].lineNumber()) <<
			   ": argument " << QUOTE(argPos) <<
			   " mentioned twice in frozen attribute.");
	      opDef.frozen.insert(argPos - 1);
	    }
	  else
	    {
	      IssueWarning(LineNumber(frozen[i].lineNumber()) <<
			   ": bad value " << QUOTE(string) <<
			   " in frozen attribute. Recovering by ignoring frozen attribute.");
	      opDef.frozen.clear();  // for safety
	      return;
	    }
	}
    }
  opDef.symbolType.setFlags(SymbolType::FROZEN);
}

void
PreModule::setStrat(const Vector<Token>& strategy)
{
  int length = strategy.length();
  OpDef& opDef = opDefs[opDefs.length() - 1];
  int maxArgPos = opDef.types.length();
  for (int i = 0; i < length; i++)
    {
      const char* string = strategy[i].name();
      char* pointer;
      long argPos = strtol(string, &pointer, 10);
      if (pointer != string && *pointer == '\0' &&
	  argPos >= -maxArgPos && argPos <= maxArgPos)
	opDef.strategy.append(static_cast<int>(argPos));
      else
	{
	  IssueWarning(LineNumber(strategy[i].lineNumber()) <<
		       ": bad value " << QUOTE(string) <<
		       " in strategy attribute. Recovering by ignoring strategy attribute.");
	  opDef.strategy.clear();  // for safety
	  return;
	}
    }
  opDef.symbolType.setFlags(SymbolType::STRAT);
}

void
PreModule::setLatexMacro(const string& latexMacro)
{
  opDefs[opDefs.length() - 1].latexMacro = latexMacro;
}

void
PreModule::addHook(HookType type, Token name, const Vector<Token>& details)
{
  int code = name.code();
  OpDef& opDef = opDefs[opDefs.length() - 1];
  int nrHooks = opDef.special.length();
  opDef.special.expandBy(1);
  Hook& hook = opDef.special[nrHooks];
  hook.type = type;
  hook.name = code;
  hook.details = details;  // deep copy
  if (type == ID_HOOK)
    opDef.symbolType.setBasicType(SymbolType::specialNameToBasicType(name.name()));
}

void
PreModule::makeOpDeclsConsistent()
{
  //
  //	Call if we encounter a syntax error while parsing module to make sure
  //	opDefs/opDecls are left in a good state.
  //
  int nrOpDefs = opDefs.length();
  if (nrOpDefs == 0)
    return;
  int lastDefIndex = nrOpDefs - 1;
  if(opDefs[lastDefIndex].types.length() == 0)
    {
      //
      //	Problem: we have op decls for which op def has not been
      //	properly filled in; quietly delete them and reset
      //	lastSawOpDecl flag
      //
      int m = opDecls.length();
      while (m > 0 && opDecls[m - 1].defIndex == lastDefIndex)
	--m;
      opDecls.contractTo(m);
      lastSawOpDecl = false;
    }
}
