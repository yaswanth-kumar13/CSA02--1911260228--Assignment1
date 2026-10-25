
#include <stdio.h>

int main(void)
{
    int units;
    long amount_paise;

    /* Variables for format specifier demonstration */
    unsigned int count = 4000;
    long population = 60000L;
    long long district = 800000LL;
    float rate = 2.25f;
    double total = 162.50;
    char category = 'A';
    char name[] = "Household";

    printf("RURAL ELECTRICITY BILL\n");
    printf("----------------------\n");

    printf("Enter electricity units consumed: ");

    if (scanf("%d", &units) != 1)
    {
        printf("Invalid input! Please enter a number.\n");
        return 1;
    }

    if (units < 0)
    {
        printf("Invalid input! Units cannot be negative.\n");
        return 1;
    }

    amount_paise = 5000 + (units > 100 ? (long)(units - 100) * 225 : 0);

    printf("\nBILL DETAILS\n");
    printf("Units consumed: %d\n", units);
    printf("Total amount: Rs. %ld.%02ld\n",
           amount_paise / 100, amount_paise % 100);

    printf("\nFORMAT SPECIFIER DEMONSTRATION\n");
    printf("Unsigned integer: %u\n", count);
    printf("Long integer: %ld\n", population);
    printf("Long long integer: %lld\n", district);
    printf("Float value: %.2f\n", rate);
    printf("Double value: %.2f\n", total);
    printf("Character: %c\n", category);
    printf("String: %s\n", name);

    printf("\nWRONG FORMAT SPECIFIER DEMONSTRATION\n");
    printf("Correct long value: %ld\n", population);
    printf("Incorrect long format using %%d is not demonstrated here "
           "because mismatched format arguments cause undefined behaviour.\n");

    return 0;
}
