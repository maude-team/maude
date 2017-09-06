//
//      Class for meta level signature.
//
#ifndef _metaLevel_hh_
#define _metaLevel_hh_
#include "cachedDag.hh"
#include "metaModuleCache.hh"

class MetaLevel
{
  NO_COPYING(MetaLevel);

public:
  MetaLevel();
  MetaLevel(const MetaLevel* original, SymbolMap* map);
  ~MetaLevel();

  bool bind(const char* name, Symbol* symbol);
  bool bind(const char* name, Term* term);
  void postInterSymbolPass();
  void reset();

  DagNode* upResultPair(DagNode* dagNode, MixfixModule* m);
  DagNode* upResultPair(Term* term, MixfixModule* m);
  DagNode* upNoParse(int badTokenIndex);
  DagNode* upAmbiguity(Term* parse1, Term* parse2, MixfixModule* m);
  DagNode* upBool(bool value);
  DagNode* upType(Sort* sort, PointerMap& qidMap);
  DagNode* upKindSet(const Vector<ConnectedComponent*>& kinds);
  DagNode* upSortSet(const Vector<Sort*>& sorts);
  DagNode* upQidList(const Vector<int>& ids);
  DagNode* upResultTriple(DagNode* dagNode,
			  const Substitution& substitution,
			  const VariableInfo& variableInfo,
			  MixfixModule* m);
  DagNode* upFailureTriple();
  DagNode* upResult4Tuple(DagNode* dagNode,
			  const Substitution& substitution,
			  const VariableInfo& variableInfo,
			  DagNode* metaContext,
			  MixfixModule* m);
  DagNode* upFailure4Tuple();
  DagNode* upContext(DagNode* dagNode,
		     MixfixModule* m,
		     DagNode* hole,
		     PointerMap& qidMap,
		     PointerMap& dagNodeMap);
  DagNode* upSubstition(const Substitution& substitution,
			const VariableInfo& variableInfo,
			MixfixModule* m,
			PointerMap& qidMap,
			PointerMap& dagNodeMap);
  DagNode* upNoMatchSubst();
  DagNode* upNoMatchPair();
  DagNode* upMatchPair(const Substitution& substitution,
		       const VariableInfo& variableInfo,
		       DagNode* dagNode,
		       DagNode* hole,
		       MixfixModule* m);

  DagNode* upMbs(bool flat, ImportModule* m, PointerMap& qidMap);
  DagNode* upEqs(bool flat, ImportModule* m, PointerMap& qidMap);
  DagNode* upRls(bool flat, ImportModule* m, PointerMap& qidMap);

  bool downBound(DagNode* metaBound, int& bound) const;
  bool downSaturate(DagNode* metaBound, int& bound) const;
  bool downBound64(DagNode* metaBound, Int64& bound) const;
  bool downSaturate64(DagNode* metaBound, Int64& bound) const;

  bool downBool(DagNode* metaBool, bool& value);
  bool downQid(DagNode* metaQid, int& id);
  MetaModule* downModule(DagNode* metaModule);
  bool downTermAndSort(DagNode* metaTerm ,
		       DagNode* metaSort , 
		       Term*& term ,
		       Sort*& sort ,
		       MixfixModule* m);
  bool downTermPair(DagNode* metaTerm1,
		    DagNode* metaTerm2, 
		    Term*& term1,
		    Term*& term2,
		    MixfixModule* m);
  Term* downTerm(DagNode* metaTerm, MixfixModule* m);
  bool downCondition(DagNode* metaCondition,
		     MixfixModule* m,
		     Vector<ConditionFragment*>& condition);
  bool downSimpleSort(DagNode* metaSort, MixfixModule* m, Sort*& sort);
  bool downType(DagNode* metaType, MixfixModule* m, Sort*& type);
  bool downQidList(DagNode* metaQidList, Vector<int>& ids);
  bool downComponent(DagNode* metaComponent,
		     MixfixModule* m,
		     ConnectedComponent*& component);
  bool downSubstitution(DagNode* metaSubstitution,
			MixfixModule* m,
			Vector<Term*>& variables,
			Vector<Term*>& values);
  bool downAssignment(DagNode* metaAssignment,
		      MixfixModule* m,
		      Vector<Term*>& variables,
		      Vector<Term*>& values);

private:
  enum Implementation
  {
    nrPreallocatedArgs = 3
  };

  enum ComplexSymbolType
  {
    IDENTITY_SYMBOL,
    SPECIAL_SYMBOL,
    POLYMORPH,
    BUBBLE
  };

  enum Flags
  {
    NONEXEC = 1,
    OWISE = 2
  };

  struct AttributeInfo
  {
    AttributeInfo();
    
    SymbolType symbolType;
    Vector<int> strategy;
    NatSet frozen;
    int prec;
    Vector<int> gather;
    Vector<int> format;
    DagNode* identity;
    DagNode* fixUpInfo;
  };

  DagNode* upQid(int id, PointerMap& qidMap);
  DagNode* upJoin(int id, Sort* sort, char sep, PointerMap& qidMap);
  DagNode* upConstant(int id, Sort* sort, PointerMap& qidMap);
  DagNode* upVariable(int id, Sort* sort, PointerMap& qidMap);
  DagNode* upDagNode(DagNode* dagNode,
		     MixfixModule* m,
		     PointerMap& qidMap,
		     PointerMap& dagNodeMap);
  DagNode* upTerm(const Term* term, MixfixModule* m, PointerMap& qidMap);

