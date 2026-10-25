# Task 07 – Control Type Conversion and Precision

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Subject:** C Programming

## Aim
To understand implicit and explicit type conversion, integer division, casting, rounding rules, and floating-point precision in C programming.

## Files Included
- `Task07.c` – C source code.
- `Task07_Output.png` – Screenshot of program execution.

## Compiler Details
- **Compiler:** GCC
- **Version:** GCC 16.2.0

## Compilation and Execution

**Compile:**
```bash
gcc Task07.c -o Task07 -lm
```

**Run on Windows:**
```powershell
.\Task07.exe
```

The `-lm` option links the mathematical library required for the `round()` function.

## Program Description
The program demonstrates different type conversions and precision-related issues using electricity billing examples. It shows how C handles integer and floating-point values during calculations.

## 1. Implicit Conversion
When an integer and a double are combined in an arithmetic expression, the integer is automatically converted to double.

For example, multiplying 150 units by a rate of 2.25 produces 337.50.

## 2. Integer Division
Integer division removes the fractional part of the result.

- `150 / 100` produces `1`.
- `150.0 / 100` produces `1.50`.

Using floating-point operands is necessary when a fractional result is required.

## 3. Explicit Casting
Explicit casting converts a value from one data type to another.

The program converts a `long long` value of 3000000000 to `int`. Since this value is outside the range of a 32-bit signed integer, the resulting value is implementation-defined.

## 4. Three Unexpected Expressions

| Expression | Output | Explanation |
|---|---:|---|
| `5 / 2` | 2 | Integer division removes the fractional part. |
| `(double)(5 / 2)` | 2.00 | Division happens before conversion to double. |
| `(int)2.99` | 2 | Conversion to int truncates the fractional part. |

## 5. Rounding Rules
The program uses the `round()` function to convert a fractional rupee amount into paise.

The rounding rule is to round to the nearest paise. For example, Rs. 162.505 is rounded to Rs. 162.51.

## 6. Integer Paise vs Floating-Point Calculation
The program compares two approaches using 1,000 bills of Rs. 162.505 each.

- **Integer-paise approach:** Each bill is rounded to paise before adding it to the total.
- **Floating-point approach:** The original fractional amounts are added first, and the total is rounded once.

The results are:
- Integer-paise total: Rs. 162510.00
- Floating-point total: Rs. 162505.00
- Difference: -500 paise

The difference occurs because the two approaches apply rounding at different stages.

## 7. Time and Space Complexity Analysis
For n bills:

- Both approaches take O(n) time because each bill is processed once.
- Integer-paise calculation uses `long long`, requiring 8 bytes per value on the tested system.
- Floating-point calculation uses `double`, requiring 8 bytes per value on the tested system.
- Both approaches use O(1) auxiliary space in this program because only running totals and a fixed number of variables are stored.

Integer-paise calculations provide consistent monetary rounding, while floating-point calculations can introduce precision differences.

## Result
The program was successfully compiled and executed. Implicit conversion, explicit casting, integer division, three unexpected expressions, rounding to paise, and floating-point precision differences were demonstrated.
