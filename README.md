# Ostendo — Collatz Stopping-Time Research

Ostendo is a C++17 research project designed to investigate the Collatz conjecture, with a particular focus on identifying **clusters of unusually large stopping times**.

## Research Objective

The Collatz conjecture states that repeatedly applying the following rules to any positive integer will eventually produce 1:

$$
T(n)=
\begin{cases}
n/2 & \text{if } n \text{ is even}\\
3n+1 & \text{if } n \text{ is odd}
\end{cases}
$$

Rather than simply calculating individual trajectories, Ostendo investigates the distribution of stopping times across large ranges of starting values.

The primary research questions are:

- Where do unusually large stopping times occur?
- Do large stopping times form identifiable clusters?
- Are there patterns in the starting values surrounding these clusters?
- How do these clusters behave as the investigated range increases?

## Planned Features

- Calculate stopping times for large ranges of positive integers.
- Identify unusually large stopping times and record holders.
- Detect clusters of starting values with large stopping times.
- Measure cluster sizes, distributions, and concentration.
- Export results for further mathematical and statistical analysis.

## Technology

- **Language:** C++17 or later
- **Environment:** Command-line application
- **Focus:** Algorithms, number theory, statistical analysis, and computational research.

## Research Disclaimer

The Collatz conjecture remains unproven. Computational observations can identify patterns and generate hypotheses, but they cannot establish that the conjecture holds for every positive integer.


