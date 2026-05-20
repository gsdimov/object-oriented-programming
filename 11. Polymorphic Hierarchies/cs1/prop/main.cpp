#include "Conj.hpp"
#include "Disj.hpp"
#include "PropExpr.hpp"
#include "SimpleExpr.hpp"
#include <iostream>

int main() {

  Conj conj1(SimpleExpr("q"), SimpleExpr("r"));
  Disj disj1(SimpleExpr("p"), conj1);

  Context ctx = {{"p", false}, {"q", false}, {"r", true}};

  std::cout << disj1.eval(ctx) << '\n';

  return 0;
}
