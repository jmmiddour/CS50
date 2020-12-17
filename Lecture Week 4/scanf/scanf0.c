// Gets an int from user using scanf

#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);  // a standard C function
    printf("x: %i\n", x);
}