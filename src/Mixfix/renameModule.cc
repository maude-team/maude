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

ImportModule*
ImportModule::makeRenamedCopy(int name, Renaming* canonical, ModuleCache* moduleCache)
{
  ImportModule* copy = new ImportModule(name, getModuleType(), moduleCache);
  LineNumber lineNumber(FileTable::AUTOMATIC);

  int nrParameters = parameterNames.size();
  for (int i = 0; i < nrParameters; ++i)
    {
      Token t;
      t.tokenize(parameterNames[i], FileTable::AUTOMATIC);
      copy->addParameter(t, importedModules[i]);
    }
  copy->nrBoundParameters = nrBoundParameters;

  int nrImports = importedModules.size();
  for (int i = nrParameters; i < nrImports; ++i)
    copy->addImport(moduleCache->makeRenamedCopy(importedModules[i], canonical), INCLUDING, lineNumber);  // HACK should this be INCLUDING?

  finishCopy(copy, canonical);
  return copy;
}

ImportModule*
ImportModule::makeParameterCopy(int moduleName, int parameterName, ModuleCache* moduleCache)
{
  ImportModule* copy = new ImportModule(moduleName, getModuleType(), moduleCache);
  LineNumber lineNumber(FileTable::AUTOMATIC);

  //
  //	We construct a parameter renaming which will map sorts and labels from us and
  //	our imported theories.
  //
  Renaming* canonical = new Renaming;
  {
    //
    //	For each sort s declared in us, we add a mapping s -> X$s where X is our parameter name.
    //
    const Vector<Sort*>& sorts = getSorts();
    for (int i = nrImportedSorts; i < nrUserSorts; ++i)
      {
	Token fromTok;
	Token toTok;
	fromTok.tokenize(sorts[i]->id(), FileTable::AUTOMATIC);
	toTok.parameterRename(parameterName, fromTok);
	canonical->addSortMapping(fromTok, toTok);
      }
  }
  {
    //
    //	Technically this is wrong since labels contains labels from our imports
    //	which if from a theory will get added in a later step and if from a module
    //	shouldn't be added at all.
    //
    //	However addSortAndLabelMappings() will silently ignore dups and renaming
    //	labels from modules is harmess since parameter renamings never get applied to
    //	to modules. There is a certain inelegance and potential inefficiency in carrying
    //	superfluous label mappings around but they will be (very) rare in practice and
    //	doing the right thing would cost a second "local" label set in each ImportModule.
    //
    FOR_EACH_CONST(i, set<int>, labels)
      {
	Token fromTok;
	Token toTok;
	fromTok.tokenize(*i, FileTable::AUTOMATIC);
	toTok.parameterRename(parameterName, fromTok);
	canonical->addLabelMapping(fromTok, toTok);
      }
  }
  {
    //
    //	We make a parameter copy of imported theories and directly import imported modules.
    //
    FOR_EACH_CONST(i, Vector<ImportModule*>, importedModules)
      {
	ImportModule* import = *i;
	if (isTheory(import->getModuleType()))
	  {
	    ImportModule* importCopy = moduleCache->makeParameterCopy(parameterName, *i);
	    copy->addImport(importCopy, INCLUDING, lineNumber);
	    canonical->addSortAndLabelMappings(importCopy->canonicalRenaming);
	  }
	else
	  copy->addImport(*i, INCLUDING, lineNumber);  // HACK need to fix including
      }
  }
  finishCopy(copy, canonical);
  return copy;
}

