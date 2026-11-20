#include "../hailstone/hailstone.h"
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdint.h>
#include <vector>

void hailstoneTest(const std::vector<std::uint64_t> &n,
                   const std::uint64_t &stop_limit) {
  std::uint64_t index = 1;
  for (const auto &num : n) {
    try {

      TrajectoryResult result = stoppingTime(num, stop_limit);
      if (result.completed) {
        std::cout << "|---------completed---------|" << "\n";
        std::cout << "When n = " << num << "\n";
        std::cout << "item( " << index << " )" << "\n"
                  << "Transition: " << result.transitions << "\n"
                  << "Stopping Time: " << *result.stopping_time << "\n";

      } else {
        std::cout << "|---------No completed------|" << "\n";
        std::cout << "When n = " << num << "\n";
        std::cout << "item( " << index << " )" << "\n"
                  << "Transition: " << result.transitions << "\n";
      }
      index++;

    } catch (const std::exception &e) {

      // catch the error here so that we don't get invalid
      //  Outputs
      std::cerr << "Error ->" << e.what() << "\n";
    }
  }
}

int main() {
  std::uint64_t limit = 16;
  std::vector<std::uint64_t> testnumber = {1, // 0
                                           2, // 1
                                           3, // 16
                                           4, 5, 6, 7, 8, 9, 10, 20, 0};

  hailstoneTest(testnumber, limit);
  return 0;
}
