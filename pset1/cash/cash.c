#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float chg;
    int cents, remain, coins;

    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;

    do
    {
        // Prompt user for a positive float
        chg = get_float("How much change?\n");
    }
    // Only run if user input is a postive number
    while (chg < 0);

    // Turn cents into an intergar to avoid errors when calculating
    cents = round(chg * 100);

    // Get the number of quarters needed
    q += cents / 25;
    cents %= 25;

    // Get the number of dimes needed
    d += cents / 10;
    cents %= 10;

    // Get the number of nickels needed
    n += cents / 5;
    cents %= 5;

    // Get the number of pennies needed
    p += cents;

    printf("Change owed: %.2f\n", chg);

    // Add the number of each coin needed to get total coins
    coins = (q + d + n + p);

    printf("%i\n", coins);
}