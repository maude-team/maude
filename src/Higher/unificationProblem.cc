/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2006 SRI International, Menlo Park, CA 94025, USA.

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
//	Implementation for class UnificationProblem.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "allSat.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "subproblem.hh"

//	variable class definitions
#include "variableDagNode.hh"

//	core class definitions
#include "module.hh"
#include "sortBdds.hh"
#include "connectedComponent.hh"
//#include "rewritingContext.hh"
#include "unificationContext.hh"
#include "freshVariableGenerator.hh"
#include "unificationProblem.hh"

UnificationProblem::UnificationProblem(Term* lhs, Term* rhs, FreshVariableGenerator* freshVariableGenerator)
  : lhs(lhs),
    rhs(rhs),
    freshVariableGenerator(freshVariableGenerator)
{
  sortBdds = lhs->symbol()->getModule()->getSortBdds();
  //
  //	Preprocess terms and create corresponding dags.
  //
  lhs = lhs->normalize(true);
  lhs->indexVariables(*this);
  lhsDag = lhs->term2Dag();
  lhsDag->computeBaseSortForGroundSubterms();

  rhs = rhs->normalize(true);
  rhs->indexVariables(*this);
  rhsDag = rhs->term2Dag();
  rhsDag->computeBaseSortForGroundSubterms();
  //
  //	Solve the underlying many-sorted unification problem, and if it has a
  //	solution, calculate sorts of free variables, and check sorts of assignments.
  //
  orderSortedUnifiers = 0;
  int nrOriginalVariables = getNrProtectedVariables();
  //Substitution::notify(nrVariables);
  sortedSolution = new Substitution(nrOriginalVariables);
  unsortedSolution = new UnificationContext(freshVariableGenerator, nrOriginalVariables);
  for (int i = 0; i < nrOriginalVariables; ++i)
    {
      sortedSolution->bind(i, 0);  // so GC doesn't barf
      unsortedSolution->bind(i, 0);  // HACK
    }
  //unsortedSolution->clear(nrOriginalVariables);  // unsafe!
  //  cout << "=== computing solved form ===" << endl;
  //
  //	computeSolvedForm() only sets subproblem on success; so if we don't clear it
  //	here we will attempt to free a random location in our dtor following a failure.
  //
  subproblem = 0;
  viable = lhsDag->computeSolvedForm(rhsDag, *unsortedSolution, subproblem);
  /*
  int nrRealVariables = getNrProtectedVariables();
  for (int i = 0; i < nrRealVariables; ++i)
    {
      cout << index2Variable(i) << " =? ";
      if (unsortedSolution->value(i) == 0)
	cout << "(null)" << endl;
      else
	cout << unsortedSolution->value(i) << endl;
    }
  cout << "=== end of solved form ===" << endl;
  */
}

UnificationProblem::~UnificationProblem()
{
  delete subproblem;
  delete orderSortedUnifiers;
  delete freshVariableGenerator;
  delete unsortedSolution;
  delete sortedSolution;
  //
  //	Only now can we safely destruct these as they are needed by VariableInfo.
  //
  rhs->deepSelfDestruct();
  lhs->deepSelfDestruct();
}

void
UnificationProblem::markReachableNodes()
{
  lhsDag->mark();
  rhsDag->mark();
  {
    int nrFragile = sortedSolution->nrFragileBindings();
    for (int i = 0; i < nrFragile; i++)
      {
	DagNode* d = sortedSolution->value(i);
	if (d != 0)
	  d->mark();
      }
  }
  {
    int nrFragile = unsortedSolution->nrFragileBindings();
    for (int i = 0; i < nrFragile; i++)
      {
	DagNode* d = unsortedSolution->value(i);
	if (d != 0)
	  d->mark();
      }
  }
}

