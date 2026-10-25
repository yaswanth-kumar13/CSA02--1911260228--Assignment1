#include <stdio.h>

int main(void)
{
    FILE *file = fopen("missing_file.txt", "r");

    if (file == NULL)
    {
        printf("RUNTIME ERROR: Unable to open the file.\n");
        return 1;
    }

    fclose(file);
    return 0;
}