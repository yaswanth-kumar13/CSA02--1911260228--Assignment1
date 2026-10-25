
#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void)
{
    printf("TASK 07 - CONTROL TYPE CONVERSION AND PRECISION\n");
    printf("------------------------------------------------\n");

    /* 1. Implicit conversion */
    int units = 150;
    double rate = 2.25;
    double charge = units * rate;

    printf("\n1. IMPLICIT CONVERSION\n");
    printf("Integer units * double rate = %.2f\n", charge);
    printf("The integer is automatically converted to double.\n");

    /* 2. Integer division */
    printf("\n2. INTEGER DIVISION\n");
    printf("150 / 100 = %d\n", 150 / 100);
    printf("150.0 / 100 = %.2f\n", 150.0 / 100);

    /* 3. Explicit casting */
    printf("\n3. EXPLICIT CASTING\n");

    long long large_value = 3000000000LL;
    int converted_value = (int)large_value;

    printf("Original long long value = %lld\n", large_value);
    printf("After conversion to int = %d\n", converted_value);
    printf("Converting an out-of-range value to int gives an implementation-defined result.\n");

    /* 4. Three unexpected expressions */
    printf("\n4. THREE UNEXPECTED EXPRESSIONS\n");

    printf("Expression 1: 5 / 2 = %d\n", 5 / 2);
    printf("Reason: Integer division removes the fractional part.\n");

    printf("Expression 2: (double)(5 / 2) = %.2f\n", (double)(5 / 2));
    printf("Reason: Division occurs before casting.\n");

    printf("Expression 3: (int)2.99 = %d\n", (int)2.99);
    printf("Reason: Conversion from double to int truncates the fraction.\n");

    /* 5. Rounding fractional charges to paise */
    printf("\n5. ROUNDING TO PAISE\n");

    double fractional_charge = 162.505;
    long long amount_paise =
        (long long)round(fractional_charge * 100.0);

    printf("Original charge = %.3f rupees\n", fractional_charge);
    printf("Rounded bill = Rs. %lld.%02lld\n",
           amount_paise / 100, amount_paise % 100);
    printf("Rule: Round to the nearest paise using round().\n");

    /* 6. Integer paise and floating-point comparison */
    printf("\n6. INTEGER AND FLOATING-POINT COMPARISON\n");

    long long integer_total_paise = 0;
    double floating_total = 0.0;

    double one_bill = 162.505;
    int n = 1000;

    for (int i = 0; i < n; i++)
    {
        integer_total_paise +=
            (long long)round(one_bill * 100.0);

        floating_total += one_bill;
    }

    long long floating_rounded_paise =
        (long long)round(floating_total * 100.0);

    printf("Number of bills = %d\n", n);

    printf("Integer-paise total = Rs. %lld.%02lld\n",
           integer_total_paise / 100,
           integer_total_paise % 100);

    printf("Floating-point total = Rs. %lld.%02lld\n",
           floating_rounded_paise / 100,
           floating_rounded_paise % 100);

    printf("Difference = %lld paise\n",
           floating_rounded_paise - integer_total_paise);

    /* 7. Time and space analysis */
    printf("\n7. TIME AND SPACE ANALYSIS\n");
    printf("Both approaches take O(n) time for n bills.\n");
    printf("Integer paise uses integer storage per value.\n");
    printf("Floating-point calculation uses double storage per value.\n");
    printf("Integer paise avoids accumulated fractional rounding errors.\n");

    return 0;
}
