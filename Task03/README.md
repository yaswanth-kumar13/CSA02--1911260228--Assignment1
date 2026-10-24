# Task 03 – Electricity Bill Calculation

## Student Details

**Student Name:** Yaswanth Kumar H  
**Register Number:** 1911260228  
**Compiler:** GCC 16.2.0 (MSYS2)  
**Programming Language:** C

## 1. Program Description

This program calculates the electricity bill based on the number of electricity units consumed.

It uses predefined tariff details, including a fixed charge, free units, and different rates for electricity consumption. The program uses conditional statements and a separate function to calculate the total electricity bill.

## 2. Electricity Tariff Details

| Description | Value |
|---|---:|
| Fixed Charge | Rs. 50 |
| Free Units | 100 |
| First Slab Limit | 200 |
| First Slab Rate | Rs. 2.25 |
| Second Slab Rate | Rs. 4.50 |

## 3. Compilation Command

```bash
gcc -std=c11 -Wall -Wextra Task03.c -o Task03.exe
```

## 4. Execution Command

```bash
.\Task03.exe
```

## 5. Test Results

The program was executed with the following test cases:

| Electricity Units | Expected Bill | Actual Bill |
|---:|---:|---:|
| 0 | Rs. 50.00 | Rs. 50.00 |
| 100 | Rs. 50.00 | Rs. 50.00 |
| 150 | Rs. 162.50 | Rs. 162.50 |
| 200 | Rs. 275.00 | Rs. 275.00 |
| 350 | Rs. 950.00 | Rs. 950.00 |

## 6. Output Screenshot

The screenshot of the program execution is saved as:

`Task03_Output.png`

## 7. Conclusion

The program successfully calculates electricity bills for different consumption levels using predefined tariff rates. The output was verified for all five test cases, and the actual results matched the expected results.
