#include "../hailstone/hailstone.h"
#include <chrono>
#include <cstdint>
#include <exception>
#include <iostream>
#include <matplot/matplot.h>
#include <matplot/util/colors.h>
#include <stdint.h>
#include <vector>

void hailstoneExperiment(std::uint64_t range) {

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

void hailstoneTestdotplot(std::uint64_t range) {
  using namespace matplot;

  std::vector<double> x;
  std::vector<double> y;

  std::uint64_t largest_stoppingtime = 0;
  std::uint64_t n_value = 0;

  for (std::uint64_t i = 1; i <= range; ++i) {
    try {
      TrajectoryResult result = stoppingTime(i);

      x.push_back(static_cast<double>(i));
      y.push_back(static_cast<double>(result.stoptime));

      if (result.stoptime > largest_stoppingtime) {
        largest_stoppingtime = result.stoptime;
        n_value = i;
      }

    } catch (const std::exception &e) {
      std::cerr << "Error -> " << e.what() << "\n";
    }
  }

  auto f = figure(true);
  f->size(1200, 700);

  auto p = scatter(x, y);

  p->marker(".");

  title("Collatz Stopping Time Distribution");
  xlabel("Starting Number (n)");
  ylabel("Stopping Time");

  grid(on);

  std::cout << "-----------\n"
            << "n value: " << n_value << "\n"
            << "Stop time: " << largest_stoppingtime << std::endl;

  show();
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
void hailstoneTestheatmap(std::uint64_t range) {
  using namespace matplot;

  const size_t X_BINS = 200;
  const size_t Y_BINS = 100;
  const int MAX_STOP_Y = 1000;

  std::vector<std::vector<double>> grid(Y_BINS,
                                        std::vector<double>(X_BINS, 0.0));

  std::vector<std::vector<double>> display_grid(
      Y_BINS, std::vector<double>(X_BINS, 0.0));

  std::uint64_t largest_stoppingtime = 0;
  std::uint64_t n_value = 0;

  auto f = figure(true);
  f->size(1000, 600);

  auto img =
      imagesc(0.0, static_cast<double>(range), 0.0, MAX_STOP_Y, display_grid);

  gca()->y_axis().reverse(false);
  colormap(palette::hot());
  colorbar();

  title("Collatz Stopping Time Density Heatmap (Log10 Count)");
  xlabel("Starting Number (n)");
  ylabel("Stopping Time (Steps)");

  auto last_draw = std::chrono::steady_clock::now();

  for (std::uint64_t i = 1; i <= range; ++i) {
    try {
      TrajectoryResult result = stoppingTime(i);

      if (result.stoptime > largest_stoppingtime) {
        largest_stoppingtime = result.stoptime;
        n_value = i;
      }

      size_t x_idx = std::min(
          X_BINS - 1,
          static_cast<size_t>((static_cast<double>(i - 1) / range) * X_BINS));

      size_t y_idx = std::min(
          Y_BINS - 1,
          static_cast<size_t>(
              (static_cast<double>(result.stoptime) / MAX_STOP_Y) * Y_BINS));

      grid[y_idx][x_idx] += 1.0;

    } catch (const std::exception &e) {
      std::cerr << "Error -> " << e.what() << "\n";
    }

    if (i % 250000 == 0) {
      auto now = std::chrono::steady_clock::now();

      if (std::chrono::duration_cast<std::chrono::milliseconds>(now - last_draw)
              .count() >= 150) {

        for (size_t r = 0; r < Y_BINS; ++r) {
          for (size_t c = 0; c < X_BINS; ++c) {
            display_grid[r][c] = std::log10(grid[r][c] + 1.0);
          }
        }

        img->matrix_r(display_grid);

        f->draw();
        last_draw = now;
      }
    }
  }

  for (size_t r = 0; r < Y_BINS; ++r) {
    for (size_t c = 0; c < X_BINS; ++c) {
      display_grid[r][c] = std::log10(grid[r][c] + 1.0);
    }
  }

  img->matrix_r(display_grid);

  f->draw();

  std::cout << "-----------\n"
            << "n value: " << n_value << "\n"
            << "Stop time: " << largest_stoppingtime << std::endl;

  show();
}

void hailstoneMaxEnvelope(std::uint64_t range) {
  using namespace matplot;

  const std::uint64_t BIN_SIZE = 100;

  std::vector<double> x;
  std::vector<double> y;

  std::uint64_t bin_max = 0;
  std::uint64_t bin_max_n = 0;

  std::uint64_t largest_stoppingtime = 0;
  std::uint64_t n_value = 0;

  for (std::uint64_t i = 1; i <= range; ++i) {
    try {
      TrajectoryResult result = stoppingTime(i);

      if (result.stoptime > bin_max) {
        bin_max = result.stoptime;
        bin_max_n = i;
      }

      if (result.stoptime > largest_stoppingtime) {
        largest_stoppingtime = result.stoptime;
        n_value = i;
      }

      if (i % BIN_SIZE == 0 || i == range) {
        if (bin_max_n != 0) {
          x.push_back(static_cast<double>(bin_max_n));
          y.push_back(static_cast<double>(bin_max));
        }

        bin_max = 0;
        bin_max_n = 0;
      }

    } catch (const std::exception &e) {
      std::cerr << "Error -> " << e.what() << "\n";
    }
  }

  auto f = figure(true);
  f->size(1200, 700);

  auto p = plot(x, y);
  p->line_width(1.5);
  p->marker(".");
  p->marker_size(5);

  title("Collatz Stopping Time Upper Envelope");
  xlabel("Starting Number (n)");
  ylabel("Maximum Stopping Time");

  grid(on);

  std::cout << "-----------\n"
            << "n value: " << n_value << "\n"
            << "Stop time: " << largest_stoppingtime << std::endl;

  show();
}

int main() {
  hailstoneMaxEnvelope(1000000);
  return 0;
}
