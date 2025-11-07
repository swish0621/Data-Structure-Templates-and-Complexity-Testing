![Build Status](https://github.com/swish0621/Data-Structure-Templates-and-Complexity-Testing/actions/workflows/workflow_file.yml/badge.svg)

# Data Structure Templates and Complexity Testing

A C++ project implementing three generic data structures `Linear`, `Tree`, and `HashMap` built entirely from scratch using templates.  
Each file defines its own structure and logic without relying on STL containers, and includes testing with Catch2 to validate and measure runtime behavior.

---

## Overview

This project focuses on understanding container logic and templating.  
Each structure is templated, handles its own memory, and supports multiple data types — including built-ins, strings, and a custom `Person` struct.

Testing covers both functionality and time complexity, comparing real runtime behavior against expected Big-O performance.

---

## Files

- **`Linear.hpp`** – Implements a simple vector-based linear structure that supports insert, delete, search, and operator overloading for output.  
- **`Tree.hpp`** – Implements a templated binary search tree with recursive insert, delete, and traversal.  
- **`HashMap.hpp`** – Implements a hash-based container using separate chaining and dynamic resizing.  
- **`Person.h`** – Defines a custom data type with comparison and hash operators to test generic structure support.  
- **`test.cpp`** – Uses Catch2 to validate all structures across types and run timing comparisons.  
- **`Makefile`** – Handles build, test, and cleanup targets.  

---

## Key Concepts

- Templates and generic programming  
- Manual data structure implementation (no STL containers)  
- Operator overloading and template specialization  
- Hashing and collision handling  
- Runtime measurement using `std::chrono`  
- Unit testing with Catch2  

---

## Time Complexity

Testing verifies expected runtime behavior:
- **Linear:** O(n) — grows linearly with input size.  
- **Tree:** O(log n) — maintains balanced performance unless skewed input.  
- **HashMap:** O(1) — constant-time average lookups and inserts.  

The test suite benchmarks each structure using large input data (`data/integers.csv`, `data/decimals.csv`, `data/strings.csv`) and outputs real timing in milliseconds.

---

## Build & Run

To build and run tests:

```bash
make test
./test
```
