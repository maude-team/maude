/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2014 SRI International, Menlo Park, CA 94025, USA.

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
//      Abstract base class for symbols that carry SMT information.
//
#ifndef _SMT_Base_hh_
#define _SMT_Base_hh_
#include <map>

class SMT_Base
{
public:
  enum SMT_Type
    {
      BOOLEAN,
      INTEGER,
      REAL
    };

  typedef map<int, int> SortIndexToSMT_TypeMap;
  //
  //	We need to know how Maude sorts map to SMT types, and this information
  //	is implicity encoded in the SMT operators declarations so we have a function to
  //	a function to collect it.
  //
  virtual void fillOutSortMap(SortIndexToSMT_TypeMap& sortMap) = 0;
};

#endif
