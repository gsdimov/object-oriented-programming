// при включване на наши собствени заглавни файлове,
// а не - библиотечни такива, използваме двойни кавички
#include "LineSegment.hpp"
// cmath е библиотечен файл
#include <cmath>
#include <limits>

LineSegment::LineSegment(Point const &begin, Point const &end) {
  this->begin = begin;
  this->end = end;
}

void LineSegment::setBegin(Point const &begin) {
  this->begin = begin;
}

void LineSegment::setEnd(Point const &end) {
  this->end = end;
}

Point LineSegment::getBegin() const {
  return begin;
}

Point LineSegment::getEnd() const {
  return end;
}

double LineSegment::length() const {
  double dx = begin.x - end.x;
  double dy = begin.y - end.y;
  return sqrt(dx*dx + dy*dy);
}

double LineSegment::slope() const {
  double dx = begin.x - end.x;
  double dy = begin.y - end.y;

  // константи за епсилон и максималната стойност на double
  if (dx < std::numeric_limits<double>::epsilon())
    return std::numeric_limits<double>::max();

  return dy / dx;
}

Point LineSegment::midpoint() const {
  double midx = (begin.x + end.x) / 2;
  double midy = (begin.y + end.y) / 2;
  return Point{midx, midy};
}

void LineSegment::translate(double dx, double dy) {
  begin.x += dx;
  end.x += dx;

  begin.y += dy;
  end.y += dy;
}
