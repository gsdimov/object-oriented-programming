#ifndef __INTERVAL_COLLECTION_HPP
#define __INTERVAL_COLLECTION_HPP

#include "Collection.hpp"

// -3, -1

template<unsigned LOWER, unsigned UPPER>
class IntervalCollection : public Collection {
public:
  bool isInInterval(int x) const {
    return x >= 0 && x >= LOWER && x < UPPER;
  }

  virtual void add(int x) override {
    if (!isInInterval(x))
      return;

    m_data[x - LOWER] = true;
  }

  virtual void remove(int x) override {
    if (!isInInterval(x))
      return;

    m_data[x - LOWER] = false;
  }

  virtual bool contains(int x) const override {
    return isInInterval(x) && m_data[x - LOWER];
  }

public:
  IntervalCollection() : m_data() {}

private:
  bool m_data[UPPER - LOWER];
};

// [1,6)

#endif // __INTERVAL_COLLECTION_HPP
