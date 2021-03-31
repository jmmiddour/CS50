// Implements a list of numbers with an array of dynamic size

#include <stdio.h>
#include <stdlib.h>  // contains malloc and free

int main(void)
{
    // List of size 3
    int *list = malloc(3 * sizeof(int));  // allocate memory for 3 ints the size of int for each int
    if (list == NULL)  // Check for edge case (is memory full)
    {
        return 1;  // If memory is full, raise an error
    }

    // Initialize list of size 3 with numbers, since an int is 4 bytes...
    list[0] = 1;  // this will point to the first byte
    list[1] = 2;  // this one points 4th btyes from the first byte
    list[2] = 3;  // this one points 8th byte from the first byte

    // List of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    // Copy list of size 3 into list of size 4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // Add number to list of size 4
    tmp[3] = 4;

    // Free list of size 3
    free(list);

    // Remember list of size 4
    list = tmp;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);  // Need to make sure to release the memory to avoid memory leakage.
}
