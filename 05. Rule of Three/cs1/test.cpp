#include <iostream>
#include <string>

#include "String.hpp"

int main() {

  String s("abcd");
  // s.print();

  // std::string s2("fnwjk");

  // std::cout << "fwejfn" << 7;
  // std::cout << s2;

  // std::cout << s.c_str();

  // std::cout << "abcd";
  // std::cout << 7;

  // std::cout << s;

  // (std::cout << s) << "abceb" << String("abcd");

  String s2("abcd");

  s.append(s2);

  s.append("abcd");

  s += "abcd";

  // std::cout << s;
  std::string s3;

  s += (String("gasndjk") += s);

  // s + "123"
  // "123" + s
  String s4 = "123" + String("abc");

  std::cout << s4 << '\n';

  s4[2] = '9';

  std::cout << s4 << '\n';

  String const s5("987");

  std::cout << std::boolalpha;
  std::cout << ("987" == s5) << '\n';

  return 0;
}