ImportModule*
ImportModule::makeInstantiation(int moduleName,
				const Vector<View*>& arguments,
				const Vector<int>& parameterArgs,
				ModuleCache* moduleCache)
{
  Assert(arguments.size() == parameterArgs.size(), "argument/parameterArgs mismatch");
  //
  //	An instantiation is a renamed copy of an parameterized module with
  //	different imports.
  //
  ImportModule* copy = new ImportModule(moduleName, getModuleType(), moduleCache);
  LineNumber lineNumber(FileTable::AUTOMATIC);
  //
  //	We construct an instatiation renaming which will map sorts and operations
  //	we got from our parameters to those of our arguments targets. Also we
  //	directly import targets.
  //
  Renaming* canonical = new Renaming;
  ParameterMap parameterMap;
  int nrParameters = parameterNames.size();
  int start = 0;
  if (nrBoundParameters != nrParameters)
    {
      //
      //	We have free parameters, so we must be instantiating them. Any bound
      //	parameters are copied unchanged first.
      //
      Assert(arguments.size() == nrParameters - nrBoundParameters, "argument/free parameter mismatch");
      start = nrBoundParameters;
      for (int i = 0; i < nrBoundParameters; ++i)
	{
	  Token t;
	  t.tokenize(parameterNames[i], FileTable::AUTOMATIC);
	  copy->addParameter(t, importedModules[i]);
	}
    }
  else
    {
      //
      //	We only have bound parameters so we must be instantiating them.
      //
      Assert(arguments.size() == nrBoundParameters, "argument/bound parameter mismatch");
    }

  {
    //
    //	First we handle parameters instantiated by parameters from an enclosing module.
    //	These parameters keep their theory but change their name to that of the
    //	parameter from the enclosing module. They also become bound (of course they
    //	might have been bound already). Multiple parameters may be instantiated to
    //	the same parameter from the enclosing module, in which case they collapse
    //	to a single bound parameter.
    //
    for (int i = start; i < nrParameters; ++i)
      {
	int argIndex = i - start;
	if (arguments[argIndex] == 0)
	  {
	    //
	    //	Parameter instantiated by a parameter from an enclosing module.
	    //
	    int parameterName = parameterArgs[argIndex];  // name can change
	    if (copy->findParameterIndex(parameterName) == NONE)
	      {
		//
		//	We don't already have a (must be bound since we've only added
		//	bound parameters so far) parameter with name we need to add one.
		//
		Token t;
		t.tokenize(parameterName, FileTable::AUTOMATIC);
		ImportModule* toModule = getParameterTheory(i);  // parameter theory stays the same
		ImportModule* parameterTheory = moduleCache->makeParameterCopy(parameterName, toModule);
		copy->addParameter(t, parameterTheory);
	      }
	    int oldParameterName = parameterNames[i];
	    if (oldParameterName != parameterName)
	      {
		parameterMap[oldParameterName] = parameterName;
		//
		//	For each Foo -> X$Foo we mapped in the parameter copy of the parameter theory,
		//	we need to have a mapping X$Foo -> Y$Foo where Y is the new parameter name.
		//
		const Renaming* parameterRenaming = importedModules[i]->canonicalRenaming;
		int nrSortMappings = parameterRenaming->getNrSortMappings();
		for (int j = 0; j < nrSortMappings; ++j)
		  {
		    int fromName = parameterRenaming->getSortFrom(j);  // Foo
		    int toName = parameterRenaming->getSortTo(j);  // X$Foo
		    Token fromTok;
		    Token tmpTok;  // HACK
		    Token toTok;
		    fromTok.tokenize(toName, FileTable::AUTOMATIC);
		    tmpTok.tokenize(fromName, FileTable::AUTOMATIC);
		    toTok.parameterRename(parameterName, tmpTok);  // Y$Foo
		    canonical->addSortMapping(fromTok, toTok);
		    //cerr << "Mapped " << fromTok << " to "  << toTok << endl;
		  }
	      }
	  }
      }
  }
  //
  //	If we are instantiating free parameters, all bound parameters have now been added.
  //
  //cerr << "After pass 1 construcing " << copy << " from " << this <<
  //  " nrBoundParameters = " << nrBoundParameters <<
  //  " nrParameters = " << nrParameters <<
  //  "  copy->parameterNames.size() = " <<  copy->parameterNames.size() << endl;
  if (nrBoundParameters != nrParameters)
    copy->nrBoundParameters = copy->parameterNames.size();
  {
    //
    //	Second we handle parameters instantiated by views to theories. These parameters keep
    //	their name (unless we need to resolve a name clash) but change their theory to that
    //	of the view target. They keep their free or bound status.
    //
    for (int i = start; i < nrParameters; ++i)
      {
	int argIndex = i - start;
	const View* argumentView = arguments[argIndex];
	if (argumentView != 0)
	  {
	    ImportModule* toModule = argumentView->getToModule();
	    if (MixfixModule::isTheory(toModule->getModuleType()))
	      {
		int parameterName = parameterNames[i];
		while (copy->findParameterIndex(parameterName) != NONE)  // what if our "free" parameter is actually bound???
		  {
		    crope newName("$");
		    newName += Token::name(parameterName);
		    IssueAdvisory("In making " << copy << " free parameter " << Token::name(parameterName) <<
				  " clashes with a bound parameter of the same name. Resolving by renaming free parameter to " <<
				  newName);
		    parameterName = Token::encode(newName.c_str());
		  }
		Token t;
		t.tokenize(parameterName, FileTable::AUTOMATIC); 
		ImportModule* parameterTheory = moduleCache->makeParameterCopy(parameterName, toModule);
		copy->addParameter(t, parameterTheory);

		int oldParameterName = parameterNames[i];
		if (oldParameterName != parameterName)
		  parameterMap[oldParameterName] = parameterName;
		//
		//	For each Foo -> X$Foo we mapped in the parameter copy of the parameter theory,
		//	we need to have a mapping X$Foo -> X$Bar where Bar is the target of Foo in our view.
		//
		const Renaming* parameterRenaming = importedModules[i]->canonicalRenaming;
		int nrSortMappings = parameterRenaming->getNrSortMappings();
		for (int j = 0; j < nrSortMappings; ++j)
		  {
		    int fromName = argumentView->renameSort(parameterRenaming->getSortFrom(j));  // Bar
		    int toName = parameterRenaming->getSortTo(j);  // X$Foo
		    Token fromTok;
		    Token tmpTok;  // HACK
		    Token toTok;
		    fromTok.tokenize(toName, FileTable::AUTOMATIC);
		    tmpTok.tokenize(fromName, FileTable::AUTOMATIC);
		    toTok.parameterRename(parameterName, tmpTok);  // X$Bar
		    if (fromTok.code() != toTok.code())
		      canonical->addSortMapping(fromTok, toTok);
		  }
	      }
	  }
      }
  }
  {
    //
    //	Third we handle parameters instantiated by views to modules.
    //
    for (int i = start; i < nrParameters; ++i)
      {
	int argIndex = i - start;
	const View* argumentView = arguments[argIndex];
	if (argumentView != 0)
	  {
	    ImportModule* toModule = argumentView->getToModule();
	    if(!(MixfixModule::isTheory(toModule->getModuleType())))
	      {
		copy->addImport(argumentView->getToModule(), INCLUDING, lineNumber);    // HACK need to fix including
		//
		//	For each Foo -> X$Foo we mapped in the parameter copy of the parameter theory,
		//	we need to have a mapping X$Foo -> Bar where Bar is the target of Foo in our view.
		//
		const Renaming* parameterRenaming = importedModules[i]->canonicalRenaming;
		int nrSortMappings = parameterRenaming->getNrSortMappings();
		for (int j = 0; j < nrSortMappings; ++j)
		  {
		    int fromName = argumentView->renameSort(parameterRenaming->getSortFrom(j));
		    int toName = parameterRenaming->getSortTo(j);
		    Token fromTok;
		    Token toTok;
		    fromTok.tokenize(toName, FileTable::AUTOMATIC);
		    toTok.tokenize(fromName, FileTable::AUTOMATIC);
		    canonical->addSortMapping(fromTok, toTok);
		  }
		int oldParameterName = parameterNames[i];
		int newParameterName = arguments[argIndex]->id();
		if (oldParameterName != newParameterName)
		  parameterMap[oldParameterName] = newParameterName;
	      }
	  }
      }
  }
  //
  //	If we are instantiating bound parameters, all parameters are bound parameters.
  //
  if (nrBoundParameters == nrParameters)
    copy->nrBoundParameters = copy->parameterNames.size();
  {
    //
    //	Check for parameterized sorts declared inside us.
    //	We also need to map sorts delared in parameterized modules that
    //	we import otherwise our use of those sorts will fail.
    //	For the moment we consider all user sorts for mapping.
    //
    const Vector<Sort*>& sorts = getSorts();
    int nrSorts = getNrUserSorts();
    for (int i = 0; i < nrSorts; ++i)
      {
	int sortId = sorts[i]->id();
	if (Token::auxProperty(sortId) == Token::AUX_PARAMETERIZED_SORT)
	  {
	    bool mapped = false;
	    int header;
	    Vector<int> parameters;
	    Token::splitParameterList(sortId, header, parameters);
	    int nrSortParameters = parameters.size();
	    for (int j = 0; j < nrSortParameters; ++j)
	      {
		ParameterMap::const_iterator m = parameterMap.find(parameters[j]);
		if (m != parameterMap.end())
		  {
		    parameters[j] = m->second;
		    mapped = true;
		  }
	      }
	    if (mapped)
	      {
		Token fromTok;
		Token toTok;
		fromTok.tokenize(sortId, FileTable::AUTOMATIC);
		toTok.tokenize(Token::joinParameterList(header, parameters), FileTable::AUTOMATIC);
		canonical->addSortMapping(fromTok, toTok);
	      }
	  }
      }
  }
  {
    //cerr << "making " << Token::name(moduleName) << " from " << this << " nrImports = " << 
    //  importedModules.size() - nrParameters << endl;
    //
    //	Now handle our regular imports.
    //
    int nrImports = importedModules.size();
    for (int i = nrParameters; i < nrImports; ++i)
      {
	ImportModule* import = importedModules[i];
	//cerr << "original import: " << import << endl;
	int nrImportParameters = import->parameterNames.size();
	if (nrImportParameters == 0)
	  copy->addImport(import, INCLUDING, lineNumber);  // HACK need to fix including
	else
	  {
	    //
	    //	Imported module is itself parameterized; it parameters must all be bound and must be a subset of
	    //	our own so we can build an instantiation for them.
	    //
	    Assert(import->nrBoundParameters == nrImportParameters, "free parameter in imported module");
	    Vector<View*> views(nrImportParameters);
	    Vector<int> names(nrImportParameters);
	    for (int j = 0; j < nrImportParameters; ++j)
	      {
		int parameterName = import->parameterNames[j];
		for (int k = 0;;)  // what if we have both kinds of parameter??? - is this possible?
		  {
		    if (parameterNames[k] == parameterName)
		      {
			views[j] = arguments[k];
			names[j] = parameterArgs[k];
			break;
		      }
		    ++k;
		    Assert(k < nrParameters, "couldn't find parameter " << Token::name(parameterName));
		  }
	      }
	    ImportModule* instance = moduleCache->makeInstatiation(import, views, names);
	    //cerr << "adding " << instance << " made from " << import << endl;
	    copy->addImport(instance, INCLUDING, lineNumber);  // HACK need to fix including
	  }
      }
  }
  finishCopy(copy, canonical);
  return copy;
}

