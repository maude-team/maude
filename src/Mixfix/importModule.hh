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
//      Class for modules which can import and be imported.
//
#ifndef _importModule_hh_
#define _importModule_hh_
#include <set>
#include <map>
#include "mixfixModule.hh"
#include "entity.hh"
#include "fileTable.hh"

class ImportModule
  : public MixfixModule,
    public Entity,
    public Entity::User
{
  NO_COPYING(ImportModule);

public:
  enum ImportMode
  {
    PROTECTING,
    EXTENDING,
    INCLUDING
  };

  ImportModule(int name, ModuleType moduleType, Entity::User* parent = 0);
  ~ImportModule();

  void addImport(ImportModule* importedModule,
		 ImportMode mode,
		 LineNumber lineNumber);
  void addParameter(const Token parameterName,
		    ImportModule* parameterTheory);
  void closeSortSet();
  void closeSignature();
  void deepSelfDestruct();
  void importSorts();
  void importOps();
  void fixUpImportedOps();
  void importStatements();
  void resetImports();

  void localStatementsComplete();
  void protect();
  bool unprotect();

  int getNrParameters() const;
  int getNrFreeParameters() const;
  ImportModule* getParameterTheory(int index) const;
  int getNrImportedSorts() const;
  int getNrUserSorts() const;
  int getNrImportedSubsorts(int sortIndex) const;
  int getNrImportedSymbols() const;
  int getNrImportedPolymorphs() const;
  int getNrUserSymbols() const;
  int getNrImportedDeclarations(int symbolIndex) const;
  int getNrUserDeclarations(int symbolIndex) const;
  int getNrOriginalMembershipAxioms() const;
  int getNrOriginalEquations() const;
  int getNrOriginalRules() const;
  const set<int>& getLabels() const;
  ImportModule* makeRenamedCopy(int name, Renaming* canonical, ModuleCache* moduleCache);
  ImportModule* makeParameterCopy(int moduleName, int parameterName, ModuleCache* moduleCache);
  ImportModule* makeInstantiation(int moduleName, const Vector<View*>& arguments, const Vector<int>& parameterArgs, ModuleCache* moduleCache);
  int findParameterIndex(int name) const;

private:
  enum Phase
  {
    UNVISITED,
    SORTS_IMPORTED,
    OPS_IMPORTED,
    OPS_FIXED_UP,
    STATEMENTS_IMPORTED,
    DOOMED
  };

  typedef map<int,int> ParameterMap;

  static Sort* localSort(ImportModule* copy, Renaming* renaming, const Sort* sort);
  static Sort* localSort2(ImportModule* copy, Renaming* renaming, const Sort* sort);
  static void deepCopyCondition(ImportTranslation* importTranslation,
				const Vector<ConditionFragment*>& original,
				Vector<ConditionFragment*>& copy);

  void regretToInform(Entity* doomedEntity);
  void donateSorts(ImportModule* importer);
  void donateSorts2(ImportModule* copy, Renaming* renaming = 0);
  void donateOps(ImportModule* importer);
  void donateOps2(ImportModule* copy, Renaming* renaming = 0);
  void fixUpDonatedOps(ImportModule* importer);
  void fixUpDonatedOps2(ImportModule* copy, Renaming* renaming = 0);
  void donateStatements(ImportModule* importer);
  void donateStatements2(ImportModule* importer, ImportTranslation& importTranslation);
  void resetImportPhase();
  void finishCopy(ImportModule* copy, Renaming* canonical);

  Phase importPhase;
  //
  //	These are the theories and modules we directly import.
  //
  //	0,...,nrBoundParameters - 1				bound parameters
  //	nrBoundParameters,..., parameterNames.size() - 1	free parameters
  //	parameterNames.size(),..., importedModules.size() - 1	regular imports
  //
  int nrBoundParameters;
  Vector<int> parameterNames;
  //  Vector<ImportModule*> parameterTheories;
  Vector<ImportModule*> importedModules;
  //
  //	If we are a renaming of another module we need to store this info.
  //
  Renaming* canonicalRenaming;
  ImportModule* baseModule;
  //
  //	Need to keep track of what parts of MixfixModule actually belong
  //	to us (and need to be donated to our importers) and what parts
  //	we imported or otherwise generated.
  //
  //	For sorts, symbols and op declarations, imports come first,
  //	then locals, then generated.
  //
  //	For subsorts, imported subsort (relations) come first, then locals.
  //	The are no generated subsort relations.
  //
  //	For mbs, eqs, and rls, locals come first, then imports.
  //	The reason for this different order is to avoid imports unless
  //	we ace actually going to do some work in the module.
  //
  int nrUserSorts;			// total number of user declared sorts
  int nrImportedSorts;			// how many of these were imported
  Vector<int> nrImportedSubsorts;	// for each sort, how many subsorts were imported

  int nrUserSymbols;			// total number of user symbols
  int nrImportedSymbols;		// how many of these were imported
  //
  //	For each symbol:
  //
  Vector<int> nrUserDecls;		// total number of user declarations
  Vector<int> nrImportedDecls;		// total number of imported user declarations

  int nrImportedPolymorphs;		// number of polymorphs that were imported
  int nrOriginalMembershipAxioms;
  int nrOriginalEquations;
  int nrOriginalRules;

  set<int> labels;
  int protectCount;
};

