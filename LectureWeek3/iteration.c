// Draws a pyramid using iteration

#include <cs50.h>
#include <stdio.h>

void draw(int h);

int main(void)
{
    // Get height of pyramid
    int height = get_int("Height: ");

    // Draw pyramid
    draw(height);
}

// Create a function to draw the pyramid
void draw(int h)  // Use void when it doesn't need to return a value
{
    // Draw pyramid of height h
    for (int i = 1; i <= h; i++)
    {
        // 
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}