/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for class View.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "core.hh"
#include "interface.hh"
#include "mixfix.hh"

//	front end class definitions
#include "token.hh"
#include "moduleExpression.hh"
#include "preModule.hh"
//#include "importModule.hh"
#include "view.hh"

View::View(Token viewName)
  : NamedEntity(viewName.code()),
    LineNumber(viewName.lineNumber())
{
  fromTheory = 0;
  toModule = 0;
  status = INITIAL;
}

View::~View()
{
  if (fromTheory != 0)
    fromTheory->removeUser(this);
  if (toModule != 0)
    toModule->removeUser(this);
}

void
View::regretToInform(Entity* /* doomedEntity */)
{
  //
  //	Something we depended on changed so self destruct all calculated stuff.
  //
  if (fromTheory != 0)
    fromTheory->removeUser(this);
  fromTheory = 0;
  if (toModule != 0)
    toModule->removeUser(this);
  toModule = 0;
  status = UNKNOWN;
}

void
View::finishView()
{
  evaluate();
}

bool
View::evaluate()
{
  //
  //	See if view needs to be evaluated.
  //
  switch (status)
    {
    case INITIAL:
      break;
    case GOOD:
      return true;
    case BAD:
      return false;
    case UNKNOWN:
      {
	IssueAdvisory("reexamining view " << static_cast<NamedEntity*>(this));
	break;
      }
    }
  //
  //	Evaluate from part.
  //
  fromTheory = PreModule::makeModule(fromExpr);
  if (fromTheory != 0)
    {
      fromTheory->addUser(this);
      if (!(MixfixModule::isTheory(fromTheory->getModuleType())))
	{
	  IssueWarning(*this << ": from part of a view must be a theory.");
	  status = BAD;
	}
    }
  else
    status = BAD;
  //
  //	Evaluate to part.
  //
  toModule = PreModule::makeModule(toExpr);
  if (toModule != 0)
    toModule->addUser(this);
  else
    status = BAD;

  if (status == BAD)
    return false;
  {
    //
    //	Now we check that for each pair os sorts (A, B) lying in the same kind
    //	in toTheory, there exists under out mapping sorts (A', B') that are in 
    //	the same kind in toModule, and further more if A < B then A' < B'.
    //
    const Vector<ConnectedComponent*> kinds = fromTheory->getConnectedComponents();
    FOR_EACH_CONST(i, Vector<ConnectedComponent*>, kinds)
      {
	ConnectedComponent* kind = (*i);
	int nrSorts = kind->nrSorts();
	for (int j = 1; j < nrSorts; ++j)
	  {
	    Sort* jSort = kind->sort(j);
	    int jTrans = renameSort(jSort->id());
	    Sort* jTransSort = toModule->findSort(jTrans);
	    if (jTransSort == 0)
	      {
		IssueWarning(*this << ": failed to find sort " << QUOTE(Token::name(jTrans)) <<  // HACK: what ifjTrans is structured?
			     " in " << QUOTE(toModule) << " to represent sort " << QUOTE(jSort) <<
			     " from " << QUOTE(fromTheory) << '.');
		status = BAD;
		return false;
	      }
	    ConnectedComponent* transKind = jTransSort->component();
	    for (int k = 1; k < j; ++k)
	      {
		Sort* kSort = kind->sort(k);
		Sort* kTransSort = toModule->findSort(renameSort(kSort->id()));
		if (jTransSort->component() != kTransSort->component())
		  {
		    IssueWarning(*this << ": sorts " << QUOTE(jSort) << " and " << QUOTE(kSort) << " from " <<
				 QUOTE(fromTheory) << " are in the same kind but " <<
				 QUOTE(jTransSort) << " and " << QUOTE(kTransSort) << " from " <<
				 QUOTE(toModule) << " are in different kinds.");
		    status = BAD;
		    return false;
		  }
		if (leq(jSort, kSort) && !(leq(jTransSort, kTransSort)))
		  {
		    IssueWarning(*this << ": " << QUOTE(jSort) << " is a subsort of " << QUOTE(kSort) <<
				 " in " << QUOTE(fromTheory) << " but " << QUOTE(jTransSort) <<
				 " is not a subsort of " << QUOTE(kTransSort) << " in " <<
				 QUOTE(toModule) << '.');
		  }			      
	      }
	  }
      }
  }
  {
    //
    //	Now we check that for each operator
    //	  f : D1 ... Dn -> R
    //	in fromTheory, there exists (or can be instantiated) an operator
    //	  f' : D1' ... Dn' -> R'
    //	in toModule where the prime mappings are obtained from the view.
    //
    const Vector<Symbol*>& symbols = fromTheory->getSymbols();
    int nrUserSymbols =  fromTheory->getNrUserSymbols();
    for (int i = 0; i < nrUserSymbols; ++i)
      {
	Symbol* s = symbols[i];
	Assert(fromTheory->getSymbolType(s).getBasicType() != SymbolType::VARIABLE,
	       "didn't exepct variable");
	Assert(fromTheory->getSymbolType(s).getBasicType() != SymbolType::SORT_TEST,
	       "didn't exepct sort test");
	//
	//	Translate the name.
	//
	//	ISSUE: Should we translate the name if the operator is "module declared" as opposed to
	//	theory declared?
	//
	int id = s->id();
	int index = renameOp(s);
	if (index != NONE)
	  id = getOpTo(index);
	//
	//	Translate the domain and range components.
	//
	int nrArgs = s->arity();
	Vector<ConnectedComponent*> domainComponents(nrArgs);
	for (int j = 0; j < nrArgs; ++j)
	  domainComponents[j] = toModule->findSort(renameSort(s->domainComponent(j)->sort(1)->id()))->component();
	ConnectedComponent* rangeComponent = toModule->findSort(renameSort(s->rangeComponent()->sort(1)->id()))->component();
	//
	//	Check to see that a suitable operator exists or can be made in toModule.
	//
	if (toModule->findSymbol(id, domainComponents, rangeComponent) == 0)
	  {
	    IssueWarning(*this << ": failed to find suitable operator " << QUOTE(Token::name(id)) <<
			     " in " << QUOTE(toModule) << " to represent operator " << QUOTE(s) <<
			     " from " << QUOTE(fromTheory) << '.');
	    status = BAD;
	    return false;
	  }
      }
  }
  {
    //
    //	Now we check that for each polymorphic operator
    //	  f : D1 ... Dn -> R
    //	in fromTheory, there exists (or can be instantiated) an operator
    //	  f' : D1' ... Dn' -> R'
    //	in toModule where the prime mappings are obtained from the view, and
    //	the null sort maps to the null sort.
    //
    //	ISSUE: Should polymorphs even be allowed in theories?
    //
    int nrPolymorphs = fromTheory->getNrImportedPolymorphs();
    for (int i = 0; i < nrPolymorphs; ++i)
      {
	//
	//	Translate the name.
	//
	int id = fromTheory->getPolymorphName(i).code();
	int index = renamePolymorph(id);
	if (index != NONE)
	  id = getOpTo(index);
	//
	//	Translate the domain and range components.
	//
	const Vector<Sort*>& domainAndRange = fromTheory->getPolymorphDomainAndRange(i);
	int nrSorts = domainAndRange.size();
	Vector<Sort*> newDomainAndRange(nrSorts);
	for (int j = 0; j < nrSorts; ++j)
	  {
	    Sort* s = domainAndRange[j];
	    newDomainAndRange[j] = (s == 0) ? 0 : toModule->findSort(renameSort(s->id()));
	  }
	//
	//	Check to see that a suitable polymorphic operator exists in toModule.
	//
	if (toModule->findPolymorphIndex(id, newDomainAndRange) == NONE)
	  {
	    IssueWarning(*this << ": failed to find suitable polymorphic operator " << QUOTE(Token::name(id)) <<
			 " in " << QUOTE(toModule) << " to represent polymorphic operator " <<
			 QUOTE(fromTheory->getPolymorphName(i)) << " from " << QUOTE(fromTheory) << '.');
	    status = BAD;
	    return false;
	  }
      }
  }
  status = GOOD;
}

void
View::showView(ostream& s)
{
  s << "view " << static_cast<NamedEntity*>(this) << " from " <<
    fromExpr << " to " << toExpr << " is\n";
  printRenaming(s, "  ", " .\n  ");
  if (getNrSortMappings() > 0 || getNrOpMappings() > 0)
    s << " .\n";
  s << "endv\n";
}
