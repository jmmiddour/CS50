// Prints string char by char, one per line

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    for (int i = 0; s[i] != '\0'; i++)  // get each char of a string without the \0
    {
        printf("%c", s[i]);
    }
    printf("\n");
}