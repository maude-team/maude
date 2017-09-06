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
//      Class for views.
//
#ifndef _view_hh_
#define _view_hh_
#include "namedEntity.hh"
#include "lineNumber.hh"
#include "entity.hh"
#include "renaming.hh"

class View
  : public NamedEntity,
    public LineNumber,
    public Entity::User,
    public Renaming
{
public:
  View(Token viewName);
  ~View();
  void addFrom(ModuleExpression* expr);
  void addTo(ModuleExpression* expr);
  void finishView();
  bool evaluate();
  bool isComplete();
  void showView(ostream& s);
  ImportModule* getFromTheory() const;
  ImportModule* getToModule() const;

private:
  enum Status
    {
      INITIAL,
      GOOD,
      BAD,
      UNKNOWN
    };

  void regretToInform(Entity* doomedEntity);

  Status status;
  ModuleExpression* fromExpr;
  ModuleExpression* toExpr;
  ImportModule* fromTheory;
  ImportModule* toModule;
};

inline void
View::addFrom(ModuleExpression* expr)
{
  fromExpr = expr;
}

inline void
View::addTo(ModuleExpression* expr)
{
  toExpr = expr;
}

inline bool
View::isComplete()
{
  return status != INITIAL;
}

inline ImportModule*
View::getFromTheory() const
{
  Assert(status == GOOD, "view status not good");
  return fromTheory;
}

inline ImportModule*
View::getToModule() const
{
  Assert(status == GOOD, "view status not good");
  return toModule;
}

#endif
