#include <cs50.h>
#include <stdio.h>

// Implements linear search for numbers
int main(void)
{
    // Statically Initialized Array
    // You know in advanced what values are going to be in the array
    int numbers[6] = {4, 8, 15, 16, 23, 42};
    
    // Search for 50
    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == 50)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}