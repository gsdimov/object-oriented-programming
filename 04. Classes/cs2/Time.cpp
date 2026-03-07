#include "Time.hpp"
#include <iostream>

constexpr unsigned HOURS_IN_DAY = 24;
constexpr unsigned MINUTES_IN_HOUR = 60;

// това не е метод, а просто помощна функция
char const *padIfSingleDigit(unsigned i) {
  if (i < 10) return "0";
  return "";
}

Time::Time() {
  setToDefault();
}

Time::Time(unsigned hours, unsigned minutes) {
  setIfValid(hours, minutes);
}

Time::Time(unsigned minutes) {
  unsigned hrs = minutes / MINUTES_IN_HOUR;
  unsigned mins = minutes % MINUTES_IN_HOUR;
  setIfValid(hrs, mins);
}

void Time::setHours(unsigned hours) {
  if (hours < HOURS_IN_DAY)
    this->hours = hours;
}

void Time::setMinutes(unsigned minutes) {
  if (minutes < MINUTES_IN_HOUR)
    this->minutes = minutes;
}

unsigned Time::getHours() const {
  return hours;
}

unsigned Time::getMinutes() const {
  return minutes;
}

void Time::addMinutes(unsigned minutes) {
  unsigned hrs = minutes / MINUTES_IN_HOUR + this->hours;
  unsigned mins = minutes % MINUTES_IN_HOUR + this->minutes;

  hrs += mins / MINUTES_IN_HOUR;
  mins %= MINUTES_IN_HOUR;

  hrs %= HOURS_IN_DAY;

  setHours(hrs);
  setMinutes(mins);
}

void Time::print() const {
  std::cout << padIfSingleDigit(hours) << hours << ':';
  std::cout << padIfSingleDigit(minutes) << minutes;
}

bool Time::isBefore(Time const &other) const {
  return toMinutes() < other.toMinutes();
}

unsigned Time::toMinutes() const {
  return hours * MINUTES_IN_HOUR + minutes;
}

void Time::setToDefault() {
  hours = 0;
  minutes = 0;
}

void Time::setIfValid(unsigned hours, unsigned minutes) {
  setToDefault();
  if (hours < HOURS_IN_DAY && minutes < MINUTES_IN_HOUR) {
    this->hours = hours;
    this->minutes = minutes;
  }
}

bool Time::equals(Time const &other) const {
  return toMinutes() == other.toMinutes();
}