void
ImportModule::finishCopy(ImportModule* copy, Renaming* canonical)
{
  copy->canonicalRenaming = canonical;
  copy->baseModule = this;
  addUser(copy);
  //
  //	Copy our local contents, renaming it as we go, and flattening
  //	in our imports (but not statements).
  //
  copy->importSorts();
  donateSorts2(copy, canonical);
  copy->closeSortSet();
  
  copy->importOps();
  donateOps2(copy, canonical);
  copy->closeSignature();

  copy->fixUpImportedOps();
  fixUpDonatedOps2(copy, canonical);
  copy->closeFixUps();
  //
  //	Statements are not copied so we have no local statements.
  //
  copy->localStatementsComplete();
  //
  //	Reset phase counter in each imported module and return copy.
  //
  copy->resetImports();
}

Sort*
ImportModule::localSort(ImportModule* copy, Renaming* renaming, const Sort* sort)
{
  return (sort->index() == Sort::KIND) ?
    localSort2(copy, renaming, sort->component()->sort(1))->component()->sort(Sort::KIND) :
    localSort2(copy, renaming, sort);
}

Sort*
ImportModule::localSort2(ImportModule* copy, Renaming* renaming, const Sort* sort)
{
  int id = sort->id();
  if (renaming != 0)
    id = renaming->renameSort(id);
  Sort* ts = copy->findSort(id);
  Assert(ts != 0, "couldn't find sort " << QUOTE(Token::sortName(id)) <<  // HACK: should check mixfix setting
	 " renamed from " << QUOTE(sort) << " in module " << copy);
  return ts;
}

