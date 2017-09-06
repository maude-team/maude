//
//	Nested class within Vector<T> for checked const_iterators.
//
//	Note that in this implementation we assume that swap()ing a pair of
//	Vectors invalidates all iterators that point to their elements.
//	This is stricter but safer than other possibilities.
//

template<class T>
class Vector<T>::const_iterator
// Can't do this because of g++ bug.
//  : public random_access_iterator<T, Vector<T>::difference_type>
{
public:
  //
  //	Types needed by STL algorithms.
  //
  typedef random_access_iterator_tag iterator_category;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  //
  //	Trivial iterator stuff.
  //
  const_iterator();
  const_iterator(const const_iterator& other);
  const_iterator(const iterator& other);  // conversion ctor
  const_iterator& operator=(const const_iterator& other);
  bool operator==(const const_iterator& other) const;
  bool operator!=(const const_iterator& other) const;
  const_reference operator*();
  const_pointer operator->();
  //
  //	Forward iterator stuff.
  //
  const_iterator& operator++();
  const_iterator operator++(int);
  //
  //	Bidirectional iterator stuff.
  //
  const_iterator& operator--();
  const_iterator operator--(int);
  //
  //	Random access iterator stuff.
  //
  const_iterator& operator+=(difference_type delta);
  const_iterator operator+(difference_type delta) const;
  const_iterator& operator-=(difference_type delta);
  const_iterator operator-(difference_type delta) const;
  difference_type operator-(const const_iterator& other) const;
  const_reference operator[](difference_type i) const;
  bool operator<(const const_iterator& other) const;
  
private:
  const_iterator(const Vector* parent, size_type index);
  void checkValid() const;
  void checkDereferenceable() const;
  
  const_pointer ptr;
  const Vector* parent;
  size_type index;
  
  friend class Vector;
};

template<class T>
inline void
Vector<T>::const_iterator::checkValid() const
{
  Assert(parent != 0, "uninitialized iterator");
  Assert(index <= parent->pv.getLength(),
	 "index > length (" << index << " > " <<
	 parent->pv.getLength() << ')');
  Assert(ptr == static_cast<const_pointer>(parent->pv.getBase()) + index,
	 "bad pointer");
}

template<class T>
inline void
Vector<T>::const_iterator::checkDereferenceable() const
{
  Assert(parent != 0, "uninitialized iterator");
  Assert(index < parent->pv.getLength(),
	 "index >= length (" << index << " >= " <<
	 parent->pv.getLength() << ')');
  Assert(ptr == static_cast<const_pointer>(parent->pv.getBase()) + index,
	 "bad pointer");
}

template<class T>
inline
Vector<T>::const_iterator::const_iterator()
{
  parent = 0;
}

template<class T>
inline
Vector<T>::const_iterator::const_iterator(const const_iterator& other)
{
  if (other.parent != 0)
    other.checkValid();
  ptr = other.ptr;
  parent = other.parent;
  index = other.index;
}

template<class T>
inline
Vector<T>::const_iterator::const_iterator(const iterator& other)
{
  if (other.parent != 0)
    other.checkValid();
  ptr = other.ptr;
  parent = other.parent;
  index = other.index;
}

template<class T>
inline
Vector<T>::const_iterator::const_iterator(const Vector* parent, size_type index)
  : ptr(static_cast<const_pointer>(parent->pv.getBase()) + index),
    parent(parent),
    index(index)
{
}

template<class T>
inline typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator=(const const_iterator& other)
{
  if (other.parent != 0)
    other.checkValid();
  ptr = other.ptr;
  parent = other.parent;
  index = other.index;
  return *this;
}

template<class T>
inline bool
Vector<T>::const_iterator::operator==(const const_iterator& other) const
{
  checkValid();
  other.checkValid();
  return ptr == other.ptr;
}

template<class T>
inline bool
Vector<T>::const_iterator::operator!=(const const_iterator& other) const
{
  checkValid();
  other.checkValid();
  return ptr != other.ptr;
}

template<class T>
inline typename Vector<T>::const_reference
Vector<T>::const_iterator::operator*()
{
  checkDereferenceable();
  return *ptr;
}

template<class T>
inline typename Vector<T>::const_pointer
Vector<T>::const_iterator::operator->()
{
  checkDereferenceable();
  return ptr;
}

template<class T>
inline typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator++()
{
  checkDereferenceable();
  ++ptr;
  ++index;
  return *this;
}

template<class T>
inline typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator++(int)
{
  Vector::const_iterator tmp(*this);
  operator++();
  return tmp;
}

template<class T>
inline typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator--()
{
  checkValid();
  Assert(index > 0, "decrementing past start");
  --ptr;
  --index;
  return *this;
}

template<class T>
inline typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator--(int)
{
  Vector::const_iterator tmp(*this);
  operator--();
  return tmp;
}

template<class T>
inline typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator+=(difference_type delta)
{
  checkValid();
  Assert(index + delta <= parent->pv.getLength(), "past end");
  ptr += delta;
  index += delta;
  return *this;
}

template<class T>
inline typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator+(difference_type delta) const
{
  Vector::const_iterator tmp(*this);
  return tmp += delta;
}

template<class T>
inline typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator-=(difference_type delta)
{
  checkValid();
  Assert(index - delta <= parent->pv.getLength(), "past end");
  ptr -= delta;
  index -= delta;
  return *this;
}

template<class T>
inline typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator-(difference_type delta) const
{
  Vector::const_iterator tmp(*this);
  return tmp -= delta;
}

template<class T>
inline typename Vector<T>::const_reference
Vector<T>::const_iterator::operator[](difference_type i) const
{
  checkValid();
  Assert(index + i <= parent->pv.getLength(), "past end");
  return ptr[i];
}

template<class T>
inline bool
Vector<T>::const_iterator::operator<(const const_iterator& other) const
{
  checkValid();
  other.checkValid();
  Assert(parent == other.parent, "incomparable iterators");
  return ptr < other.ptr;
}

template<class T>
inline typename Vector<T>::difference_type
Vector<T>::const_iterator::operator-(const const_iterator& other) const
{
  checkValid();
  other.checkValid();
  Assert(parent == other.parent, "incomparable iterators");
  return ptr - other.ptr;
}
