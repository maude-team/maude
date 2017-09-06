//
//      Class for object system rewriting contexts.
//
#ifndef _objectSystemRewritingContext_hh_
#define _objectSystemRewritingContext_hh_
#include "rewritingContext.hh"

class ObjectSystemRewritingContext : public RewritingContext
{
  NO_COPYING(ObjectSystemRewritingContext);

public:
  enum Mode
  {
    STANDARD,	// use standard rewriting
    FAIR,	// use object-message fair rewriting
    EXTERNAL	// as above, but allow interactions with external objects
  };

  ObjectSystemRewritingContext(DagNode* root);

  void setObjectMode(Mode m);
  Mode getObjectMode() const;

private:
  Mode mode;
};

inline
ObjectSystemRewritingContext::ObjectSystemRewritingContext(DagNode* root)
  : RewritingContext(root)
{
  mode = STANDARD;
}

inline void
ObjectSystemRewritingContext::setObjectMode(Mode m)
{
  mode = m;
}

inline ObjectSystemRewritingContext::Mode
ObjectSystemRewritingContext::getObjectMode() const
{
  return mode;
}

#endif
