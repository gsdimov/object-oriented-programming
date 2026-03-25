#include <iostream>

// rule of three - изпуска се конструктор по подразбиране

// голяма четворка:
// 1. конструктор по подразбиране
// 2. копиращ конструктор
// 3. копиращ оператор за присвояване
// 4. деструктор

class Point {
private:
  double x, y;

public:
  // по подразбиране се създават методите от Г4

  // default constructor
  Point() {
    x = 0;
    y = 0;
  }

  // parametrised constructor
  Point(double x, double y) {
    setX(x);
    setY(y);
  }

  // копиращ конструктор
  Point(Point const &other) {
    x = other.x;
    y = other.y;
  }

  // копиращ оператор за присвояване
  Point &operator=(Point const &other) {
    x = other.x;
    y = other.y;

    // this  : Point *
    // *this : Point
    return *this;
  }

  // деструктор
  ~Point() {}

  // RAII

public:
  // мутатори (setters)
  void setX(double x) {
    this->x = x;
  }

  void setY(double y) {
    this->y = y;
  }

  // селектори (getters)
  double getX() const {
    return x;
  }

  double getY() const {
    return y;
  }

  void print() const {
    std::cout << '(' << x << ',' << y << ')';
  }
};

int main() {

  Point p;

  std::cout << p.getX() << '\n';

  p.setX(4);

  // non-const methods - this : Point *
  // const methods     - this : Point const *

  // setX(&p, 4);

  Point const p2(5,6);

  // std::cout << p2.getX();

  p.print();
  p2.print();

  Point p3(p);

  p3.print();

  // копиращ конструктор
  Point p4(p2);

  // оператор=
  p4.operator=(p2);
  p4 = p2;

  int x,y,z;

  x = (y = z);

  // a.foo(b);
  // a = b;
  // a.operator=(b);
  p4 = (p = p3);

  std::cout << "fnwkjfn";

  return 0;
}
