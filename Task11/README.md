# Task 11 – Recommend and Defend the Final Design

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Department:** Computer Science and Engineering
- **Course:** C Programming

## 1. Aim
To recommend suitable data types, constants and preprocessor features for the electricity billing system, and justify the design using program output and district-scale calculations.

## 2. Files Included
- `Task11.c` – C source code
- `Task11.exe` – Compiled executable
- `Task11_Recommendation_Output.png` – Program execution screenshot

## 3. Compiler Details
- **Compiler:** GCC 16.2.0
- **Compile command:**
```bash
gcc -Wall -Wextra Task11.c -o Task11.exe
```
- **Execution command:**
```bash
.\Task11.exe
```

## 4. Recommended Data Types

| Data | Recommended type | Reason |
|---|---|---|
| Meter reading | `unsigned short` | Suitable for non-negative meter readings within the tested range |
| Money values | `long long` | Supports large accumulated totals |
| Tariff rates | Integer constants | Stores money in paise without floating-point rounding |

The program uses integer paise for billing calculations to avoid floating-point rounding errors.

## 5. Tariff Constants

The program defines the following tariff values using `#define`:

- Fixed charge: 5000 paise
- First slab limit: 100 units
- Second slab limit: 200 units
- First slab rate: 225 paise per unit
- Second slab rate: 450 paise per unit

## 6. Experimental Results

The program was tested with a consumption of 150 units.

| Test | Result |
|---|---:|
| Units consumed | 150 |
| Electricity bill | ₹162.50 |
| Number of district bills | 800,000 |
| District total in paise | 13,000,000,000 |
| District total in rupees | ₹13,00,00,000.00 |
| Does the total fit in `long long`? | YES |

The district-scale calculation uses the sample bill of ₹162.50 for each household. Actual totals will depend on individual household consumption.

## 7. Tariff Revision Method

The current tariff values are defined using `#define`. If the tariff changes, the relevant definitions must be updated and the program must be recompiled.

## 8. Design Limitations

- Compile-time constants require recompilation after tariff changes.
- The program assumes valid, non-negative unit values.
- The district total is an illustrative calculation based on one sample bill.
- Actual district totals depend on the consumption of each household.

## 9. Alternative Concept – Configuration File

Instead of using `#define`, tariff values can be stored in a configuration file and read when the program starts.

- Reading `t` tariff values takes **O(t)** time.
- Storing `t` tariff values requires **O(t)** space.
- Tariffs can be changed without recompiling the program.
- The program must validate the configuration file and handle missing or invalid values.

This approach is more flexible when tariff revisions happen frequently.

## 10. Final Recommendation

I recommend using `long long` for accumulated money in paise, integer constants for tariff rates and `#define` for values that remain fixed during compilation. If tariff revisions become frequent, a configuration file is a better option because it allows values to be changed without recompiling the program.

The experiment showed that the calculated district total of 13,000,000,000 paise fits within the `long long` range.

## 11. Conclusion

The experiment demonstrates that choosing suitable data types and constants is important for accurate electricity billing. Integer-based money calculations avoid floating-point rounding, while `long long` safely stores the tested district-scale total. A configuration file provides a flexible alternative for future tariff changes.
