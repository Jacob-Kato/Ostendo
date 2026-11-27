# Ostendo

Ostendo is a C++ project for exploring the Collatz conjecture through small, reproducible computational experiments. The project measures stopping times, looks for record-setting starting values, and compares different strategies for selecting inputs.

The goal is to collect observations, not to prove or disprove the conjecture.

## Terms

- **Stopping time:** the number of Collatz transformations required for a positive starting value to reach `1`.
- **`n ≡ 3 (mod 4)`:** values that leave a remainder of `3` when divided by `4`, such as `3`, `7`, and `11`.
- **Record:** a starting value with the largest stopping time observed in one experiment.

## Baseline: Exhaustive Range Scan

The baseline experiment evaluates every positive integer from `1` through a selected upper bound. It records the largest stopping time observed and the first input that reached it.

| Range scanned | Largest observed stopping time | Starting value | Elapsed time |
| --- | ---: | ---: | ---: |
| 1–1,000 | 178 | 871 | under 1 ms |
| 1–10,000,000 | 685 | 8,400,511 | 4,836 ms |
| 1–100,000,000 | 949 | 63,728,127 | 54,171 ms |
| 1–500,000,000 | 964 | 268,549,803 | 294,035 ms |

These are observations from this program and environment. The elapsed times are benchmarks, not mathematical properties; they depend on the build settings and hardware.

## Experiment 1: Values Congruent to 3 Modulo 4

This experiment examines candidates of the form `4k + 3`, which are exactly the positive values for which `n % 4 == 3`. It is motivated by the informal observation that long Collatz trajectories may appear frequently in this residue class.

The results below are the largest stopping times observed during time-bounded runs. A longer run examines more candidates; it does not by itself show that the reported value is the maximum for every number in a numeric range.

| Run duration | Largest observed stopping time | Starting value |
| --- | ---: | ---: |
| 1 second | 524 | 837,799 |
| 10 seconds | 685 | 8,400,511 |
| 20 seconds | 704 | 15,733,191 |

## Experiment 2: Modified 3 Modulo 4 Skip Rule

This experiment also constructs candidates of the form `4k + 3`, but it changes the search index during the early part of a run. Under its configured loop-count and stopping-time conditions, it applies an experimental jump based on multiplying the current index by `11` before continuing the scan.

This is a heuristic search, not an exhaustive scan. It intentionally skips possible inputs, so its results describe the values visited by the heuristic rather than the largest stopping time in a complete numeric range.

| Run duration | Largest observed stopping time | Starting value |
| --- | ---: | ---: |
| 1 second | 778 | 10,375,416,815 |
| 10 seconds | 902 | 10,376,388,847 |
| 20 seconds | 995 | 10,383,226,991 |

## Interpreting Results

When comparing experiments, keep these questions separate:

1. Did the experiment inspect every value in its claimed range?
2. What rule selected or skipped candidates?
3. What was the largest stopping time *observed*?
4. How long did the same workload take under the same build settings?

An exhaustive scan can make a claim about the complete scanned range. A filtered or skipped scan can make a claim only about the values it actually visited.

## Running an Experiment

From the project root:

```sh
./run_test.sh
```

The current test program selects the experiment and its range or time limit in `test/main_test.cpp`.
