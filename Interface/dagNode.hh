//
//      Abstract base class for dag nodes.
//	This class also provides memory management for dag nodes (mandatory)
//	together with their variable length contents (optional).
//	
//
#ifndef _dagNode_hh_
#define _dagNode_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "memoryCell.hh"
#include "redexPosition.hh"

class DagNode : private MemoryCell
{
  NO_COPYING(DagNode);

public:
  DagNode(Symbol* symbol);
  virtual ~DagNode() {}
  //
  //	HACK we need to pass this stuff thru for the moment.
  //
  MemoryCell::okToCollectGarbage;
  MemoryCell::setCallDtor;
  //
  //	Static members (for memory management).
  //
  void* operator new(size_t size);
  void* operator new(size_t size, DagNode* old);
  //
  //	These member functions should not be overridden.
  //
  Symbol* symbol() const;
  int compare(const DagNode* other) const;
  bool equal(const DagNode* other) const;
  bool leq(const Sort* sort) const;

  bool isReduced() const;
  void reduce(RewritingContext& context);
  void mark();
  void setReduced();
  void setUnrewritable();
  bool isUnrewritable() const;
  void setUnstackable();
  bool isUnstackable() const;
  Byte getTheoryByte() const;
  void setTheoryByte(Byte value);

  DagNode* copyReducible();
  DagNode* copyEagerUptoReduced();
  void clearCopyPointers();
  DagNode* copyAndReduce(RewritingContext& context);
  void setSortIndex(int index);
  int getSortIndex() const;
  Sort* getSort() const;
  void computeTrueSort(RewritingContext& context);
  void repudiateSortInfo();
  bool checkSort(const Sort* boundSort, Subproblem*& returnedSubproblem);
  bool checkSort(const Sort* boundSort, RewritingContext& context);
  bool inErrorSort();
  bool matchVariable(int index,
		     const Sort* sort,
		     bool copyToAvoidOverwriting,
		     Substitution& solution,
		     Subproblem*& returnedSubproblem,
		     ExtensionInfo* extensionInfo);
  //
  //	These member functions must be defined for each derived class.
  //
  virtual RawDagArgumentIterator* arguments() = 0;
  virtual size_t getHashValue() = 0;
  virtual int compareArguments(const DagNode* other) const = 0;
  virtual void overwriteWithClone(DagNode* old) = 0;
  virtual DagNode* makeClone() = 0;
  virtual DagNode* copyWithReplacement(int argIndex, DagNode* replacement) = 0;
  virtual DagNode* copyWithReplacement(Vector<RedexPosition>& redexStack,
				       int first,
				       int last) = 0;
  virtual void stackArguments(Vector<RedexPosition>& redexStack,
			      int parentIndex,
			      bool respectFrozen) = 0;
  //
  //	These member functions must be defined for each derived class in theories
  //	that need extension
  //
  virtual bool matchVariableWithExtension(int index,
					  const Sort* sort,
					  Substitution& solution,
					  Subproblem*& returnedSubproblem,
					  ExtensionInfo* extensionInfo);
  virtual void partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo);
  virtual DagNode* partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo);
  virtual ExtensionInfo* makeExtensionInfo();

#ifdef DUMP
  //
  //	dump() routine is optional; Default will dump common stuff togther with args
  //	in naive way. Replacement routine should call dumpCommon() to dump stuff in
  //	base class.
  //
  virtual void dump(ostream& s, int indentLevel = 0);
  void dumpCommon(ostream& s, int indentLevel);
#endif

protected:
  enum Sizes
  {
    //
    //	We use 2 of the available words in a memory cell; one for our
    //	symbol/copy pointer and one for our virtual function table pointer.
    //	It would be nice to do this in a cleaner way, rather than assume
    //	the existence/size of our virtual function table pointer.
    //
    nrWords = NR_EXTRA_WORDS - 2
  };

  static size_t hash(size_t v1, size_t v2);
  static size_t hash(size_t v1, size_t v2, size_t v3);
  //
  //	Functions to set and test the status of the hash valid flag.
  //
  void setHashValid();
  bool isHashValid() const;
  //
  //	These member functions must be defined for each derived class.
  //
  virtual DagNode* markArguments() = 0;
  virtual DagNode* copyEagerUptoReduced2() = 0;
  virtual void clearCopyPointers2() = 0;

private:  
  enum Flags
  {
    REDUCED = 1,	// reduced up to strategy by equations
    COPIED = 2,		// copied in current copy operation; copyPointer valid
    UNREWRITABLE = 4,	// reduced and not rewritable by rules
    UNSTACKABLE = 8,	// unrewritable and all subterms unstackable or frozen
    CACHED = 16,	// node exists as part of a cache
    HASH_VALID = 32	// node has a valid hash value (storage is theory dependent)
  };

  bool isCopied() const;
  void setCopied();
  void clearCopied();

  union
  {
    //
    //	Since copy pointers are needed infrequently we will use the top symbol slot
    //	and restore the top symbol from the copy of the dag node when the entire
    //	copy operation in finished; this is slightly hairy but dag nodes are the
    //	fundemental runtime data structure and need to be highly optimized.
    //
    Symbol* topSymbol;
    DagNode* copyPointer;
  };
};

//
//	Output function for DagNode must be defined by library user.
//
ostream& operator<<(ostream& s, DagNode* dagNode);

inline int
DagNode::getSortIndex() const
{
  return getHalfWord();
}

inline void
DagNode::setSortIndex(int index)
{
  setHalfWord(index);
}