bool
UnificationProblem::findNextUnifier()
{
  if (!viable)
    return false;
  if (orderSortedUnifiers == 0)
    {
      //
      //	First solution.
      //
      if (subproblem != 0 && !(subproblem->unificationSolve(true, *unsortedSolution)))
	return false;
      //cerr << "first unsorted solution";
      //cout << "=== final solved form ===" << endl;
      //int nrRealVariables = getNrProtectedVariables();
      /*
      cout << "total variables = " << unsortedSolution->nrFragileBindings() << endl;
      for (int i = 0; i < nrRealVariables; ++i)
	{
	  cout << index2Variable(i) << " =? ";
	  if (unsortedSolution->value(i) == 0)
	    cout << "(null)" << endl;
	  else
	    cout << unsortedSolution->value(i) << endl;
	}
      cout << "=== end of solved form ===" << endl;
      */
      if (!extractUnifier())
	goto nextUnsorted;
      findOrderSortedUnifiers();
      if (orderSortedUnifiers == 0)
	goto nextUnsorted;
      bool t = orderSortedUnifiers->nextAssignment();
      Assert(t, "no first order sorted unifier");
    }
  else
    {
      //
      //	Try to find another way of assigning sorts to current solution.
      //
      if (!(orderSortedUnifiers->nextAssignment()))
	{
	  delete orderSortedUnifiers;
	  orderSortedUnifiers = 0;
	nextUnsorted:
	  if (subproblem == 0 || !(subproblem->unificationSolve(false, *unsortedSolution)))
	    return false;
	  //cerr << "next unsorted solution";
	  if (!extractUnifier())
	    goto nextUnsorted;
	  //freshVariableGenerator->reset();
	  findOrderSortedUnifiers();
	  if (orderSortedUnifiers == 0)
	    goto nextUnsorted;
	  bool t = orderSortedUnifiers->nextAssignment();
	  Assert(t, "no first order sorted unifier");
	}
    }

  const Vector<Byte>& assignment = orderSortedUnifiers->getCurrentAssignment();
  int bddVar = sortBdds->getFirstAvailableVariable();
  FOR_EACH_CONST(i, Vector<int>, freeVariables)
    {
      DagNode* variable = sortedSolution->value(*i);
      ConnectedComponent* component = variable->symbol()->rangeComponent();
      //
      //	Compute the index of the new sort for this variable from the
      //	value of the BDD variables in the current satisfying assignment.
      //
      int nrBddVariables = sortBdds->getNrVariables(component->getIndexWithinModule());
      int index = 0;
      for (int j = nrBddVariables - 1; j >= 0; --j)
	{
	  index <<= 1;
	  if (assignment[bddVar + j])
	    ++index;
	}
      bddVar += nrBddVariables;
      //
      //	Replace each variable symbol in a free variable with the
      //	variable symbol corresponding to its newly calculated sort.
      //
      variable->replaceSymbol(freshVariableGenerator->getBaseVariableSymbol(component->sort(index)));
    }
  return true;
}

