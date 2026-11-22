#include "../hailstone/hailstone.h"
#include <chrono>
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdint.h>

void hailstoneTest(std::uint64_t range, std::uint64_t large_threshold) {
  for (auto i = 1; i <= range; i++) {
    try {
      TrajectoryResult result = stoppingTime(i, large_threshold);
      if (result.overlimit) {
        std::cout << "-----------" << std::endl;
        std::cout << "n value: " << result.original_value << std::endl
                  << "Stop time: " << result.stoptime << std::endl;
      }
    } catch (const std::exception &e) {

      // catch the error here so that we don't get invalid
      //  Outputs
      std::cerr << "Error ->" << e.what() << "\n";
    }
  }
}

int main() {
  auto start = std::chrono::steady_clock::now();
  hailstoneTest(1000, 178);
  auto end = std::chrono::steady_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Time spent: " << duration.count() << "milliseconds"
            << std::endl;

  return 0;
}
