// Thia is not the one I turned in for my assignment,
  // just another way to solve the problem.

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// instantiate function from below
int get_index(string s);

// instantiate the main program
int main()
{
    // Prompt user for text
    string_text = get_string("Text: ");

    // Assign function to a variable that uses text as input
    int index = get_index(text);

    // If index returns less than 1, print "Before Grade 1"
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    // If index returns greater than 15, print "Grade 16+"
    else if (index <= 16)
    {
        printf("Grade 16+\n");
    }

    // If index returns n == 1 thru 15, print "Grade n"
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}


// Function to clean the string of text inputted by user
int get_index(string s)
{
    // Create variable for letters, sentences, and words
    int letters = 0, sentences = 0, words = 0;

    // Iterate over the string of text
    for (int i = 0; i < strlen(s); i++)
    {
        // Assign variable to each character in string of text
        char ch = s[i];

        // Check if character is a letter, then increase by 1 for each true statement
        if (isalpha(ch))
        {
            letters++;
        }

        // Check if character is a space, then increase by 1 for each true statement
        if (isspace(ch))
        {
            words++;
        }

        // Check if character is . ! or ?, then increase by 1 for each true statment
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentences++;
        }
    }

    // Increase words by 1 for each iteration
    words++;

    // Assign variable to the average number of letters per 100 words equation
    float L = (letters * 100.0f) / words;

    // Assign varaible to the average number of sentences per 100 words equation
    float S = (sentences * 100.0f) / words;

    // Return rounded level from the Coleman-Liau Index
    return round(0.0588 * L - 0.296 * S - 15.8)
}