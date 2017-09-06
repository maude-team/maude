/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2012 SRI International, Menlo Park, CA 94025, USA.

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
//	Class to search for a complete set of variants from a given term.
//
#ifndef _variantSearch_hh_
#define _variantSearch_hh_
#include <map>
#include "cacheableState.hh"
#include "simpleRootContainer.hh"
#include "narrowingVariableInfo.hh"
#include "variantFolder.hh"

class VariantSearch : public CacheableState, private SimpleRootContainer
{
  NO_COPYING(VariantSearch);

public:
  VariantSearch(RewritingContext* context, FreshVariableGenerator* freshVariableGenerator);
  ~VariantSearch();

  const NarrowingVariableInfo& getVariableInfo() const;
  const Vector<DagNode*>* getNextVariant(int& nrFreeVariables);
  RewritingContext* getContext();

private:
  typedef set<int> VariantIndexSet;

  void expand(const Vector<DagNode*>& variant, int index, bool odd);
  void dumpVariant(const Vector<DagNode*>& variant, int index,  int parentIndex);

  void markReachableNodes();

  RewritingContext* const context;
  FreshVariableGenerator* const freshVariableGenerator;

  NarrowingVariableInfo variableInfo;
  VariantFolder variantCollection;

  VariantIndexSet frontier;
  VariantIndexSet newFrontier;
  int currentIndex;

  Vector<DagNode*> protectedVariant;
};

inline const NarrowingVariableInfo&
VariantSearch::getVariableInfo() const
{
  return variableInfo;
}

inline const Vector<DagNode*>*
VariantSearch::getNextVariant(int& nrFreeVariables)
{
  return context->traceAbort() ? 0 : variantCollection.getNextSurvivingVariant(nrFreeVariables);
}

inline RewritingContext*
VariantSearch::getContext()
{
  return context;
}

#endif