void
ImportModule::donateSorts2(ImportModule* copy, Renaming* renaming)
{
  //
  //	Donate our sorts, after a possible renaming.
  //
  const Vector<Sort*>& sorts = getSorts();
  for (int i = nrImportedSorts; i < nrUserSorts; i++)
    {
      Sort* original = sorts[i];
      int id = original->id();
      if (renaming != 0)
	id = renaming->renameSort(id);
      Sort* sort = copy->findSort(id);
      if (sort == 0)
	{
	  sort = copy->addSort(id);
	  sort->setLineNumber(original->getLineNumber());
	}
      else
	{
	  IssueAdvisory(*copy << ": sort " << QUOTE(original) <<
		       " has been imported from both " << *original <<
		       " and " << *sort << '.');
	}
    }
  //
  //	Donate our subsort relations, after a possible renaming.
  //
  for (int i = 0; i < nrUserSorts; i++)
    {
      int nrImports = getNrImportedSubsorts(i);
      const Sort* s = sorts[i];
      const Vector<Sort*>& subsorts = s->getSubsorts();
      int nrSubsorts = subsorts.length();
      if (nrSubsorts > nrImports)
	{
	  Sort* ts = localSort2(copy, renaming, s);
	  for (int j = nrImports; j < nrSubsorts; j++)
	    ts->insertSubsort(localSort2(copy, renaming, subsorts[j]));
	}
    }
}

