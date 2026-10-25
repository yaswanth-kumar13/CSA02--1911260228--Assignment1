# Task 06 – Read and Print Data Correctly

## Student Details
- **Name:** Yaswanth Kumar H
- **Register Number:** 1911260228
- **Subject:** C Programming

## Aim
To design input and output using `scanf()` and `printf()`, demonstrate format specifiers, validate user input, and display electricity bills correctly in rupees and paise.

## Files Included
- `Task06.c` – C source code.
- `Task06_Output.png` – Screenshot of successful program execution.

## Compiler Details
- **Compiler:** GCC
- **Version:** GCC 16.2.0

## Compilation and Execution

**Compile:**
```bash
gcc Task06.c -o Task06
```

**Run on Windows:**
```powershell
.\Task06.exe
```

## Program Description
The program accepts electricity units from the user using `scanf()`. It checks the return value of `scanf()` to identify invalid input and also rejects negative units.

The bill is calculated using integer paise. The output uses `printf()` to display the amount in rupees and paise. For example, 150 units produces a bill of Rs. 162.50.

## Format Specifiers Demonstrated

| Format specifier | Purpose |
|---|---|
| `%d` | Integer |
| `%u` | Unsigned integer |
| `%ld` | Long integer |
| `%lld` | Long long integer |
| `%f` | Floating-point output |
| `%lf` | Double input with `scanf()` |
| `%c` | Character |
| `%s` | String |

For `printf()`, `%f` is used to print a `double`. The `%lf` specifier is used for reading a `double` with `scanf()`.

## Wrong Format Specifier
Using `%d` to print a `long` value is incorrect. The correct specifier is `%ld`. A mismatched format specifier causes undefined behaviour, so the incorrect version is explained rather than executed.

## Input Validation
The return value of `scanf()` is checked. If the user enters letters instead of a number, the program displays an invalid-input message. Negative electricity units are also rejected.

## Rupees and Paise
The bill amount is stored as an integer in paise. The quotient and remainder after division by 100 are used to display rupees and paise separately.

## Alternative Concept and Complexity Analysis
Instead of reading input directly with `scanf()`, the program could use `fgets()` to read a complete line and `strtol()` to convert it into an integer.

For a line of length L:
- Reading and processing the line takes O(L) time.
- A character buffer of size B requires O(B) space.
- `fgets()` can read the complete line, while `strtol()` helps detect invalid input and conversion errors.
- Direct `scanf()` is simpler, but handling invalid input and leftover characters can be more difficult.

## Result
The program was successfully compiled and executed. Correct format specifiers, input validation, and rupees-and-paise formatting were demonstrated.
