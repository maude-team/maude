//
//      Implementation for class ConnectedComponent
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"

//      core class definitions
#include "namedEntity.hh"

//      core class definitions
#include "sort.hh"
#include "connectedComponent.hh"
#include "module.hh"

ConnectedComponent::ConnectedComponent(Sort* firstSort)
{
  sortCount = 0;
  errorFreeFlag = true;
  Sort* errorSort = new Sort(firstSort->id());
  firstSort->getModule()->insertSort(errorSort);
  errorSort->registerConnectedSorts(this);
  firstSort->registerConnectedSorts(this);
  nrMaxSorts = sorts.length() - 1;
  if (nrMaxSorts == 0)
    {
      IssueWarning("the connected component in the sort graph that contains sort " <<
		   QUOTE(firstSort) << " has no maximal sorts due to a cycle.");
      firstSort->getModule()->markAsBad();
      return;
    }
  for (int i = 1; i <= nrMaxSorts; i++)
    errorSort->insertSubsort(sorts[i]);
  for (int i = 1; i < sorts.length(); i++)  // sorts.length() may increase
    sorts[i]->processSubsorts();
  if (sorts.length() != sortCount)
    {
      IssueWarning("the connected component in the sort graph that contains sort " <<
		   QUOTE(firstSort) << " could not be linearly ordered due to a cycle.");
      firstSort->getModule()->markAsBad();
      return;
    }
  for (int i = sortCount - 1; i >= 0; i--)
    sorts[i]->computeLeqSorts();
}

ConnectedComponent::~ConnectedComponent()
{
}

bool
ConnectedComponent::leq(int index1, int index2) const
{
  Assert(index1 != Sort::SORT_UNKNOWN, cerr << "bad index1");
  Assert(index2 != Sort::SORT_UNKNOWN, cerr << "bad index2");
  return sorts[index2]->getLeqSorts().contains(index1);
}

void
ConnectedComponent::findMaximalSorts(const NatSet& uSorts, Vector<int>& indices) const
{
  NatSet unionSoFar;
  for (int i = 0; unionSoFar != uSorts; i++)
    {
      Assert(i < sortCount, cerr << "index overrun");
      if (uSorts.contains(i))
        {
          const NatSet& leqSorts = sorts[i]->getLeqSorts();
          if (!(unionSoFar.contains(leqSorts)))
            {
              unionSoFar.insert(leqSorts);
              indices.append(i);
            }
        }
    }
}

int
ConnectedComponent::findIndex(const NatSet& leqSorts) const
{
  int i = leqSorts.min();
  for (; i > 0; i--)
    {
      if (sorts[i]->getLeqSorts().contains(leqSorts))
	break;
    }
  return i;
}

const NatSet&
ConnectedComponent::getLeqSorts(int index) const
{
  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort index");
  return sorts[index]->getLeqSorts();
}

#ifdef DUMP
void
ConnectedComponent::dump(ostream& s)
{
  int nrSorts = sorts.length();
  for (int i = 0; i < nrSorts; i++)
    sorts[i]->dump(s);
}
#endif
