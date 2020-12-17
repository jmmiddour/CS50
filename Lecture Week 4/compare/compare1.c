// Compares two strings' addresses

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    string s = get_string("s: ");
    string t = get_string("t: ");

    // Compare strings' addresses
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

// With this code even if you type in the same string 
  //in the prompts it will return "Different".
// This is because they are stored at different memory locations.
// The computer only sees the memory locations and not the actual characters.
// In this case we would need to use a pointer for it to compare the characters.