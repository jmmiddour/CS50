// Stores and prints an integer's address

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}

// `*p` means "this is a pointer"
// `int` in front of `*p` means that is the type of data the pointer is pointing to
// `&n` means "the address of n"
// prints `0x7ffe8e9590ac`