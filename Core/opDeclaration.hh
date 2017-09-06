//
//	Class for operator declarations.
//
#ifndef _opDeclaration_hh_
#define _opDeclaration_hh_

class OpDeclaration
{
public:
  void setInfo(const Vector<Sort*>& domainAndRange, bool constructorFlag);
  const Vector<Sort*>& getDomainAndRange() const;
  bool isConstructor() const;

private:
  Vector<Sort*> sortInfo;
  bool ctorFlag;
};

inline void
OpDeclaration::setInfo(const Vector<Sort*>& domainAndRange,
		       bool constructorFlag)
{
  sortInfo = domainAndRange;  // deep copy
  ctorFlag = constructorFlag;
}

inline const Vector<Sort*>& 
OpDeclaration::getDomainAndRange() const
{
  return sortInfo;
}

inline bool
OpDeclaration::isConstructor() const
{
  return ctorFlag;
}

#endif
