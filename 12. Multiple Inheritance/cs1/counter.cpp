#include <iostream>

class Counter {
public:
  Counter() {
    COUNTER_INSTANCES++;
  }

  ~Counter() {
    COUNTER_INSTANCES--;
  }

  static unsigned counterInstances() {
    return COUNTER_INSTANCES;
  }

private:
  static unsigned COUNTER_INSTANCES;
};

unsigned Counter::COUNTER_INSTANCES = 0;

int main() {

  std::cout << Counter::counterInstances() << '\n';

  Counter c1;

  // 1 cnt

  Counter c2;

  // 2 cnt

  std::cout << Counter::counterInstances() << '\n';

  {
    Counter c3;
    // 3 cnt
    std::cout << Counter::counterInstances() << '\n';
  }

  // 2 cnt
  std::cout << Counter::counterInstances() << '\n';

  return 0;
}
