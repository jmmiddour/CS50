// A function to prompt the user for their name and then say Hello to them:

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("Hello, %s!\n", name);
}