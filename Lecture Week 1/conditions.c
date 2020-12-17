// Connditions and relational operators:

#include <cs50.h>
#include <stdio.h>

int main (void)
{
    // Prompt user for x:
    int x = get_int("What is x in a whole number?\n");
    
    // Prompt user for y:
    int y = get_int("What is y in a whole number?\n");
    
    // Compare x and y:
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}