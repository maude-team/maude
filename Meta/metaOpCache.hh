//
//      Class for cache of meta-operations.
//
#ifndef _metaOpCache_hh_
#define _metaOpCache_hh_

class MetaOpCache
{
  NO_COPYING(MetaOpCache);

public:
  MetaOpCache(int maxSize = 4);
  ~MetaOpCache();

  void insert(FreeDagNode* metaOp, SearchState* state, Int64 lastSolutionNr);
  bool remove(FreeDagNode* metaOp,
	      RewritingContext& parentContext,
	      SearchState*& state,
	      Int64& lastSolutionNr);

  void insert(FreeDagNode* metaOp, RewriteSequenceSearch* search, Int64 lastSolutionNr);
  bool remove(FreeDagNode* metaOp,
	      RewritingContext& parentContext,
	      RewriteSequenceSearch*& search,
	      Int64& lastSolutionNr);


private:
  bool sameProblem(FreeDagNode* m1, DagNode* m2);

  struct Item
  {
    void clear();

    DagRoot* metaOp;
    SearchState* state;
    RewriteSequenceSearch* search;
    Int64 lastSolutionNr;
  };

  const int maxSize;
  Vector<Item> cache;
};

#endif
