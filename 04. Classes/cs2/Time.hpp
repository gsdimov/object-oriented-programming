#ifndef __TIME_HPP
#define __TIME_HPP

class Time {
public:
  Time();
  Time(unsigned hours, unsigned minutes);
  Time(unsigned minutes);

  void setHours(unsigned hours);
  void setMinutes(unsigned minutes);

  unsigned getHours() const;
  unsigned getMinutes() const;

  void addMinutes(unsigned minutes);

  void print() const;

  bool isBefore(Time const &other) const;

  unsigned toMinutes() const;

  bool equals(Time const &other) const;

private:
  void setToDefault();
  void setIfValid(unsigned hours, unsigned minutes);

private:
  unsigned hours, minutes;
};

#endif // __TIME_HPP
