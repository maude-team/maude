//
//	Class for garbage collected argument vectors.
//
//	For efficiency we assume that the parameter class T is very simple:
//	(1) no constructor
//	(2) no destructor
//	(3) can be copied efficiently and correctly by default assignment operator
//
//	Typically T will be a DagNode* or a small struct containing a DagNode*
//	and other simple data types (ints, ptrs).
//	Garbage collection sweep phase will invalidate all ArgVec objects that
//	have not had their evacuate() member function called during the mark phase.
// 
#ifndef _argVec_hh_
#define _argVec_hh_
#ifdef __GNUG__
#pragma interface
#endif

template<class T>
class ArgVec
{
public:
  ArgVec(int length);

  void evacuate();			// move vector to safe location (during GC)
  const T& operator[](int i) const;	// access for reading
  T& operator[](int i);			// access for writing
  void expandBy(int extra);
  void contractTo(int length);
  int length() const;
  void swap(ArgVec& other);
  const T* rawBasePointer() const;	// access for gross performance hacks
  T* rawBasePointer();			// access for even uglier stuff

private:

  int len;			// number of objects that are properly initialized
  size_t allocatedBytes;	// space allocated in bytes
  T* vector;
};

template<class T>
inline
ArgVec<T>::ArgVec(int length)
{
  Assert(length >= 0, cerr << "-ve length");
  len = length;
  allocatedBytes = length * sizeof(T);
  vector = static_cast<T*>(MemoryCell::allocateStorage(allocatedBytes));
}

template<class T>
inline const T& 
ArgVec<T>::operator[](int i) const
{
  Assert(i >= 0, cerr << "-ve index");
  Assert(i < len, cerr << "index too big");
  return vector[i];
}

template<class T>
inline T& 
ArgVec<T>::operator[](int i)
{
  Assert(i >= 0, cerr << "-ve index");
  Assert(i < len, cerr <<  "index too big");
  return vector[i];
}

template<class T>
inline void
ArgVec<T>::expandBy(int extra)
{
  Assert(extra >= 0, cerr << "extra < 0");
  int oldLen = len;
  len += extra;
  size_t neededBytes = len * sizeof(T);
  if (neededBytes > allocatedBytes)
    {
      T* oldVector = vector;
      vector = static_cast<T*>(MemoryCell::allocateStorage(neededBytes));
      for (T* n = vector; oldLen > 0; oldLen--)
	*n++ = *oldVector++;
      allocatedBytes = neededBytes;
    }
}

template<class T>
inline void
ArgVec<T>::evacuate()
{
  int l = len;
  allocatedBytes = l * sizeof(T);
  T* v = vector;
  vector = static_cast<T*>(MemoryCell::allocateStorage(allocatedBytes));
  for (T* n = vector; l > 0; l--)
    *n++ = *v++;
}
  
template<class T>
inline void
ArgVec<T>::contractTo(int length)
{
  Assert(length <= len, cerr << "new length > old length");
  len = length;
}

template<class T>
inline int
ArgVec<T>::length() const
{
  return len;
}

template<class T>
inline void
ArgVec<T>::swap(ArgVec& other)
{
  int t = len;
  len = other.len;
  other.len = t;
  t = allocatedBytes;
  allocatedBytes = other.allocatedBytes;
  other.allocatedBytes = t;
  T* p = vector;
  vector = other.vector;
  other.vector = p;
}

template<class T>
inline const T* 
ArgVec<T>::rawBasePointer() const
{
  return vector;
}

template<class T>
inline T* 
ArgVec<T>::rawBasePointer()
{
  return vector;
}

#ifdef SPEED_HACKS
#define ARG_VEC_HACK(type, fast, orig)		type* fast = (orig).rawBasePointer()
#define CONST_ARG_VEC_HACK(type, fast, orig)	type const * fast = (orig).rawBasePointer()
#else
#define ARG_VEC_HACK(type, fast, orig)		ArgVec<type>& fast = (orig)
#define CONST_ARG_VEC_HACK(type, fast, orig)	const ArgVec<type>& fast = (orig)
#endif

#endif
