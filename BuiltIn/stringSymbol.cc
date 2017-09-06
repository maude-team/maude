//
//      Implementation for class StringSymbol.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//	built in class definitions
#include "stringSymbol.hh"
#include "stringTerm.hh"
#include "stringDagNode.hh"

StringSymbol::StringSymbol(int id)
  : NA_Symbol(id)
{
  sort = 0;
  charSort = 0;
}

void
StringSymbol::fillInSortInfo(Term* subject)
{
  Sort* s = (static_cast<StringTerm*>(subject)->getValue().length() == 1) ? charSort : sort;
  subject->setSortInfo(s->component(), s->index());
}

void
StringSymbol::computeBaseSort(DagNode* subject)
{
  Sort* s = (static_cast<StringDagNode*>(subject)->getValue().length() == 1) ? charSort : sort;
  subject->setSortIndex(s->index());
}

bool
StringSymbol::isConstructor(DagNode* /* subject */)
{
  return true;
}

void
StringSymbol::compileOpDeclarations()
{
  const Vector<OpDeclaration>& opDecls = getOpDeclarations();
  int nrOpDecls = opDecls.length();
  for (int i = 0; i < nrOpDecls; i++)
    {
      Sort* s = opDecls[i].getDomainAndRange()[0];
      if (sort == 0 || s->index() < sort->index())
	sort = s;  // set sort to largest (smallest index) declared sort
      if (charSort == 0 || s->index() > charSort->index())
	charSort = s;  // set charSort to smallest (largest index) declared sort
    }
}
