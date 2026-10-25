
#include <stdio.h>

#define READINGS_PER_DAY 96
#define DAYS_PER_YEAR 365
#define READINGS_PER_YEAR (READINGS_PER_DAY * DAYS_PER_YEAR)
#define PEAK_START 72
#define PEAK_END 88
#define WH_PER_KWH 1000ULL
#define PERCENT_SCALE 100ULL

typedef struct
{
    unsigned long long fixed_charge_paise;
    unsigned long long normal_rate_paise;
    unsigned int peak_surcharge_percent;
} Tariff;

int load_tariff(Tariff *tariff)
{
    FILE *file = fopen("tariff.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open tariff.txt\n");
        return 0;
    }

    int result = fscanf(file, "%llu %llu %u",
                        &tariff->fixed_charge_paise,
                        &tariff->normal_rate_paise,
                        &tariff->peak_surcharge_percent);

    fclose(file);

    if (result != 3 ||
        tariff->fixed_charge_paise > 100000000ULL ||
        tariff->normal_rate_paise == 0 ||
        tariff->normal_rate_paise > 1000000ULL ||
        tariff->peak_surcharge_percent > 1000)
    {
        printf("Error: Invalid tariff configuration\n");
        return 0;
    }

    return 1;
}

int main(void)
{
    Tariff tariff;

    unsigned long long total_wh = 0;
    unsigned long long scaled_charge = 0;
    unsigned long long peak_wh = 0;
    unsigned long long normal_wh = 0;

    if (!load_tariff(&tariff))
        return 1;

    printf("TASK 12 - SMART METER BILLING DESIGN\n");
    printf("------------------------------------\n");

    printf("Tariff loaded from tariff.txt\n");
    printf("Fixed charge: %llu paise\n",
           tariff.fixed_charge_paise);
    printf("Normal rate: %llu paise per kWh\n",
           tariff.normal_rate_paise);
    printf("Peak surcharge: %u%%\n",
           tariff.peak_surcharge_percent);

    /*
       Demonstration: 100 Wh is used in each
       15-minute interval for one year.
       Intervals 72 to 87 are peak hours.
    */

    for (int i = 0; i < READINGS_PER_YEAR; i++)
    {
        unsigned long long energy_wh = 100;
        int interval_in_day = i % READINGS_PER_DAY;

        total_wh += energy_wh;

        if (interval_in_day >= PEAK_START &&
            interval_in_day < PEAK_END)
        {
            peak_wh += energy_wh;
        }
        else
        {
            normal_wh += energy_wh;
        }
    }

    scaled_charge =
        normal_wh * tariff.normal_rate_paise * PERCENT_SCALE +
        peak_wh * tariff.normal_rate_paise *
        (PERCENT_SCALE + tariff.peak_surcharge_percent);

    unsigned long long divisor =
        WH_PER_KWH * PERCENT_SCALE;

    unsigned long long energy_charge =
        (scaled_charge + divisor / 2) / divisor;

    unsigned long long total_bill =
        energy_charge + tariff.fixed_charge_paise;

    printf("\nYEARLY SMART METER ANALYSIS\n");
    printf("---------------------------\n");

    printf("Readings per year: %d\n", READINGS_PER_YEAR);
    printf("Total energy: %llu Wh\n", total_wh);
    printf("Normal-hour energy: %llu Wh\n", normal_wh);
    printf("Peak-hour energy: %llu Wh\n", peak_wh);

    printf("\nBILL CALCULATION\n");
    printf("----------------\n");

    printf("Energy charge: Rs. %llu.%02llu\n",
           energy_charge / 100, energy_charge % 100);

    printf("Fixed charge: Rs. %llu.%02llu\n",
           tariff.fixed_charge_paise / 100,
           tariff.fixed_charge_paise % 100);

    printf("Total yearly bill: Rs. %llu.%02llu\n",
           total_bill / 100, total_bill % 100);

    printf("\nDATA TYPE AND DESIGN EVALUATION\n");
    printf("--------------------------------\n");

    printf("sizeof(unsigned long long): %zu bytes\n",
           sizeof(unsigned long long));

    printf("Watt-hour totals use unsigned long long.\n");
    printf("Money uses scaled integer arithmetic.\n");
    printf("Tariff values are loaded at runtime.\n");
    printf("Peak hours are from 6 PM to 10 PM.\n");
    printf("The peak surcharge is applied during peak hours.\n");

    printf("\nTASK 12 ANALYSIS COMPLETED\n");

    return 0;
}
