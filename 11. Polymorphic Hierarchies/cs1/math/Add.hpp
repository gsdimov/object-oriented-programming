#ifndef __ADD_HPP
#define __ADD_HPP

#include "Expr.hpp"

class Add : public Expr {
public:
  virtual double eval() const override;
  virtual void print(std::ostream &os=std::cout) const override;

  virtual Add *clone() const override;

public:
  Add(Expr const &lhs, Expr const &rhs);
  Add(Add const &);
  Add &operator=(Add const &);
  virtual ~Add();

private:
  void copy(Add const &other);
  void free();

private:
  Expr *m_lhs;
  Expr *m_rhs;
};

#endif
