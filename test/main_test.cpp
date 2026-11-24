#include "../hailstone/hailstone.h"
#include <chrono>
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <stdint.h>

void hailstone3Mod4() {
  TrajectoryResult topstopingtimeItem;
  auto start_time = std::chrono::steady_clock::now();
  std::uint64_t n = 0;

  while (std::chrono::steady_clock::now() - start_time <
         std::chrono::seconds(1)) {

    if ((n % 4) != 3) {
      n++;
      continue;
    }
    TrajectoryResult result = stoppingTime(n);
    if (result.stoptime > topstopingtimeItem.stoptime) {
      topstopingtimeItem = result;
    }
    n++;
  }
  std::cout << "Top stopping Time" << std::endl
            << "N value: " << topstopingtimeItem.original_value << std::endl
            << "stopping Time: " << topstopingtimeItem.stoptime << std::endl;
}

void hailstoneExperiment(std::uint64_t range) {
  // Always initialize primitive variables to 0
  if (range == 0) {
    throw std::runtime_error("Range has to be above 1 !");
  }

  std::uint64_t largest_stoppingtime = 0;
  std::uint64_t n_value = 0;

  for (std::uint64_t i = 1; i <= range; i++) {
    try {
      TrajectoryResult result = stoppingTime(i);

      if (result.stoptime > largest_stoppingtime) {
        largest_stoppingtime = result.stoptime;
        n_value = result.original_value; // Consistent with your first block
      }
    } catch (const std::exception &e) {
      std::cerr << "Error at i = " << i << " -> " << e.what() << "\n";
      return;
    }
  }

  std::cout << "-----------\n"
            << "n value: " << n_value << "\n"
            << "Stop time: " << largest_stoppingtime << std::endl;
}

void hailstonetimed(std::uint64_t range) {
  auto start = std::chrono::steady_clock::now();
  hailstoneExperiment(range);
  auto end = std::chrono::steady_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Time spent: " << duration.count() << "milliseconds"
            << std::endl;
}

int main() {
  hailstone3Mod4();
  return 0;
}
