/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

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
//      Class for symbols for built-in meta-level operations.
//
#ifndef _completenessCheckerSymbol_hh_
#define _completenessCheckerSymbol_hh_

//      utility stuff
#include "macros.hh"
#include "vector.hh"
 
class DagNode;
class Equation;
class ExtensionInfo;
class FreeRemainder;
class Module;
class RedexPosition;
class RewritingContext;
class Rule;
class Sort;
class SortBdds;
class SortConstraint;
class SymbolMap;
class Term;

class Substitution;
class VariableDagNode;
class LocalBinding;
class Substitution;
class UnificationContext;
class UnificationSubproblem;
class PendingUnificationStack;
class Environment;
class HashConsSet;
class Interpreter;
class variableGenerator;
class FreshVariableGenerator;
class NarrowingVariableInfo;
class NarrowingSequenceSearch;

class Instruction; // new for Maude 2.7a
class StackMachine; // new for Maude 2.7a
class Frame; // new for Maude 2.7a
class StackMachineRhsCompiler; // new for Maude 2.7a
class VariantSearch; // new for Maude 2.7a

#include "freeSymbol.hh"

class ACU_Symbol;
class FreeDagNode;
class MetaLevel;
class MetaLevelOpSymbol;

class CompletenessCheckerSymbol : public FreeSymbol
{
  NO_COPYING(CompletenessCheckerSymbol);

public:
  CompletenessCheckerSymbol(int id, int nrArgs);
  ~CompletenessCheckerSymbol();

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);
  void getSymbolAttachments(Vector<const char*>& purposes,
			    Vector<Symbol*>& symbols);
  void getTermAttachments(Vector<const char*>& purposes,
			  Vector<Term*>& terms);

  void postInterSymbolPass();
  void reset();
  bool eqRewrite(DagNode* subject, RewritingContext& context);
private:
  bool okToBind();
  bool setReachability(FreeDagNode* subject, RewritingContext& context);

  MetaLevel* metaLevel;
  MetaLevelOpSymbol* shareWith;
  Symbol* nilSymbol;
  ACU_Symbol* unionSymbol;
  Symbol* unverifiableOpSymbol;
  Symbol* unverifiableMbSymbol;
  Symbol* counterexampleOpSymbol;
  Symbol* counterexampleMbSymbol;
};

#endif
