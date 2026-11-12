#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <stdint.h>

std::uint64_t nextHailstone(std::uint64_t n) {
  // both time and space are O(1); because we --
  // can only take one input and we don't save items
  if (n == 0) {
    throw std::invalid_argument("invalid input ");
  }

  if ((n % 2) == 0) {
    return n / 2;
  }

  if (n > (UINT64_MAX - 1) / 3) { // Check the closest value that can
                                  // cause a // UINT64 overflow
    throw std::overflow_error("Value is to large");
  }

  return (3 * n) + 1;
}

std::uint64_t stoppingTime(std::uint64_t n) {
  std::uint64_t count = 0;
  while (true) {
    std::uint64_t reslut = nextHailstone(n);
    count++;
    if (reslut == 1) {
      break;
    }
    continue;
  }
  return count;
}

void hailstoneTest(std::uint64_t n) {
  try {
    std::cout << "n = " << n << "\n";
    std::uint64_t reslut = stoppingTime(n);
    std::cout << "Stop time = " << reslut << "\n";
  } catch (const std::exception &e) {
    // catch the error here so that we don't get invalid
    //  Outputs
    std::cerr << "Error ->" << e.what() << "\n";
  }
}

int main() {
  std::uint64_t n = 7;
  // n = 7 reslut = 16
  hailstoneTest(n);
  return 0;
}
