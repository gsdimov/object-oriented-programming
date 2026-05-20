#ifndef __CONJ_HPP
#define __CONJ_HPP

#include "BinOp.hpp"
#include "PropExpr.hpp"

class Conj : public BinOp {
public:
  virtual bool eval(Context const &ctx) const override {
    return evalHelper(ctx, [](bool lhs, bool rhs) { return lhs && rhs; });
  }

  virtual Conj *clone() const override {
    return new Conj(*this);
  }

public:
  Conj(PropExpr const &lhs, PropExpr const &rhs)
  : BinOp(lhs, rhs) {}
};

#endif
