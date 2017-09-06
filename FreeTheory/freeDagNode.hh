//
//	Class for DAG nodes in the free theory.
//
#ifndef _freeDagNode_hh_
#define _freeDagNode_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "dagNode.hh"

class FreeDagNode : public DagNode
{
public:
  FreeDagNode(Symbol* symbol);
  ~FreeDagNode();

  RawDagArgumentIterator* arguments();
  size_t getHashValue();
  int compareArguments(const DagNode* other) const;
  void overwriteWithClone(DagNode* old);
  DagNode* makeClone();
  DagNode* copyWithReplacement(Vector<RedexPosition>& redexStack,
			       int first,
			       int last);
  DagNode* copyWithReplacement(int argIndex, DagNode* replacement);
  void stackArguments(Vector<RedexPosition>& stack,
		      int parentIndex,
		      bool respectFrozen);
  //
  //	Fast theory specific access to argument list
  //
  DagNode* getArgument(int i) const;

private:
  union Word  // HACK - should make MemoryCell::Word visible
  {
    void* pointer;
    int integer;
    size_t size;
  };

  union
    {
      DagNode* internal[nrWords];
      DagNode** external;
      Word hashCache[nrWords];
    };

  DagNode** argArray() const;
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();  
  void clearCopyPointers2();
    
  friend class FreeSymbol;		// to reduce subterms prior to rewrite
  friend class FreeUnarySymbol;		// to reduce subterms prior to rewrite
  friend class FreeBinarySymbol;	// to reduce subterms prior to rewrite
  friend class FreeTernarySymbol;	// to reduce subterms prior to rewrite
  friend class FreeTerm;		// for term->DAG conversion & comparison
  friend class FreeLhsAutomaton;	// for matching DAG subject
  friend class FreeNet;			// for matching DAG subject
  friend class FreeRhsAutomaton;	// for constructing replacement DAG
};

inline
FreeDagNode::FreeDagNode(Symbol* symbol) : DagNode(symbol)
{
  int nrArgs = symbol->arity();
  if (nrArgs > nrWords)
    {
      setCallDtor();  // need our dtor called when garbage collected so we can free arg array
      external = new (DagNode*)[nrArgs];
    }
}

inline DagNode*
FreeDagNode::getArgument(int i) const
{
  Assert(i >= 0, cerr << "-ve arg number");
  int nrArgs = symbol()->arity();
  Assert(i < nrArgs, cerr << "arg number too big");
  return (nrArgs > nrWords) ? external[i] : internal[i];
}

inline DagNode**
FreeDagNode::argArray() const
{
  return (symbol()->arity() > nrWords) ? external : const_cast<DagNode**>(&(internal[0]));
}

#endif

