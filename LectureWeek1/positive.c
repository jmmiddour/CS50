// Abstraction and scope:

#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main (void)
{
    int i = get_positive_int();
    printf("%i\n", i);
}

// Prompt user for a positive interger and create a loop to keep going back
  // to the beginning if user does not enter a positive int:
int get_positive_int(void)
{
    int n;  // <-- tells the computer you just want a blank int variable called `n`
    do      // <-- Start of a "do while loop" means `do` `n = ...` `while (n < 1)`
    {
        n = get_int("Provide a postive whole number: ");
    }
    while (n < 1);
    return n;
}