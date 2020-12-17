// Dangerously gets a string from user using scanf

#include <stdio.h>

int main(void)
{
    char s[5];  // char * is already a pointer
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}