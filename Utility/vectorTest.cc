#include "macros.hh"
#include "vector.hh"
#include <algorithm>
//#include <vector>
//#define Vector vector
#include <deque>

struct Foo
{
  int a;
  int b;
};

void
constTest(const Vector<int>& v)
{
  Vector<int>::const_iterator e = v.end();
  for (Vector<int>::const_iterator i = v.begin(); i != e; ++i)
    cout << *i << ' ';
  cout << endl;
}

/*
extern void foo();
extern void bar();

void
emptyTest1(const Vector<int>& v)
{
  if (v.isNull())
    foo();
  else
    bar();
}

void
emptyTest2(const Vector<int>& v)
{
  if (v.empty())
    foo();
  else
    bar();
}

extern void foo(int);

void
itorTest1(const Vector<int>& v)
{
  int len = v.size();
  for (int i = 0; i < len; i++)
    foo(v[i]);
}

void
itorTest2(const Vector<int>& v)
{
  Vector<int>::const_iterator e = v.end();
  for (Vector<int>::const_iterator b = v.begin(); b != e; ++b)
    foo(*b);
}

void
itorTest3(Vector<int>& v)
{
  int len = v.size();
  for (int i = 0; i < len; i++)
    foo(v[i]);
}
*/
int
main(int argc, char* argv[])
{
  {
    deque<int> Q;
    Q.push_back(3);
    Q.push_front(1);
    cout << *(Q.begin() + 1) << endl;
    // cout << *(1 + Q.begin()) << endl; *** random access itors are supposed to provide this
  }
  //Vector<int> a(10);
  Vector<int> a;

  for (int i = 0; i < 10 ; i++)
    a.append(i * i);

    //  a[i] = i * i ;

  constTest(a);

  Vector<int>::iterator e = a.end();
  for (Vector<int>::iterator i = a.begin(); i != e; i++)
    cout << *i << ' ';
  cout << endl;

  for (Vector<int>::iterator i = a.begin(); i != e; ++i)
    cout << *i << ' ';
  cout << endl;

  for (Vector<int>::iterator i = a.begin(); i != e; i += 2)
    cout << *i << ' ';
  cout << endl;

  Vector<int>::iterator b = a.begin();
  for (Vector<int>::iterator i = (a.end()) - 1; i != b; i--)
    cout << *i << ' ';
  cout << endl;

  for (Vector<int>::iterator i = a.end(); i != b; --i)
    cout << i[-1] << ' ';
  cout << endl;

  for (Vector<int>::iterator i = a.end(); i != b; i -= 2)
    cout << i[-1] << ' ';
  cout << endl;

  {
    Vector<int>::iterator j = a.end();
    for (Vector<int>::iterator i = a.begin(); i != e; ++i, --j)
      {
	cout << i - j << ' ';
	swap(i, j);
	cout << i - j << ' ';
	swap(i, j);
      }
    cout << endl;
  }
  {
    sort(a.begin(), a.end());
    Vector<int>::iterator e = a.end();
    for (Vector<int>::iterator i = a.begin(); i != e; i++)
      cout << *i << ' ';
    cout << endl;
  }


  /*
  for (int i = 0; i < 10; i++)
    cout << *(i + a.begin()) << ' ';  *** we don't provide this either
  cout << endl;
  */
  // bug - invalidated iterator e
  /*
  a.resize(100);
  for (Vector<int>::iterator i = a.begin(); i != e; ++i)
    cout << *i << endl;
  */
  {
    Vector<Foo> c(10);
    Vector<Foo>::iterator e = c.end();
    for (Vector<Foo>::iterator i = c.begin(); i != e; i++)
      {
	(*i).a = 101;
	i->b = 2001;
      }
  }
}
