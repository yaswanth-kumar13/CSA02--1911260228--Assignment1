# Task 05 – Organise the Program with Header Files and Conditional Compilation

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Subject:** C Programming

## Aim
To organise a C program using a separate header file, include guards, function prototypes, and conditional compilation for debugging.

## Files Included
- `Task05.c` – Main C source code containing the functions and program logic.
- `Task05.h` – Header file containing constants and function prototypes.
- `Task05_Normal_Output.png` – Screenshot of the normal program output.
- `Task05_DEBUG_Output.png` – Screenshot of the output when DEBUG mode is enabled.

## Compiler Details
- **Compiler:** GCC
- **Version:** GCC 16.2.0

## Compilation Commands

**Normal compilation:**
```bash
gcc Task05.c -o Task05
```

**Run the program:**
```bash
./Task05
```

**Compile with DEBUG mode:**
```bash
gcc -DDEBUG Task05.c -o Task05
```

**Run the DEBUG version:**
```bash
./Task05
```

## Program Description
The program uses a separate header file named `Task05.h` to store constants and function prototypes. Include guards prevent the same header file from being included multiple times.

The program contains functions to calculate the square of a number, find the maximum of two numbers, and calculate the area of a circle.

Conditional compilation using `#ifdef DEBUG` displays intermediate values only when the program is compiled with the `-DDEBUG` option.

## Concepts Learned
1. Structure of a C program: header files, global declarations, `main()` and other functions.
2. Use of include guards with `#ifndef`, `#define` and `#endif`.
3. Conditional compilation using `#ifdef DEBUG`.
4. Difference between `#include <file>` and `#include "file"`.
5. Difference between compile-time debugging and run-time debugging.

## Alternative Concept and Complexity Analysis
If debugging output is controlled using a run-time variable such as `if (debug)`, the program checks the condition whenever it reaches that statement. This adds a small constant-time check during execution, and the debug code remains in the executable.

With `#ifdef DEBUG`, debugging statements are included only when the program is compiled with `-DDEBUG`. Without DEBUG mode, those statements are removed during preprocessing. Therefore, there is no run-time check for those statements, and the executable can be smaller.

## Result
The program was successfully compiled and executed in both normal mode and DEBUG mode. The header file, include guards, and conditional compilation worked as expected.