void
UnificationProblem::findOrderSortedUnifiers()
{
  sortedSolution->clone(*unsortedSolution);
  //
  //	For each free variable allocate a block of BDD variables based on the
  //	size of the connected component of its sort.
  //
  freeVariables.clear();
  int nrActualVariables = sortedSolution->nrFragileBindings();
  Vector<int> realToBdd(nrActualVariables);
  int nextBddVariable = sortBdds->getFirstAvailableVariable();
  int nrOriginalVariables = getNrProtectedVariables();
  for (int i = 0; i < nrActualVariables; ++i)
    {
      if (sortedSolution->value(i) == 0)
	{
	  freeVariables.append(i);
	  realToBdd[i] = nextBddVariable;
	  Sort* sort = (i < nrOriginalVariables) ?
	    safeCast(VariableSymbol*, index2Variable(i)->symbol())->getSort() :
	    unsortedSolution->getFreshVariableSort(i);
	  nextBddVariable += sortBdds->getNrVariables(sort->component()->getIndexWithinModule());
	}
    }
  //
  //	Now compute a BDD which tells us if a given assignment of sorts to free
  //	variables yields an order-sorted unifier.
  //
  Bdd unifier = bddtrue;
  for (int i = 0; i < nrOriginalVariables; ++i)
    {
      bddPair* bitMap = bdd_newpair();
      Sort* sort = safeCast(VariableSymbol*, index2Variable(i)->symbol())->getSort();
      Bdd leqRelation = sortBdds->getLeqRelation(sort->getIndexWithinModule());
      DagNode* d = sortedSolution->value(i);
      if (d != 0)
	{
	  //
	  //	Bound variable: term must have sort <= variables sort.
	  //
	  Vector<Bdd> genSort;
	  d->computeGeneralizedSort(*sortBdds, realToBdd, genSort);	  
	  int nrBdds =  genSort.size();
	  for (int j = 0; j < nrBdds; ++j)
	    bdd_setbddpair(bitMap, j, genSort[j]);
	  leqRelation = bdd_veccompose(leqRelation, bitMap);
	}
      else
	{
	  //
	  //	Free variable: sort assigned to free variable must be <= variables original sort.
	  //
	  int firstVar = realToBdd[i];
	  int nrBdds= sortBdds->getNrVariables(sort->component()->getIndexWithinModule());
	  for (int j = 0; j < nrBdds; ++j)
	    bdd_setpair(bitMap, j, firstVar + j);
	  leqRelation = bdd_replace(leqRelation, bitMap);
	}
      bdd_freepair(bitMap);
      unifier = bdd_and(unifier, leqRelation);
      if (unifier == bddfalse)
	return;
    }
  //
  //	Now compute a BDD that tells us if a unifier has maximal sort assignments to free
  //	variables.
  //
  //	maximal(X1,...,  Xn) = unifier(X1,..., Xn) /\ 
  //	  for each i in 1 ... n
  //	    not(exists Yi .[gt(Yi,Xi) /\ unifier(X1,..., Y1,...., Xn)])
  //
  Bdd maximal = unifier;
  int nrFreeVariables = freeVariables.size();
  int secondBase = sortBdds->getFirstAvailableVariable();
  for (int i = 0; i < nrFreeVariables; ++i)
    {
      int fv = freeVariables[i];
      Sort* sort = (fv < nrOriginalVariables) ?
	safeCast(VariableSymbol*, index2Variable(fv)->symbol())->getSort() :
	unsortedSolution->getFreshVariableSort(fv);
      int nrBddVariables = sortBdds->getNrVariables(sort->component()->getIndexWithinModule());
      //
      //	Replace the bdd variables allocated to the real variable in unifier with 0...nrBddVariables-1.
      //	Replace the bdd variables firstAvail,..., firstAvail+nrBddVariables-1 in gtOp with the
      //	variables allocated to real variable.
      //
      bddPair* realTofirstArg = bdd_newpair();
      bddPair* secondArgToReal = bdd_newpair();
      int firstVar = realToBdd[fv];
      for (int j = 0; j < nrBddVariables; ++j)
	{
	  int bddVariable = firstVar + j;
	  bdd_setpair(realTofirstArg, bddVariable, j);
	  bdd_setpair(secondArgToReal, secondBase + j, bddVariable);
	}
      Bdd gtRelation = sortBdds->getGtRelation(sort->component()->getIndexWithinModule());
      Bdd modifiedGtRelation = bdd_replace(gtRelation, secondArgToReal);
      bdd_freepair(secondArgToReal);
      Bdd modifiedUnifier = bdd_replace(unifier, realTofirstArg);
      bdd_freepair(realTofirstArg);
      maximal = bdd_and(maximal, bdd_appall(modifiedGtRelation, modifiedUnifier, bddop_nand,
					    sortBdds->makeVariableBdd(0, nrBddVariables)));
      Assert(maximal != bddfalse, "maximal false even though unifier isn't");
    }
  orderSortedUnifiers = new AllSat(maximal, secondBase, nextBddVariable - 1);
  if (nrFreeVariables > 0)
    {
      int freshVariableCount = 0;
      //
      //	Finally we bind each free variable to a fresh variable of the appropriate sort and
      //	instantiate all bindings to replace all occurences of the (formerly) free variables.
      //
      for (int i = 0; i < nrActualVariables; ++i)
	{
	  if (sortedSolution->value(i) == 0)
	    {
	      Sort* sort = (i < nrOriginalVariables) ?
		safeCast(VariableSymbol*, index2Variable(i)->symbol())->getSort() :
		unsortedSolution->getFreshVariableSort(i);
	      sortedSolution->bind(i, new VariableDagNode(freshVariableGenerator->getBaseVariableSymbol(sort),
					  freshVariableGenerator->getFreshVariableName(freshVariableCount),
					  i));
	      ++freshVariableCount;
	    }
	}
      for (int i = 0; i < nrOriginalVariables; ++i)
	{
	  if (DagNode* d = sortedSolution->value(i)->instantiate(*sortedSolution))
	    sortedSolution->bind(i, d);
	}
    }
}

bool
UnificationProblem::extractUnifier()
{
  //
  //	We try to extract a unifier from the solved form by first ordering
  //	bound variables by their dependencies and if that can be done, by
  //	instantiating their bindings in that order.
  //
  int nrOriginalVariables = getNrProtectedVariables();
  order.clear();
  done.clear();
  pending.clear();
  for (int i = 0; i < nrOriginalVariables; ++i)
    {
      if (!explore(i))
	return false;
    }
  FOR_EACH_CONST(i, Vector<int>, order)
    {
      //cout << "processing " << *i << endl;
      if (DagNode* d = unsortedSolution->value(*i)->instantiate(*unsortedSolution))
	unsortedSolution->bind(*i, d);
    }
  return true;
}

bool
UnificationProblem::explore(int index)
{
  //
  //	Depth-first exploration of the dependencies of the binding for the
  //	variable with a given index.
  //
  if (done.contains(index))
    return true;
  DagNode* d = unsortedSolution->value(index);
  if (d == 0)
    {
      done.insert(index);
      return true;
    }
  NatSet occurs;
  d->insertVariables(occurs);
  if (!occurs.disjoint(pending))
    return false;  // dependency cycle
   occurs.subtract(done);
   if (!occurs.empty())
     {
       pending.insert(index);
       FOR_EACH_CONST(i, NatSet, occurs)
	 {
	   if (!explore(*i))
	     return false;
	 }
       pending.subtract(index);
     }
   order.append(index);
   done.insert(index);
   return true; 
}
