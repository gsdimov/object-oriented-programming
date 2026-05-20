#include <iostream>
#include <functional>

struct X {
  std::string s;
};

class Foo {
public:
  Foo();
  Foo(std::function<void(int)> const &f) : f(f) {}

  void setX(X x) {
    this->x = x;
  }

private:
  std::function<void(int)> f;
  X x;
};

void foo(Foo foo) {}

int main() {

  Foo foo1;

  foo(Foo{});

  // Foo()
  // ~Foo

  // Foo()
  // Foo(Foo const &)
  // ~Foo
  // ~Foo

  return 0;
}
