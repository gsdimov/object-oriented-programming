#ifndef __SIMPLE_EXPR_HPP
#define __SIMPLE_EXPR_HPP

#include "PropExpr.hpp"
#include <stdexcept>
#include <string>

class SimpleExpr : public PropExpr {
public:
  virtual bool eval(Context const &ctx) const override {

    for (auto const &[sym, value] : ctx) {
      if (symbol == sym)
        return value;
    }

    throw std::runtime_error("symbol not in context");
  }

  virtual SimpleExpr *clone() const override {
    return new SimpleExpr(*this);
  }

public:
  SimpleExpr(std::string symbol) : symbol(symbol) {}

private:
  // ro0
  std::string symbol;
};

#endif
