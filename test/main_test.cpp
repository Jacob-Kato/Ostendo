#include "/home/kato/Ostendo/hailstone/hailstone.h"
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdint.h>
#include <vector>

void hailstoneTest(const std::vector<std::uint64_t> &n) {

  try {
    for (const auto &num : n) {
      std::cout << "n = " << num << "\n";
      std::uint64_t reslut = stoppingTime(num);
      std::cout << "Stop time = " << reslut << "\n";
    }
  } catch (const std::exception &e) {
    // catch the error here so that we don't get invalid
    //  Outputs
    std::cerr << "Error ->" << e.what() << "\n";
  }
}

int main() {
  std::vector<std::uint64_t> testnumber = {
      1, // 0
      2, // 1
      7, // 16
      0  // invalid agrument
  };

  // n = 7 reslut = 16
  hailstoneTest(testnumber);
  return 0;
}
