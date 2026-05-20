#ifndef __PROP_EXPR_HPP
#define __PROP_EXPR_HPP

#include <ostream>
#include <string>
#include <vector>

using Context = std::vector<std::pair<std::string, bool> >;

class PropExpr {
public:
  virtual bool eval(Context const &ctx) const=0;
  virtual std::string toString() const;

  friend std::ostream &operator<<(std::ostream &os, PropExpr const &);

  virtual PropExpr *clone() const=0;
  virtual ~PropExpr()=default;
};

#endif
