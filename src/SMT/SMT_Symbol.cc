/*

    This file is part of the Maude 2 interpreter.

    Copyright 2014 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for class SMT_Symbol.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "variable.hh"
#include "SMT.hh"

//      interface class definitions
#include "term.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "symbolMap.hh"

//      variable class definitions
#include "variableSymbol.hh"
#include "variableDagNode.hh"

//      free theory class definitions
#include "freeDagNode.hh"

//      built in stuff
#include "bindingMacros.hh"

//	SMT stuff
#include "SMT_Symbol.hh"
#include "SMT_NumberSymbol.hh"
#include "SMT_NumberDagNode.hh"


SMT_Symbol::SMT_Symbol(int id, int arity)
  : FreeSymbol(id, arity)
{
  op = NONE;
}

bool
SMT_Symbol::attachData(const Vector<Sort*>& opDeclaration,
		       const char* purpose,
		       const Vector<const char*>& data)
{
  BIND_OP3(purpose, SMT_Symbol, op, data);
  return FreeSymbol::attachData(opDeclaration, purpose, data);
}

void
SMT_Symbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  SMT_Symbol* orig = safeCast(SMT_Symbol*, original);
  op = orig->op;
  FreeSymbol::copyAttachments(original, map);
}

void
SMT_Symbol::getDataAttachments(const Vector<Sort*>& opDeclaration,
			       Vector<const char*>& purposes,
			       Vector<Vector<const char*> >& data)
{
  if (op != NONE)
    {
      int nrDataAttachments = purposes.length();
      purposes.resize(nrDataAttachments + 1);
      purposes[nrDataAttachments] = "SMT_Symbol";
      data.resize(nrDataAttachments + 1);
      data[nrDataAttachments].resize(1);
      const char*& d = data[nrDataAttachments][0];
      switch (op)
	{
	  CODE_CASE3(d, 't', 'r', 'u', "true");
	  CODE_CASE3(d, 'f', 'a', 'l', "false");
	  CODE_CASE3(d, 'n', 'o', 't', "not");
	  CODE_CASE3(d, 'a', 'n', 'd', "and");
	  CODE_CASE(d, 'o', 'r', "or");
	  CODE_CASE3(d, 'x', 'o', 'r', "xor");
	  CODE_CASE3(d, 'i', 'm', 'p', "implies");

	  CODE_CASE(d, '=', 0, "=");
	  CODE_CASE(d, '!', '=', "!=");
	  CODE_CASE3(d, 'i', 't', 'e', "ite");

	  CODE_CASE3(d, 'i', 'n', 't', "integers");
	  CODE_CASE(d, '-', 0, "-");
	  CODE_CASE(d, '+', 0, "+");
	  CODE_CASE(d, '*', 0, "*");

	  CODE_CASE3(d, 'm', 'o', 'd', "mod");
	  CODE_CASE(d, '<', 0, "<");
	  CODE_CASE(d, '<', '=', "<=");
	  CODE_CASE(d, '>', 0, ">");
	  CODE_CASE(d, '>', '=', ">=");

	  CODE_CASE3(d, 'r', 'e', 'a', "reals");
	  CODE_CASE(d, '/', 0, "/");
	  CODE_CASE3(d, 't', 'o', 'R', "toReal");
	  CODE_CASE3(d, 't', 'o', 'I', "toInteger");
	  CODE_CASE3(d, 'i', 's', 'I', "isInteger");

	  case CODE3('d', 'i', 'v'):
	    {
	      if (rangeComponent() == domainComponent(0))
		{
		  //
		  //	Must be div operator.
		  //
		  d = "div";
		  break;
		}
	      else
		{
		  //
		  //	Must be divisible operator.
		  //
		  d = "divisible";
		  break;
		}
	    }
	  default:
	    CantHappen("bad SMT op");
	}
    }
  FreeSymbol::getDataAttachments(opDeclaration, purposes, data);
}

void
SMT_Symbol::fillOutSortMap(SortIndexToSMT_TypeMap& sortMap)
{
  //
  //	If we are the construction operator for some SMT type, fill out that information.
  //
  switch (op)
    {
    case CODE3('t', 'r', 'u'):
    case CODE3('f', 'a', 'l'):
      {
	Sort* rangeSort = getRangeSort();
	sortMap[rangeSort->getIndexWithinModule()] = BOOLEAN;
	break;
      }
    //
    //	HACK: these cases will go away once we have a NA_Theory based class for Integers and Reals.
    //
    /*
    case CODE3('i', 'n', 't'):
      {
	Sort* rangeSort = getOpDeclarations()[0].getDomainAndRange()[0];
	sortMap[rangeSort->getIndexWithinModule()] = INTEGER;
	break;
      }
    case CODE3('r', 'e', 'a'):
      {
	Sort* rangeSort = getOpDeclarations()[0].getDomainAndRange()[0];
	sortMap[rangeSort->getIndexWithinModule()] = REAL;
	break;
      }
    */
    default:
      break;
    }
}

Expr
SMT_Symbol::makeRationalConstant(const mpq_class& rational, ExprManager& em)
{
  //
  //	We would like to do:
  //	  return em.mkConst(Rational(rational));
  //	but CVC4 makes the required constructor private thus we have this ugliness.
  //
  string ratStr = rational.get_str();
  return em.mkConst(Rational(ratStr.c_str()));
}

