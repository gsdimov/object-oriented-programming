#include <cstring>
#include <iostream>

// std::string

class String {
public:
  bool empty() const { return length() == 0; }
  size_t length() const { return m_length; }

public:
  String() : String("") {}

  String(char const *str) {
    m_length = strlen(str);
    m_capacity = m_length + 1;

    m_str = new char[m_capacity];
    strcpy(m_str, str);
  }

  String(String const &other) {
    copy(other);
  }

  String &operator=(String const &other) {
    if (this != &other) {
     free();
     copy(other);
    }
    return *this;
  }

  ~String() {
    free();
  }

private:
  void copy(String const &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;

    m_str = new char[m_capacity];
    strcpy(m_str, other.m_str);
  }
  void free() { delete[] m_str; }

private:
  char *m_str;
  size_t m_length;
  size_t m_capacity;
};

int main() {

  String s2("abcd");

  String s;
  String s3("");

  std::cout << s.empty();

  String s4(s);

  s = s4;

  return 0;
}