  DagNode* upAssignment(const Term* variable,
			DagNode* value,
			MixfixModule* m,
			PointerMap& qidMap,
			PointerMap& dagNodeMap);

  DagNode* upMb(const SortConstraint* mb, MixfixModule* m, PointerMap& qidMap);
  DagNode* upEq(const Equation* equation, MixfixModule* m, PointerMap& qidMap);
  DagNode* upRl(const Rule* rule, MixfixModule* m, PointerMap& qidMap);
  DagNode* upLabel(const Label& label, PointerMap& qidMap);
  DagNode* upCondition(const Vector<ConditionFragment*>& condition,
		       MixfixModule* m,
		       PointerMap& qidMap);
  DagNode* upConditionFragment(const ConditionFragment* fragment,
			       MixfixModule* m,
			       PointerMap& qidMap);
  DagNode* upStatementAttributes(MixfixModule* m,
				 MixfixModule::ItemType type,
				 const PreEquation *pe,
				 PointerMap& qidMap);

  bool downVariable(DagNode* metaVariable, MixfixModule* m, Symbol*& vs);
  bool downTypeList(DagNode* metaTypeList, MixfixModule* m, Vector<Sort*>& typeList);
  bool downType2(int id, MixfixModule* m, Sort*& type);
  bool downSimpleSortList(DagNode* metaSortList, MixfixModule* m, Vector<Sort*>& sortList);
  bool downNatList(DagNode* metaNatList, Vector<int>& intList);
  bool downImports(DagNode* metaImports, MetaModule* m);
  bool downImport(DagNode* metaImport, MetaModule* m);
  bool downSorts(DagNode* metaSorts, MixfixModule* m);
  bool downSort(DagNode* metaSort, MixfixModule* m);
  bool downSubsorts(DagNode* metaSubsorts, MixfixModule* m);
  bool downSubsort(DagNode* metaSubsort, MixfixModule* m);
  bool downOpDecls(DagNode* metaOpDecls, MetaModule* m);
  bool downOpDecl(DagNode* metaOpDecl, MetaModule* m);
  bool downAttrSet(DagNode* metaAttrSet, AttributeInfo& ai);
  bool downAttr(DagNode* metaAttr, AttributeInfo& ai);
  bool downBubbleSpec(DagNode* metaBubbleSpec,
		      MetaModule* m,
		      Symbol* topSymbol,
		      int& bubbleSpecIndex);

  void checkHookList(DagNode* metaHookList, SymbolType& symbolType);
  void checkHook(DagNode* metaIdHook, SymbolType& symbolType);
 
  bool downConditionFragment(DagNode* metaConditionFragment,
			     MixfixModule* m,
			     ConditionFragment*& fragment);

  bool downStatementAttrSet(DagNode* metaAttrSet, int& label, int& metadata, FlagSet& flags);
  bool downStatementAttr(DagNode* metaAttr, int& label, int& metadata, FlagSet& flags);

  bool downMembAxs(DagNode* metaMembAxs, MixfixModule* m);
  bool downMembAx(DagNode* metaMembAx, MixfixModule* m);
  bool downEquations(DagNode* metaEquations, MixfixModule* m);
  bool downEquation(DagNode* metaEquation, MixfixModule* m);
  bool downRules(DagNode* metaRules, MixfixModule* m);
  bool downRule(DagNode* metaRule, MixfixModule* m);
  bool downTermList(DagNode* metaTermList, MixfixModule* m, Vector<Term*>& termList);
  bool downAssignment(DagNode* metaAssignment,
		      MixfixModule* m,
		      Vector<Symbol*>& variables,
		      Vector<Term*>& values);

  bool downFixUps(MetaModule* m);
  bool fixUpIdentitySymbol(DagNode* metaIdentity, MetaModule* m, BinarySymbol* s);
  bool fixUpSpecialSymbol(DagNode* metaHookList,
			  MetaModule* m,
			  Symbol* symbol,
			  const Vector<Sort*>& domainAndRange);
  bool downHook(DagNode* metaHook,
		MetaModule* m,
		Symbol* symbol,
		const Vector<Sort*>& domainAndRange);
  bool downOpHook(DagNode* metaOpHook, MetaModule* m, int& purpose, Symbol*& op);
  bool fixUpPolymorph(DagNode* metaHookList, MetaModule* m, int polymorphIndex);
  bool fixUpBubble(DagNode* metaHookList, MetaModule* m, int polymorphIndex);

  //
  //	Metalevel signature (generated by macro expansion).
  //
#define MACRO(SymbolName, SymbolClass, RequiredFlags, NrArgs) \
  SymbolClass* SymbolName;
#include "metaLevelSignature.cc"
#undef MACRO

  CachedDag trueTerm;
  CachedDag falseTerm;
  MetaModuleCache cache;
};

inline
MetaLevel::AttributeInfo::AttributeInfo()
{
  prec = DEFAULT;
  identity = 0;
  fixUpInfo = 0;
}

#endif
