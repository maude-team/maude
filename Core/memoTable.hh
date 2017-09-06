//
//      Class for memoization tables.
//
#ifndef _memoTable_hh_
#define _memoTable_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "simpleRootContainer.hh"

class MemoTable
{
public:
  class SourceSet : private SimpleRootContainer
  {
    void markReachableNodes();
    Vector<DagNode*> sources;
    friend class MemoTable;
  };

  MemoTable(bool memoFlag);
  ~MemoTable();

  bool isMemoized() const;
  bool memoRewrite(SourceSet& sourceSet, DagNode* subject, RewritingContext& context);
  void memoEnter(SourceSet& sourceSet, DagNode* destination);
  void clearMemo();

private:
  struct dagNodeLt;
  class MemoMap;

  const bool memo;
  MemoMap* memoMap;
};

inline
MemoTable::MemoTable(bool memoFlag)
  : memo(memoFlag)
{
  memoMap = 0;
}

inline bool
MemoTable::isMemoized() const
{
  return memo;
}

#endif

