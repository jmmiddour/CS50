#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

bool is_val_key(string s);

int main(int argc, string argv[])
{
    // Verify that the key is the correct type and
    //   prompt user for plaintext string
    if (argc != 2 || !is_val_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get the Plaintext using get_string
    string s = get_string("plaintext: ");

    // Encipher the Plaintext (using isalpha(), isupper(), and/or islower())
    int k = atoi(argv[1]);
    int n = strlen(s);
    char cipher[n + 1];
    int i = 0;
    for (i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (isalpha(c))
        {
            // Formula to wrap Z back to A
            // Ci = (Pi + K) % 26
            // ith char = (ith plaintext + key) remainder when / 26
            if (isupper(c))
            {
                char cu = c - 'A';
                char ciu = ((cu + k) % 26) + 'A';
                cipher[i] = ciu;
            }
            else
            {
                char cl = c - 'a';
                char cil = ((cl + k) % 26) + 'a';
                cipher[i] = cil;
            }
        }
        else
        {
            cipher[i] = c;
        }
    }
    cipher[i] = '\0';

    printf("ciphertext: %s\n", cipher);

    return 0;
}

// Function to validate if key is correct
bool is_val_key(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}