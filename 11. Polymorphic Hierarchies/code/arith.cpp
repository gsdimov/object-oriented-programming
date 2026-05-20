class Expr {
public:
  virtual double eval() const=0;

  virtual Expr *clone() const=0;

  virtual ~Expr()=default;
};

class Literal : public Expr {
public:
  virtual

public:
  Literal(double value) : value(value) {}

private:
  double value;
};
