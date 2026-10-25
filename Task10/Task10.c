
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define VILLAGE_BILLS 4000
#define TALUK_BILLS 60000
#define DISTRICT_BILLS 800000

#define BILL_PAISE 16250LL

void compare_totals(int number_of_bills)
{
    long long paise_total = 0;
    float float_total = 0.0f;
    double double_total = 0.0;

    for (int i = 0; i < number_of_bills; i++)
    {
        paise_total += BILL_PAISE;
        float_total += 162.50f;
        double_total += 162.50;
    }

    double exact_total = (double)paise_total / 100.0;

    printf("\nNumber of bills: %d\n", number_of_bills);
    printf("Integer-paise total: Rs. %.2f\n", exact_total);
    printf("Float total: Rs. %.2f\n", float_total);
    printf("Double total: Rs. %.2f\n", double_total);

    printf("Float difference: Rs. %.2f\n",
           (double)float_total - exact_total);

    printf("Double difference: Rs. %.2f\n",
           double_total - exact_total);
}

int main(void)
{
    long long district_total =
        (long long)DISTRICT_BILLS * BILL_PAISE;

    printf("TASK 10 - COMPARE EXPECTATIONS WITH EXECUTION\n");
    printf("---------------------------------------------\n");

    printf("\n1. VILLAGE, TALUK AND DISTRICT TOTALS\n");

    compare_totals(VILLAGE_BILLS);
    compare_totals(TALUK_BILLS);
    compare_totals(DISTRICT_BILLS);

    printf("\n2. DATA TYPE SIZES ON THIS SYSTEM\n");

    printf("sizeof(int)       = %zu bytes\n", sizeof(int));
    printf("sizeof(long)      = %zu bytes\n", sizeof(long));
    printf("sizeof(long long) = %zu bytes\n", sizeof(long long));
    printf("sizeof(float)     = %zu bytes\n", sizeof(float));
    printf("sizeof(double)    = %zu bytes\n", sizeof(double));

    printf("\n3. DATA TYPE RANGES\n");

    printf("INT_MAX       = %d\n", INT_MAX);
    printf("LONG_MAX      = %ld\n", LONG_MAX);
    printf("LLONG_MAX     = %lld\n", LLONG_MAX);
    printf("FLT_DIG       = %d decimal digits\n", FLT_DIG);
    printf("DBL_DIG       = %d decimal digits\n", DBL_DIG);

    printf("\nMinimum ranges guaranteed by the C standard:\n");
    printf("int: at least -32767 to 32767\n");
    printf("long: at least -2147483647 to 2147483647\n");
    printf("long long: at least -9223372036854775807 to 9223372036854775807\n");
    printf("float: at least 6 decimal digits of precision\n");
    printf("double: at least 10 decimal digits of precision\n");

    printf("\n4. INTEGER OVERFLOW CHECK\n");

    printf("District total in paise = %lld\n", district_total);
    printf("Maximum int value       = %d\n", INT_MAX);
    printf("Maximum long value      = %ld\n", LONG_MAX);
    printf("Maximum long long value = %lld\n", LLONG_MAX);

    printf("Can int hold district total?       %s\n",
           district_total <= INT_MAX ? "YES" : "NO");

    printf("Can long hold district total?      %s\n",
           district_total <= LONG_MAX ? "YES" : "NO");

    printf("Can long long hold district total? %s\n",
           district_total <= LLONG_MAX ? "YES" : "NO");

    printf("\n5. TIME AND SPACE ANALYSIS\n");

    printf("Each method processes n bills in O(n) time.\n");
    printf("Each total variable uses O(1) space.\n");
    printf("Each addition takes constant time, O(1).\n");
    printf("On this system, int, long and float use 4 bytes each.\n");
    printf("Long long and double use 8 bytes each.\n");
    printf("Integer types can overflow when their range is exceeded.\n");
    printf("Floating-point types can lose precision when values grow.\n");
    printf("Double provides more precision than float.\n");

    printf("\nTASK 10 ANALYSIS COMPLETED\n");

    return 0;
}
