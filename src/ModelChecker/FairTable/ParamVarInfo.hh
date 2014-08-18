/*
 * ParamVarInfo.hh
 *
 *  Created on: Sep 3, 2013
 *      Author: kquine
 */

#ifndef PARAMVARINFO_HH_
#define PARAMVARINFO_HH_
#include "variableDagNode.hh"
#include "Utility/indexedSet.hh"

namespace modelChecker {

/**
 * Since we do not need to actually instantiate a term, we define a data structure to
 * manage variable info for s param fair formula, instead of using the existing one.
 */
class ParamVarInfo
{
public:
	ParamVarInfo(DagNode* dag);

	unsigned int getNrVariables() const;
	unsigned int variable2Index(VariableDagNode* variableDag) const;
	unsigned int variable2Index(Term* variableTerm) const;
	VariableDagNode* index2Variable(unsigned int index) const;

private:
	void indexVariables(DagNode* dag);	// it's supposed to be called after TermUtil::checkGround.

	indexed_set<VariableDagNode*> variables;
};

} /* namespace modelChecker */
#endif /* PARAMVARINFO_HH_ */
