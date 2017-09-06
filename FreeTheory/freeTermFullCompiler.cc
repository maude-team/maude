//
//	Code to help with full compilation of free terms
//
#include "freePositionTable.hh"
#include "freeSubterm.hh"

bool
FreeTerm::scanFreeSkeleton(const NatSet& usedVariables,
			   Vector<int>& path,
			   FreePositionTable& positions,
			   NatSet& boundVariables,
			   Vector<FreeSubterm>& subterms)
{
  bool unfailing = true;
  int last = path.length();
  path.expandBy(1);
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    {
      path[last] = i;
      Term* t = argArray[i];
      if (FreeTerm* f = dynamic_cast<FreeTerm*>(t))
	{
	  if (!(f->scanFreeSkeleton(usedVariables, path, positions, boundVariables, subterms)))
	    unfailing = false;
	}
      else
	{
	  int posIndex = positions.position2Index(path);
	  if (VariableTerm* v = dynamic_cast<VariableTerm*>(t))
	    {
	      int varIndex = v->getIndex();
	      if (boundVariables.contains(varIndex))
		{
		  unfailing = false;
		  subterms.append(FreeSubterm(FreeSubterm::BOUND_VARIABLE, posIndex));
		}
	      else
		{
		  boundVariables.insert(varIndex);
		  int efm = v->getSort()->errorFreeMaximal();
		  if (!efm)
		    unfailing = false;
		  if (!efm ||
		      usedVariables.contains(varIndex) ||
		      t->occursInContext().contains(varIndex))
		    subterms.append(FreeSubterm(FreeSubterm::FREE_VARIABLE, posIndex));
		}  
	    }
	  else
	    {
	      unfailing = false;
	      if (t->ground())
		subterms.append(FreeSubterm(FreeSubterm::GROUND_ALIEN, posIndex));
	      else
		subterms.append(FreeSubterm(FreeSubterm::NON_GROUND_ALIEN, posIndex));
	    }
	}
    }
  path.contractTo(last);
  return unfailing;
}
