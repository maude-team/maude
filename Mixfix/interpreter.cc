//
//      Implementation for class Interpreter.
//
#ifdef __GNUG__
#pragma implementation
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "tty.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "AU_Theory.hh"
#include "higher.hh"
#include "mixfix.hh"

//      interface class definitions
#include "term.hh"
#include "extensionInfo.hh"

//	higher class definitions
#include "pattern.hh"
#include "matchSearchState.hh"
#include "rewriteSequenceSearch.hh"

//	front end class definitions
#include "timer.hh"
#include "userLevelRewritingContext.hh"
#include "maudemlBuffer.hh"
#include "preModule.hh"
#include "visibleModule.hh"
#include "loopSymbol.hh"
#include "interpreter.hh"

//	our stuff
#include "execute.cc"
#include "match.cc"
#include "search.cc"
#include "loopMode.cc"

Interpreter::Interpreter()
{
  xmlLog = 0;
  xmlBuffer = 0;

  flags = DEFAULT_FLAGS;
  currentModule = 0;

  savedContext = 0;
  savedMatchSearchState = 0;
  savedRewriteSequenceSearch = 0;
  savedModule = 0;
  continueFunc = 0;
}

Interpreter::~Interpreter()
{
  delete xmlBuffer;
  delete xmlLog;
}

void
Interpreter::setFlag(Flags flag, bool polarity)
{
  if (polarity)
    flags |= flag;
  else
    flags &= ~flag;
  RewritingContext::setTraceStatus(flags & EXCEPTION_FLAGS);
}

void
Interpreter::showProfile() const
{
  currentModule->getFlatModule()->showProfile(cout);
}

void
Interpreter::beginXmlLog(const char* fileName)
{
  delete xmlBuffer;
  delete xmlLog;
  xmlLog = new ofstream(fileName);
  xmlBuffer = new MaudemlBuffer(*xmlLog);
}

void
Interpreter::endXmlLog()
{
  delete xmlBuffer;
  xmlBuffer = 0;
  delete xmlLog;
  xmlLog = 0;
}

bool
Interpreter::setCurrentModule(const Vector<Token>& moduleExpr, int start)
{
  PreModule* m;
  int nrTokens = moduleExpr.length() - start;
  if (moduleExpr.length() == 0)
    {
      if (currentModule == 0)
	{
	  IssueWarning("no module expression provided and no last module.");
	  return false;
	}
      else if (currentModule->getFlatSignature()->isBad())
	m = currentModule;
      else
	return true;
    }
  else
    {
      if (nrTokens == 1)
	{
	  m = getModule(moduleExpr[start].code());
	  if (m != 0)
	    {      
	      if (m->getFlatSignature()->isBad())
		goto bad;
	      setCurrentModule(m);
	      return true;
	    }
	}
      IssueWarning(LineNumber(moduleExpr[0].lineNumber()) <<
		   ": no module " << QUOTE(moduleExpr) << '.');
      return false;
    }
 bad:
  IssueWarning(*m << ": module " << QUOTE(m) <<
	       " is unusable due to unpatchable errors.");
  return false;
}

void
Interpreter::setCurrentModule(PreModule* module)
{
  if (currentModule != module)
    {
      if (currentModule != 0)
	{
	  clearContinueInfo();
	  currentModule->loseFocus();
	}
      currentModule  = module;
    }
}

void
Interpreter::makeClean(int lineNumber)
{
  if (currentModule != 0 && !(currentModule->isComplete()))
    {
      IssueAdvisory(LineNumber(lineNumber) << ": discarding incomplete module.");
      delete currentModule;
      currentModule = 0;
    }
}

void
Interpreter::addSelected(const Vector<Token>& opName)
{
  selected.insert(Token::bubbleToPrefixNameCode(opName));
  //  opName.contractTo(0);
}

void
Interpreter::traceSelect(bool add)
{
  UserLevelRewritingContext::selectSymbols(selected, add);
  selected.makeEmpty();
}

void
Interpreter::breakSelect(bool add)
{
  UserLevelRewritingContext::selectBreakSymbols(selected, add);
  selected.makeEmpty();
}

void
Interpreter::traceExclude(bool add)
{
  UserLevelRewritingContext::excludeModules(selected, add);
  selected.makeEmpty();
}

void
Interpreter::printConceal(bool polarity)
{
  MixfixModule::concealSymbols(selected, polarity);
  selected.makeEmpty();
}

void
Interpreter::parse(const Vector<Token>& subject)
{
  //
  //	We need can't use getFlatSignature() since sort info
  //	is not computed until module is flattened.
  //
  Term *s = currentModule->getFlatModule()->parseTerm(subject);
  if (s != 0)
    {
      if (s->getSortIndex() == Sort::SORT_UNKNOWN)
	s->symbol()->fillInSortInfo(s);
      cout << s->getSort() << ": " << s << '\n';
      s->deepSelfDestruct();
    }
}

void
Interpreter::showSortsAndSubsorts() const
{
  currentModule->getFlatModule()->showSortsAndSubsorts(cout);
}

void
Interpreter::showModule(bool all) const
{
  currentModule->getFlatModule()->showModule(cout, all);
}

void
Interpreter::showOps(bool all) const
{
  currentModule->getFlatModule()->showOps(cout, false, all);
}

void
Interpreter::showVars() const
{
  currentModule->getFlatModule()->showVars(cout, false);
}

void
Interpreter::showMbs(bool all) const
{
  currentModule->getFlatModule()->showMbs(cout, false, all);
}

void
Interpreter::showEqs(bool all) const
{
  currentModule->getFlatModule()->showEqs(cout, false, all);
}

void
Interpreter::showRls(bool all) const
{
  currentModule->getFlatModule()->showRls(cout, false, all);
}

void
Interpreter::showKinds() const
{
  currentModule->getFlatModule()->showKinds(cout);
}

void
Interpreter::showSummary() const
{
  currentModule->getFlatModule()->showSummary(cout);
}
