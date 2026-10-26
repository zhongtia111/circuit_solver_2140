# Circuit Solver

A C++ console program that analyzes DC circuits made up of resistors, independent
voltage sources, and independent current sources. You describe a circuit as a
*netlist* (typed into the terminal or loaded from a text file), and the program
builds the nodal-analysis equations, solves them with Gaussian elimination, and
reports every node voltage, branch current, and the power absorbed or delivered by
each component.

Circuit Solver is aimed at students in introductory circuits courses who want to
check hand calculations quickly.

**Course:** EECE 2140 — Computing Fundamentals for Engineers
**Team:** Jayden Tran · Joseph Gereige · Tianhong "T" Zhong

---

## Features

- Read a circuit netlist from a text file or from terminal input
- Support for resistors, independent DC voltage sources, and independent DC current sources
- Build and solve nodal-analysis equations to find all node voltages
- Compute the current through and power for every component
- Display results in a formatted table in the terminal
- Input validation with helpful error messages (bad formatting, missing ground node, invalid values, unsolvable circuits)

---

## Requirements

<!-- TODO: confirm/replace once the toolchain is finalized -->

- A C++17-capable compiler (project targets `g++ -std=c++17`)
- _Placeholder: list any other dependencies here (e.g., make, CMake) once decided._

---

## Building

> **Placeholder — to be replaced with real build instructions.**

<!-- TODO: replace the command(s) below with the actual build steps -->

```bash
# Example / placeholder — not yet confirmed
g++ -std=c++17 -Wall -Wextra -pedantic -o circuit_solver main.cpp
```

---

## Running

> **Placeholder — to be replaced with real run instructions.**

<!-- TODO: replace with the actual run command and any arguments -->

```bash
# Example / placeholder — not yet confirmed
./circuit_solver
```

When the program starts, it presents a text menu. Each menu option runs exactly one
task.

```
=== Circuit Solver ===
<!-- TODO: fill in the real menu once finalized -->
1. Load netlist from file
2. Enter netlist from terminal
3. Solve circuit
4. Display results (node voltages, branch currents, power)
5. ...
0. Exit
```

---

## Netlist Input Format

> **Draft format — subject to change once the input parser is finalized.**

Each line describes one component by its name, the two nodes it connects, and its
value. Node `0` is reserved for ground.

<!-- TODO: confirm the exact syntax, units, and source conventions -->

```
# <Name> <Node+> <Node-> <Value>
R1 1 2 1000      # resistor, 1000 ohms
V1 1 0 5         # voltage source, 5 V
I1 2 0 0.01      # current source, 10 mA
```

_Placeholder: document units, sign conventions, comment syntax, and any header
lines once the format is locked in._

---

## Sample Output

> **Placeholder — replace with real output once the solver produces results.**

<!-- TODO: paste actual program output for a known test circuit -->

```
Node Voltages
  Node 1:  5.000 V
  Node 2:  2.500 V

Branch Currents / Power
  R1:  2.50 mA,  12.50 mW absorbed
  V1: -2.50 mA,  12.50 mW delivered
```

---

## Project Structure

<!-- TODO: update to match the actual files/folders as the code is written -->

```
circuit_solver_2140/
├── src/                  # source code (placeholder layout)
│   ├── main.cpp
│   ├── parser.*          # netlist parsing & validation
│   ├── solver.*          # nodal analysis + Gaussian elimination
│   └── output.*          # results display
├── tests/                # test circuits with hand-calculated answers
├── docs/                 # PDF report and Excel project plan
└── README.md
```

---

## Testing

The solver is validated against at least 10 DC circuits with hand-calculated
answers. The target is matching hand calculations within **0.1%** on every test
circuit, plus correct error messages on a set of invalid inputs.

<!-- TODO: describe how to run the test circuits once that process exists -->

---

## Known Limitations

Out of scope for this project:

- AC, phasor, or time-domain (transient) analysis
- Capacitors, inductors, diodes, transistors, and op-amps
- Dependent (controlled) sources
- Any graphical user interface or schematic editor
- Exporting results to formats other than plain text

---

## Repository

GitHub: https://github.com/zhongtia111/circuit_solver_2140