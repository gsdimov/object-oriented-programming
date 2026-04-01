#include <iostream>
#include <fstream>

template<typename T>
struct DynArr {
  T *arr;
  size_t size;
};

DynArr<double> readNumbers(char const *filename) {
  std::ifstream ifs(filename, std::ios::in);
  if (!ifs) {
    return {nullptr, 0};
  }

  double x;
  size_t arrSize = 0;
  while (ifs >> x) {
    arrSize++;
  }

  ifs.seekg(0, std::ios::beg);

  DynArr<double> result{new double[arrSize], 0};

  while (ifs >> x) {
    result.arr[result.size] = x;
    result.size++;
  }

  return result;
}

int main() {

  DynArr<double> result = readNumbers("file.txt");

  delete[] result.arr;

  return 0;
}
