#include "macros.hh"
#include "vector.hh"
#include "natSet.hh"

int
main(int argc, char* argv[])
{
  NatSet a;
  NatSet b;
  NatSet e;
  NatSet f;
  for (int i = 0; i <= 20; i++)
    {
      a.insert(2 * i);
      b.insert(3 * i);
      e.insert((i + 1) * 100);
      f.insert(i * 199);
    }
  cout << a.min() << '\t' << a.max() << '\n';
  cout << a << '\n';
  cout << b.min() << '\t' << b.max() << '\n';
  cout << b << '\n';

  cout << e << '\n' << f << '\n';

  NatSet c(a);
  c.intersect(b);
  NatSet d(b);
  d.insert(a);
  cout << c.min() << '\t' << c.max() << '\n';
  cout << c << '\n';
  cout << d.min() << '\t' << d.max() << '\n';
  cout << d << '\n';

  d.subtract(a);
  cout << d.min() << '\t' << d.max() << '\n';
  cout << d << '\n';
}
