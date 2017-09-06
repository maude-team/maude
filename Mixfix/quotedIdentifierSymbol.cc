//
//      Implementation for class QuotedIdentifierSymbol.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"
#include "mixfix.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "rewritingContext.hh"

//	mixfix class definitions
#include "token.hh"
#include "importTranslation.hh"
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierTerm.hh"
#include "quotedIdentifierDagNode.hh"

QuotedIdentifierSymbol::QuotedIdentifierSymbol(int id)
  : NA_Symbol(id)
{
  baseSort = 0;
  constantSort = 0;
  variableSort = 0;
  sortSort = 0;
  kindSort = 0;
}

bool
QuotedIdentifierSymbol::attachData(const Vector<Sort*>& opDeclaration,
				   const char* purpose,
				   const Vector<const char*>& data)
{
  if (strcmp(purpose, "QuotedIdentifierSymbol") == 0)
    {
      if (data.length() == 0)
	return true;
      if (data.length() == 1)
	{
	  const char* subsortName = data[0];
	  Sort* sort = opDeclaration[0];
	  if (strcmp(subsortName, "constantQid") == 0)
	    constantSort = sort;
	  else if (strcmp(subsortName, "variableQid") == 0)
	    variableSort = sort;
	  else if (strcmp(subsortName, "sortQid") == 0)
	    sortSort = sort;
	  else if (strcmp(subsortName, "kindQid") == 0)
	    kindSort = sort;
	  else
	    return false;
	  return true;
	}
      return false;
    }
  return Symbol::attachData(opDeclaration, purpose, data);
}

#define COPY_SORT(original, name, mapping) \
  if (name == 0) \
    { \
      if (Sort* s = original->name) \
	name = (mapping == 0) ? s : mapping->translate(s); \
    }

void
QuotedIdentifierSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  QuotedIdentifierSymbol* orig = safeCast(QuotedIdentifierSymbol*, original);
  ImportTranslation* mapping = safeCast(ImportTranslation*, map);
  COPY_SORT(orig, constantSort, mapping);
  COPY_SORT(orig, variableSort, mapping);
  COPY_SORT(orig, sortSort, mapping);
  COPY_SORT(orig, kindSort, mapping);
  Symbol::copyAttachments(original, map);
}

Sort*
QuotedIdentifierSymbol::determineSort(int idIndex)
{
  switch (Token::auxProperty(idIndex))
    {
    case Token::AUX_CONSTANT:
      {
	if (constantSort != 0)
	  return constantSort;
	break;
      }
    case Token::AUX_VARIABLE:
      {
	if (variableSort != 0)
	  return variableSort;
	break;
      }
    case Token::AUX_KIND:
      {
	if (kindSort != 0)
	  return kindSort;
	break;
      }
    case Token::AUX_SORT:
      {
	if (sortSort != 0)
	  return sortSort;
	break;
      }
    }
  return baseSort;
}

void
QuotedIdentifierSymbol::fillInSortInfo(Term* subject)
{
  Sort* s = determineSort(static_cast<QuotedIdentifierTerm*>(subject)->getIdIndex());
  subject->setSortInfo(s->component(), s->index());
}

void
QuotedIdentifierSymbol::computeBaseSort(DagNode* subject)
{
  Sort* s = determineSort(static_cast<QuotedIdentifierDagNode*>(subject)->getIdIndex());
  subject->setSortIndex(s->index());
}

bool
QuotedIdentifierSymbol::isConstructor(DagNode* /* subject */)
{
  return true;
}

void
QuotedIdentifierSymbol::compileOpDeclarations()
{
  const Vector<OpDeclaration>& opDecls = getOpDeclarations();
  int nrOpDecls = opDecls.length();
  for (int i = 0; i < nrOpDecls; i++)
    {
      Sort* s = opDecls[i].getDomainAndRange()[0];
      if (baseSort == 0 || s->index() < baseSort->index())
	baseSort = s;  // set baseSort to largest (smallest index) declared sort
    }
}
