# Ostendo
A scientific tool built in C++17 to computationally investigate the unproven Collatz Conjecture. This repository tracks a modular, production-grade command-line research application designed to simulate, track, optimize, and analyze millions of integer trajectories.

**Status:** Work in Progress. This project is actively being developed through a structured, multi-milestone academic framework.

---

## The Mathematical Mystery

The Collatz Conjecture (or the $3n + 1$ problem) states that for any positive integer $n$, repeating the following transformation will always eventually reach $1$:

$$
T(n) = 
\begin{cases} 
\frac{n}{2} & \text{if } n \text{ is even} \\ 
3n + 1 & \text{if } n \text{ is odd} 
\end{cases}
$$

For example, starting with a value of **7** requires **16 steps** to terminate, soaring to a peak maximum value of **52** along its path:
`7 → 22 → 11 → 34 → 17 → 52 → 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1`

While the conjecture remains unproven, **The Hailstone Observatory** is engineered to test these trajectories computationally over large data ranges while uncovering the architectural rigors required to make mathematical experiments trustworthy.

---

## Project Roadmap

The application is structured into four sequential, high-impact development milestones:

| Milestone | Phase | Description & Key Focus | Core C++ Concepts |
| :--- | :--- | :--- | :--- |
| **M1** | **The Arithmetic Engine** | Implement sequence transition and path analysis. Build a repeatable test suite while managing edge cases and preventing integer overflow. | Functions, Contracts, Integer types, Exceptions, Testing |
| **M2** | **The Orbit Census** | Bulk-process thousands of starting values. Track stopping times, maximum excursions, record-holding outliers, and frequency distributions. | Vectors, Structures, Invariants, Time and space complexity |
| **M3** | **The Memory of the Machine** | Integrate a memoization layer using caching to accelerate large-scale ranges. Profile against the uncached version. | Hash maps, Ownership, Memory growth, Reference lifetimes, Performance measurement |
| **M4** | **The Anomaly Hunter** | File export systems, trajectory mutation testing, validation loops, and compiling a reproducible research report. | Algorithms, Experimental design, File I/O, Validation, Reproducibility |

---

## Tech Stack & Core Requirements

* **Language:** C++17 or later
* **Environment:** Command-line tool (CLI)
* **Goal:** A professional application complete with native test suites, full documentation, performance benchmarks, and structured data exports.

---

## Engineering & Workflow Philosophy

Development follows a strict system of independent implementation and rigid review criteria:

* **Strict Code Documentation:** Comments do not translate code lines into English. Instead, they strictly justify *why* a design choice exists, document class/loop invariants, or explicitly detail subtle mathematical guarantees.
* **Rigorous Verification Process:** Every milestone follows a strict cycle: learning concepts, independent implementation, assessment of ownership/complexity, systematic debugging, and test validation. 
* **Justified Progression:** Advancing to the next milestone happens only when code correctness can be defended against edge cases and algorithmic complexity—not merely when it compiles.

---

## License

This project is open-source and available under the [MIT License](LICENSE).



