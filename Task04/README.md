# Task 04 – Use Macros Safely

## Student Details

**Student Name:** Yaswanth Kumar H  
**Register Number:** 1911260228  
**Compiler:** GCC 16.2.0 (MSYS2)  
**Programming Language:** C

## 1. Program Description

This program demonstrates the safe usage of macros in C programming. It uses macros for rupees-to-paise conversion, square calculation, and finding the maximum of two numbers.

It also demonstrates macro expansion using the GCC preprocessor and compares macros with static inline functions.

## 2. Macros Used

| Macro | Purpose |
|---|---|
| RUPEES_TO_PAISE(x) | Converts rupees into paise |
| SQUARE(x) | Calculates the square of a number |
| MAX(a,b) | Finds the maximum of two values |

## 3. Safe Macro Implementation

Parentheses are used around macro arguments and the complete expression to prevent operator precedence problems.

For example:

`#define SQUARE(x) ((x) * (x))`

This safely calculates the square of the given expression.

## 4. Compilation Command

```bash
gcc -std=c11 -Wall -Wextra Task04.c -o Task04.exe
```

## 5. Execution Command

```bash
.\Task04.exe
```

## 6. Preprocessor Command

```bash
gcc -E Task04.c -o Task04.i
```

The GCC preprocessor expands macros and generates the preprocessed source file named `Task04.i`.

## 7. Test Results

| Test | Expected Result | Actual Result |
|---|---|---|
| Rupees to Paise (50) | 5000 paise | 5000 paise |
| Square of 5 | 25 | 25 |
| Square of 4+1 | 25 | 25 |
| Maximum of 10 and 20 | 20 | 20 |
| Square using inline function | 25 | 25 |
| Maximum using inline function | 20 | 20 |

## 8. Macro Expansion Observation

The preprocessed file `Task04.i` shows how the compiler replaces macro calls with their expanded expressions.

The square macro expands into `((number) * (number))`, demonstrating the use of parentheses for safe macro evaluation.

## 9. Output Screenshot

The program execution screenshot is saved as:

`Task04_Output.png`

## 10. Conclusion

The program successfully demonstrates safe macro usage, macro expansion, and the advantages of using parentheses in macro definitions. It also compares macros with static inline functions. All test cases produced the expected results.
