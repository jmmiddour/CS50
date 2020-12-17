#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

bool is_val_key(string s);
char map[26];

int main(int argc, string argv[])
{
    // Verify that the key is the correct type
    // argc --> the count of the arguments in the command line
    // argv[0] --> name of the program
    // argv[1] --> user defined key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if ((argc > 1 && !is_val_key(argv[1])) || (strlen(argv[1]) < 26))
    {
        printf("Key must contain 26 unique letter characters.\n");
        return 1;
    }

    // Get the Plaintext using get_string
    string s = get_string("plaintext: ");
    
    int n = strlen(s);
    char cipher[n + 1];

    // Map the input letters to alphabet letters
    for (int i = 0; i < argv[1][i]; i++)
    {
        if (isupper(argv[1][i]))
        {
            map[i] = tolower(argv[1][i]);
        }
        else
        {
            map[i] = tolower(argv[1][i]);
        }
    }
    
    // Encipher the Plaintext (using isalpha(), isupper(), and/or islower())
    int i = 0;
    for (i = 0; i < strlen(s); i++)
    {
        
        char c = s[i];
        // Check if the character is alphabetical
        if (isalpha(c))
        {
            // Formula to assign key letter to alpha letter
            // Ci = Pi % 26
            // ith char = ith plaintext remainder when / 26
            // Check first to see if input string is uppercase
            if (isupper(c))
            {
                int piu = c - 'A';
                char ciu = map[piu];
                cipher[i] = toupper(ciu);
            }
            // If not Uppercase
            else
            {
                int pil = c - 'a';
                char cil = map[pil];
                cipher[i] = tolower(cil);
            }
        }
        // If not an alpha charater, just return that character
        else
        {
            cipher[i] = c;
        }
    }
    // add the null value at the end of the string
    cipher[i] = '\0';

    printf("ciphertext: %s\n", cipher);

    return 0;
}

// Function to validate if key is correct
bool is_val_key(string s)
{
    int i = 0;
    int buff[26];
    for (i = 0; i < 26; i++)
    {
        buff[i] = -1;
    }
    
    for (i = 0; i < strlen(s); i++)
    {
        char c = s[i];

        if (!isalpha(c))
        {
            return false;
        }

        if (buff[tolower(c) - 'a'] != -1)
        {
            return false;
        }
        else
        {
            buff[tolower(c) - 'a'] = 1;
        }
    }

    return i == 26;
}