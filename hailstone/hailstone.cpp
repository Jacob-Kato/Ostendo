#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <stdexcept>
#include <stdint.h>

struct TrajectoryResult {
  std::uint64_t original_value;
  std::uint64_t stoptime;
  bool overlimit;
  TrajectoryResult *lastLagre_value;
  TrajectoryResult *nextLagre_value;
};

class Ostendo {
private:
  std::unique_ptr<TrajectoryResult> head;
  std::uint64_t large_limit;

public:
  Ostendo(std::uint64_t set_limit) { large_limit = set_limit; }

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

  std::unique_ptr<TrajectoryResult> stoppingTime(std::uint64_t n) {
    std::unique_ptr<TrajectoryResult> n_container;
    std::uint64_t count = 0;
    while (n != 1) {
      std::uint64_t reslut = nextHailstone(n);
      count++;
      n = reslut;
    }
    if (!n_container) {
      n_container->nextLagre_value = std::nullptr_t();
      n_container->lastLagre_value = head;
    }
    return n_container;
  }
};
