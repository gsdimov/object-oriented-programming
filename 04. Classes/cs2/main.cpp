#include "Calendar.hpp"
#include <iostream>

int main() {

  Time t1(4, 56);
  t1.print();
  std::cout << '\n';

  t1.addMinutes(5);
  t1.print();
  std::cout << '\n';

  Time t2(23, 31);
  t2.print();
  std::cout << '\n';

  t2.addMinutes(10109);
  t2.print();
  std::cout << '\n';

  std::cout << std::boolalpha;
  std::cout << t2.isBefore(t1) << '\n';

  std::cout << t2.equals(Time()) << '\n';

  Event e1("event #1", t1, 200);
  Event e2("event #2", t2, 120);

  e1.print();
  e2.print();

  std::cout << e1.overlapsWith(e2) << '\n';
  std::cout << e1.overlapsWith(e1) << '\n';

  Calendar c;
  c.earliestEvent().print();

  c.addEvent(e1);
  c.addEvent(e2);

  c.earliestEvent().print();

  c.removeEvent(e2);

  c.earliestEvent().print();

  return 0;
}
