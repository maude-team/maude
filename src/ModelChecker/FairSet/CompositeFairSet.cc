/*
 * CompositeFairSet.cc
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#include "macros.hh"
#include "vector.hh"

#include "natSet.hh"
#include "CompositeFairSet.hh"

namespace modelChecker {

void
CompositeFairSet::addComponent(unique_ptr<FairSet>&& f)
{
	fairSets.push_back(move(f));
}

const FairSet&
CompositeFairSet::getComponent(unsigned int i) const
{
	return *fairSets[i];
}

void
CompositeFairSet::paste(const FairSet& f)
{
	const CompositeFairSet& cf = static_cast<const CompositeFairSet&>(f);
	for (unsigned int i = 0; i < fairSets.size(); ++i)
		fairSets[i]->paste(*cf.fairSets[i]);
}

void
CompositeFairSet::merge(const FairSet& f, const AbstractFairnessTable& table)
{
	const CompositeFairSet& cf = static_cast<const CompositeFairSet&>(f);
	for (unsigned int i = 0; i < fairSets.size(); ++i)
		fairSets[i]->merge(*cf.fairSets[i], static_cast<const CompositeFairnessTable&>(table).getComponent(i));
}

bool
CompositeFairSet::isSatisfied() const
{
	return all_of(fairSets.begin(), fairSets.end(), [] (const unique_ptr<FairSet>& i) { return i->isSatisfied(); });
}

bool
CompositeFairSet::operator<(const FairSet& f) const
{
	const CompositeFairSet& cf = static_cast<const CompositeFairSet&>(f);
	for (unsigned int i = 0; i < fairSets.size(); ++i)
		if (*fairSets[i] < *cf.fairSets[i])
			return true;
	return false;
}

unique_ptr<FairSet>
CompositeFairSet::clone() const
{
	CompositeFairSet* cfs = new CompositeFairSet;
	cfs->fairSets.resize(fairSets.size());
	transform(fairSets.begin(), fairSets.end(), cfs->fairSets.begin(), [](const unique_ptr<FairSet>& i) {
		return i->clone();
	});
	return unique_ptr<FairSet>(cfs);
}

unique_ptr<FairSet::Goal>
CompositeFairSet::makeFairGoal(const AbstractFairnessTable& table) const
{
	return unique_ptr<FairSet::Goal>(new Goal(*this, table));
}

unique_ptr<FairSet::Bad>
CompositeFairSet::makeBadGoal() const
{
	return unique_ptr<FairSet::Bad>(new Bad(*this));
}

void
CompositeFairSet::dump(ostream& o) const
{
	o << "[composited:";
	for (auto& i : fairSets)
	{
		o << " ";
		i->dump(o);
	}
	o << "]";
}


CompositeFairSet::Goal::Goal(const CompositeFairSet& f, const AbstractFairnessTable& table)
{
	fairGoals.resize(f.fairSets.size());

	for (unsigned int i = 0; i < fairGoals.size(); ++i)
		fairGoals[i] = f.fairSets[i]->makeFairGoal(
							static_cast<const CompositeFairnessTable&>(table).getComponent(i));
}

bool
CompositeFairSet::Goal::empty() const
{
	return all_of(fairGoals.begin(), fairGoals.end(), [] (const unique_ptr<FairSet::Goal>& i) { return i->empty(); });
}

bool
CompositeFairSet::Goal::update(const FairSet& f, const AbstractFairnessTable& table)
{
	bool result = false;
	for (unsigned int i = 0; i < fairGoals.size(); ++i)
		result |= fairGoals[i]->update(*static_cast<const CompositeFairSet&>(f).fairSets[i],
				static_cast<const CompositeFairnessTable&>(table).getComponent(i));
	return result;
}

void
CompositeFairSet::Goal::dump(ostream& o) const
{
	o << "[composited:";
	for (auto& i : fairGoals)
	{
		o << " ";
		i->dump(o);
	}
	o << "]";
}

CompositeFairSet::Bad::Bad(const CompositeFairSet& f): fairBadSets(f.fairSets.size())
{
	transform(f.fairSets.begin(), f.fairSets.end(), fairBadSets.begin(), [](const unique_ptr<FairSet>& i) {
		return i->makeBadGoal();
	});
}

bool
CompositeFairSet::Bad::isBad(const FairSet& f, const AbstractFairnessTable& table) const
{
	const CompositeFairSet& cf = static_cast<const CompositeFairSet&>(f);
	for (unsigned int i = 0; i < fairBadSets.size(); ++i)
		if ( fairBadSets[i]->isBad(*cf.fairSets[i], static_cast<const CompositeFairnessTable&>(table).getComponent(i)) )
			return true;
	return false;
}

bool
CompositeFairSet::Bad::empty() const
{
	return all_of(fairBadSets.begin(), fairBadSets.end(), [] (const unique_ptr<FairSet::Bad>& i) { return i->empty(); });
}

void
CompositeFairSet::Bad::merge(const FairSet::Bad& b)
{
	const Bad& nb = static_cast<const Bad&>(b);
	for (unsigned int i = 0; i < fairBadSets.size(); ++i)
		fairBadSets[i]->merge(*nb.fairBadSets[i]);
}

void
CompositeFairSet::Bad::dump(ostream& o) const
{
	o << "[composited:";
	for (auto& i : fairBadSets)
	{
		o << " ";
		i->dump(o);
	}
	o << "]";
}

} /* namespace modelChecker */