Expr
SMT_Symbol::dagToCVC4(DagNode* dag, const Vector<Expr>& variables, SortIndexToSMT_TypeMap& sortMap, ExprManager& em)
{
  int nrArgs = arity();
  Vector<Expr> exprs(nrArgs);
  FreeDagNode* f = safeCast(FreeDagNode*, dag);
  //
  //	Arguments must be variables of SMT sort, or SMT dags, or SMT numbers.
  for (int i = 0; i < nrArgs; ++i)
    {
      DagNode* a = f->getArgument(i);
      if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(a))
	{
	  exprs[i] = variables[v->getIndex()];
	}
      else if (SMT_Symbol* s = dynamic_cast<SMT_Symbol*>(a->symbol()))
	{
	  exprs[i] = s->dagToCVC4(a, variables, sortMap, em);
	}
      else if (SMT_NumberDagNode* n = dynamic_cast<SMT_NumberDagNode*>(a))
	{
	  //
	  //	CVC4 can't actually make integer constants so we have to
	  //	use rationals for all numeric constants.
	  //
	  exprs[i] = makeRationalConstant(n->getValue(), em);
	}
      else
	{
	  IssueWarning("subterm " << QUOTE(a) << " is not headed by an SMT operator.");
	  return Expr();  // null expression
	}
    }

  switch (op)
    {
    case CODE3('t', 'r', 'u'):
      {
	return em.mkConst(true);
      }
    case CODE3('f', 'a', 'l'):
      {
	return em.mkConst(false);
      }
    case CODE3('n', 'o', 't'):
      {
	return em.mkExpr(kind::NOT, exprs[0]);
      }
    case CODE3('a', 'n', 'd'):
      {
	return em.mkExpr(kind::AND, exprs[0], exprs[1]);
      }
    case CODE('o', 'r'):
      {
	return em.mkExpr(kind::OR, exprs[0], exprs[1]);
      }
    case CODE3('x', 'o', 'r'):
      {
	return em.mkExpr(kind::XOR, exprs[0], exprs[1]);
      }
    case CODE3('i', 'm', 'p'):
      {
	return em.mkExpr(kind::IMPLIES, exprs[0], exprs[1]);
      }
      //
      //	CVC4 does not distinguish between integer and real versions of many arithmetic operators.
      //
    case '-':
      {
	return (nrArgs == 1) ?
	  em.mkExpr(kind::UMINUS, exprs[0]) :
	  em.mkExpr(kind::MINUS, exprs[0], exprs[1]);
      }
    case '+':
      {
	return em.mkExpr(kind::PLUS, exprs[0], exprs[1]);
      }
    case '*':
      {
	return em.mkExpr(kind::MULT, exprs[0], exprs[1]);
      }
    case '<':
      {
	return em.mkExpr(kind::LT, exprs[0], exprs[1]);
      }
    case CODE('<', '='):
      {
	return em.mkExpr(kind::LEQ, exprs[0], exprs[1]);
      }
    case '>':
      {
	return em.mkExpr(kind::GT, exprs[0], exprs[1]);
      }
    case CODE('>', '='):
      {
	return em.mkExpr(kind::GEQ, exprs[0], exprs[1]);
      }
      //
      //	Bizarrely CVC4 requires the IFF be used for Boolean equality so we need to
      //	check the SMT type associated with our first argument sort to catch this case.
      //
    case '=':
      {
	int domainSortIndex = getOpDeclarations()[0].getDomainAndRange()[0]->getIndexWithinModule();
	SMT_Base::SortIndexToSMT_TypeMap::const_iterator j = sortMap.find(domainSortIndex);
	if (j == sortMap.end())
	  {
	    IssueWarning("term " << QUOTE(dag) << " does not belong to an SMT sort.");
	    goto fail;
	  }
	return em.mkExpr((j->second == BOOLEAN ? kind::IFF : kind::EQUAL), exprs[0], exprs[1]);
      }
      //
      //	CVC4 does not distinguish between Boolean, integer and real versions for these operators.
      //
    case CODE('!', '='):
      {
	return em.mkExpr(kind::DISTINCT, exprs[0], exprs[1]);
      }
    case CODE3('i', 't', 'e'):
      {
	return em.mkExpr(kind::ITE, exprs[0], exprs[1], exprs[2]);
      }
      //
      //	Integer only operations.
      //
    case CODE3('d', 'i', 'v'):
      {
	return em.mkExpr(((rangeComponent() == domainComponent(0)) ? kind::INTS_DIVISION : kind::DIVISIBLE), exprs[0], exprs[1]);
      }
    case CODE3('m', 'o', 'd'):
      {
	return em.mkExpr(kind::INTS_MODULUS, exprs[0], exprs[1]);
      }
      //
      //	Real only operation.
      //
    case '/':
      {
	return em.mkExpr(kind::DIVISION, exprs[0], exprs[1]);
      }
      //
      //	Integer <-> Real conversion.
      //
    case CODE3('t', 'o', 'R'):
      {
	return em.mkExpr(kind::TO_REAL, exprs[0]);
      }
    case CODE3('t', 'o', 'I'):
      {
	return em.mkExpr(kind::TO_INTEGER, exprs[0]);
      }
    case CODE3('i', 's', 'I'):
      {
	return em.mkExpr(kind::IS_INTEGER, exprs[0]);
      }
    }

  CantHappen("bad SMT op");
 fail:
  return Expr();
}
