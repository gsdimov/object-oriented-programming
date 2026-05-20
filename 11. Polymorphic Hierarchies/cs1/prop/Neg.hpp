#ifndef __NEG_HPP
#define __NEG_HPP

#include "PropExpr.hpp"

class Neg : public PropExpr {
public:
  virtual bool eval(Context const &ctx) const override {
    return !inner->eval(ctx);
  }

  virtual Neg *clone() const override {
    return new Neg(*this);
  }

public:
  Neg(PropExpr const &inner)
  : inner(inner.clone()) {}

  Neg(Neg const &other) {
    copy(other);
  }

  Neg &operator=(Neg const &other) {
    if (this != &other) {
      free();
      copy(other);
    }
    return *this;
  }

  virtual ~Neg() override {
    free();
  }

private:
  void copy(Neg const &other) {
    inner = other.inner->clone();
  }

  void free() {
    delete inner;
  }

private:
  PropExpr *inner;
};

#endif
