
# Task 12 – Re-evaluate and Adapt the Design

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Course:** C Programming
- **Task:** 12 – Re-evaluate and Adapt the Design

## 1. Objective
To re-evaluate the original electricity billing design after introducing smart meter readings every 15 minutes, peak-hour tariffs and runtime-configurable tariff values.

## 2. Changed Requirements
The original billing design must now handle:
- 35,040 smart meter readings per house per year.
- Energy readings measured in watt-hours (Wh).
- Different rates for normal and peak hours.
- A 20% surcharge between 6 PM and 10 PM.
- Tariff values that can be changed without recompiling the program.

## 3. Impact Analysis
The increased number of readings requires reliable accumulation of yearly energy values. A 32-bit signed integer can store up to 2,147,483,647, but an annual total can exceed this limit depending on the maximum interval reading.

The revised program uses `unsigned long long` for yearly energy totals and monetary calculations. This provides a wider range for accumulated values.

The fixed tariff values are no longer suitable as compile-time constants because the board needs to change them without recompiling. Therefore, the program reads tariff values from `tariff.txt` at runtime.

## 4. Evaluation of the Original Design
The original design is not sufficient for the new requirements because:
- It does not process 15-minute smart meter readings.
- It does not separate normal-hour and peak-hour energy.
- Fixed compile-time tariff values cannot be changed conveniently.
- Narrow integer types may overflow when storing large yearly totals.

For evaluation, the revised program uses an illustrative maximum interval reading of 65,535 Wh.

Annual maximum under this assumption:

65,535 × 35,040 = 2,296,346,400 Wh

This exceeds the maximum signed 32-bit integer value of 2,147,483,647. Therefore, a wider integer type is appropriate.

## 5. Adaptation and Revised Design
The revised program includes:
- `unsigned long long` for energy totals and billing calculations.
- A `Tariff` structure to store tariff information.
- Runtime tariff loading using `fopen()` and `fscanf()`.
- Separate accumulation of normal-hour and peak-hour energy.
- A 20% surcharge for readings between 6 PM and 10 PM.
- Integer-based monetary calculations using paise to avoid floating-point rounding errors.

### Tariff Configuration
The `tariff.txt` file contains:

5000 225 20

Meaning:
- Fixed charge: 5000 paise (₹50.00)
- Normal rate: 225 paise per kWh (₹2.25)
- Peak surcharge: 20%

## 6. Test Scenario and Results
For demonstration, the program assumes 100 Wh of energy usage in every 15-minute interval for one year.

| Test item | Result |
|---|---:|
| Readings per year | 35,040 |
| Total energy | 3,504,000 Wh |
| Normal-hour energy | 2,920,000 Wh |
| Peak-hour energy | 584,000 Wh |
| Energy charge | ₹8,146.80 |
| Fixed charge | ₹50.00 |
| Total yearly bill | ₹8,196.80 |

## 7. Evidence-Based Defence
The revised design is more suitable because it handles large yearly energy totals using a wider integer type. It also separates normal and peak-hour consumption and applies the correct surcharge.

Loading tariff values from an external file allows the electricity board to update rates without modifying or recompiling the C program.

The demonstration output confirms that the revised program calculates the yearly energy consumption and bill correctly for the stated test scenario.

## 8. Trade-offs
- Wider integer types use more memory but provide a larger storage range.
- Runtime file handling makes tariff changes easier but requires a valid configuration file.
- Integer-based monetary calculations avoid floating-point representation errors but require careful scaling.
- The demonstration assumes a constant 100 Wh per interval; actual smart meter readings may vary.

## 9. Conclusion
The original design was modified to meet the new smart meter requirements. The revised solution supports yearly energy accumulation, peak-hour billing and runtime tariff configuration. Based on the calculations and successful execution test, the modified design is appropriate for the stated requirements.

## 10. Compiler and Execution Details
- **Compiler:** GCC 16.2.0
- **Compile command:** `gcc -Wall -Wextra Task12.c -o Task12.exe`
- **Execution command:** `.\Task12.exe`
- **Input file:** `tariff.txt`
- **Source file:** `Task12.c`
- **Output screenshot:** `Task12_Smart_Meter_Billing_Output.png`

