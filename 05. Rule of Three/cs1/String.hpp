#ifndef __STRING_HPP
#define __STRING_HPP

#include <cstddef>
#include <cstring>
#include <iostream>

// пишем само дефиницията на класа
// и декларациите на методите
class String {
public:
  bool empty() const; 
  size_t length() const;
  char const *c_str() const;
  void print(std::ostream &os=std::cout) const;

  void push_back(char c);

  // void append(char const *);
  void append(String const &);

  String &operator+=(String const &);
  friend String operator+(String const &lhs, String const &rhs);

  // String s3 = s1 + s2;

  // int x; x += 10;
  // x = x + 10;

  // char arr[10]; arr[0]
  char &operator[](size_t index);
  char const &operator[](size_t index) const;
  // T const &

  friend bool operator<(String const &lhs, String const &rhs);
  friend bool operator<=(String const &lhs, String const &rhs);
  friend bool operator==(String const &lhs, String const &rhs);
  friend bool operator!=(String const &lhs, String const &rhs);

  // приятелските функции са външни за класа
  // std::cout << str;
  friend std::ostream &operator<<(std::ostream &os, String const &str);
  // lhs << rhs
  // std::cout << obj
  // лявата страна не е обект на класа -> приятелска функция

public:
  String();

  String(char const *str);

  String(String const &other);

  String &operator=(String const &other);

  ~String();

private:
  void copy(String const &other);
  void free();

  void resizeTo(size_t newCapacity);

private:
  char *m_str;
  size_t m_length;
  size_t m_capacity;
};

#endif // __STRING_HPP
