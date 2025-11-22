# Banker's Algorithm – Safe State Checker

## Table of Contents
- [Description](#description)
- [Files](#files)
- [Requirements](#requirements)
- [How It Works](#how-it-works)
    - [Safety Algorithm Summary](#safety-algorithm-summary)
- [Compilation](#compilation)
    - [Option 1: Using g++](#option-1-using-g)
    - [Option 2: Using CMake](#option-2-using-cmake)
- [Usage](#usage)
    - [Input File Format](#input-file-format-inputtxt)
- [Example](#example)
    - [Explanation](#explanation)

## Description

This project implements the **Banker’s Algorithm**, a classic deadlock-avoidance algorithm used in operating systems. The program reads resource allocation data from an input file (`input.txt`), calculates the **Need** and **Available** vectors, and determines whether the system is in a **safe** or **unsafe** state.

If the system is safe, it outputs a valid **safe sequence** of processes. If no such sequence exists, it reports that the system is **not in a safe state**.

***NOTE***

I spoke with Professor Jinhui Ma prior to programming assignment #1 and he told me it was okay to centralize all my Documentation (program description & explanation of key components), Readme (List and briefly describe each file included in your repository & usage instructions) into a single ReadMe file.



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

- Linux, macOS, or Windows
- C++ compiler (e.g., `g++`)
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

You can compile the project using either `g++` directly or `CMake`.

 ### Option 1: Using g++
 ```bash
 g++ -std=c++20 main.cpp BankersAlgorithm.cpp -o BankersAlgorithm
 ```

 ### Option 2: Using CMake
 ```bash
 mkdir build
 cd build
 cmake ..
 make
 ```

 ## Usage

 1. Create an `input.txt` file in the same directory as your executable (see format below).
 2. Run the program:
    ```bash
    ./BankersAlgorithm      # On Linux/macOS
    BankersAlgorithm.exe    # On Windows
    ```

 ### Input File Format (`input.txt`)

 The program expects `input.txt` to contain integers separated by whitespace in this specific order:
 1. Number of Processes (`n`)
 2. Number of Resource Types (`m`)
 3. **Total Resources** vector (size `m`)
 4. **Allocation Matrix** (`n` rows × `m` columns)
 5. **Maximum Matrix** (`n` rows × `m` columns)

 **Example Input:**
 ```text
 5 3           <-- 5 Processes, 3 Resources
 10 5 7        <-- Total Resources in system (A, B, C)
 0 1 0         <-- Allocation Matrix (P0)
 2 0 0         <-- (P1)
 3 0 2         <-- (P2)
 2 2 1         <-- (P3)
 0 0 2         <-- (P4)
 7 5 3         <-- Maximum Demand Matrix (P0)
 3 3 2         <-- (P1)
 9 0 2         <-- (P2)
 2 2 2         <-- (P3)
 4 3 3         <-- (P4)
 ```

## Example
<img width="1137" height="520" alt="image" src="https://github.com/user-attachments/assets/f123346d-6a1d-46ed-a8db-506d0188e278" />

### Explanation

The example above shows the program running with the provided `input.txt`. Here is a breakdown of what the output means:

1.  **The program first reads all input values**
    - Number of processes: `5`
    - Number of resource types: `3`
    - Total resources: `10 5 7`
    - Reads the **Allocation** and **Maximum** matrices.

2.  **It computes the Need matrix**
    The Need matrix represents what each process still requires to finish.
    ```text
    Need = Maximum - Allocation
    ```

3.  **It computes the Available vector**
    It calculates how many resources are currently free in the system.
    ```text
    Available = Total - sum(Allocation for each resource)
    ```

4.  **It begins the safety algorithm**
    The program looks for a process whose `Need <= Available`.

5.  **It finds a valid safe sequence**
    In this example, the algorithm discovers:
    **P3 -> P4 -> P1 -> P2 -> P0**

    This means:
    - **P3** can finish first.
    - After **P3** finishes, its allocated resources are returned to the system.
    - Now **P4** has enough resources and can finish.
    - Then **P1**, **P2**, and finally **P0**.

6.  **The system is in a safe state**
    Since all processes can run to completion in some valid order, the program prints:
    ```text
    System is in a safe state.
    Safe sequence: P3 -> P4 -> P1 -> P2 -> P0
    ```

### Why This Matters

- If the program is able to find **any** valid ordering where all processes can finish without deadlock, the system is **safe**.
- If no such ordering exists, even though some processes might complete, the system is considered **unsafe** because there is a risk of deadlock.