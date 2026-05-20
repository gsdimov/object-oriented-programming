#include <iostream>

class A {
public:
  A() : x(15) {}

public:
  virtual void print() const {
    std::cout << "object of type A\n";
  }

public:
  int x;
protected:
  int y;
private:
  int z;
};

class B : public A {
public:
  virtual void print() const override {
    A::print();
    std::cout << "object of type B\n";
  }

  int x;
};

int main() {

  B b;
  b.print();

  std::cout << b.x;

  A &bRef = b;
  bRef.print();

  return 0;
}
