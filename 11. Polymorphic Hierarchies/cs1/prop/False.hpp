#ifndef __FALSE_HPP
#define __FALSE_HPP

#include "PropExpr.hpp"

class False : public PropExpr {
public:
  virtual bool eval(Context const &) const override {
    return false;
  }

  virtual False *clone() const override {
    return new False(*this);
  }

};

#endif
