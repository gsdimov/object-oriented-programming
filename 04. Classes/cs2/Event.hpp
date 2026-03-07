#ifndef __EVENT_HPP
#define __EVENT_HPP

#include "Time.hpp"

constexpr unsigned MAX_NAME_SIZE = 128;

class Event {
public:
  // конструкторът по подразбиране е важен, за да можем
  // да имаме конструктор по подразбиране за класа Calendar
  Event();
  Event(char const *name, Time const &start, unsigned duration);

  void setName(char const *name);
  void setStart(Time const &start);
  void setDuration(unsigned duration);

  char const *getName() const;
  Time const &getStart() const;
  unsigned getDuration() const;

  Time getEnd() const;

  bool overlapsWith(Event const &other) const;

  void print() const;

  bool isSameAs(Event const &other) const;

private:
  char name[MAX_NAME_SIZE];
  Time start;
  unsigned duration;
};

#endif // __EVENT_HPP
