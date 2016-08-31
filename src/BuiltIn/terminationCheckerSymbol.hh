/*

    This file is part of the Maude 2 interpreter.

    Portions copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//      Class for symbols for built in operations on strings.
//
#ifndef _terminationCheckerSymbol_hh_
#define _terminationCheckerSymbol_hh_

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

// Types used in declaration
#include "freeSymbol.hh"
// #include "ropeStuff.hh"
#include "rope.hh"

#include "term.hh"
#include "cachedDag.hh"

#include <vector>
#include <map>
using namespace std;

class StringSymbol;

class TerminationCheckerSymbol : public FreeSymbol
{
public:
  TerminationCheckerSymbol(int id, int arity);
  ~TerminationCheckerSymbol();

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void getDataAttachments(const Vector<Sort*>& opDeclaration,
			  Vector<const char*>& purposes,
			  Vector<Vector<const char*> >& data);
  void getSymbolAttachments(Vector<const char*>& purposes,
			    Vector<Symbol*>& symbols);
  void getTermAttachments(Vector<const char*>& purposes,
			  Vector<Term*>& terms);
  void postInterSymbolPass();
  void reset();
  void resetRules();
private:

//   static const string mfeConfigFileName;

  enum CreationResult
  {
    SUCCESS = 0,
    ERROR = -1
  };
  
  Rope sendMsg(vector<Rope> & msg);
  void terminate(void);

  Rope lastTheory;
  int op;
  StringSymbol* stringSymbol;
  Symbol* falseSymbol;
  Symbol* trueSymbol;
  QuotedIdentifierSymbol* quotedIdentifierSymbol;
  Symbol* nilQidListSymbol;
  AU_Symbol* qidListSymbol;
  SuccSymbol* succSymbol;
  pid_t child;
  int queryFd;
  int replyFd;
  //CachedDag executableTerm;

  map<Rope, pair<Rope, Rope> > *execFiles;

  const pair <Rope, Rope> chooseBatch(const Rope & tool);
  void readToolsFile(map<Rope, pair<Rope, Rope> > **);
  Rope createTempFile(const Rope &, const Rope &);
  Rope writeLogFile(const vector<Rope> &args);
  Rope writeLogFileBool(const vector<Rope> &args);
};

#endif
