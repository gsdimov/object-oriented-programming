#ifndef __LITERAL_HPP
#define __LITERAL_HPP

#include "Expr.hpp"

class Literal : public Expr {
public:
  virtual double eval() const override;
  virtual void print(std::ostream &os=std::cout) const override;

  virtual Literal *clone() const override;

public:
  Literal(double);

private:
  double m_value;
};

#endif
