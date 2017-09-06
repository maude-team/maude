//
//	Abstract class for table of sort constraints indexed under some symbol.
//
#ifndef _sortConstraintTable_hh_
#define _sortConstraintTable_hh_
#ifdef __GNUG__
#pragma interface
#endif

class SortConstraintTable
{
public:
  SortConstraintTable();

  void offerSortConstraint(SortConstraint* sortConstraint);
  const Vector<SortConstraint*>& getSortConstraints() const;
  bool sortConstraintFree() const;
  void orderSortConstraints();
  virtual void compileSortConstraints();
  void constrainToSmallerSort(DagNode* subject, RewritingContext& context);
  void constrainToExactSort(DagNode* subject, RewritingContext& context);
  
protected:
  bool safeToInspectSortConstraints();
  virtual bool acceptSortConstraint(SortConstraint* sortConstraint) = 0;
  
private:
  static bool sortConstraintLt(SortConstraint* const& sc1, SortConstraint* const& sc2);
  void constrainToSmallerSort2(DagNode* subject, RewritingContext& context);

  bool tableComplete;
  Vector<SortConstraint*> sortConstraints;
};

inline void
SortConstraintTable::offerSortConstraint(SortConstraint* sortConstraint)
{
  if (acceptSortConstraint(sortConstraint))
    sortConstraints.append(sortConstraint);
}

inline const Vector<SortConstraint*>&
SortConstraintTable::getSortConstraints() const
{
  return sortConstraints;
}

inline bool
SortConstraintTable::sortConstraintFree() const
{
  return sortConstraints.isNull();
}

inline void
SortConstraintTable::constrainToSmallerSort(DagNode* subject, RewritingContext& context)
{
  if (!sortConstraintFree())
    constrainToSmallerSort2(subject, context);
}

inline void
SortConstraintTable::constrainToExactSort(DagNode* subject, RewritingContext& context)
{
  if (!sortConstraintFree())
    constrainToSmallerSort2(subject, context);
}

inline bool
SortConstraintTable::safeToInspectSortConstraints()
{
  return tableComplete;
}

#endif
