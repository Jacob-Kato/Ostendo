
#pragma once

#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <stdint.h>

struct TrajectoryResult {
  bool completed;
  std::uint64_t stopping_time;
};

std::uint64_t nextHailstone(std::uint64_t n);

TrajectoryResult stoppingTime(std::uint64_t n, const std::uint64_t &stop_limit);
