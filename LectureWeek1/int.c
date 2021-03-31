#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int age = get_int("What is your age?\n");
    printf("You are at least %i days old.\n", age * 365 );
}