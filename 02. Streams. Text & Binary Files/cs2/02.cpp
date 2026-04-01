#include <ios>
#include <iostream>
#include <fstream>

std::streamsize size(char const *filename) {
  std::ifstream ifs(filename, std::ios::in);
  if (!ifs) {
    return -1;
  }

  ifs.seekg(0, std::ios::end);
  // std::streamsize sz = ifs.tellg();
  // ifs.close();
  // return sz;

  return ifs.tellg();
  // ~std::ifstream -> ifs.close()
}

std::streamsize size(std::ifstream &ifs) {
  if (!ifs) {
    return -1;
  }

  std::streamsize initial = ifs.tellg();

  ifs.seekg(0, std::ios::end);
  std::streamsize result = ifs.tellg();

  // възстановяваме първоначалната позиция
  ifs.seekg(initial, std::ios::beg);

  return result;
}

void halve(char const *filename) {
  std::ifstream ifs(filename, std::ios::in);
  if (!ifs) {
    return;
  }

  std::streamsize n = size(ifs) / 2;

  char *buf = new char[n + 1];
  ifs.getline(buf, n + 1);

  ifs.close();

  // съдържанието се изтрива
  std::ofstream ofs(filename, std::ios::out);
  if (!ofs) {
    return;
  }

  ofs << buf;

  ofs.close();
}

int main() {

  halve("test.txt");

  return 0;
}
