#ifndef __BIN_OP_HPP
#define __BIN_OP_HPP

#include <functional>
#include "PropExpr.hpp"

class BinOp : public PropExpr {
public:
  BinOp(PropExpr const &lhs, PropExpr const &rhs)
  : lhs(lhs.clone()), rhs(rhs.clone()) {}

  BinOp(BinOp const &other) {
    copy(other);
  }

  BinOp &operator=(BinOp const &other) {
    if (this != &other) {
      free();
      copy(other);
    }
    return *this;
  }

  virtual ~BinOp() override {
    free();
  }

protected:
  bool evalHelper(Context const &ctx, std::function<bool(bool,bool)> const &op) const {
    return op(lhs->eval(ctx), rhs->eval(ctx));
  }

private:
  void copy(BinOp const &other) {
    lhs = other.lhs->clone();
    rhs = other.rhs->clone();
  }

  void free() {
    delete lhs;
    delete rhs;
  }

// std::function<bool(bool, bool)>
// [](bool lhs, bool rhs) -> bool { return lhs && rhs; }
// [](bool lhs, bool rhs) -> bool { return lhs || rhs; }

private:
  PropExpr *lhs, *rhs;
};

#endif
