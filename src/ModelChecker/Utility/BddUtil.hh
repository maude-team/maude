/*
 * BddUtil.hh
 *
 *  Created on: Sep 14, 2013
 *      Author: kquine
 */

#ifndef BDDUTIL_HH_
#define BDDUTIL_HH_
#include "bdd.hh"

namespace modelChecker {

class BddUtil
{
public:
	static bool satisfiesFormula(Bdd formula, const std::function<bool(unsigned int)>& truth)
	{
	    for(;;)
	    {
	        if (formula == bdd_true())
	        	return true;
	        else if (formula == bdd_false())
	            return false;
	        else
	        {
				auto propId = bdd_var(formula);
				formula = truth(propId) ? bdd_high(formula) : bdd_low(formula);
	        }
	    }
	}

	static pair<bool,Bdd> satisfiesPartialFormula(Bdd formula,
			const std::function<bool(unsigned int)>& domain, const std::function<bool(unsigned int)>& truth)
	{
	    for(;;)
	    {
	        if (formula == bdd_true())
	        	return make_pair(true, bdd_true());
	        else if (formula == bdd_false())
	            return make_pair(false, bdd_false());
	        else
	        {
				auto propId = bdd_var(formula);
				if (domain(propId))
					formula = truth(propId) ? bdd_high(formula) : bdd_low(formula);
				else
					return make_pair(true, formula);
	        }
	    }
	}
};

} /* namespace modelChecker */
#endif /* BDDUTIL_HH_ */
