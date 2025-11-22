# Banker's Algorithm – Safe State Checker

## Table of Contents
- [Description](#description)
- [Files](#files)
- [Requirements](#requirements)
- [How-It-Works](#how-it-works)
- [Compilation](#compilation)
- [Usage](#usage)
- [Example](#example)

## Description

This project implements the **Banker’s Algorithm**, a classic deadlock-avoidance algorithm used in operating systems. The program reads resource allocation data from an input file (`input.txt`), calculates the **Need** and **Available** vectors, and determines whether the system is in a **safe** or **unsafe** state.

If the system is safe, it outputs a valid **safe sequence** of processes. If no such sequence exists, it reports that the system is **not in a safe state**.

## Files

| File | Description |
|------|-------------|
| `main.cpp` | Entry point of the program. Loads input, executes the algorithm, prints results. |
| `BankersAlgorithm.h` | Declares the `BankersAlgorithm` class and function prototypes. |
| `BankersAlgorithm.cpp` | Implements file parsing, Need/Available calculation, and the safety check. |
| `input.txt` | Input file specifying total resources, allocation matrix, and maximum matrix. |
| `CMakeLists.txt` | Build configuration for compiling the program with CMake. |

## Requirements

To compile and run this project, you will need:

- Linux, macOS, or Windows (via WSL)
- A C++ compiler with C++20 support (e.g., `g++`)
- **OR** CMake 3.10+ for building with CMake

Example version checks:

```bash
g++ --version
cmake --version
```

## How It Works

The Banker’s Algorithm checks whether a safe execution sequence exists so the system can avoid deadlock. It uses:

- **Total** – Total number of resource instances  
- **Allocation** – Current allocation to each process  
- **Maximum** – Maximum demand of each process  
- **Need = Maximum – Allocation**  
- **Available = Total – Σ Allocation**  

### Safety Algorithm Summary

1. Initialize `Work = Available`.  
2. Find an unfinished process whose `Need <= Work`.  
3. Pretend it completes:  
   ```text
   Work += Allocation[i]
4. Mark the process as finished and append it to the safe sequence.
5. Repeat until one of the following occurs:
    - All processes finish → The system is safe.
    - No valid process remains → The system is unsafe.

## Compilation

## Usage

## Example
<img width="1137" height="520" alt="image" src="https://github.com/user-attachments/assets/f123346d-6a1d-46ed-a8db-506d0188e278" />
