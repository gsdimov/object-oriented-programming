#ifndef __DISJ_HPP
#define __DISJ_HPP

#include "BinOp.hpp"

class Disj : public BinOp {
public:
  virtual bool eval(Context const &ctx) const override {
    return evalHelper(ctx, [](bool lhs, bool rhs) { return lhs || rhs; });
  }

  virtual Disj *clone() const override {
    return new Disj(*this);
  }

  Disj(PropExpr const &lhs, PropExpr const &rhs)
  : BinOp(lhs, rhs) {}
};

#endif
