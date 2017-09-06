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
//      Class for symbols representing SMT operators.
//
#ifndef _SMT_Symbol_hh_
#define _SMT_Symbol_hh_
#include "freeSymbol.hh"
#include "SMT_Base.hh"

#include "cvc4/expr/expr_manager.h"

using namespace CVC4;

class SMT_Symbol : public FreeSymbol, public SMT_Base
{
public:
  SMT_Symbol(int id, int arity);
  //
  //	Standard functionality for managing hooks.
  //
  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  void copyAttachments(Symbol* original, SymbolMap* map);
  void getDataAttachments(const Vector<Sort*>& opDeclaration,
			  Vector<const char*>& purposes,
			  Vector<Vector<const char*> >& data);
  //
  //	For SMT_Base.
  //
  void fillOutSortMap(SortIndexToSMT_TypeMap& sortMap);
  //
  //	CVC4 specific.
  //
  Expr dagToCVC4(DagNode* dag, const Vector<Expr>& variables, SortIndexToSMT_TypeMap& sortMap, ExprManager& em);

private:
  static Expr makeRationalConstant(const mpq_class& rational, ExprManager& em);

  int op;
};

#endif
