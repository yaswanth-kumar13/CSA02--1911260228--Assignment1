# Task 1 – Understand the Problem and Identify the Data

## 1. Introduction

The aim of this program is to calculate the electricity bill for each household in Grama Jyothi Rural Electricity Co-operative. The program uses the previous and current meter readings to find the units consumed. It then calculates the energy charge based on the given tariff and adds the fixed charge to get the final bill.

The main purpose is to calculate the bill correctly and avoid problems such as negative bills, incorrect charges and rounding errors.

## 2. Inputs and Outputs

The program needs a few inputs to calculate the bill.

| Input | Why it is needed |
|---|---|
| Household number | To identify the household. |
| Previous reading | To know the meter reading from the last billing period. |
| Current reading | To know the latest meter reading. |
| Household category | To identify the category if different billing rules are used. |

The program produces the following outputs:

| Output | Purpose |
|---|---|
| Units consumed | Shows how much electricity was used. |
| Energy charge | The amount charged for the units consumed. |
| Fixed charge | The fixed amount added to every bill. |
| Total bill | The final amount payable by the household. |

## 3. Constants and Variables

The tariff rates, slab limits and fixed charge should be treated as constants because they normally remain the same during a program run. For example, the fixed charge in this assignment is ₹50.

The meter readings, units consumed and bill amount are variables because their values change from one household to another.

Keeping the tariff values in one place also makes it easier to update them when the electricity rates change.

## 4. Choosing the Data Types

Meter readings can be stored using an unsigned integer type because they cannot normally be negative. The assignment uses a 16-bit meter register with a maximum reading of 65535.

A wider integer type is useful for storing the total consumption and the combined bill amounts when many households are processed.

For money, storing the amount in paise is a good choice. For example, ₹162.50 can be stored as 16250 paise. This avoids the usual floating-point rounding problems when calculating bills.

The household number can be stored as an integer if it contains only digits. A character string is more suitable if the identifier contains letters or leading zeros.

## 5. Rules the Program Must Follow

The program must follow these rules:

1. Calculate the units consumed using the meter readings.
2. Handle the meter rollover from 65535 to 0 correctly.
3. Keep the first 100 units free.
4. Charge ₹2.25 per unit for consumption between 101 and 200 units.
5. Charge ₹4.50 per unit for consumption above 200 units.
6. Add the fixed charge of ₹50 to the energy charge.
7. Make sure the total bill equals the energy charge plus the fixed charge.
8. Check invalid readings before calculating the bill.
9. Avoid negative bills caused by incorrect calculations.
10. Keep the money calculations accurate to the nearest paisa.

## 6. Assumptions

For this program, I assume that the readings entered are valid and belong to the same household. I also assume that no more than one meter rollover occurs between two readings.

The given tariff rates and fixed charge are used for all households unless a different category-based tariff is specified. If the readings are invalid or inconsistent, the program should display an error instead of calculating an incorrect bill.

## 7. Alternative Method: Storing Readings as Text

Another way to store meter readings is as character strings. For example, the reading 1530 could be stored as "01530".

The advantage is that the original format and leading zeros are preserved. However, the program must check that the string contains valid digits and convert it into a number before performing calculations.

If a reading contains d digits, checking and converting it takes O(d) time. Comparing two readings after conversion can also take up to O(d) time when considering the original text length.

An integer uses a fixed amount of memory for the chosen data type, whereas a text reading needs space proportional to its number of digits, or O(d).

For this program, I would prefer integers because meter readings need to be compared and subtracted frequently. Text storage would be useful if preserving the original reading format were important.

## 8. Conclusion

This analysis shows that the billing program needs suitable data types, clearly defined tariff values and proper input validation. Using integer readings and storing money in paise can help make the calculations reliable. Special care is also needed when a meter reading rolls over, so that the household receives the correct bill.
