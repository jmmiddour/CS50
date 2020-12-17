// Prints a row and columns of n hash tags with a a loop:

#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;
    do
    {
        n = get_int("Size = ");
    }
    while (n < 1);
    for (int i = 0; i < n; i++)  // <-- this is iterating the number of rows.
    {
        for (int j = 0; j < n; j++)  // <-- this is iterating the number of columns.
        {
            printf("#");
        }
        printf("\n");
    }
}