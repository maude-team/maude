//
//      Base class for things which have (user given) names.
//
#ifndef _namedEntity_hh_
#define _namedEntity_hh_
#ifdef __GNUG__
#pragma interface
#endif
 
class NamedEntity
{
public:
  NamedEntity(int id);
  int id() const;

private:
  const int name;
};

inline
NamedEntity::NamedEntity(int id)
  : name(id)
{
}

inline int
NamedEntity::id() const
{
  return name;
}

//
//	Output function for NamedEntity must be defined by library user.
//
ostream& operator<<(ostream& s, const NamedEntity* e);

#endif