inline void
DagNode::repudiateSortInfo()
{
  setSortIndex(Sort::SORT_UNKNOWN);
}

#include "memoryCellNew.hh"

inline void*
DagNode::operator new(size_t  size)
{
  //
  //	We rely on the MemoryCell new() setting the half word to
  //	Sort::SORT_UNKNOWN.
  //
  return MemoryCell::operator new(size);
}

inline void*
DagNode::operator new(size_t /* size */, DagNode* old)
{
  if (old->needToCallDtor())
    old->~DagNode();	// explicitly call virtual destructor
  old->clearAllExceptMarked();
  old->repudiateSortInfo();
  return static_cast<void*>(old);
}

inline
DagNode::DagNode(Symbol* symbol)
{
  topSymbol = symbol;
}

inline Symbol*
DagNode::symbol() const
{
  return topSymbol;
}

inline int
DagNode::compare(const DagNode* other) const
{
  if (this == other)
    return 0;  // pointers to same shared node
  Symbol* s = other->topSymbol;
  return (topSymbol == s) ? compareArguments(other) : topSymbol->compare(s);
}

inline bool
DagNode::equal(const DagNode* other) const
{
  return this == other || (topSymbol == other->topSymbol && compareArguments(other) == 0);
}

inline bool
DagNode::isReduced() const
{
  return getFlag(REDUCED);
}

inline void
DagNode::setReduced()
{
  setFlag(REDUCED);
}

inline bool
DagNode::isCopied() const
{
  return getFlag(COPIED);
}

inline void
DagNode::setCopied()
{
  setFlag(COPIED);
}

inline void
DagNode::clearCopied()
{
  clearFlag(COPIED);
}

inline void
DagNode::setUnrewritable()
{
  setFlag(UNREWRITABLE);
}

inline bool
DagNode::isUnrewritable() const
{
  return getFlag(UNREWRITABLE);
}

inline void
DagNode::setUnstackable()
{
  setFlag(UNSTACKABLE);
}

inline bool
DagNode::isUnstackable() const
{
  return getFlag(UNSTACKABLE);
}

inline void
DagNode::setHashValid()
{
  setFlag(HASH_VALID);
}

inline bool
DagNode::isHashValid() const
{
  return getFlag(HASH_VALID);
}

inline Byte
DagNode::getTheoryByte() const
{
  return getByte();
}

inline void
DagNode::setTheoryByte(Byte value)
{
  setByte(value);
}

//
//	We use Symbol::fastComputeTrueSort() inline function which in turn uses
//	our setSortIndex() inline function.
//
#include "symbol2.hh"

inline void
DagNode::reduce(RewritingContext& context)
{
  if (!isReduced())
    {
      while (topSymbol->eqRewrite(this, context))
	;
      setReduced();
      //      if (sortIndex == Sort::SORT_UNKNOWN)
      topSymbol->fastComputeTrueSort(this, context);
    }
}

inline void
DagNode::mark()
{
  Assert(this != 0, cerr << "bad dag node");
  Assert(topSymbol->arity() >= 0, cerr << "bad symbol");
  DagNode* d = this;
  while (!(d->isMarked()))
    {
      d->setMarked();
      //
      //	markArguments() returns a pointer our the last argument
      //	rather than calling mark() on it. This allows us to
      //	do tail recursion elimination on the last argument
      //	which is important for cons style lists.
      //
      d = d->markArguments();
      if (d == 0)
	break;  // leaf
    }
}

inline bool
DagNode::inErrorSort()
{
  int t = getSortIndex();
  if (t == Sort::SORT_UNKNOWN)
    {
      topSymbol->computeBaseSort(this);
      t = getSortIndex();
      if (!(topSymbol->sortConstraintFree()))
	setSortIndex(Sort::SORT_UNKNOWN);
    }
  return t == Sort::ERROR_SORT;
}

inline Sort*
DagNode::getSort() const
{
  return (getSortIndex() == Sort::SORT_UNKNOWN) ? 0 :
    topSymbol->rangeComponent()->sort(getSortIndex());
}

inline void
DagNode::computeTrueSort(RewritingContext& context)
{
  if (getSortIndex() == Sort::SORT_UNKNOWN)
    topSymbol->normalizeAndComputeTrueSort(this, context);
}

inline DagNode*
DagNode::copyEagerUptoReduced()
{
  if (isReduced())
    return this;
  if (!isCopied())
    {
      setCopied();
      copyPointer = copyEagerUptoReduced2();  // this destroys our top symbol
    }
  return copyPointer;
}

inline void
DagNode::clearCopyPointers()
{
  if (isCopied())
    {
      clearCopied();
      topSymbol = copyPointer->topSymbol;  // restore our top symbol from copy
      clearCopyPointers2();  // can't safely call this until top symbol restored
    }
}

inline DagNode*
DagNode::copyReducible()
{
  DagNode* d = copyEagerUptoReduced();
  clearCopyPointers();
  return d;
}

inline DagNode*
DagNode::copyAndReduce(RewritingContext& context)
{
  DagNode* d = copyReducible();
  d->reduce(context);
  return d;
}

inline bool
DagNode::leq(const Sort* sort) const
{
  return ::leq(getSortIndex(), sort);
}

inline size_t
DagNode::hash(size_t v1, size_t v2)
{
  return 3 * v1 + v2;
}

inline size_t
DagNode::hash(size_t v1, size_t v2, size_t v3)
{
  return 3 * v1 + v2 * v3;
}

#endif
