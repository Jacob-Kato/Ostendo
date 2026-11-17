#include "hailstone.h"
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdint.h>

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
  std::uint64_t n = 1;
  // n = 7 reslut = 16
  hailstoneTest(n);
  return 0;
}
