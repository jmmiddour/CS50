#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Instantiate functions from below
int count_ltrs(char text[]);
int count_words(char text[]);
int count_sent(char text[]);

int main(void)
{
    // Set up the text array
    char text[500];
    do
    {
        // Prompt user for text
        printf("Text: ");
        fgets(text, sizeof(text), stdin);
    }
    while (strlen(text) - 1 == 0);

    // Use the functions to get counts
    int Ltrs = count_ltrs(text);
    int Wrds = count_words(text);
    int Sents = count_sent(text);

    // Print out the counts
    // printf("%i Letter(s)\n", Ltrs);
    // printf("%i Word(s)\n", Wrds);
    // printf("%i Sentence(s)\n", Sents);

    // Get L and S for Coleman-Liau Index formula
    float L = (float) Ltrs / Wrds * 100;
    float S = (float) Sents / Wrds * 100;

    // Apply the Coleman-Liau Index formula
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    // Get grade level
    int grade = round(index);

    // Display grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }
}

// Functionn to get letter counts
int count_ltrs(char text[])
{
    // Get count of characters
    int num_char = 0;

    // Iterate through characters to get count
    for (int i = 0; i < strlen(text); i++)
    {
        // Condition to make sure it is a letter based on ASCII Decimal
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            // Increase by one each time the above condition is True
            num_char++;
        }
    }
    return num_char;
}

// Function to get word counts
int count_words(char text[])
{
    // Get count of words
    int words = 1;

    // Iterate through characters to get count
    for (int i = 0; i < strlen(text); i++)
    {
        // Condition to get number of spaces based on ASCII Decimal
        if (text[i] == 32)
        {
            // Increase by one each time the above condition is True
            words++;
        }
    }
    return words;
}

// Function to get sentence counts
int count_sent(char text[])
{
    // Get counts of sentences
    int sent = 0;

    // Iterate through characters to get count
    for (int i = 0; i < strlen(text); i++)
    {
        // Condition to get just the . ! ? out based on ASCII Decimal
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            // Increase by one each time the above condition is True
            sent++;
        }
    }
    return sent;
}