void
ImportModule::donateOps2(ImportModule* copy, Renaming* renaming)
{
  Vector<int> gather;
  Vector<Sort*> domainAndRange;
  Vector<int> emptyStrategy;
  //
  //	Handle our regular operators.
  //
  const Vector<Symbol*>& symbols = getSymbols();
  for (int i = 0; i < nrUserSymbols; i++)
    {
      int nrImportedDeclarations = getNrImportedDeclarations(i);
      int nrUserDeclarations = nrUserDecls[i];
      if (nrUserDeclarations > nrImportedDeclarations)
	{
	  //
	  //	Need to donate some declarations for this symbol.
	  //
	  Symbol* symbol = symbols[i];
	  SymbolType symbolType = getSymbolType(symbol);
	  Assert(!(symbolType.isCreatedOnTheFly()),
		 "unexpected variable/sort test/polymorph instance " << symbol);

	  Token name;
	  int prec = DEFAULT;
	  const Vector<int>* format;

	  int index = (renaming == 0) ? NONE : renaming->renameOp(symbol);
	  if (index == NONE)
	    {
	      name.tokenize(symbol->id(), symbol->getLineNumber());
	      prec = symbolType.hasFlag(SymbolType::PREC) ? getPrec(symbol) : DEFAULT;
	      if (symbolType.hasFlag(SymbolType::GATHER))
		getGather(symbol, gather);
	      else
		gather.clear();
	      format = &(getFormat(symbol));
	    }
	  else
	    {
	      name.tokenize(renaming->getOpTo(index), symbol->getLineNumber());
	      prec = renaming->getPrec(index);
	      symbolType.assignFlags(SymbolType::PREC, prec != DEFAULT);
	      gather = renaming->getGather(index);  // deep copy
	      symbolType.assignFlags(SymbolType::GATHER, !gather.empty());
	      format = &(renaming->getFormat(index));
	      symbolType.assignFlags(SymbolType::FORMAT, !format->empty());
	    }

	  const Vector<OpDeclaration>& opDecls = symbol->getOpDeclarations();
	  int domainAndRangeLength = opDecls[0].getDomainAndRange().length();
	  domainAndRange.resize(domainAndRangeLength);
	  const Vector<int>& strategy = symbolType.hasFlag(SymbolType::STRAT) ?
	    symbol->getStrategy() : emptyStrategy;
	  const NatSet& frozen = symbol->getFrozen();

	  bool originator;
	  for (int j = nrImportedDeclarations; j < nrUserDeclarations; j++)
	    {
	      const Vector<Sort*>& oldDomainAndRange = opDecls[j].getDomainAndRange();
	      for (int k = 0; k < domainAndRangeLength; k++)
		domainAndRange[k] = localSort(copy, renaming, oldDomainAndRange[k]);
	      symbolType.assignFlags(SymbolType::CTOR, opDecls[j].isConstructor());
	      Symbol* newSymbol = copy->addOpDeclaration(name,
							 domainAndRange,
							 symbolType,
							 strategy,
							 frozen,
							 prec,
							 gather,
							 *format,
							 getMetadata(symbol, j),
							 originator);
	      if (j == 0)
		{
		  if (originator)
		    {
		      if (symbolType.getBasicType() == SymbolType::BUBBLE)
		        copy->copyBubbleSpec(symbol, newSymbol);
		    }
		  else
		    {
		      IssueAdvisory(*copy << ": operator " << QUOTE(symbol) <<
				   " has been imported from both " << *newSymbol <<
				   " and " << *symbol << " with no common ancestor.");
		    }
		}
	      else  // we must have already imported some declarations
	        Assert(!originator, "bad origination of " << symbol);
	    }
	}
    }
  //
  //	Now handle our polymorphic operators.
  //
  int nrPolymorphs = getNrPolymorphs();
  for (int i = nrImportedPolymorphs; i < nrPolymorphs; i++)
    {
      Token name = getPolymorphName(i);
      SymbolType symbolType = getPolymorphType(i);
      int prec = DEFAULT;
      const Vector<int>* format;

      int index = (renaming == 0) ? NONE : renaming->renamePolymorph(name.code());
      if (index == NONE)
	{
	  prec = symbolType.hasFlag(SymbolType::PREC) ? getPolymorphPrec(i) : DEFAULT;
	  if (symbolType.hasFlag(SymbolType::GATHER))
	    getPolymorphGather(i, gather);
	  else
	    gather.clear();
	  const Vector<int>* format = &(getPolymorphFormat(i));
	}
      else
	{
	  name.tokenize(renaming->getOpTo(index), name.lineNumber());
	  prec = renaming->getPrec(index);
	  symbolType.assignFlags(SymbolType::PREC, prec != DEFAULT);
	  gather = renaming->getGather(index);  // deep copy
	  symbolType.assignFlags(SymbolType::GATHER, !gather.empty());
	  format = &(renaming->getFormat(index));
	  symbolType.assignFlags(SymbolType::FORMAT, !format->empty());
	}

      const Vector<Sort*>& oldDomainAndRange = getPolymorphDomainAndRange(i);
      int domainAndRangeLength = oldDomainAndRange.length();
      domainAndRange.resize(domainAndRangeLength);
      for (int j = 0; j < domainAndRangeLength; j++)
	{
	  Sort* s = oldDomainAndRange[j];
	  domainAndRange[j] = (s == 0) ? 0 : localSort(copy, renaming, s);
	}

      const Vector<int>& strategy = symbolType.hasFlag(SymbolType::STRAT) ?
	getPolymorphStrategy(i) : emptyStrategy;

      copy->addPolymorph(name,
			 domainAndRange,
			 symbolType,
			 strategy,
			 getPolymorphFrozen(i),
			 prec,
			 gather,
			 *format,
			 getPolymorphMetadata(i));
    }
}

