#include "Add.hpp"
#include "Expr.hpp"

double Add::eval() const {
  return m_lhs->eval() + m_rhs->eval();
}

void Add::print(std::ostream &os) const {
  m_lhs->print(os);
  os << " + ";
  m_rhs->print(os);
}

Add *Add::clone() const {
  // Add(Add const &)
  return new Add(*this);
}

Add::Add(Expr const &lhs, Expr const &rhs)
: m_lhs(lhs.clone()), m_rhs(rhs.clone()) {}

Add::Add(Add const &other) {
  copy(other);
}

Add &Add::operator=(Add const &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

Add::~Add() {
  free();
}

void Add::copy(Add const &other) {
  m_lhs = other.m_lhs->clone();
  m_rhs = other.m_rhs->clone();
}

void Add::free() {
  delete m_lhs;
  delete m_rhs;
}
