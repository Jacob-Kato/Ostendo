#include <cstdint>
#include <iostream>
#include <stdint.h>

std::uint64_t nextHailstone(std::uint64_t n) {
  if (n > 0) {
    if ((n % 2) == 0) {
      std::cout << n / 2;
      return n / 2;
    } else {
      std::cout << (3 * n) + 1;
      return (3 * n) + 1;
    }
  }
  std::cout << "n Can not be 0 or less then 0!";
  return 0;
}

int main() {
  std::uint64_t n = 2;
  nextHailstone(n);
  return 0;
}
