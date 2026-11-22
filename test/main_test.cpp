#include "../hailstone/hailstone.h"
#include <chrono>
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdint.h>

void hailstoneTest(std::uint64_t range) {
  std::uint64_t largest_stoppingtime = 0;
  std::uint64_t n_value;

  for (auto i = 1; i <= range; i++) {
    try {
      TrajectoryResult result = stoppingTime(i);
      if (result.stoptime > largest_stoppingtime) {
        largest_stoppingtime = result.stoptime;
        n_value = i;
      }
    } catch (const std::exception &e) {

      // catch the error here so that we don't get invalid
      //  Outputs
      std::cerr << "Error ->" << e.what() << "\n";
    }
  }
  std::cout << "-----------" << std::endl;

  std::cout << "n value: " << n_value << std::endl
            << "Stop time: " << largest_stoppingtime << std::endl;
}

int main() {
  auto start = std::chrono::steady_clock::now();
  hailstoneTest(10000000);
  auto end = std::chrono::steady_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Time spent: " << duration.count() << "milliseconds"
            << std::endl;

  return 0;
}
