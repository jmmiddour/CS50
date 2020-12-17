// Function to create a pyramid using n number of # as blocks:

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j;
    do
    {
        // Prompt user for a postive number between 1 and 8
        n = get_int("How tall do you want the pyramid between 1 and 8?  \n");
    }
    // Only run if user input is 1-8
    while (n < 1 || n > 8);
    // Iterate over n and increase n by 1 each time
    for (i = 0; i < n; i++)
    {
        // Adds whitespace in front of # symbols
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Adds the # symbols for n in each row
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Creates a new line for each iteration
        printf("\n");
    }
}