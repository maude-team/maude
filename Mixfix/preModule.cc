//
//      Implementation for class PreModule.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "builtIn.hh"
#include "freeTheory.hh"
#include "AU_Theory.hh"
#include "higher.hh"
#include "mixfix.hh"

//      interface class definitions
#include "term.hh"
#include "lhsAutomaton.hh"
#include "extensionInfo.hh"
#include "subproblem.hh"
#include "binarySymbol.hh"
 
//      core class definitions
#include "lineNumber.hh"
#include "equation.hh"
#include "rule.hh"
#include "sortConstraint.hh"
#include "module.hh"
#include "rewritingContext.hh"
#include "argumentIterator.hh"
#include "dagArgumentIterator.hh"
//#include "dagNodeSet.hh"

//	front end class definitions
#include "timer.hh"
#include "fileTable.hh"
#include "userLevelRewritingContext.hh"
#include "quotedIdentifierSymbol.hh"
#include "token.hh"
#include "loopSymbol.hh"
#include "visibleModule.hh"
#include "preModule.hh"

#include "interpreter.hh"
#include "maudemlBuffer.hh"
#include "main.hh"  // HACK shouldn't be accessing global variables


#ifdef QUANTIFY_PROCESSING
#include "quantify.h"
#endif

//	our stuff
#include "import.cc"
#include "process.cc"
#include "fixUp.cc"
#include "ops.cc"
#include "command.cc"

PreModule::PreModule(Token moduleName, MixfixModule::ModuleType moduleType)
  : NamedEntity(moduleName.code()),
    LineNumber(moduleName.lineNumber()),
    moduleType(moduleType)
{
  lastSawOpDecl = false;
  isCompleteFlag = false;
  flatModule = 0;
}

PreModule::~PreModule()
{
  if (flatModule != 0)
    flatModule->deepSelfDestruct();
}

void
PreModule::regretToInform(ImportModule* doomedModule)
{
  Assert(doomedModule == flatModule, "module pointer error");
  flatModule = 0;
#ifdef COMPILER
  interpreter.invalidate(this);
#endif
}

VisibleModule*
PreModule::getFlatModule()
{
  VisibleModule* m = getFlatSignature();
  if (m->getStatus() != Module::THEORY_CLOSED)
    {
      //
      //	Need to flatten in statements and compile.
      //
      m->importStatements();
      if (m->isBad())
	{
	  IssueWarning(*m <<
		       ": this module contains one or more errors that \
could not be patched up and thus it cannot be used or imported.");
	}
      else
	m->closeTheory();
      m->resetImports();
    }
  return m;
}

VisibleModule*
PreModule::getFlatSignature() 
{
  if (flatModule == 0)
    {
      IssueAdvisory("reparsing module " << QUOTE(this) <<
		    " due to changes in imported modules.");
      process();
    }
  else if (flatModule->getStatus() == Module::OPEN)
    return 0;  // we must already be in the middle of processing this module
  return flatModule;
}

void
PreModule::finishModule()
{
  autoImports = interpreter.getIncludes(); // deep copy
  isCompleteFlag = true;
  interpreter.insertModule(id(), this);
  process();
}

PreModule::OpDef::OpDef()
{
  prec = DEFAULT;
}

void
PreModule::addStatement(const Vector<Token>& statement)
{
  if (statement[1].code() == leftBracket &&
      statement[3].code() == rightBracket &&
      statement[4].code() == colon)
    (void) labels.insert(statement[2].code());

  int i = statement.length() - 1;
  if (statement[i].code() == rightBracket)
    {
      int bracketCount = 1;
      for (i -= 2; i >= 4; i--)
	{
	  int t = statement[i].code();
	  if (t == leftBracket)
	    {
	      --bracketCount;
	      if (bracketCount == 0)
		break;
	    }
	  else if (t == label)
	    labels.insert(statement[i+1].code());
	  else if (t == rightBracket)
	    ++bracketCount;
	}
    }
  statements.append(statement);
}
