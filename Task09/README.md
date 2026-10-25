# Implement and Test the Billing Program

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Course:** C Programming
- **Assignment:** Task 09

## Aim
To implement and test a rural electricity billing program using previous and current meter readings, slab-based tariff calculation, meter rollover handling and input validation.

## Tariff Details
- Fixed charge: Rs. 50.00
- First 100 units: Free
- Next 100 units: Rs. 2.25 per unit
- Above 200 units: Rs. 4.50 per unit
- Meter reading range: 0 to 65535

## Files
- `Task09.c` – Main C program
- `Task09.exe` – Compiled executable
- `Task09_Test_Output.png` – Automated test results
- `Task09_Invalid_Input_Output.png` – Letter input test
- `Task09_Negative_Input_Output.png` – Negative input test

## Compiler and Compilation

**Compiler:** GCC 16.2.0 (MSYS2)

**Compile command:**
```bash
gcc -Wall -Wextra Task09.c -o Task09.exe
```

**Execution command:**
```powershell
.\Task09.exe
```

Choose option 1 to calculate a bill or option 2 to run the automated tests.

## Billing Logic
The program calculates consumption by subtracting the previous meter reading from the current reading.

If the previous reading is 65535 and the current reading is 0, the program handles the meter rollover and calculates one unit of consumption.

A decreasing reading that does not match this rollover case is rejected.

The bill is calculated in integer paise to avoid floating-point rounding errors.

## Test Results

| Test case | Expected result | Actual result |
|---|---|---|
| Zero units | Rs. 50.00 | Rs. 50.00 |
| 50 units | Rs. 50.00 | Rs. 50.00 |
| 100 units | Rs. 50.00 | Rs. 50.00 |
| 150 units | Rs. 162.50 | Rs. 162.50 |
| 200 units | Rs. 275.00 | Rs. 275.00 |
| 350 units | Rs. 950.00 | Rs. 950.00 |
| Meter rollover 65535 to 0 | 1 unit | 1 unit |
| Invalid decreasing reading | Rejected | Rejected |
| Letter input | Rejected | Rejected by validation |
| Negative reading | Rejected | Rejected by validation |

## Five-Bill Calculation

| Bill | Units | Amount |
|---|---:|---:|
| 1 | 50 | Rs. 50.00 |
| 2 | 100 | Rs. 50.00 |
| 3 | 150 | Rs. 162.50 |
| 4 | 200 | Rs. 275.00 |
| 5 | 350 | Rs. 950.00 |
| **Total** | | **Rs. 1487.50** |

The total was calculated manually and matched the program output.

## Alternative Concept: Arrays and Loops

Instead of using fixed `if-else` statements, the slab limits and rates could be stored in arrays. A loop could process each slab and calculate the energy charge.

For `s` slabs:
- **Time complexity:** O(s) per bill because the loop checks the slabs.
- **Extra space:** O(s) for the arrays storing slab limits and rates.
- **Fixed conditions:** A constant number of comparisons, effectively O(1) for a fixed tariff structure.

An array-based approach is easier to modify when tariff limits or rates change because the data can be updated without rewriting the billing logic.

## Result
The electricity billing program was implemented and tested successfully. It correctly calculates bills for different consumption levels, handles the specified meter rollover, rejects invalid readings and matches the manually calculated five-bill total of Rs. 1487.50.
