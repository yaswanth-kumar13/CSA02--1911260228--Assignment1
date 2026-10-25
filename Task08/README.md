# Task 08 – Trace the Compilation Process

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Course:** C Programming
- **Task:** 08 – Trace the Compilation Process

## 1. Aim
To understand the different stages of C compilation, identify compile-time, link-time and run-time errors, and examine compiler warnings using GCC.

## 2. Software and Compiler
- Operating System: Windows
- Compiler: GCC 16.2.0 (MSYS2)
- Editor: Visual Studio Code

## 3. Program Description
The program calculates an electricity bill using a fixed charge and an additional energy charge.

The macro `FIXED_CHARGE` is defined as 50. The function `calculate_bill()` calculates the energy charge for consumption above 100 units.

For 150 units:
- Fixed charge = Rs. 50
- Energy charge = (150 − 100) × 2 = Rs. 100
- Total bill = Rs. 150

## 4. Stages of Compilation

### Stage 1 – Preprocessing
Command:
`gcc -E Task08.c -o Task08.i`

Output: `Task08.i`

The preprocessor processes header files and macros. The `#include <stdio.h>` directive is expanded, and `FIXED_CHARGE` is replaced with its value, 50.

### Stage 2 – Assembly Generation
Command:
`gcc -S Task08.c -o Task08.s`

Output: `Task08.s`

The compiler converts the C source code into assembly language instructions.

### Stage 3 – Object File Generation
Command:
`gcc -c Task08.c -o Task08.o`

Output: `Task08.o`

The compiler generates an object file containing machine code. It is not yet a complete executable.

### Stage 4 – Linking
Command:
`gcc Task08.o -o Task08.exe`

Output: `Task08.exe`

The linker combines the object file with the required library components and creates the executable program.

### Stage 5 – Execution
Command:
`.\Task08.exe`

Output:
```text
TASK 08 - COMPILATION PROCESS
-----------------------------
Units consumed: 150
Fixed charge: Rs. 50
Total electricity bill: Rs. 150
```

## 5. Types of Errors

### Compile-Time Error
A syntax error was intentionally introduced in `Task08_CompileError.c`:

`int number = ;`

GCC reported an error because an expression was missing after the assignment operator.

### Link-Time Error
In `Task08_LinkError.c`, the function `missing_function()` was declared but not defined.

The object file was generated successfully, but the linker reported:

`undefined reference to 'missing_function'`

### Run-Time Error
In `Task08_RuntimeError.c`, the program attempted to open a file named `missing_file.txt`, which was unavailable.

The program compiled successfully but displayed:

`RUNTIME ERROR: Unable to open the file.`

This demonstrated an error encountered during program execution.

## 6. Compiler Warnings and Their Resolution

The command used was:

`gcc -Wall -Wextra -c Task08.c -o Task08.o`

An unused variable was temporarily added:

`int unused = 10;`

GCC displayed the warning:

`warning: unused variable 'unused' [-Wunused-variable]`

The warning was resolved by removing the unused variable. The program was compiled again using the same command, and no warnings were displayed.

## 7. Alternative Concept – Multi-File Compilation

If the program were divided into multiple source files, such as `input.c`, `tariff.c` and `report.c`, a shared header file could contain function declarations and common constants.

Each source file would be compiled separately:

- `gcc -c input.c -o input.o`
- `gcc -c tariff.c -o tariff.o`
- `gcc -c report.c -o report.o`

The object files would then be linked:

`gcc input.o tariff.o report.o -o electricity.exe`

### Compilation Time Analysis
In a single-file program, changing the source code generally requires recompiling the complete file.

In a multi-file program, only the modified source file needs to be recompiled, followed by linking the object files again. This can save compilation time in larger projects.

### Object File Space Analysis
Each source file generates a separate object file. The total disk space used is approximately the sum of the sizes of the object files. The actual size depends on the code and compiler.

## 8. Time and Space Complexity
- Compilation time depends on source code size and the number of files.
- Recompiling a single-file program requires processing the complete source file.
- In a multi-file program, an unchanged source file does not need recompilation.
- Object files require additional disk storage until linking is completed.

## 9. Difference Between Header File Include Methods

- `#include <stdio.h>` searches for a standard or configured system header file.
- `#include "Task08.h"` searches for the header in the local source-file directory first, then configured include directories.

## 10. Result
The compilation stages were successfully demonstrated using GCC. Preprocessing, assembly generation, object file generation, linking and execution were completed. Compile-time, link-time and run-time errors were demonstrated, and a compiler warning was identified and resolved. The multi-file compilation approach was also studied.
