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
//      Implementation for class Entity.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "mixfix.hh"

//	front end class definitions
#include "importModule.hh"
#include "entity.hh"

void
Entity::addUser(User* user)
{
  pair<UserSet::iterator, bool> p = users.insert(user);
  if (!p.second)
    DebugAdvisory("already added user");
}

void
Entity::removeUser(User* user)
{
#ifndef NO_ASSERT
  if (ImportModule* m = dynamic_cast<ImportModule*>(user))
    {
      if (ImportModule* us = dynamic_cast<ImportModule*>(this))
	DebugAdvisory("removed module " << m << " from user set for module " << us);
      else
	DebugAdvisory("removed module " << m << " from user set");
    }
  else
    DebugAdvisory("removed unknown user from user set");
#endif
  if (users.erase(user) != 1)
    DebugAdvisory("missing user");
}

void
Entity::informUsers()
{
  //
  //	We need to be careful since informing a user will often cause the user
  //	and/or other users to be removed, invalidating iterators.
  //
  const UserSet::const_iterator e = users.end();
  for (;;)
    {
      UserSet::iterator i = users.begin();
      if (i == e)
	return;
      for (;;)
	{
	  User* u = *i;
	  u->regretToInform(this);  // invalidates i
	  i = users.begin();
	  if (i == e)
	    return;
	  if (*i == u)
	    break;
	}
      users.erase(i);
    } 
}
