#include <iostream>

// подтипов полиморфизъм
// upcasting, downcasting
// свързване
// виртуални функции, vtables; override, final
// чисто виртуални функции
// dynamic_cast
// деструктор

class A {
public:
  // vptr
  virtual void foo() {
    std::cout << "A\n";
  }

  // ако имаме поне 1 виртуален метод
  // virtual ~A()=default;
};

class B : public A {
public:
  // override
  virtual void foo() override {
    std::cout << "B\n";
  }

  // virtual ~B() {
    // // ...
  // }
};

struct Foo {
  void foo();
  virtual void bar();
  virtual void baz();
};

struct Bar : Foo {
  void foo();
  virtual void bar() override final;
};

struct Baz : Bar {
  // virtual void bar() override;
};

// имаме полиморфизъм, ако:
// 1. наследяване
// 2. виртуални функции (поне 1)

struct C {
  // в класа C тази функция няма дефиниция
  virtual void foo()=0;
};

struct D : C {};

// поне 1 чисто виртуална функция -> класът е абстрактен
class Shape {
public:
  virtual double perimeter() const=0;
};

class Triangle : public Shape {
public:
  virtual double perimeter() const {
    return a + b + c;
  }

private:
  double a, b, c;
};

int main() {

  // Shape е абстрактен => не можем да създаваме обекти
  // Shape shape;

  Triangle triangle;

  Shape *shapePtr = &triangle;

  Shape &shapeRef = triangle;

  Baz baz;

  baz.bar();

  Foo foo;
  Bar bar;

  bar.baz();

  A a;
  B b;

  // upcasting
  A a2 = static_cast<A>(b);

  // downcasting
  // B b2 = static_cast<B>(a);

  a.foo(); // A
  b.foo(); // B

  A *ptr = &b;
  A &ref = b;

  ptr->foo(); // B
  ref.foo();  // B

  std::cout << sizeof(A) << ' ' << sizeof(B) << '\n';

  return 0;
}
