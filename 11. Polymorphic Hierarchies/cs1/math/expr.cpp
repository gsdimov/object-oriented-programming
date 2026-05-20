#include "Add.hpp"
#include "Literal.hpp"
#include <vector>

// Expr **

double sum(std::vector<Expr *> const &vec) {
  double s = 0;
  for (Expr *expr : vec) {
    s += expr->eval();
  }
  return s;
}

int main() {

  Add add1(Literal(1), Literal(2.5));
  Literal lit1(4.5);

  Add expr(add1, lit1);

  expr.print();
  std::cout << '\n';
  std::cout << expr.eval() << '\n';

  std::vector<Expr *> vec;
  vec.push_back(add1.clone());
  vec.push_back(expr.clone());

  std::cout << sum(vec) << '\n';

  for (Expr *expr : vec)
    delete expr;

  return 0;
}

// Expr *arr; -> delete[] arr;
// free() -> delete[] arr;
