#include <climits>
#include <ios>
#include <iostream>
#include <fstream>

bool increasing(char const *filename) {
  std::ifstream ifs(filename, std::ios::in|std::ios::binary);
  if (!ifs) {
    return false;
  }

  // ifs.read(char *buf, size_t n)
  int prev = INT_MIN, x;
  // &x -> int *
  // reinterpret_cast<char *>(&x) -> char *
  // (char *)&x
  // static_cast, reinterpret_cast; const_cast, dynamic_cast
  while (ifs.read(reinterpret_cast<char *>(&x), sizeof(x))) {
    if (x < prev) {
      return false;
    }

    prev = x;
  }

  return true;
}

bool increasing2(char const *filename) {
  std::ifstream ifs(filename, std::ios::in|std::ios::binary);
  if (!ifs) {
    return false;
  }

  ifs.seekg(0, std::ios::end);
  std::streamsize n = ifs.tellg() / sizeof(int);

  ifs.seekg(0, std::ios::beg);

  int *buf = new int[n];
  // for (size_t i = 0; i < n; ++i) {
    // ifs.read(reinterpret_cast<char *>(&buf[i]), sizeof(int));
  // }

  // &buf взима адреса на указателя
  ifs.read(reinterpret_cast<char *>(buf), sizeof(int) * n);

  // логика

  return true;
}

void writeNumbers(char const *filename, int const *arr, size_t n) {
  if (!arr)
    return;

  std::ofstream ofs(filename, std::ios::out|std::ios::binary);
  if (!ofs) {
    return;
  }

  // ifs.read(char *buf, size_t n)
  // write(char *buf, size_t n)

  // for (size_t i = 0; i < n; ++i) {
    // ofs.write(reinterpret_cast<char *>(&arr[i]), sizeof(int));
  // }

  ofs.write(reinterpret_cast<char const *>(arr), sizeof(int) * n);

  ofs.close();
}

int main() {

  int arr[5]{1,5,7,9,8};
  writeNumbers("ints.bin", arr, sizeof(arr)/sizeof(int));

  std::cout << std::boolalpha;
  std::cout << increasing("ints.bin");

  return 0;
}
