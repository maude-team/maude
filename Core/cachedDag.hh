//
//      Class dags that are constructed from terms as then cached for reuse.
//
#ifndef _cachedDag_hh_
#define _cachedDag_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "dagRoot.hh"

class CachedDag
{
public:
  CachedDag(Term* t = 0);
  ~CachedDag();

  void setTerm(Term* t);
  Term* getTerm() const;
  bool normalize();
  void prepare();
  DagNode* getDag();
  void reset();

private:
  Term* term;
  DagRoot dag;
};

inline
CachedDag::CachedDag(Term* t)
{
  term = t;
}

inline
CachedDag::~CachedDag()
{
  if (term != 0)
    term->deepSelfDestruct();
}

inline void
CachedDag::setTerm(Term* t)
{
  term = t;
  dag.setNode(0);
}

inline Term*
CachedDag::getTerm() const
{
  return term;
}

inline bool
CachedDag::normalize()
{
  bool changed;
  term = term->normalize(true, changed);
  return changed;
}

inline DagNode*
CachedDag::getDag()
{
  DagNode* d = dag.getNode();
  if (d == 0)
    {
      d = term->term2Dag(term->getSortIndex() != Sort::SORT_UNKNOWN);  // HACK
      dag.setNode(d);
    }
  return d;
}

inline void
CachedDag::reset()
{
  dag.setNode(0);  // so dag can be garbage collected
}

#endif
