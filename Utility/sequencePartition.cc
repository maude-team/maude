//
//      Implementation for class SequencePartition
//
#ifdef __GNUG__
#pragma implementation
#endif
 
#include "macros.hh"
#include "vector.hh"
#include "sequencePartition.hh"
 
SequencePartition::SequencePartition(int sequenceLength, int estNrParts)
  : sequenceLength(sequenceLength), parts(0, estNrParts)
{
  minSum = 0;
  maxSum = 0;
  closed = false;
  failed = false;
}

void
SequencePartition::insertPart(int minLength, int maxLength)
{
  Assert(!closed, cerr << "system closed");
  Assert(minLength >= 0, cerr << "minLength < 0");
  Assert(minLength <= maxLength, cerr << "minLength > maxLength");
  int nrParts = parts.length();
  parts.expandBy(1);
  Part& p = parts[nrParts];
  p.minLength = minLength;
  p.maxLength = maxLength;
  p.sumPrevMin = minSum;
  p.sumPrevMax = maxSum;
  minSum += minLength;
  maxSum = uplus(maxSum, maxLength);
}

bool
SequencePartition::solve()
{
  bool findFirst = !closed;
  if (findFirst)
    {
      Assert(parts.length() > 0, cerr << "no parts");
      closed = true;
      if (sequenceLength < minSum || sequenceLength > maxSum)
	{
	  failed = true;
	  return false;
	}
    }
  return mainSolve(findFirst);
}

bool
SequencePartition::mainSolve(bool findFirst)
{
  int nrParts = parts.length();
  int i = nrParts;
  int nextStart = sequenceLength;

  if (!findFirst)
    {
      //
      //	Try to find a next solution by finding the leftmost start that
      //	could legally be moved rightward and incrementing it.
      //
      for (i = 0; i < nrParts; i++)
	{
	  Part& p = parts[i];
	  if (p.start < p.sumPrevMax)
	    {
	      nextStart = (i == nrParts - 1) ? sequenceLength : parts[i + 1].start;
	      if (p.start + p.minLength < nextStart)
		{
		  nextStart = ++p.start;
		  goto finishPartition;
		}
	    }
	}
      failed = true;
      return false;
    }
finishPartition:
  //
  //	Finish the partition by moving starts of parts 0,...,i-1 to their leftmost
  //	legal positions.
  //
  for (i--; i >= 0; i--)
    {
      Part& p = parts[i];
      int start = p.sumPrevMin;  // leftMost start that leaves enough for previous parts
      if (nextStart - start > p.maxLength)
	start = nextStart - p.maxLength;	// move right to respect our max length
      Assert(nextStart - start >= p.minLength, cerr << "not enough for part " << i);
      Assert(start <= p.sumPrevMax, cerr << "too much for parts preceeding " << i);
      p.start = start;
      nextStart = start;
    }
  return true;
}

