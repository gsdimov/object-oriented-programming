#include <iostream>

// без разделна компилация

class Counter {
private:
  unsigned i;

public:
  Counter() {
    i = 0;
  }

  Counter(unsigned i) {
    this->i = i;
  }

  // void inc(Counter *this) { this->i++; }
  void inc() {
    i++;
  }

  void dec() {
    if (i > 0)
      i--;
  }

  // unsigned getCounter(Counter const *this) { return this->i; }
  unsigned getCounter() const {  // const qualifier
    return i;
  }
};

int main() {

  Counter c;
  c.inc();
  c.dec();

  Counter c2;
  c2.inc();

  Counter const c3(60);
  std::cout << c3.getCounter() << '\n';

  return 0;
}
