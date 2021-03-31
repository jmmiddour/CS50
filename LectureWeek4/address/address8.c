// Prints a string's chars

#include <cs50.h>
#include <stdio.h>

// int main(void)
// {
//     string s = "EMMA";
//     printf("%c\n", s[0]);
//     printf("%c\n", s[1]);
//     printf("%c\n", s[2]);
//     printf("%c\n", s[3]);
// }

// Another way to do the above is:
int main(void)
{
    string s = "EMMA";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    printf("%c\n", *(s+3));
}