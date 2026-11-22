#include <cstdint>
#include <stdexcept>
#include <stdint.h>

struct TrajectoryResult {
  std::uint64_t original_value;
  std::uint64_t stoptime;
  bool overlimit;
};

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

TrajectoryResult stoppingTime(std::uint64_t n, std::uint64_t large_threshold) {
  TrajectoryResult n_container;
  n_container.original_value = n;
  std::uint64_t count = 0;
  while (n != 1) {
    std::uint64_t reslut = nextHailstone(n);
    count++;
    n = reslut;
  }
  n_container.stoptime = count;
  if (n_container.overlimit > large_threshold) {
    n_container.overlimit = true;
    return n_container;
  }
  n_container.overlimit = false;
  return n_container;
}
