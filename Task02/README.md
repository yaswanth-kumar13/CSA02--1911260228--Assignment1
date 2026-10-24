# Task 02 – Electricity Meter Rollover

**Student Name:** Yaswanth Kumar H  
**Register Number:** 1911260228  
**Compiler:** GCC 16.2.0 (MSYS2)  
**Language:** C

## Program Description

This program calculates electricity consumption using unsigned short meter readings. It demonstrates normal consumption and meter rollover when the reading reaches its maximum value.

## Compilation Command

```bash
gcc -std=c11 -Wall -Wextra Task02.c -o Task02.exe
```

## Execution Command

```bash
./Task02.exe
```

## Test Results

| Test | Expected | Actual |
|---|---:|---:|
| Normal reading | 330 | 330 |
| Meter rollover | 256 | 256 |

## Conclusion

The program successfully calculates electricity consumption for both normal readings and meter rollover conditions using an unsigned short data type. ## Data Type Selection and Justification

The data types are selected based on the kind of values used in the electricity billing system.

| Data | Suggested data type | Reason |
|---|---|---|
| Meter reading | unsigned short | Stores readings from 0 to 65535 |
| Household number | unsigned int | Can store large household numbers |
| Consumer category | char | Stores a single category character |
| Units consumed | unsigned int | Consumption cannot be negative |
| Energy charge | long long | Stores money in integer paise |
| Fixed charge | long long | Avoids decimal precision errors |
| Total bill | long long | Stores the complete amount in paise |

### Size and Range of Data Types

On my GCC environment, the commonly used type sizes are:

| Data type | Size | Range |
|---|---:|---|
| char | 1 byte | -128 to 127 (signed) |
| short | 2 bytes | -32768 to 32767 |
| unsigned short | 2 bytes | 0 to 65535 |
| int | 4 bytes | -2147483648 to 2147483647 |
| unsigned int | 4 bytes | 0 to 4294967295 |
| long long | 8 bytes | Signed 64-bit range |
| float | 4 bytes | Approximately 6–7 decimal digits of precision |
| double | 8 bytes | Approximately 15–16 decimal digits of precision |

The exact sizes can be checked using the sizeof operator. The limits.h and float.h header files provide the minimum and maximum values supported by these types.

### Why Money Should Be Stored in Paise

Storing money directly as float rupees can produce small rounding errors because floating-point numbers cannot represent every decimal value exactly.

For example, adding ₹0.10 to a float variable 4,000 times may produce an inaccurate total instead of exactly ₹400.

A better method is to store the amount in integer paise.

- ₹0.10 = 10 paise
- 4,000 × 10 paise = 40,000 paise
- 40,000 paise = ₹400

This method avoids floating-point rounding errors in the final bill.

### Understanding Meter Rollover

The electricity meter uses an unsigned 16-bit register with a maximum value of 65535.

When the meter reaches 65535, the next reading becomes 0. This is called meter rollover.

For example:

Previous reading = 65400  
Current reading = 120  

Units consumed = 256

The program handles this situation using unsigned short arithmetic without using if-else statements.

### Conclusion

Selecting suitable data types is important for producing accurate electricity bills. Using unsigned short for meter readings and integer paise for money helps avoid incorrect calculations. The rollover calculation also ensures that electricity consumption is calculated correctly when the meter resets.

