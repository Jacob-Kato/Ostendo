<h1 align="center">Ostendo</h1>
<p>
A project where I'm exploring the Collatz Conjecture using programming and mathematics. I'm starting by finding numbers that create record-breaking sequence lengths, tracking their patterns, and investigating whether certain groups of numbers, especially those congruent to 3 mod 4, behave differently.

The goal is to experiment, collect data, and see what interesting patterns I can find along the way.
</p>

## Tests
|       1 - 1k       |        1 - 10m       |     1 - 100m        |     1 - 500m         |
| -------------------|----------------------|---------------------|----------------------|
| Max stop time = 178| Max stop time = 685  | Max stop time = 949 | Max stop time = 964  |
| N value = 871      | N value = 8400511    | N value = 63728127  | N value = 268549803  |
| milliseconds = 0   | milliseconds = 4836  | milliseconds = 54171| milliseconds = 294035|
---- 
trying to find the biggest stopping time under one second
|  First Try        |
|-------------------|
  | n % 4 = 3 |
  | ------------- |
  | Max stop time = 778|
  | N value = 10375416815 |
  |milliseconds = 1000 |
| Explanation: |
---- 
<img align="center" width="1000" height="600" alt="1m_test" src="https://github.com/user-attachments/assets/c82418d8-5adc-4097-9b65-de3ea1950e6c" />

