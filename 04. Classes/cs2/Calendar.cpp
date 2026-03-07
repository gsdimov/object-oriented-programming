#include "Calendar.hpp"
#include "Event.hpp"

Calendar::Calendar() {
  currSize = 0;
}

bool Calendar::addEvent(Event const &event) {
  if (currSize >= MAX_EVENT_SIZE)
    return false;

  events[currSize++] = event;
  return true;
}

bool Calendar::removeEvent(Event const &other) {
  unsigned i = 0;
  while (i < currSize) {
    if (events[i].isSameAs(other))
      break;

    i++;
  }

  if (i == currSize)
    return false;

  while (i < currSize - 1) {
    events[i] = events[i + 1];
    i++;
  }

  currSize--;
  return true;
}

Event Calendar::earliestEvent() const {
  if (currSize == 0)
    return Event();

  Event earliest = events[0];
  for (unsigned i = 1; i < currSize; ++i)
    if (events[i].getStart().isBefore(earliest.getStart()))
      earliest = events[i];

  return earliest;
}
