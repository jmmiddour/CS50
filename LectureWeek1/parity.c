#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n = get_int("What is your whole number?\n");
    
    if (n % 2 == 0)  // if n/2=R0 would be coded like this using a remainder statement. 
    {
        printf("Your number is even.\n");
    }
    else
    {
        printf("Your number is odd.\n");
    }
}