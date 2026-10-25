
#include <stdio.h>

#define FIXED_CHARGE 50

int calculate_bill(int units)
{
    int energy_charge = 0;

    if (units > 100)
    {
        energy_charge = (units - 100) * 2;
    }

    return FIXED_CHARGE + energy_charge;
}

int main(void)
{
    

    int units = 150;
    int bill = calculate_bill(units);

    printf("TASK 08 - COMPILATION PROCESS\n");
    printf("-----------------------------\n");

    printf("Units consumed: %d\n", units);
    printf("Fixed charge: Rs. %d\n", FIXED_CHARGE);
    printf("Total electricity bill: Rs. %d\n", bill);

    return 0;
}
