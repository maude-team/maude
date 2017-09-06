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
ImportModule::makeParameterCopy(int moduleName, int parameterName, ModuleCache* moduleCache)
{
  ImportModule* copy = new ImportModule(moduleName, getModuleType(), PARAMETER, moduleCache);
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
  Assert(arguments.size() == getNrFreeParameters(), "argument/free parameter mismatch");
  //
  //	An instantiation is a renamed copy of an parameterized module with
  //	different imports.
  //
  ModuleType moduleType = getModuleType();
  if (moduleType == FUNCTIONAL_MODULE)
    {
      //
      //	Check views to see if we need to promote a functional module
      //	to a system module.
      //
      FOR_EACH_CONST(i, Vector<View*>, arguments)
	{
	  View* v = *i;
	  if (v != 0 && v->getToModule()->getModuleType() == SYSTEM_MODULE)
	    {
	      moduleType = SYSTEM_MODULE;
	      break;
	    }
	}
    }
  ImportModule* copy = new ImportModule(moduleName, moduleType, INSTANTIATION, moduleCache);
  LineNumber lineNumber(FileTable::AUTOMATIC);
  {
    //
    //	We copy any bound parameters.
    //
    for (int i = 0; i < nrBoundParameters; ++i)
      {
	Token t;
	t.tokenize(parameterNames[i], FileTable::AUTOMATIC);
	copy->addParameter(t, importedModules[i]);
      }
  }
  //
  //	We construct an instatiation renaming which will map sorts and operations
  //	we got from our parameters to those of our arguments targets. Also we
  //	directly import targets.
  //
  Renaming* canonical = new Renaming;
  ParameterMap parameterMap;  // map for parameters in sorts
  ParameterMap extraParameterMap;  // map for generating extra parameter list for parameterized sorts
  int nrParameters = parameterNames.size();
  {
    //
    //	First we handle parameters instantiated by parameters from an enclosing module.
    //	These parameters keep their theory but change their name to that of the
    //	parameter from the enclosing module. They also become bound. Multiple parameters may be instantiated to
    //	the same parameter from the enclosing module, in which case they collapse
    //	to a single bound parameter.
    //
    for (int i = nrBoundParameters; i < nrParameters; ++i)
      {
	int argIndex = i - nrBoundParameters;
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
  {
    //
    //	All bound parameters have now been added.
    //
    copy->nrBoundParameters = copy->parameterNames.size();
    if (copy->nrBoundParameters > 0)
      {
	//
	//	Because the instantiated module has bound parameters, it needs
	//	to keep track of how it was made.
	//
	copy->viewArgs = arguments;  // deep copy
	copy->paramArgs = parameterArgs;  // deep copy
      }
  }
  {
    //
    //	Second we handle parameters instantiated by views to theories. These parameters keep
    //	their name (unless we need to resolve a name clash) but change their theory to that
    //	of the view target. These parameters give rise to an extra parameter list for
    //	parameterized sorts.
    //
    for (int i = nrBoundParameters; i < nrParameters; ++i)
      {
	int argIndex = i - nrBoundParameters;
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
		int viewName = arguments[argIndex]->id();
		if (oldParameterName != viewName)
		  parameterMap[oldParameterName] = viewName;
		extraParameterMap[oldParameterName] = parameterName;
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
    for (int i = nrBoundParameters; i < nrParameters; ++i)
      {
	int argIndex = i - nrBoundParameters;
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
	if (Token::auxProperty(sortId) == Token::AUX_STRUCTURED_SORT)
	  {
	    bool mapped = false;
	    int header;
	    Vector<int> parameters;
	    Vector<int> extraParameters;
	    Token::splitParameterList(sortId, header, parameters);
	    int nrSortParameters = parameters.size();
	    for (int j = 0; j < nrSortParameters; ++j)
	      {
		int original = parameters[j];
		ParameterMap::const_iterator m = parameterMap.find(original);
		if (m != parameterMap.end())
		  {
		    parameters[j] = m->second;
		    mapped = true;
		  }
		ParameterMap::const_iterator e = extraParameterMap.find(original);
		if (e != extraParameterMap.end())
		  extraParameters.append(e->second);
	      }
	    int newSortId = mapped ? Token::joinParameterList(header, parameters) : sortId;
	    if (!extraParameters.empty())
	      newSortId = Token::joinParameterList(newSortId, extraParameters);
	    if (newSortId != sortId)
	      {
		Token fromTok;
		Token toTok;
		fromTok.tokenize(sortId, FileTable::AUTOMATIC);
		toTok.tokenize(newSortId, FileTable::AUTOMATIC);
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
	    Assert(import->nrBoundParameters == nrImportParameters, "free parameter in imported module " << import);
	    Vector<View*> views(nrImportParameters);
	    Vector<int> names(nrImportParameters);
	    for (int j = 0; j < nrImportParameters; ++j)
	      {
		int parameterName = import->parameterNames[j];
		int indexInUs = findParameterIndex(parameterName);
		Assert(indexInUs != NONE, "couldn't find bound parameter " << Token::name(parameterName) <<
		       " for import " << import << " in " << this);
		int indexInArgList = indexInUs - nrBoundParameters;
		if (indexInArgList >= 0)
		  {
		    //
		    //	Our import shared one of our free parameters, so its instantiation
		    //	will share the appropriate argument.
		    //
		    views[j] = arguments[indexInArgList];
		    names[j] = parameterArgs[indexInArgList];
		  }
		else
		  {
		    //
		    //	Our import shared one of our bound parameters, so its instantiation
		    //	will just instantiate the bound parameter to itself.
		    //
		    views[j] = 0;
		    names[j] = parameterName;
		  }
	      }
	    ParameterMap parametersNeedingRebinding;
	    ImportModule* instance =
	      import->instantiateBoundParameters(views, names, moduleCache, parametersNeedingRebinding);
	    int nrFreeParameters = instance->getNrFreeParameters();
	    Assert(nrFreeParameters == parametersNeedingRebinding.size(), "escaped parameters mismatch");
	    if (nrFreeParameters > 0)
	      {
		DebugAdvisory("import " << import << " became " << instance << " with " <<
			      nrFreeParameters << " free parameters after bound parameters were instantiated");
		//
		//	Some of our bound parameters were instantiated by theory-views and
		//	need to be rebound.
		//
		Vector<View*> newViewArgs(nrFreeParameters);
		Vector<int> newParamArgs(nrFreeParameters);
		for (int i = 0; i < nrFreeParameters; ++i)
		  {
		    newViewArgs[i] = 0;
		    ParameterMap::const_iterator m =
		      parametersNeedingRebinding.find(instance->getFreeParameterName(i));
		    Assert(m != parametersNeedingRebinding.end(), "could find escaped parameter");
		    newParamArgs[i] = m->second;
		  }
		instance = moduleCache->makeInstatiation(instance, newViewArgs, newParamArgs);
	      }
		
	    Assert(instance->nrBoundParameters == instance->parameterNames.size(),
		   "free parameter in instance " << instance << " of imported module " << import);
	    //cerr << "adding " << instance << " made from " << import << endl;
	    copy->addImport(instance, INCLUDING, lineNumber);  // HACK need to fix including
	  }
      }
  }
  finishCopy(copy, canonical);
  return copy;
}

ImportModule*
ImportModule::instantiateBoundParameters(const Vector<View*>& arguments,
					 const Vector<int>& parameterArgs,
					 ModuleCache* moduleCache,
					 ParameterMap& escapedParameters)
{
  DebugAdvisory("instantiating bound parameters of " << this);
  //
  //	We are an instantiated (not renamed) module with parameters that have
  //	been bound by a parameterized module that imported us. Now that these
  //	parameters have been been instantiated, we need to make a new instanted
  //	module that is "like us" except that our bound parameters are
  //	instantiated with the new arguments.
  //
  Assert(nrBoundParameters > 0, "no bound parameters");
  Assert(arguments.size() == nrBoundParameters &&
	 parameterArgs.size() == nrBoundParameters, "bound parameter args bad");
  Assert(escapedParameters.empty(), "escaped parameters nonempty");
  Assert(!viewArgs.empty(), "no original args");
  Assert(viewArgs.size() == paramArgs.size(), "original args bad");
  Assert(baseModule != 0, "no base module");
  /*
  if (viewArgs.empty())
    {
      Assert(paramArgs.empty(), "original args inconsistent");
      //
      //	We are a renaming of a module with bound parameters.
      //	The bound parameters will be identical to our own so
      //	we first make a new instantiation of our base module and
      //	then rename it.
      //
      ImportModule* newBase = baseModule->
	instantiateBoundParameters(arguments, parameterArgs, moduleCache, escapedParameters);  // HACK
      return moduleCache->makeRenamedCopy(newBase, canonicalRenaming);  // HACK: we need to make a new renaming
    }
  */
  //
  //	We are an instantiation of a parameterized module so we
  //	first check our base module; if it has bound parameters we must
  //	make a new instantiation of it.
  //
  ParameterMap parametersNeedingRebinding;
  ImportModule* foundation = baseModule;
  int nrBaseBoundParameters = foundation->nrBoundParameters;
  if (nrBaseBoundParameters > 0)
    {
      Vector<View*> baseViewArgs(nrBaseBoundParameters);
      Vector<int> baseParamArgs(nrBaseBoundParameters);
      for (int i = 0; i < nrBaseBoundParameters; ++i)
	{
	  int index = findParameterIndex(foundation->parameterNames[i]);
	  Assert(index != NONE && index < nrBoundParameters, "didn't find bound parameter");
	  baseViewArgs[i] = arguments[index];
	  baseParamArgs[i] = parameterArgs[index];
	}
      foundation = foundation->instantiateBoundParameters(baseViewArgs,
							  baseParamArgs,
							  moduleCache,
							  parametersNeedingRebinding);
      DebugAdvisory("when instantiating bound parameters of " << baseModule <<
		    " to get " << foundation << ", " << parametersNeedingRebinding.size() <<
		    " bound parameters escaped");
    }
  //
  //	We build a new set of arguments to instantiate our "foundation" on.
  //
  int nrFreeParameters = foundation->getNrFreeParameters();
  Assert(nrFreeParameters == viewArgs.size() + parametersNeedingRebinding.size(),
	 "disagreement over how many free parameters foundation should take");
  Vector<View*> newViewArgs(nrFreeParameters);
  Vector<int> newParamArgs(nrFreeParameters);
  int j = 0;
  for (int i = 0; i < nrFreeParameters; ++i)
    {
      int freeParameterName = foundation->getFreeParameterName(i);
      ParameterMap::const_iterator e = parametersNeedingRebinding.find(freeParameterName);
      if (e == parametersNeedingRebinding.end())
	{
	  //
	  //	The free parameter was an original free parameter so we see what it
	  //	was originally instantiated by.
	  //
	  View* v = viewArgs[j];
	  if (v == 0)
	    {
	      //
	      //	The free parameter was originally instantiated by a parameter
	      //	from an enclosing module, making it bound in us. So we now look
	      //	up its name in our in our parameters to find the index of its
	      //	new instantiation in the argument list we were passed.
	      //
	      int boundParameterName = paramArgs[j];
	      int index = findParameterIndex(boundParameterName);
	      Assert(index != NONE && index < nrBoundParameters, "didn't find bound parameter");
	      View* v2 = arguments[index];
	      newViewArgs[i] = v2;
	      newParamArgs[i] = parameterArgs[index];
	      if (v2 != 0 && MixfixModule::isTheory(v2->getToModule()->getModuleType()))
		{
		  //
		  //	Instantiating a bound parameter by a theory-view allows it
		  //	to escape. This must be recorded so that it can be rebound
		  //	in a subsequent instantiation. escapedParameters maps
		  //	from the free name of a parameter to the name of the
		  //	external parameter is was bound to before it escaped.
		  //
		  escapedParameters[freeParameterName] = boundParameterName;
		}
	    }
	  else
	    {
	      //
	      //	The free parameter was originally instantiated by a view
	      //	so this instantiation does not change.
	      //
	      newViewArgs[i] = v;
	      newParamArgs[i] = 0;
	    }
	  ++j;
	}
      else
	{
	  //
	  //	The free parameter is an escapee that wasn't free in base module
	  //	so we instantiate it by the parameter it escaped from.
	  //
	  newViewArgs[i] = 0;
	  newParamArgs[i] = e->second;
	}
    }
  return moduleCache->makeInstatiation(foundation, newViewArgs, newParamArgs);
}
