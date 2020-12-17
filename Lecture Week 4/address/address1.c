// Prints an integer's address

#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}

// `%p` p means "pointer"
// `&n` & means "the address of..."
// prints `0x7ffd573bbbbc`