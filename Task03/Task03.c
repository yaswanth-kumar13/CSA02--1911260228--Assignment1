
#include <stdio.h>

// Electricity tariff details
#define FIXED_CHARGE 50.0
#define FREE_UNITS 100
#define SECOND_SLAB_LIMIT 200
#define RATE_FIRST 2.25
#define RATE_SECOND 4.50

// Function to calculate the electricity bill
double compute_bill(int units)
{
    double bill = FIXED_CHARGE;

    if (units > FREE_UNITS)
    {
        if (units <= SECOND_SLAB_LIMIT)
        {
            bill += (units - FREE_UNITS) * RATE_FIRST;
        }
        else
        {
            bill += (SECOND_SLAB_LIMIT - FREE_UNITS) * RATE_FIRST;
            bill += (units - SECOND_SLAB_LIMIT) * RATE_SECOND;
        }
    }

    return bill;
}

int main(void)
{
    int readings[] = {0, 100, 150, 200, 350};
    int count = sizeof(readings) / sizeof(readings[0]);

    printf("ELECTRICITY BILL CALCULATION\n");
    printf("----------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("Units: %d | Bill: Rs. %.2f\n",
               readings[i], compute_bill(readings[i]));
    }

    return 0;
}