inline void
ImportModule::protect()
{
  ++protectCount;
}

inline int
ImportModule::getNrImportedSorts() const
{
  //
  //	Sorts with index < this value were imported.
  //
  return nrImportedSorts;
}

inline int
ImportModule::getNrParameters() const
{
  return parameterNames.size();
}

inline int
ImportModule::getNrFreeParameters() const
{
  return parameterNames.size() - nrBoundParameters;
}

inline ImportModule*
ImportModule::getParameterTheory(int index) const
{
  Assert(index < getNrParameters(), "bad parameter index " << index);
  return importedModules[index]->baseModule;
}

inline int
ImportModule::getNrUserSorts() const
{
  //
  //	Sorts with index >= this value were generated (e.g. for kinds).
  //
  return nrUserSorts;
}

inline int
ImportModule::getNrImportedSubsorts(int sortIndex) const
{
  //
  //	Subsorts with index < this value were imported.
  //
  return (sortIndex < nrImportedSorts) ? nrImportedSubsorts[sortIndex] : 0;
}

inline int
ImportModule::getNrImportedSymbols() const
{
  //
  //	Symbols with index < this value were imported.
  //
  return nrImportedSymbols;
}

inline int
ImportModule::getNrImportedPolymorphs() const
{
  //
  //	Symbols with index < this value were imported.
  //
  return nrImportedPolymorphs;
}

inline int
ImportModule::getNrUserSymbols() const
{
  //
  //	Symbols with index >= this value were generated (e.g. for polymorph instantiation).
  //
  return nrUserSymbols;
}

inline int
ImportModule::getNrImportedDeclarations(int symbolIndex) const
{
  //
  //	Declarations with index < this value were imported.
  //
  return (symbolIndex >= nrImportedSymbols) ? 0 : nrImportedDecls[symbolIndex];
}

inline int
ImportModule::getNrUserDeclarations(int symbolIndex) const
{
  //
  //	Declarations with index >= this value were generated (e.g. for comm completion).
  //
  return nrUserDecls[symbolIndex];
}

inline int
ImportModule::getNrOriginalMembershipAxioms() const
{
  //
  //	Membership axioms with index >= this value were imported.
  //
  return nrOriginalMembershipAxioms;
}

inline int
ImportModule::getNrOriginalEquations() const
{
  //
  //	 Equations with index >= this value were imported.
  //
  return nrOriginalEquations;
}
 
inline int
ImportModule::getNrOriginalRules() const
{
  //
  //	 Rules with index >= this value were imported.
  //
  return nrOriginalRules;
}

inline const set<int>&
ImportModule::getLabels() const
{
  return labels;
}

#endif
