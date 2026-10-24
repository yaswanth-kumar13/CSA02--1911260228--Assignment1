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

The program successfully calculates electricity consumption for both normal readings and meter rollover conditions using an unsigned short data type.
