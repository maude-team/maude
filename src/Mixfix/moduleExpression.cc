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
//      Implementation for class ModuleExpression.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "mixfix.hh"

//	front end class definitions
#include "token.hh"
#include "moduleExpression.hh"

ModuleExpression::ModuleExpression(int moduleName)
 : type(MODULE),
   moduleName(moduleName)
{
}

ModuleExpression::ModuleExpression(ModuleExpression* left, ModuleExpression* right)
 : type(SUMMATION)
{
  // should we flatten summations?
  modules.append(left);
  modules.append(right);
}

ModuleExpression::ModuleExpression(ModuleExpression* module, Renaming* renaming)
 : type(RENAMING),
   module(module),
   renaming(renaming)
{
}

ostream&
operator<<(ostream& s, const ModuleExpression* expr)
{
  switch (expr->getType())
    {
    case ModuleExpression::MODULE:
      {
	cout << Token::name(expr->getModuleName());
	break;
      }
    default:
      CantHappen("not implemented");
    }
  return s;
}

