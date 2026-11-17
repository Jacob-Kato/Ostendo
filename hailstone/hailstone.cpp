#include <cstdint>
#include <stdexcept>
#include <stdint.h>

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

std::uint64_t stoppingTime(std::uint64_t n, const std::uint64_t &stop_limit) {
  std::uint64_t count = 0;
  while (n != 1) {
    if (count >= stop_limit) {
      throw std::range_error(
          "This N value has hit the stop time limit you set !");
    }
    std::uint64_t reslut = nextHailstone(n);
    count++;
    n = reslut;
  }
  return count;
}
