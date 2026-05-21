# Полиморфизъм

Да се определи какво ще бъде поведението на всеки от следните кодови фрагменти:

1.

```cpp
#include <iostream>

struct A {
  virtual void f() {
    std::cout << "A::f()\n";
  }

  std::string aStr;
};

struct B : A {
  void f() override {
    std::cout << "B::g()\n";
  }

  virtial void g() {
    std::cout << "B::g()\n";
  }

  std::string bStr;
};

class C : public B {
public:
  void f() const {
    std::cout << "C::f()\n";
  }

  void g() {
    std::cout << "C::g()\n";
  }
};

int main() {
  A *ptr1 = new C();
  ptr1->f();

  B *ptr2 = new C();
  ptr2->f();
  ptr2->g();

  C obj;
  obj.f();

  delete ptr1;
  delete ptr2;
}
```

2.

```cpp
#include <iostream>

class A {
public:
  void f(int) const {
    std::cout << "A::f(int)\n";
  }
};

struct B : A {
  virtual void f() const {
    std::cout << "B::f()\n";
  }
};

int main() {
  std::cout << sizeof(A) << '\n';
  std::cout << sizeof(B) << '\n';

  B *bptr1 = new B();
  bptr1->f();

  A *bptr2 = new B();
  bptr2->f();
}
```

3.

```cpp
#include <iostream>

class A {
public:
  A() {
    this->show();
  }

  virtual void show() {
    std::cout << "A\n";
  }
};

class B {
public:
  virtual void show() override {
    std::cout << "B\n";
  }
};

void foo(A a) {
  a.show();
}

void baz(A &a) {
  a.show();
}

void bar(A const &a) {
  a.show();
}

void qux(A *aptr) {
  aptr->show();
}

void quux(A const *aptr) {
  aptr->show();
}

int main() {

  A a;
  B b;

  foo(a);
  baz(a);
  bar(a);
  qux(&a);
  quux(&a);

  foo(b);
  baz(b);
  bar(b);
  qux(&b);
  quux(&b);

  return 0;
}
```

4.

```cpp
struct A {
  virtual A *get() {
    std::cout << "A\n";
    return this;
  }
};

struct B : A {
  virtual B *get() {
    std::cout << "B\n";
    return this;
  }
};

struct C : A {
  virtual C *get() {
    std::cout << "C\n";
    return this;
  }
};

int main() {

  A *ptr1 = new B();
  A *ptr2 = new C();

  if (dynamic_cast<C *>(ptr1->get())) {
    std::cout << "C *\n";
  }
  else {
    std::cout << "not C *\n";
  }

  return 0;
}
```

5. Какви проблеми бихме имали тук?

```cpp
struct A {
  virtual void foo() const=0;

  A() : x(0) {
    std::cout << "A()\n";
  }

  A(A const &) {
    std::cout << "A(A const &)\n";
  }

  virtual ~A()=0;

  int x;
};

struct B : A {
  virtual void foo() const override {
    std::cout << "B\n";
  }
};

struct C : A {
  virtual void foo() const override {
    std::cout << "C\n";
  }
};

int main() {

  new A{}.foo();

  std::vector<A *> vec;
  vec.push_back(new B());
  vec.push_back(new C());
  vec.push_back(nullptr);
  vec.push_back(new C());

  for (A *ptr : vec) {
    ptr->foo();
    ptr->x++;
  }

  // как ще преброим броя C-та?

  std::vector<A *> vec2 = vec;

  vec[3]->x++;

  std::cout << vec2[3]->x++ << '\n';

  return 0;

}
```
