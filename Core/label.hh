//
//      Class for rule labels.
//
#ifndef _label_hh_
#define _label_hh_
 
class Label : public NamedEntity
{
public:
  Label(int id);
};

inline
Label::Label(int id)
  : NamedEntity(id)
{
}

#endif
