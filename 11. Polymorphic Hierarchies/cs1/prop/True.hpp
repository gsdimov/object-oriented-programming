#ifndef __TRUE_HPP
#define __TRUE_HPP

#include "PropExpr.hpp"

class True : public PropExpr {
public:
  virtual bool eval(Context const &) const override {
    return true;
  }

  virtual True *clone() const override {
    return new True(*this);
  }

};

#endif
