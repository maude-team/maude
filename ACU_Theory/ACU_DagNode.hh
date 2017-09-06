//
//	Class for ArgVec based DAG nodes in the AC and ACU theories.
//
#ifndef _ACU_DagNode_hh_
#define _ACU_DagNode_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "ACU_BaseDagNode.hh"
#include "argVec.hh"
#include "ACU_FastIter.hh"

class ACU_DagNode : public ACU_BaseDagNode
{
public:
  ACU_DagNode(ACU_Symbol* symbol, int size);
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
  //
  //    Functions particular to ACU_DagNode.
  //
  int nrArgs() const;
  DagNode* getArgument(int i) const;
  int getMultiplicity(int i) const;

private:
  enum Sizes
  {
    INITIAL_RUNS_BUFFER_SIZE = 4,	// must be > 0
    CONVERT_THRESHOLD = 16,
    MERGE_THRESHOLD = 32

    //CONVERT_THRESHOLD = 0,
    //MERGE_THRESHOLD = 0

    //CONVERT_THRESHOLD = 25,
    //MERGE_THRESHOLD = 50
  };
  
  struct Pair
  {
    Pair(DagNode* d, int m);
    Pair();

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
  static ArgVec<Pair>::iterator fastCopy(ArgVec<Pair>::const_iterator i,
					 ArgVec<Pair>::const_iterator e,
					 ArgVec<Pair>::iterator d);
  static ArgVec<Pair>::iterator fastCopy(ACU_FastIter& i,
					 ArgVec<Pair>::iterator d);

  bool normalizeAtTop();
  bool extensionNormalizeAtTop();
  void binaryInsert(DagNode* dagNode, int multiplicity);
  void copyAndBinaryInsert(const ACU_DagNode* source, DagNode* dagNode, int multiplicity);
  void fastMerge(const ACU_DagNode* source0, const ACU_DagNode* source1);
  void fastMerge(const ACU_DagNode* source0, const ACU_TreeDagNode* source1);
  void fastMerge(const ACU_TreeDagNode* source0, const ACU_TreeDagNode* source1);

  void sortAndUniquize();
  void flattenSortAndUniquize(int expansion);
  void mergeSortAndUniquize();

  void collapse(DagNode* arg);
  void insertAlien(ACU_BaseDagNode* normalForm,
		   int nMult,
		   DagNode* alien,
		   int aMult);


  ACU_RedBlackNode* makeTree();
  static bool pow2min1(int i);
  static ACU_RedBlackNode* makeTree(const ArgVec<Pair>& args,
				    int first,
				    int size,
				    bool makeRed);


  //
  //	Functions for ACU specific operations.
  //
  int findFirstOccurrence(Symbol* key) const;
  int findFirstPotentialMatch(Term* key, const Substitution& partial) const;
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

  friend class ACU_TreeDagNode;		// for conversion
  friend class ACU_BaseDagNode;		// HACK for getSize

  friend ACU_DagNode* getACU_DagNode(DagNode* dagNode);
};

inline
ACU_DagNode::Pair::Pair()
{
}

inline
ACU_DagNode::Pair::Pair(DagNode* d, int m)
{
  dagNode = d;
  multiplicity = m;
}

inline void
ACU_DagNode::Pair::set(DagNode* d, int m)
{
  dagNode = d;
  multiplicity = m;
}

inline
ACU_DagNode::ACU_DagNode(ACU_Symbol* symbol, int size)
  : ACU_BaseDagNode(symbol), argArray(size)
{
  setTheoryByte(FRESH);
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

inline ArgVec<ACU_DagNode::Pair>::iterator
ACU_DagNode::fastCopy(ArgVec<Pair>::const_iterator i,
		      ArgVec<Pair>::const_iterator e,
		      ArgVec<Pair>::iterator d)
{
  //
  //	This beats the STL copy() algorithm because the latter maintains
  //	a counter.
  //
  while (i != e)
    {
      *d = *i;
      ++d;
      ++i;
    }
  return d;
}

inline ArgVec<ACU_DagNode::Pair>::iterator
ACU_DagNode::fastCopy(ACU_FastIter& i,
		      ArgVec<Pair>::iterator d)
{
  while (i.valid())
    {
      d->dagNode = i.getDagNode();
      d->multiplicity = i.getMultiplicity();
      ++d;
      i.next();
    }
  return d;
}

#endif
