#include "../hailstone/hailstone.h"
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdint.h>
#include <vector>

void hailstoneTest(const std::vector<std::uint64_t> &n,
                   const std::uint64_t &stop_limit) {
  for (const auto &num : n) {
    try {

      std::cout << "n = " << num << "\n";
      std::uint64_t result = stoppingTime(num, stop_limit);
      std::cout << "Stop time = " << result << "\n";

    } catch (const std::exception &e) {

      // catch the error here so that we don't get invalid
      //  Outputs
      std::cerr << "Error ->" << e.what() << "\n";
    }
  }
}

int main() {
  std::uint64_t limit = 16;
  std::vector<std::uint64_t> testnumber = {
      1, // 0
      2, // 1
      3, // 16
      4, 5, 6, 7, 8, 9, 10,
      0 // invalid agrument
  };

  // n = 7 reslut = 16
  hailstoneTest(testnumber, limit);
  return 0;
}