void
ImportModule::fixUpDonatedOps2(ImportModule* copy, Renaming* renaming)
{
  //
  //	The map from imported module's symbols to importing module's symbols
  //	is built dynamically.
  //
  ImportTranslation importTranslation(copy, renaming);
  //
  //	Handle our regular operators.
  //
  const Vector<Symbol*>& symbols = getSymbols();
  for (int i = 0; i < nrUserSymbols; i++)
    {
      int nrImportedDeclarations = getNrImportedDeclarations(i);
      if (nrUserDecls[i] > nrImportedDeclarations)
	{
	  //
	  //	We donated some declarations for this symbol so do
	  //	an incremental fixup if needed.
	  //
	  Symbol* symbol = symbols[i];
	  SymbolType st = getSymbolType(symbol);
	  if (st.hasFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID))
	    {
	      BinarySymbol* ns = safeCast(BinarySymbol*, importTranslation.translate(symbol));
	      if (ns->getIdentity() == 0)
		{
		  Term* id = safeCast(BinarySymbol*, symbol)->getIdentity();
		  Assert(id != 0, "missing identity");
		  ns->setIdentity(id->deepCopy(&importTranslation));
		}
	    }

	  if (st.hasAttachments())
	    importTranslation.translate(symbol)->copyAttachments(symbol, &importTranslation);
	  else if (st.getBasicType() == SymbolType::BUBBLE)
	    copy->copyFixUpBubbleSpec(symbol, &importTranslation);
	}
    }
  //
  //	Now handle our polymorphic operators.
  //
  {
    Vector<Sort*> domainAndRange;
    
    int nrPolymorphs = getNrPolymorphs();
    for (int i = nrImportedPolymorphs; i < nrPolymorphs; i++)
      {
	//
	//	Get polymorph name.
	//
	int id = getPolymorphName(i).code();
	if (renaming != 0)
	  {
	    int index = renaming->renamePolymorph(id);
	    if (index != NONE)
	      id = renaming->getOpTo(index);
	  }
	//
	//	Get polymorph domain and range.
	//
	const Vector<Sort*>& oldDomainAndRange = getPolymorphDomainAndRange(i);
	int domainAndRangeLength = oldDomainAndRange.length();
	domainAndRange.resize(domainAndRangeLength);
	for (int j = 0; j < domainAndRangeLength; j++)
	  {
	    Sort* s = oldDomainAndRange[j];
	    domainAndRange[j] = (s == 0) ? 0 : localSort(copy, renaming, s);
	  }

	int donatedCopyIndex = copy->findPolymorphIndex(id, domainAndRange);
	Assert(donatedCopyIndex != NONE, "missing polymorph");
	copy->copyFixUpPolymorph(donatedCopyIndex, this, i, &importTranslation);
      }
  }
}

void
ImportModule::localStatementsComplete()
{
  nrOriginalMembershipAxioms = getSortConstraints().length();
  nrOriginalEquations = getEquations().length();
  nrOriginalRules = getRules().length();

  FOR_EACH_CONST(i, Vector<ImportModule*>, importedModules)
    labels.insert((*i)->labels.begin(), (*i)->labels.end());
  if (canonicalRenaming == 0)
    {
      {
	FOR_EACH_CONST(i, Vector<SortConstraint*>, getSortConstraints())
	  {
	    int id = (*i)->getLabel().id();
	    if (id != NONE)
	      labels.insert(id);
	  }
      }
      {
	FOR_EACH_CONST(i, Vector<Equation*>, getEquations())
	  {
	    int id = (*i)->getLabel().id();
	    if (id != NONE)
	      labels.insert(id);
	  }
      }
      {
	FOR_EACH_CONST(i, Vector<Rule*>, getRules())
	  {
	    int id = (*i)->getLabel().id();
	    if (id != NONE)
	      labels.insert(id);
	  }
      }
    }
  else
    {
      FOR_EACH_CONST(i, set<int>, baseModule->labels)
	labels.insert(canonicalRenaming->renameLabel(*i));
    }
}
