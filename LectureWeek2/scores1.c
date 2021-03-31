// Averages three numbers using an array

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Scores
    int scores[3];   // Create the array
    scores[0] = 72;  // Assign value to array 0
    scores[1] = 73;  // Assign value to array 1
    scores[2] = 33;  // Assign value to array 2

    // Print average
    printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / 3);
}