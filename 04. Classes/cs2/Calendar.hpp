#ifndef __CALENDAR_HPP
#define __CALENDAR_HPP

#include "Event.hpp"

constexpr unsigned MAX_EVENT_SIZE = 128;

class Calendar {
public:
  Calendar();

  bool addEvent(Event const &event);
  bool removeEvent(Event const &event);
  // не връщаме по референция, тъй като може да нямаме никакви събития
  // и да трябва да върнем такова по подразбиране,
  // което да не е част от масива със събития
  Event earliestEvent() const;

private:
  Event events[MAX_EVENT_SIZE];
  unsigned currSize;
};

#endif // __CALENDAR_HPP
