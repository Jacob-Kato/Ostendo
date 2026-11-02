#include <cstdint>
#include <iostream>
#include <stdint.h>

std::uint64_t nextHailstone(std::uint64_t n) {
  // Make sure func doen't div by zero
  if (n > 0) {
    if ((n % 2) == 0) {
      return n / 2;
    } else {
      // Check if there is going to be a Multiplication Overflow
      if (n > (UINT64_MAX - 1) / 3) {
        std::cout << "n will cause a Multiplication Overflow";
        return 0;
      }
      std::uint64_t result = (3 * n) + 1;
      // Checking if a Addition Overflow happend
      if (result < (3 * n) || result < 1) {
        std::cout << "Addition Overflow has happend";
        return 0;
      }
      return result;
    }
  }
  std::cout << "n Can not be 0 or less then 0!";
  return 0;
}

int main() {
  // when n = 1 result = 4
  std::uint64_t test1 = 1;
  std::cout << "Test1:" << nextHailstone(test1) << '\n';
  // when n = 2 result = 1
  std::uint64_t test2 = 2;
  std::cout << "Test2:" << nextHailstone(test2) << '\n';
  // when n = 7 result = 22
  std::uint64_t test3 = 7;
  std::cout << "Test3:" << nextHailstone(test3) << '\n';
  // when n = 10 result = 5
  std::uint64_t test4 = 10;
  std::cout << "Test4:" << nextHailstone(test4) << '\n';
  // when n = 0 result = 'n can not be 0 or less then 0!'
  std::uint64_t test5 = 0;
  std::cout << "Test5:" << nextHailstone(test5) << '\n';
  // when n = 207 result = 'n will cause Multiplication Overflow
  std::uint64_t test6 = 207;
  std::cout << "Test:6" << nextHailstone(test6) << '\n';

  return 0;
}
