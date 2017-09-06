//
//	List of all descent functions supported by MetaLevelOpSymbol.
//
//	We generate various chunks of linear (branching) code to handle
//	this hetrogeneous collection by macro expansion.
//	The format is:
//		MACRO(symbols name, number of args)
//
  MACRO(metaReduce, 2)
  MACRO(metaRewrite, 3)
  MACRO(metaFrewrite, 4)
  MACRO(metaApply, 5)
  MACRO(metaXapply, 7)
  MACRO(metaMatch, 5)
  MACRO(metaXmatch, 7)
  MACRO(metaSearch, 7)
  MACRO(metaSortLeq, 3)
  MACRO(metaSameKind, 3)
  MACRO(metaLesserSorts, 2)
  MACRO(metaGlbSorts, 3)
  MACRO(metaLeastSort, 2)
  MACRO(metaCompleteName, 2)
  MACRO(metaParse, 3)
  MACRO(metaPrettyPrint, 2)
  MACRO(metaWellFormedModule, 1)
  MACRO(metaWellFormedTerm, 2)
  MACRO(metaGetKind, 2)
  MACRO(metaGetKinds, 1)
  MACRO(metaMaximalSorts, 2)
  MACRO(metaMinimalSorts, 2)
  MACRO(metaWellFormedSubstitution, 2)
  MACRO(metaUpMbs, 2)
  MACRO(metaUpEqs, 2)
  MACRO(metaUpRls, 2)
