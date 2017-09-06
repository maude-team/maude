//
//	Class for discrimination net for the free theory.
//
#ifndef _freeNet_hh_
#define _freeNet_hh_
#include "unionFind.hh"

class FreeNet
{
public:
  ~FreeNet();

  //
  //	Functions to construct a FreeNet.
  //
  int allocateNode(int nrMatchArcs);
  void fillOutNode(int nodeNr,
		   int position,
		   int argIndex,
		   const Vector<Symbol*>&  symbols,
		   const Vector<int>& targets,
		   const Vector<int>& slots,
		   int neqTarget);
  int addRemainderList(const NatSet& liveSet);
  void translateSlots(int nrRealSlots, const Vector<int>& slotTranslation);
  void buildRemainders(const Vector<Equation*>& equations,
		       const NatSet& patternsUsed,
		       const Vector<int>& slotTranslation);
  //
  //	Function to use a FreeNet.
  //
  bool applyReplace(DagNode* subject, RewritingContext& context);

#ifdef DUMP
  void dump(ostream& s, int indentLevel = 0);
#endif

private:
  enum SpecialValues
  {
    LESS = 1,
    GREATER = 0
  };

  struct TestNode
  {
    Symbol* symbol;
    union
    {
      int position;
      DagNode*** positionPtr;
    };
    union
    {
      int slot;
      DagNode*** slotPtr;
    };
#ifdef ALPHA
    //
    //	Optimize layout for 64bit ptrs, 16bit shorts.
    //
    short argIndex;
    short equal;
    short notEqual[2];
#else
    //
    //	Optimize layout for 32bit ptrs and ints.
    //
    int argIndex;
    int equal;
    int notEqual[2];
    int dummy;  // to round size up to 8 machine words
#endif
  };

  struct Triple
  {
    Symbol* symbol;
    int slot;
    int subtree;
  };

  static bool tripleLt(const Triple& p1, const Triple& p2);

  void
  FreeNet::buildTernaryTree(int& nodeIndex,
			    Vector<Triple>& triples,
			    int first,
			    int last,
			    int defaultSubtree,
			    int position,
			    int argIndex);
  bool moreImportant(Symbol* first, Symbol* second);
  bool applyReplace2(DagNode* subject, RewritingContext& context);
  
  Vector<DagNode**> stack;
  Vector<TestNode> net;
#ifdef SPEED_HACKS
  Vector<Vector<FreeRemainder*> > fastApplicable;
#endif
  Vector<FreeRemainder*> remainders;
  Vector<NatSet> applicable;
};

inline bool
FreeNet::applyReplace(DagNode* subject, RewritingContext& context)
{
  return !applicable.isNull() ? applyReplace2(subject, context) : false;
}

#endif
