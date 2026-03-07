#include "Event.hpp"
#include <cstring>
#include <iostream>

Event::Event() {
  setName("");
  setStart(Time());
  setDuration(0);
}

Event::Event(char const *name, Time const &start, unsigned duration) {
  setName(name);
  setStart(start);
  setDuration(duration);
}

void Event::setName(char const *name) {
  std::strncpy(this->name, name, MAX_NAME_SIZE);
}

void Event::setStart(Time const &start) {
  this->start = start;
}

void Event::setDuration(unsigned duration) {
  this->duration = duration;
}

char const *Event::getName() const {
  return name;
}

Time const &Event::getStart() const {
  return start;
}

unsigned Event::getDuration() const {
  return duration;
}

Time Event::getEnd() const {
  Time end = start;
  end.addMinutes(duration);
  return end;
}

bool Event::overlapsWith(Event const &other) const {
  return !(getEnd().isBefore(other.getStart())
      || other.getEnd().isBefore(getStart()));
}

void Event::print() const {
  std::cout << "Name: " << name << '\n';
  std::cout << "Start: "; start.print(); std::cout << '\n';
  std::cout << "Duration: " << duration << " min\n";
}

bool Event::isSameAs(Event const &other) const {
  return !strcmp(name, other.name)
      && start.equals(other.start)
      && duration == other.duration;
}
