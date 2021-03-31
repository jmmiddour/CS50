// Prints an integer via its address

#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n", *&n);
}

// `%p` p means "pointer"
// `*&n` & means "the address of..." * means "go to..."
// when you use `*&` together you are canceling the & out with the *, 
  // so this is a pointless code to run when you an just simply remove 
  // the & in front of n and it would do the same thing.
// prints `50`