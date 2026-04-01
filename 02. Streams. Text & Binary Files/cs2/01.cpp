#include <cstddef>
#include <iostream>
#include <fstream>

constexpr unsigned MAX_FILENAME_SIZE = 1024;

void print(char const *filename) {
  // четене - ifstream, std::cin
  std::ifstream ifs(filename, std::ios::in);
  // operator bool() const
  if (!ifs) {
    // небуфериран поток
    std::cerr << "could not open file\n";
    return;
  }

  char c;
  while (ifs.get(c)) {
    std::cout << c;
  }

  ifs.close();
}

// по-обща от std::ifstream &ifs
void print(std::istream &ifs) {
  if (!ifs) {
    std::cerr << "could not open file\n";
    return;
  }

  char c;
  while (ifs.get(c)) {
    std::cout << c;
  }

  // !!! не го правим
  // ifs.close();
}

void print(int *arr, size_t n) {
  for (size_t i = 0; i < n; ++i)
    std::cout << arr[i];

  // delete[] arr;
}

int main() {

  char filename[MAX_FILENAME_SIZE];
  std::cin.getline(filename, MAX_FILENAME_SIZE);

  print(filename);

  std::cout << '\n';

  std::ifstream ifs(filename, std::ios::in);
  print(ifs);
  ifs.close();

  // ctrl + d
  print(std::cin);

  // RAII
  int *arr = new int[10];

  print(arr,10);

  arr[0] = 1;

  delete[] arr;

  // std::cout << "fnewjfn" << std::flush;

  // std::cout << "fqlmel" << '\n';
  // '\n' + std::flush
  // std::cout << "fqlmel" << std::endl;

  return 0;
}
