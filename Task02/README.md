# Task 02 – Electricity Meter Rollover and Data Type Analysis

**Student Name:** Yaswanth Kumar H  
**Register Number:** 1911260228  
**Department:** Computer Science and Engineering  
**Subject:** C Programming  
**Compiler:** GCC 16.2.0 (MSYS2)  
**Programming Language:** C

---

## 1. Aim

To write a C program that demonstrates electricity meter reading calculations using suitable data types. The program also checks how meter rollover is handled when the reading reaches its maximum limit.

## 2. Program Description

In an electricity billing system, the meter records the amount of electricity consumed by a household. The consumption is calculated by finding the difference between the previous and current meter readings.

In this task, I used the `unsigned short` data type to represent the meter reading. It can store values from 0 to 65535 when it is a 16-bit type.

The program demonstrates two situations:

- Normal meter reading, where the current reading is greater than the previous reading.
- Meter rollover, where the reading resets to zero after reaching its maximum value.

## 3. Source Code

The program is saved in the following file:

`Task02.c`

```c
#include <stdio.h>
#include <limits.h>

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    return (unsigned short)(current - previous);
}

int main(void)
{
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);

    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120));

    return 0;
}
```

## 4. Data Type Selection and Justification

Different data types are required in an electricity billing system depending on the values being stored.

| Data | Suggested data type | Reason |
|---|---|---|
| Meter reading | unsigned short | Stores non-negative meter readings |
| Household number | unsigned int | Can store large identification numbers |
| Consumer category | char | Stores a single character |
| Units consumed | unsigned int | Represents non-negative consumption |
| Electricity charge | long long | Stores money in integer paise |
| Total bill | long long | Supports larger monetary values |

I selected `unsigned short` for the meter reading because it uses less memory than an ordinary integer on my compiler and can represent values up to 65535.

## 5. Size and Range of Data Types

The following table shows the commonly used sizes and ranges for the GCC environment.

| Data type | Size | Range |
|---|---:|---|
| char (signed) | 1 byte | -128 to 127 |
| unsigned char | 1 byte | 0 to 255 |
| short | 2 bytes | -32768 to 32767 |
| unsigned short | 2 bytes | 0 to 65535 |
| int | 4 bytes | -2147483648 to 2147483647 |
| unsigned int | 4 bytes | 0 to 4294967295 |
| long long | 8 bytes | -2⁶³ to 2⁶³-1 |
| float | 4 bytes | Approximately 6–7 decimal digits of precision |
| double | 8 bytes | Approximately 15–16 decimal digits of precision |

The actual size of a data type can be checked using the `sizeof` operator. The `limits.h` and `float.h` header files provide information about the supported limits and precision.

## 6. Why Money Should Be Stored in Integer Paise

In an electricity billing application, storing money directly using the `float` data type may cause small rounding errors.

Floating-point values cannot represent every decimal number exactly. Repeated calculations can therefore produce slightly different results from the expected amount.

A better approach is to store money in integer paise.

For example:

- ₹1 = 100 paise
- ₹10.50 = 1050 paise
- ₹100.75 = 10075 paise

If 4,000 bills each contain 10 paise, the expected total is:

4000 × 10 = 40000 paise = ₹400.

Using integer paise avoids floating-point rounding errors in these monetary calculations. A sufficiently large integer type such as `long long` can be used to store the amount.

## 7. Understanding Meter Rollover

An unsigned 16-bit meter reading has a maximum value of 65535.

When the reading reaches its maximum value, the next reading becomes zero. This situation is known as meter rollover.

For example:

**Previous reading:** 65400

**Current reading:** 120

The calculation is:

\[
(65535-65400)+1+120=256
\]

Therefore, the electricity consumption is 256 units.

The program uses unsigned arithmetic to demonstrate this behaviour without requiring an `if-else` statement.

## 8. Compilation and Execution

I used GCC through the VS Code terminal to compile and execute the program.

**Compilation command:**

```bash
gcc -std=c11 -Wall -Wextra Task02.c -o Task02.exe
```

**Execution command:**

```bash
.\Task02.exe
```

## 9. Output

The program was compiled and executed successfully.

**Actual output:**

```text
sizeof(meter_t) = 2 bytes, maximum reading = 65535
Consumption: 330 units
Consumption: 256 units
```

**Output explanation:**

- First calculation: 1530 - 1200 = 330 units.
- Second calculation: Meter rollover from 65400 to 120 gives 256 units.
- The size of `meter_t` is 2 bytes.
- The maximum meter reading is 65535.

## 10. Test Results

| Test case | Previous reading | Current reading | Expected result | Actual result |
|---|---:|---:|---:|---:|
| Normal reading | 1200 | 1530 | 330 units | 330 units |
| Meter rollover | 65400 | 120 | 256 units | 256 units |

Both test cases produced the expected results.

## 11. Files Included

The Task02 folder contains the following files:

| File name | Purpose |
|---|---|
| `Task02.c` | C source code |
| `Task02.exe` | Compiled executable |
| `Task02_Output.png` | Screenshot of program output |
| `README.md` | Program explanation and documentation |

## 12. Conclusion

Through this task, I understood how data types are selected for storing meter readings and how unsigned arithmetic works in C.

I also learned how to calculate electricity consumption when a meter reading resets after reaching its maximum value. The program successfully produced the expected results for both normal reading and meter rollover.

This task helped me understand the importance of choosing suitable data types when developing programs for real-world applications.
