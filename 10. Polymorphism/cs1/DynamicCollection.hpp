#ifndef __DYNAMIC_COLLECTION_HPP
#define __DYNAMIC_COLLECTION_HPP

#include "Collection.hpp"
#include <cstddef>
#include <cstdlib>
#include <cstring>

class DynamicCollection : public Collection {
public:
  DynamicCollection() : m_data(nullptr), m_size(0), m_capacity(0) {}

  DynamicCollection(DynamicCollection const &other) {
    copy(other);
  }

  DynamicCollection &operator=(DynamicCollection const &other) {
    if (this != &other) {
      free();
      copy(other);
    }
    return *this;
  }

  ~DynamicCollection() {
    free();
  }

private:
  void copy(DynamicCollection const &other) {
    m_data = new int[other.m_capacity];
    memcpy(m_data, other.m_data, sizeof(int) * other.m_size);

    m_size = other.m_size;
    m_capacity = other.m_capacity;
  }

  void free() {
    delete[] m_data;
  }

protected:
  void resize() {
    m_capacity = m_capacity > 0 ? m_capacity * 2 : 1;

    int *newArr = new int[m_capacity];
    memcpy(newArr, m_data, sizeof(int) * m_size);

    delete[] m_data;
    m_data = newArr;
  }

protected:
  int *m_data;
  std::size_t m_size;
  std::size_t m_capacity;
};

#endif
