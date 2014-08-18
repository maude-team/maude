/*
 * ParamSubstitution.cc
 *
 *  Created on: Aug 30, 2013
 *      Author: kquine
 */

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

// core class definitions
#include "variableInfo.hh"
#include "substitution.hh"

// ltlr definitions
#include "ParamSubstitution.hh"

namespace modelChecker {

ParamSubstitution::ParamSubstitution(vector<DagNode*>::size_type size): subst(size,nullptr) {}

ParamSubstitution::ParamSubstitution(const VariableInfo& vi, const Substitution& sb): subst(vi.getNrRealVariables())
{
	for (auto j = 0; j < vi.getNrRealVariables(); ++j)
		subst[j] = sb.value(j);
}

ParamSubstitution::ParamSubstitution(const ParamSubstitution& src,
		const vector<unsigned int>& varMap): subst(varMap.size())
{
	setSubst(src, varMap);
}

bool
ParamSubstitution::isTotal() const
{
	return none_of(subst.begin(), subst.end(), [] (DagNode* d) { return d == nullptr; });
}

bool
ParamSubstitution::isConsistent(const ParamSubstitution& other) const
{
	for (unsigned int j = 0; j < subst.size(); ++j)
		if (subst[j] != other.subst[j] && subst[j] != nullptr && other.subst[j] != nullptr)
			return false;
	return true;
}

const vector<DagNode*>&
ParamSubstitution::getSubst() const
{
	return subst;
}

void
ParamSubstitution::setSubst(const ParamSubstitution& src, const vector<unsigned int>& varMap)
{
	for (unsigned int j = 0; j < varMap.size(); ++j)
		subst[j] = src.subst[varMap[j]];
}

void
ParamSubstitution::setSubst(const vector<unsigned int>& varMap, const ParamSubstitution& src)
{
	for (unsigned int j = 0; j < varMap.size(); ++j)
		subst[varMap[j]] = src.subst[j];
}

bool
ParamSubstitution::operator<(const ParamSubstitution& ps) const
{
	// NOTE: the bot (nullptr) is less than any other
	return std::lexicographical_compare(subst.begin(), subst.end(), ps.subst.begin(), ps.subst.end());
}

bool
ParamSubstitution::operator==(const ParamSubstitution& ps) const
{
	return subst.size() == ps.subst.size() && equal(subst.begin(), subst.end(), ps.subst.begin());
}

bool
ParamSubstitution::subsume(const ParamSubstitution& ps) const
{
	// a subsumes b iff a is bot or a == b.
	return subst.size() == ps.subst.size() &&
			equal(subst.begin(), subst.end(), ps.subst.begin(), [](DagNode* a, DagNode* b) {
				return a == nullptr || a == b;
			});
}

} /* namespace modelChecker */
