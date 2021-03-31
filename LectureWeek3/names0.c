#include <cs50.h>
#include <stdio.h>
#include <string.h>  // strcmp found here

// Implements linear search for names
int main(void)
{
    //An array of names
    string names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};
    
    // Search for EMMA
    for (int i = 0; i < 4; i++)
    {
        // Can not just call names[i] == "EMMA" to compare strings
        // Need to use function strcmp to compare strings
        // strcmp(first str to comp, second str to comp)
        // Will return 0 if both strings are the same
        // Returns a pos number if the str comes after the other aphabetically
        // Returns a neg number if the str comes before the other aphabetically
        if (strcmp(names[i], "EMMA") == 0)
        {
            printf("Found\n");
            return 0;  // means it was a success
        }
    }
    printf("Not found\n");
    return 1;  // means not a success
}

// If you do not return 0 and 1 it will return both Found and Not found