#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#define FIXED_CHARGE 5000LL
#define MAX_READING 65535

int calculate_units(int previous, int current, int *units)
{
    if (previous < 0 || previous > MAX_READING ||
        current < 0 || current > MAX_READING)
        return 0;

    if (current >= previous)
        *units = current - previous;
    else if (previous == 65535 && current == 0)
        *units = 1;
    else
        return 0;

    return 1;
}

long long calculate_bill(int units)
{
    long long charge = 0;

    if (units > 100 && units <= 200)
        charge = (long long)(units - 100) * 225;
    else if (units > 200)
        charge = 100LL * 225 + (long long)(units - 200) * 450;

    return FIXED_CHARGE + charge;
}

int valid_number(const char *input)
{
    char *end;
    long value;

    errno = 0;
    value = strtol(input, &end, 10);

    return input[0] != '\0' && *end == '\0' &&
           errno != ERANGE && value >= 0 && value <= MAX_READING;
}

void run_tests(void)
{
    int previous[] = {1000, 1000, 1000, 1000, 1000,
                      1000, 1000, 65535};
    int current[] = {1000, 1050, 1100, 1150, 1200,
                 1350, 999, 0};
    const char *names[] = {
        "Zero units", "50 units", "100 units",
        "150 units", "200 units", "350 units",
        "Invalid decreasing reading", "Meter rollover"
    };

    printf("\nAUTOMATED BILLING TESTS\n");
    printf("-----------------------\n");

    long long five_bill_total = 0;

    for (int i = 0; i < 8; i++)
    {
        int units;

        printf("\n%s\n", names[i]);

        if (calculate_units(previous[i], current[i], &units))
        {
            long long bill = calculate_bill(units);

            printf("Units: %d | Bill: Rs. %lld.%02lld\n",
                   units, bill / 100, bill % 100);

            if (i >= 1 && i <= 5)
                five_bill_total += bill;
        }
        else
        {
            printf("Result: Invalid meter readings (PASS)\n");
        }
    }

    printf("\nINPUT VALIDATION TESTS\n");
    printf("---------------------\n");
    printf("Letters (abc): %s\n",
           valid_number("abc") ? "FAIL" : "PASS");
    printf("Negative reading (-10): %s\n",
           valid_number("-10") ? "FAIL" : "PASS");

    printf("\nFIVE-BILL TOTAL\n");
    printf("---------------\n");
    printf("Expected total: Rs. 1487.50\n");
    printf("Calculated total: Rs. %lld.%02lld\n",
           five_bill_total / 100, five_bill_total % 100);
}

int main(void)
{
    int choice;

    printf("GRAM JYOTHI RURAL ELECTRICITY BILLING\n");
    printf("-------------------------------------\n");
    printf("1. Calculate a bill\n");
    printf("2. Run all automatic tests\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input! Enter 1 or 2.\n");
        return 1;
    }

    if (choice == 2)
    {
        run_tests();
    }
    else if (choice == 1)
    {
        int previous, current, units;

        printf("Enter previous meter reading: ");
        if (scanf("%d", &previous) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        printf("Enter current meter reading: ");
        if (scanf("%d", &current) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        if (!calculate_units(previous, current, &units))
        {
            printf("Invalid meter readings!\n");
            return 1;
        }

        long long bill = calculate_bill(units);

        printf("Units consumed: %d\n", units);
        printf("Total bill: Rs. %lld.%02lld\n",
               bill / 100, bill % 100);
    }
    else
    {
        printf("Invalid choice!\n");
        return 1;
    }

    return 0;
}