#ifndef __IMPL_HPP
#define __IMPL_HPP

#include "BinOp.hpp"

class Impl : public BinOp {
public:
  // p => q ~ !p v q
  virtual bool eval(Context const &ctx) const override {
    return evalHelper(ctx,
      [](bool lhs, bool rhs) { return !lhs || rhs; });
  }

  virtual Impl *clone() const override {
    return new Impl(*this);
  }

public:
  Impl(PropExpr const &lhs, PropExpr const &rhs)
  : BinOp(lhs, rhs) {}
};

#endif
