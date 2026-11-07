#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <stdint.h>
#include <vector>

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

void hailstoneTest(const std::vector<uint64_t> &n) {
  int index = 1;
  for (const auto value_n : n) {
    std::cout << "Test " << index << ": " << "( n = " << value_n << ")"
              << "\n";
    try {
      std::uint64_t reslut = nextHailstone(value_n);
      std::cout << reslut << "\n";
    } catch (const std::exception &e) {
      // catch the error here so that we don't get invalid
      //  Outputs
      std::cerr << "Error ->" << e.what() << "\n";
    }
    index++;
  }
}

int main() {
  std::vector<uint64_t> narray = {
      1, 2, 7, 10, 0, (UINT64_MAX / 3), ((UINT64_MAX / 3) - 2)};
  // Test 1; n = 1 reslut = 4
  // Test 2; n =  2 reslut = 1
  // Test 3; n = 7 reslut = 22
  // Test 4; n = 10 reslut = 5
  // Test 5; n = 0 reslut = 0 error
  // Test 6; n = UINT64_MAX/ 3 reslut = overflow error
  // Test 7; n = UINT64_MAX /3 -2  reslut = 18446744073709551610
  hailstoneTest(narray);
  return 0;
}
