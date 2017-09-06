//
//	Nested class within Vector<T> for checked iterators.
//
//	Note that in this implementation we assume that swap()ing a pair of
//	Vectors invalidates all iterators that point to their elements.
//	This is stricter but safer than other possibilities.
//

template<class T>
class Vector<T>::iterator
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
  iterator();
  iterator(const iterator& other);
  iterator& operator=(const iterator& other);
  bool operator==(const iterator& other) const;
  bool operator!=(const iterator& other) const;
  reference operator*();
  pointer operator->();
  //
  //	Forward iterator stuff.
  //
  iterator& operator++();
  iterator operator++(int);
  //
  //	Bidirectional iterator stuff.
  //
  iterator& operator--();
  iterator operator--(int);
  //
  //	Random access iterator stuff.
  //
  iterator& operator+=(difference_type delta);
  iterator operator+(difference_type delta) const;
  iterator& operator-=(difference_type delta);
  iterator operator-(difference_type delta) const;
  difference_type operator-(const iterator& other) const;
  reference operator[](difference_type i) const;
  bool operator<(const iterator& other) const;
  
private:
  iterator(Vector* parent, size_type index);
  void checkValid() const;
  void checkDereferenceable() const;
  
  pointer ptr;
  Vector* parent;
  size_type index;
  
  friend class Vector;
  friend class const_iterator;
};

template<class T>
inline void
Vector<T>::iterator::checkValid() const
{
  Assert(parent != 0, "uninitialized iterator");
  Assert(index <= parent->pv.getLength(),
	 "index > length (" << index << " > " <<
	 parent->pv.getLength() << ')');
  Assert(ptr == static_cast<pointer>(parent->pv.getBase()) + index,
	 "bad pointer");
}

template<class T>
inline void
Vector<T>::iterator::checkDereferenceable() const
{
  Assert(parent != 0, "uninitialized iterator");
  Assert(index < parent->pv.getLength(),
	 "index >= length (" << index << " >= " <<
	 parent->pv.getLength() << ')');
  Assert(ptr == static_cast<pointer>(parent->pv.getBase()) + index,
	 "bad pointer");
}

template<class T>
inline
Vector<T>::iterator::iterator()
{
  parent = 0;
}

template<class T>
inline
Vector<T>::iterator::iterator(const iterator& other)
{
  if (other.parent != 0)
    other.checkValid();
  ptr = other.ptr;
  parent = other.parent;
  index = other.index;
}

template<class T>
inline
Vector<T>::iterator::iterator(Vector* parent, size_type index)
  : ptr(static_cast<pointer>(parent->pv.getBase()) + index),
    parent(parent),
    index(index)
{
}

template<class T>
inline typename Vector<T>::iterator&
Vector<T>::iterator::operator=(const iterator& other)
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
Vector<T>::iterator::operator==(const iterator& other) const
{
  checkValid();
  other.checkValid();
  return ptr == other.ptr;
}

template<class T>
inline bool
Vector<T>::iterator::operator!=(const iterator& other) const
{
  checkValid();
  other.checkValid();
  return ptr != other.ptr;
}

template<class T>
inline typename Vector<T>::reference
Vector<T>::iterator::operator*()
{
  checkDereferenceable();
  return *ptr;
}

template<class T>
inline typename Vector<T>::pointer
Vector<T>::iterator::operator->()
{
  checkDereferenceable();
  return ptr;
}

template<class T>
inline typename Vector<T>::iterator&
Vector<T>::iterator::operator++()
{
  checkDereferenceable();
  ++ptr;
  ++index;
  return *this;
}

template<class T>
inline typename Vector<T>::iterator
Vector<T>::iterator::operator++(int)
{
  Vector::iterator tmp(*this);
  operator++();
  return tmp;
}

template<class T>
inline typename Vector<T>::iterator&
Vector<T>::iterator::operator--()
{
  checkValid();
  Assert(index > 0, "decrementing past start");
  --ptr;
  --index;
  return *this;
}

template<class T>
inline typename Vector<T>::iterator
Vector<T>::iterator::operator--(int)
{
  Vector::iterator tmp(*this);
  operator--();
  return tmp;
}

template<class T>
inline typename Vector<T>::iterator&
Vector<T>::iterator::operator+=(difference_type delta)
{
  checkValid();
  Assert(index + delta <= parent->pv.getLength(), "past end");
  ptr += delta;
  index += delta;
  return *this;
}

template<class T>
inline typename Vector<T>::iterator
Vector<T>::iterator::operator+(difference_type delta) const
{
  Vector::iterator tmp(*this);
  return tmp += delta;
}

template<class T>
inline typename Vector<T>::iterator&
Vector<T>::iterator::operator-=(difference_type delta)
{
  checkValid();
  Assert(index - delta <= parent->pv.getLength(), "past end");
  ptr -= delta;
  index -= delta;
  return *this;
}

template<class T>
inline typename Vector<T>::iterator
Vector<T>::iterator::operator-(difference_type delta) const
{
  Vector::iterator tmp(*this);
  return tmp -= delta;
}

template<class T>
inline typename Vector<T>::reference
Vector<T>::iterator::operator[](difference_type i) const
{
  checkValid();
  Assert(index + i <= parent->pv.getLength(), "past end");
  return ptr[i];
}

template<class T>
inline bool
Vector<T>::iterator::operator<(const iterator& other) const
{
  checkValid();
  other.checkValid();
  Assert(parent == other.parent, "incomparable iterators");
  return ptr < other.ptr;
}

template<class T>
inline typename Vector<T>::difference_type
Vector<T>::iterator::operator-(const iterator& other) const
{
  checkValid();
  other.checkValid();
  Assert(parent == other.parent, "incomparable iterators");
  return ptr - other.ptr;
}
