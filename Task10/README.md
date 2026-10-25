# Task 10 – Compare Expectations with Execution

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Department:** Computer Science and Engineering
- **Course:** C Programming

## 1. Aim
To compare floating-point and integer-based calculations, analyse data type limits, identify possible integer overflow, and study precision differences when calculating electricity billing totals at different scales.

## 2. Problem Description
Grama Jyothi Rural Electricity Co-operative initially serves 4,000 households. The service may expand to 60,000 households at taluk level and 800,000 households at district level.

This program compares the accumulated electricity bill totals using:
- Integer paise (`long long`)
- Floating-point (`float`)
- Double-precision floating-point (`double`)

Each bill is assumed to be ₹162.50 (16,250 paise).

## 3. Files Included
- `Task10.c` – C source code.
- `Task10.exe` – Compiled executable.
- `Task10_Comparison_Output.png` – Screenshot of bill totals and data type sizes.
- `Task10_Analysis_Output.png` – Screenshot of data type ranges, overflow checks and complexity analysis.

## 4. Compiler Details
- **Compiler:** GCC
- **Version:** GCC 16.2.0
- **Operating System:** Windows
- **Compilation Command:**

```bash
gcc -Wall -Wextra Task10.c -o Task10.exe
```

- **Execution Command:**

```bash
.\Task10.exe
```

## 5. Observed Results

The program produced the following results:

| Number of Bills | Integer-Paise Total | Float Total | Float Difference |
|---:|---:|---:|---:|
| 4,000 | ₹6,50,000.00 | ₹6,50,000.00 | ₹0.00 |
| 60,000 | ₹97,50,000.00 | ₹97,45,812.00 | -₹4,188.00 |
| 800,000 | ₹13,00,00,000.00 | ₹12,92,58,144.00 | -₹7,41,856.00 |

The double total matched the integer-paise total in all three tests.

## 6. Analysis of Data Types

### Float and Double
At 4,000 bills, the float and integer-paise totals agree. At 60,000 and 800,000 bills, the float total differs because single-precision floating-point values cannot maintain the same precision as the total grows.

The double total matches the integer-paise result in all three tests because double provides greater precision for these calculations.

### Integer Overflow
The district total is 13,000,000,000 paise.

On this system:
- `int` has a maximum value of 2,147,483,647 and cannot hold the district total.
- `long` also has a maximum value of 2,147,483,647 and cannot hold the district total.
- `long long` has a maximum value of 9,223,372,036,854,775,807 and can safely hold the district total.

The program compares the required total with each type's maximum value instead of performing an overflowing signed integer calculation.

## 7. Data Type Sizes and C Standard Minimums

The observed sizes on this system are:

| Data Type | Size |
|---|---:|
| `int` | 4 bytes |
| `long` | 4 bytes |
| `long long` | 8 bytes |
| `float` | 4 bytes |
| `double` | 8 bytes |

The C standard guarantees minimum ranges of:
- `int`: at least -32,767 to 32,767.
- `long`: at least -2,147,483,647 to 2,147,483,647.
- `long long`: at least -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807.

The minimum decimal precision guarantees are 6 digits for `float` and 10 digits for `double`. This system reports 6 and 15 digits respectively.

## 8. Alternative Concept: Using Double

If the district total were accumulated using `double`, the observed total would be ₹13,00,00,000.00, matching the integer-paise calculation.

For this example, double retains enough precision to represent the accumulated total accurately. However, floating-point types can eventually lose exact precision as values grow. Integer types instead produce overflow when their representable range is exceeded.

## 9. Time and Space Complexity

- Each bill is processed once, so the total calculation takes **O(n)** time.
- Each accumulator stores one running total, so it uses **O(1)** additional space.
- Each addition is a constant-time operation, **O(1)**.
- On this system, `int`, `long` and `float` use 4 bytes each, while `long long` and `double` use 8 bytes each.

## 10. Conclusion

The experiment demonstrates that floating-point precision can affect accumulated billing totals as the number of bills increases. Double precision produced the same results as integer-paise calculations for all tested scales.

It also shows that `int` and `long` are insufficient for storing the district-level total in paise on this system, whereas `long long` can safely store it. Therefore, using `long long` for paise-based billing calculations is a suitable choice for this scenario.
