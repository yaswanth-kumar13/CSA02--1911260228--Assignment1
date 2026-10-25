
#include <stdio.h>

// Macro to convert rupees into paise
#define RUPEES_TO_PAISE(x) ((x) * 100L)

// Safe square macro
#define SQUARE(x) ((x) * (x))

// Macro to find the maximum of two values
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// Static inline function for square
static inline int square_function(int x)
{
    return x * x;
}

// Static inline function for maximum
static inline int max_function(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int number = 5;
    int a = 10;
    int b = 20;
    int value = 4;

    printf("MACRO DEMONSTRATION\n");
    printf("-------------------\n");

    printf("Rupees to Paise: %ld paise\n",
           RUPEES_TO_PAISE(50));

    printf("Square of %d: %d\n",
           number, SQUARE(number));

    printf("Square of a+1: %d\n",
           SQUARE(value + 1));

    printf("Maximum of %d and %d: %d\n",
           a, b, MAX(a, b));

    printf("\nINLINE FUNCTION DEMONSTRATION\n");
    printf("-----------------------------\n");

    printf("Square using function: %d\n",
           square_function(number));

    printf("Maximum using function: %d\n",
           max_function(a, b));

    return 0;
}
