#include "Literal.hpp"

double Literal::eval() const {
  return m_value;
}

void Literal::print(std::ostream &os) const {
  os << m_value;
}

Literal *Literal::clone() const {
  return new Literal(*this);
}

Literal::Literal(double value) : m_value(value) {}
