#include <iostream>

#include "IntervalCollection.hpp"

int main() {

  IntervalCollection<1, 6> ic;
  ic.add(4);

  std::cout << ic.contains(3) << ' ' << ic.contains(4) << '\n';

  return 0;
}
