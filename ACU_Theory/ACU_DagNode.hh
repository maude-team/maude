//
//	Class for DAG nodes in the AC and ACU theories.
//
#ifndef _ACU_DagNode_hh_
#define _ACU_DagNode_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "dagNode.hh"
#include "argVec.hh"

class ACU_DagNode : public DagNode
{
public:
  enum NormalizationStatus
  {
    //
    //	Default: no guarantees.
    //
    FRESH,
    //
    //	Node was produced by a partial replacement after matching:
    //	(a) all arguments except the last are reduced up to strategy
    //	    of our symbol (this only holds if it was true of subject
    //	    before matching);
    //	(b) all arguments except the last have the correct sort; and
    //	(c) argument list except for last argument is in theory normal form.
    //	There is no guarantee about our sort since extension could be in
    //	the error sort.
    //
    EXTENSION,
    //
    //	Node was produced by an assignment in ACU matcher:
    //	(a) all arguments are reduced up to strategy of our symbol
    //	   (this only holds if it was true of subject before matching);
    //	(b) all arguments have the correct sort;
    //	(c) argument list in theory normal form; and
    //
    ASSIGNMENT
  };

  ACU_DagNode(ACU_Symbol* symbol, int size);
  ~ACU_DagNode();
  //
  //	Member functions required by theory interface.
  //
  RawDagArgumentIterator* arguments();
  size_t getHashValue();
  int compareArguments(const DagNode* other) const;
  void overwriteWithClone(DagNode* old);
  DagNode* makeClone();
  DagNode* copyWithReplacement(int argIndex, DagNode* replacement);
  DagNode* copyWithReplacement(Vector<RedexPosition>& redexStack,
			       int first,
			       int last);
  void stackArguments(Vector<RedexPosition>& stack,
		      int parentIndex,
		      bool respectFrozen);
  //
  //	Member functions required to handle extension information.
  //
  bool matchVariableWithExtension(int index,
				  const Sort* sort,
				  Substitution& solution,
				  Subproblem*& returnedSubproblem,
				  ExtensionInfo* extensionInfo);
  void partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo);
  DagNode* partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo);
  ExtensionInfo* makeExtensionInfo();
  //
  //    Functions particular to ACU_DagNode.
  //
  ACU_Symbol* symbol() const;
  int nrArgs() const;
  DagNode* getArgument(int i) const;
  int getMultiplicity(int i) const;
  NormalizationStatus getNormalizationStatus() const;
  void setNormalizationStatus(NormalizationStatus status);

private:
  enum Sizes
  {
    INITIAL_RUNS_BUFFER_SIZE = 4	// must be > 0
  };
  
  struct Pair
  {
    void set(DagNode* d, int m);

    DagNode* dagNode;
    int multiplicity;
  };

  //
  //	Theory interface functions.
  //
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
  //
  //	Normalization functions.
  //
  bool normalizeAtTop();
  bool extensionNormalizeAtTop();
  void binaryInsert(DagNode* dagNode, int multiplicity);
  void copyAndBinaryInsert(const ACU_DagNode* source, DagNode* dagNode, int multiplicity);
  void fastMerge(const ACU_DagNode* source0, const ACU_DagNode* source1);
  void sortAndUniquize();
  void flattenSortAndUniquize(int expansion);
  void mergeSortAndUniquize();
  //
  //	Functions for ACU specific operations.
  //
  int findFirstOccurrence(Symbol* key) const;
  bool binarySearch(DagNode* key, int& pos) const;
  bool binarySearch(Term* key, int& pos) const;
  bool eliminateSubject(DagNode* target,
			int multiplicity,
			Vector<int>& subjectMultiplicity);
  bool eliminateArgument(Term* target);
  //
  //	Arguments under ACU symbol.
  //
  ArgVec<Pair> argArray;
  //
  //	Pre-allocated buffer for run-time use.
  //
  static Vector<int> runsBuffer;
  //
  //	Most related classes need direct access to our argument list for efficiency.
  //
  friend class ACU_Symbol;		// to reduce subterms prior to rewrite, normalization
  friend class ACU_Term;		// for term->DAG conversion & comparison
  friend class ACU_LhsAutomaton;	// for matching DAG subject
  friend class ACU_AlienAlienLhsAutomaton;	// for matching DAG subject
  friend class ACU_CollectorLhsAutomaton;	// for matching DAG subject
  friend class ACU_NGA_LhsAutomaton;	// for matching DAG subject
  friend class ACU_VarLhsAutomaton;	// for matching DAG subject
  friend class ACU_GndLhsAutomaton;	// for matching DAG subject
  friend class ACU_NonLinearLhsAutomaton;	// for matching DAG subject
  friend class ACU_RhsAutomaton;	// for constructing replacement DAG
  friend class ACU_Subproblem;		// for constructing substitution
  friend class ACU_ExtensionInfo;	// for constructing matched portion
  friend class ACU_DagArgumentIterator;	// to accesss Pair
};

inline void
ACU_DagNode::Pair::set(DagNode* d, int m)
{
  dagNode = d;
  multiplicity = m;
}

inline
ACU_DagNode::ACU_DagNode(ACU_Symbol* symbol, int size)
  : DagNode(symbol), argArray(size)
{
  setTheoryByte(FRESH);
}

inline ACU_Symbol*
ACU_DagNode::symbol() const
{
  return static_cast<ACU_Symbol*>(DagNode::symbol());
}

inline int
ACU_DagNode::nrArgs() const
{
  return argArray.length();
}

inline DagNode*
ACU_DagNode::getArgument(int i) const
{
  return argArray[i].dagNode;
}

inline int
ACU_DagNode::getMultiplicity(int i) const
{
  return argArray[i].multiplicity;
}

inline ACU_DagNode::NormalizationStatus
ACU_DagNode::getNormalizationStatus() const
{
  return static_cast<NormalizationStatus>(getTheoryByte());
}

inline void
ACU_DagNode::setNormalizationStatus(NormalizationStatus status)
{
  setTheoryByte(status);
}

#endif
