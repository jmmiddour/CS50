#include <stdio.h>
#include <unistd.h>  // <-- Will allow us to use the `sleep` function.

int main (void)
{
    for (int i = 1; ; i *= 2)  // <-- Creates an infinte loop
    {
        printf("%i\n", i);
        sleep(1);  // <-- Allows the computer to sleep 1 second at a time.
    }
}