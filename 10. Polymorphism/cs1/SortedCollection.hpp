#ifndef __SORTED_COLLECTION_HPP
#define __SORTED_COLLECTION_HPP

#include "DynamicCollection.hpp"
#include <cstddef>

class SortedCollection : public DynamicCollection {
public:
  virtual void add(int x) override {
    if (m_size >= m_capacity)
      resize();

    std::size_t i = 0;
    for (; i < m_size && x <= m_data[i]; ++i);

    // m_size - (m_size - i - 1) - 1 = i + 1 - 1 = i
    // i >= 0
    for (std::size_t j = 0; j < m_size - i; ++j) {
      m_data[m_size - j] = m_data[m_size - j - 1];
    }

    m_data[i] = x;
    m_size++;
  }
};

#endif // __SORTED_COLLECTION_HPP
