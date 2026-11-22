#include "../hailstone/hailstone.h"
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdint.h>

void hailstoneTest(std::uint64_t range, std::uint64_t large_threshold) {
  for (auto i = 1; i < range; i++) {
    try {
      TrajectoryResult result = stoppingTime(i, large_threshold);
      if (result.overlimit) {
        std::cout << "-----------" << std::endl;
        std::cout << "n value = " << result.original_value << std::endl
                  << "Stop time = " << result.stoptime << std::endl;
      }
    } catch (const std::exception &e) {

      // catch the error here so that we don't get invalid
      //  Outputs
      std::cerr << "Error ->" << e.what() << "\n";
    }
  }
}

int main() {
  hailstoneTest(1000, 100000);
  return 0;
}
