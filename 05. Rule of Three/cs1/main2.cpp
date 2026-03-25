#include <string>
struct Foo {
  int const x;
  int y;
  std::string s;

  Foo() : x(10), y(9), s("abc") {
    y = 8;
  }
};

struct Qux {
  Qux(int) {}
};

struct Bar {
  Foo foo;
  Qux qux;

  // Qux(int)
  Bar() : foo(), qux(5) {
    // operator=
    qux = Qux(5);
  }
};

int main() {

  // int x = 10;
  // Foo foo(x);
  // Foo foo2 = foo;

  int const a = 10;

  int b = 10;
  // int &x = b;

  Bar bar;

  return 0;
}
