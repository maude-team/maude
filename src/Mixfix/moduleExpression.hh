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
//      Class for module expressions.
//
#ifndef _moduleExpression_hh_
#define _moduleExpression_hh_

class ModuleExpression
{
public:
  enum Type
  {
    MODULE,
    SUMMATION,
    RENAMING
  };

  ModuleExpression(int moduleName);
  ModuleExpression(ModuleExpression* left, ModuleExpression* right);
  ModuleExpression(ModuleExpression* module, Renaming* renaming);

  Type getType() const;
  int getModuleName() const;
  const Vector<ModuleExpression*>& getModules() const;
  ModuleExpression* getModule() const;
  Renaming* getRenaming() const;

private:
  const Type type;
  //
  //	For named module.
  //
  int moduleName;
  //
  //	For summation.
  //
  Vector<ModuleExpression*> modules;
  //
  //	For renaming.
  //
  ModuleExpression* module;
  Renaming* renaming;
};

ostream& operator<<(ostream& s, const ModuleExpression* expr);

inline ModuleExpression::Type
ModuleExpression::getType() const
{
  return type;
}

inline int
ModuleExpression::getModuleName() const
{
  Assert(type == MODULE, "not a named module");
  return moduleName;
}

inline const Vector<ModuleExpression*>&
ModuleExpression::getModules() const
{
  Assert(type == SUMMATION, "not a summation");
  return modules;
}

inline ModuleExpression*
ModuleExpression::getModule() const
{
  Assert(type == RENAMING, "not a renaming");
  return module;
}

inline Renaming*
ModuleExpression::getRenaming() const
{
  Assert(type == RENAMING, "not a renaming");
  return renaming;
}

#endif
