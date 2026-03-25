#include "String.hpp"
#include <cstddef>
#include <ostream>

bool String::empty() const {
  return length() == 0;
}

size_t String::length() const {
  return m_length;
}

char const *String::c_str() const {
  return  m_str;
}

void String::print(std::ostream &os) const {
  os << m_str;
}

void String::push_back(char c) {
  if (m_length + 1 >= m_capacity) {
    resizeTo(m_capacity * 2);
  }

  m_str[m_length] = c;
  m_length++;
  m_str[m_length] = '\0';
}

void String::append(String const &other) {
  if (length() + other.length() + 1 >= m_capacity) {
    resizeTo(length() + other.length() + 1);
  }

  // strcat(m_str, other.m_str);
  strcpy(m_str + length(), other.m_str);
  m_length += other.length();
}

String &String::operator+=(String const &other) {
  append(other);
  // this: String *
  // *this: String
  return *this;
}

String operator+(String const &lhs, String const &rhs) {
  String result(lhs);
  result += rhs;
  return result;
}

// ... operator[](String *this, size_t index)
char &String::operator[](size_t index) {
  return m_str[index];
}

// ... operator[](String const *this, size_t index)
char const &String::operator[](size_t index) const {
  // !!! tova ne go pravim
  // return (*this)[index];
  return m_str[index];
}

bool operator<(String const &lhs, String const &rhs) {
  return strcmp(lhs.m_str, rhs.m_str) < 0;
}

// lhs <= rhs === !(rhs < lhs)
bool operator<=(String const &lhs, String const &rhs) {
  return !(rhs < lhs);
}

bool operator==(String const &lhs, String const &rhs) {
  // priqtelska funckiq - mojem da dostupvame private poleta
  // return !strcmp(lhs.m_str, rhs.m_str);
  return lhs <= rhs && rhs <= lhs;
}

bool operator!=(String const &lhs, String const &rhs) {
  return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, String const &str) {
  os << str.m_str;
  return os;
}

String::String() : String("") {}

String::String(char const *str) {
  m_length = strlen(str);
  m_capacity = m_length + 1;

  m_str = new char[m_capacity];
  strcpy(m_str, str);
}

String::String(String const &other) {
  copy(other);
}

String &String::operator=(String const &other) {
  if (this != &other) {
   free();
   copy(other);
  }
  return *this;
}

String::~String() { free(); }

void String::copy(String const &other) {
  m_length = other.m_length;
  m_capacity = other.m_capacity;

  m_str = new char[m_capacity];
  strcpy(m_str, other.m_str);
}

void String::free() { delete[] m_str; }

void String::resizeTo(size_t newCapacity) {
  char *newStr = new char[newCapacity];
  strcpy(newStr, m_str);

  m_capacity = newCapacity;

  free();
  m_str = newStr;
}
