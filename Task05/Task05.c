
#include <stdio.h>
#include "Task05.h"

// Function to calculate square
int square(int number)
{
    int result = number * number;

#ifdef DEBUG
    printf("[DEBUG] Square calculation: %d * %d = %d\n",
           number, number, result);
#endif

    return result;
}

// Function to find maximum
int maximum(int a, int b)
{
    int result = (a > b) ? a : b;

#ifdef DEBUG
    printf("[DEBUG] Comparing %d and %d\n", a, b);
    printf("[DEBUG] Maximum value = %d\n", result);
#endif

    return result;
}

// Function to calculate circle area
double calculate_circle_area(double radius)
{
    double area = PI * radius * radius;

#ifdef DEBUG
    printf("[DEBUG] Circle radius = %.2f\n", radius);
    printf("[DEBUG] Circle area = %.2f\n", area);
#endif

    return area;
}

int main(void)
{
    int number = 5;
    int a = 20, b = 35;
    double radius = 7.0;

    printf("TASK 05 - HEADER FILES AND DEBUGGING\n");
    printf("------------------------------------\n");

    printf("Square of %d = %d\n", number, square(number));

    printf("Maximum of %d and %d = %d\n",
           a, b, maximum(a, b));

    printf("Area of circle = %.2f\n",
           calculate_circle_area(radius));

    printf("Maximum allowed value = %d\n", MAX_VALUE);

    return 0;
}
