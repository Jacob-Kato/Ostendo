
#pragma once

#include <cstdint>
#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <stdint.h>

struct TrajectoryResult {
  std::uint64_t original_value;
  std::uint64_t stoptime;
};

std::uint64_t nextHailstone(std::uint64_t n);

TrajectoryResult stoppingTime(std::uint64_t n);
