#ifndef __EXPR_HPP
#define __EXPR_HPP

#include <iostream>

class Expr {
public:
  virtual double eval() const=0;
  virtual void print(std::ostream &os=std::cout) const=0;

  virtual Expr *clone() const=0;

  virtual ~Expr()=default;
};

#endif
