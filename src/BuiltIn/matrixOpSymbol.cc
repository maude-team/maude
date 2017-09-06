/*

    This file is part of the Maude 2 interpreter.

    Copyright 2004 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for class NumberOpSymbol.
//
#include <iterator>

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "diophantineSystem2.hh"
#include "diophantineSystem3.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "ACU_Persistent.hh"
#include "ACU_Theory.hh"
#include "builtIn.hh"

//      interface class definitions
#include "term.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "dagArgumentIterator.hh"

//      free theory class definitions
#include "freeSymbol.hh"
#include "freeDagNode.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"

//      built in stuff
#include "bindingMacros.hh"
#include "succSymbol.hh"
#include "minusSymbol.hh"
#include "matrixOpSymbol.hh"

MatrixOpSymbol::MatrixOpSymbol(int id, int arity)
  : NumberOpSymbol(id, arity)
{
#define MACRO(SymbolName, SymbolClass, RequiredFlags, NrArgs) \
  SymbolName = 0;
#include "matrixOpSignature.cc"
#undef MACRO
}

bool
MatrixOpSymbol::attachData(const Vector<Sort*>& opDeclaration,
			   const char* purpose,
			   const Vector<const char*>& data)
{
  if (strcmp(purpose, "MatrixOpSymbol") == 0)
    return true;
  return NumberOpSymbol::attachData(opDeclaration, purpose, data);
}

bool
MatrixOpSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
#define MACRO(SymbolName, SymbolClass, RequiredFlags, NrArgs) \
  BIND_SYMBOL(purpose, symbol, SymbolName, SymbolClass*);
#include "matrixOpSignature.cc"
#undef MACRO
  return NumberOpSymbol::attachSymbol(purpose, symbol);
}

void
MatrixOpSymbol::getDataAttachments(const Vector<Sort*>& opDeclaration,
				   Vector<const char*>& purposes,
				   Vector<Vector<const char*> >& data)
{
  int nrDataAttachments = purposes.length();
  purposes.resize(nrDataAttachments + 1);
  purposes[nrDataAttachments] = "MatrixOpSymbol";
  data.resize(nrDataAttachments + 1);
  (data[nrDataAttachments]).resize(1);
  data[nrDataAttachments][0] = "natSystemSolve";
  NumberOpSymbol::getDataAttachments(opDeclaration, purposes, data);
}

void
MatrixOpSymbol::getSymbolAttachments(Vector<const char*>& purposes,
				     Vector<Symbol*>& symbols)
{
#define MACRO(SymbolName, SymbolClass, RequiredFlags, NrArgs) \
  APPEND_SYMBOL(purposes, symbols, SymbolName);
#include "matrixOpSignature.cc"
#undef MACRO
  NumberOpSymbol::getSymbolAttachments(purposes, symbols);
}

bool
MatrixOpSymbol::downCoeff(DagNode* dagNode, int& value)
{
  if (dagNode->symbol() == getMinusSymbol())
    {
      dagNode = safeCast(FreeDagNode*, dagNode)->getArgument(0);
      if (getSuccSymbol()->getSignedInt(dagNode, value))
	{
	  value = -value;
	  return true;
	}
      return false;
    }
  return getSuccSymbol()->getSignedInt(dagNode, value);
}

bool
MatrixOpSymbol::downMatrixEntry(DagNode* dagNode, SparseMatrix& matrix, int& maxRowNr, int& maxColNr)
{
  if (dagNode->symbol() == matrixEntrySymbol)
    {
      FreeDagNode* d = safeCast(FreeDagNode*, dagNode);
      int value;
      if (downCoeff(d->getArgument(1), value))
	{
	  DagNode* arg = d->getArgument(0);
	  if (arg->symbol() == indexPairSymbol)
	    {
	      FreeDagNode* a = safeCast(FreeDagNode*, arg);
	      int rowNr;
	      int colNr;
	      if (getSuccSymbol()->getSignedInt(a->getArgument(0), rowNr) &&
		  getSuccSymbol()->getSignedInt(a->getArgument(1), colNr))
		{
		  if (rowNr > maxRowNr)
		    maxRowNr = rowNr;
		  if (colNr > maxColNr)
		    maxColNr = colNr;
		  matrix[rowNr][colNr] = value;
		  return true;
		}
	    }
	}
    }
  return false;
}

bool
MatrixOpSymbol::downMatrix(DagNode* dagNode, SparseMatrix& matrix, int& maxRowNr, int& maxColNr)
{
  maxRowNr = 0;
  maxColNr = 0;
  Symbol* s = dagNode->symbol();
  if (s == matrixSymbol)
    {
      for (DagArgumentIterator i(dagNode); i.valid(); i.next())
	{
	  if (!downMatrixEntry(i.argument(), matrix, maxRowNr, maxColNr))
	    {
	      return false;
	    }
	}
    }
  else if (s != emptyMatrixSymbol)
    return downMatrixEntry(dagNode, matrix, maxRowNr, maxColNr);
  return true;
}

bool
MatrixOpSymbol::downVectorEntry(DagNode* dagNode, Vector<int>& vec, int& maxRowNr)
{
  if (dagNode->symbol() == vectorEntrySymbol)
    {
      FreeDagNode* d = safeCast(FreeDagNode*, dagNode);
      int index;
      int value;
      if (getSuccSymbol()->getSignedInt(d->getArgument(0), index) &&
	  downCoeff(d->getArgument(1), value))
	{
	  if (index > maxRowNr)
	    {
	      maxRowNr = index;
	      vec.resize(maxRowNr + 1);
	    }
	  vec[index] = value;
	}
      return true;
    }
  return false;
}

bool
MatrixOpSymbol::downVector(DagNode* dagNode, Vector<int>& vec, int& maxRowNr)
{
  vec.resize(maxRowNr + 1);
  Symbol* s = dagNode->symbol();
  if (s == vectorSymbol)
    {
      for (DagArgumentIterator i(dagNode); i.valid(); i.next())
	{
	  if (!downVectorEntry(i.argument(), vec, maxRowNr))
	    return false;
	}
    }
  else if (s != emptyVectorSymbol)
    return downVectorEntry(dagNode, vec, maxRowNr);
  return true;
}

DagNode*
MatrixOpSymbol::upSet(const Vector<DagNode*>& elts)
{
  int n = elts.size();
  if (n == 0)
    return emptyVectorSetSymbol->makeDagNode();
  else if (n == 1)
    return elts[0];
  else
    return vectorSetSymbol->makeDagNode(elts);
}

DagNode*
MatrixOpSymbol::upVector(const Vector<int>& row)
{
  Vector<DagNode*> elts;
  Vector<DagNode*> pair(2);
  int c = 0;
  int n = row.size();
  for (int i = 1; i < n; i++)
    {
      int v = row[i];
      Assert(v >= 0, "-ve solution");
      if (v > 0)
	{
	  pair[0] = getSuccSymbol()->makeNatDag(c);
	  pair[1] = getSuccSymbol()->makeNatDag(v);
	  elts.append(vectorEntrySymbol->makeDagNode(pair));
	}
      ++c;
    }

  n = elts.size();
  if (n == 0)
    return emptyVectorSymbol->makeDagNode();
  else if (n == 1)
    return elts[0];
  else
    return vectorSymbol->makeDagNode(elts);
}

bool
MatrixOpSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  FreeDagNode* d = safeCast(FreeDagNode*, subject);
  DagNode* m = d->getArgument(0);
  m->reduce(context);
  DagNode* v = d->getArgument(1);
  v->reduce(context);

  SparseMatrix matrix;
  Vector<int> vec;

  int maxRowNr;
  int maxColNr;
  if (downMatrix(m, matrix, maxRowNr, maxColNr) && downVector(v, vec, maxRowNr))
    {
      //cerr << "maxRowNr " << maxRowNr << "maxColNr " << maxColNr << endl;
      //
      //	Build Diophantine system.
      //
      DiophantineSystem3 ds;
      int rowSize = maxColNr + 2;
      DiophantineSystem3::IntVec row(rowSize);
      for (int i = 0; i <= maxRowNr; i++)
	{
	  for (int j = 1; j < rowSize; j++)
	    row[j] = 0;

	  int v = vec[i];
	  SparseVector& r = matrix[i];
	  if (r.empty() && v != 0)
	    goto fail;

	  row[0] = -v;
	  FOR_EACH_CONST(j, SparseVector, r)
	    row[j->first + 1] = j->second;
	  ds.insertEqn(row);
	  //cerr << "inserted ";
	  //copy(row.begin(), row.end(), ostream_iterator<int>(cerr, " "));
	  //cerr << endl;
	}
      for (int j = 1; j < rowSize; j++)
	row[j] = UNBOUNDED;
      row[0] = 1;
      ds.setUpperBounds(row);
      //cerr << "bounds ";
      //copy(row.begin(), row.end(), ostream_iterator<int>(cerr, " "));
      //cerr << endl;
     
      if (ds.findNextMinimalSolution(row))
	{
	  Vector<DagNode*> homogenous;
	  Vector<DagNode*> inhomogenous;
	  do
	    {
	      //cerr << "got ";
	      //copy(row.begin(), row.end(), ostream_iterator<int>(cerr, " "));
	      //cerr << endl;
	      if (row[0] == 0);
		//homogenous.append(upVector(row));
	      else;
		//inhomogenous.append(upVector(row));
	    }
	  while (ds.findNextMinimalSolution(row));
	  if (!inhomogenous.empty())
	    {
	      Vector<DagNode*> args(2);
	      args[0] = upSet(inhomogenous);
	      args[1] = upSet(homogenous);
	      //cerr << args[0] << " " << args[1] << endl;
	      return context.builtInReplace(subject, vectorSetPairSymbol->makeDagNode(args));
	    }
	}
    fail:
      Vector<DagNode*> args;
      args.append(emptyVectorSetSymbol->makeDagNode());
      args.append(emptyVectorSetSymbol->makeDagNode());
      return context.builtInReplace(subject, vectorSetPairSymbol->makeDagNode(args));
    }
  //
  //	NumberOpSymbol doesn't know how to deal with this.
  //
  return FreeSymbol::eqRewrite(subject, context);
}
