
#include <stdio.h>
#include <limits.h>

#define FIXED_CHARGE_PAISE 5000LL
#define FIRST_SLAB_LIMIT 100
#define SECOND_SLAB_LIMIT 200
#define FIRST_SLAB_RATE 225LL
#define SECOND_SLAB_RATE 450LL

#define VILLAGE_BILLS 4000
#define TALUK_BILLS 60000
#define DISTRICT_BILLS 800000

typedef unsigned short meter_reading_t;
typedef long long money_t;

money_t calculate_bill(int units)
{
    money_t bill = FIXED_CHARGE_PAISE;

    if (units <= FIRST_SLAB_LIMIT)
    {
        return bill;
    }
    else if (units <= SECOND_SLAB_LIMIT)
    {
        bill += (money_t)(units - FIRST_SLAB_LIMIT)
                * FIRST_SLAB_RATE;
    }
    else
    {
        bill += 100LL * FIRST_SLAB_RATE;
        bill += (money_t)(units - SECOND_SLAB_LIMIT)
                * SECOND_SLAB_RATE;
    }

    return bill;
}

void display_bill(int units)
{
    money_t bill = calculate_bill(units);

    printf("Units consumed: %d\n", units);
    printf("Electricity bill: Rs. %lld.%02lld\n",
           bill / 100, bill % 100);
}

int main(void)
{
    money_t sample_bill;
    money_t district_total;

    printf("TASK 11 - RECOMMEND AND DEFEND THE FINAL DESIGN\n");
    printf("------------------------------------------------\n");

    printf("\n1. RECOMMENDED DATA TYPES\n");

    printf("Meter reading type: unsigned short\n");
    printf("Meter reading size: %zu bytes\n",
           sizeof(meter_reading_t));

    printf("Money type: long long\n");
    printf("Money type size: %zu bytes\n", sizeof(money_t));

    printf("Integer paise is used to avoid floating-point ");
    printf("rounding in billing.\n");

    printf("\n2. RECOMMENDED TARIFF CONSTANTS\n");

    printf("Fixed charge: %lld paise\n",
           FIXED_CHARGE_PAISE);

    printf("First slab limit: %d units\n",
           FIRST_SLAB_LIMIT);

    printf("Second slab limit: %d units\n",
           SECOND_SLAB_LIMIT);

    printf("First slab rate: %lld paise per unit\n",
           FIRST_SLAB_RATE);

    printf("Second slab rate: %lld paise per unit\n",
           SECOND_SLAB_RATE);

    printf("\n3. SAMPLE BILL TEST\n");

    display_bill(150);

    sample_bill = calculate_bill(150);

    printf("\n4. DISTRICT-SCALE VALIDATION\n");

    district_total = sample_bill * DISTRICT_BILLS;

    printf("Number of district bills: %d\n",
           DISTRICT_BILLS);

    printf("Total in paise: %lld\n", district_total);

    printf("Total in rupees: Rs. %lld.%02lld\n",
           district_total / 100,
           district_total % 100);

    printf("Long long maximum: %lld\n", LLONG_MAX);

    printf("District total fits in long long: %s\n",
           district_total <= LLONG_MAX ? "YES" : "NO");

    printf("\n5. TARIFF REVISION METHOD\n");

    printf("Current tariff values are defined using #define.\n");
    printf("For a tariff revision, update the relevant ");
    printf("definitions and recompile the program.\n");

    printf("\n6. DESIGN LIMITATIONS\n");

    printf("Compile-time constants require recompilation ");
    printf("after tariff changes.\n");

    printf("The program assumes valid non-negative unit values.\n");

    printf("The district calculation uses a sample bill of ");
    printf("Rs. 162.50 per household.\n");

    printf("Actual district totals depend on each household's ");
    printf("consumption.\n");

    printf("\n7. ALTERNATIVE: CONFIGURATION FILE\n");

    printf("Tariff values can be stored in a configuration file.\n");
    printf("The program can read the values when it starts.\n");

    printf("Reading t tariff values takes O(t) time.\n");
    printf("Storing t tariff values requires O(t) space.\n");

    printf("Tariff changes can then be made without recompiling.\n");

    printf("The program must validate the file and handle ");
    printf("missing or invalid values.\n");

    printf("\n8. FINAL RECOMMENDATION\n");

    printf("Use long long for accumulated money in paise.\n");
    printf("Use integer constants for tariff rates.\n");
    printf("Use #define for fixed compile-time tariff values.\n");
    printf("Use a configuration file if tariffs change frequently.\n");
    printf("The tested district total fits safely in long long.\n");

    printf("\nTASK 11 ANALYSIS COMPLETED\n");

    return 0;
}
