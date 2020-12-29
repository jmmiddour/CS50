// Implements a dictionary's functionality

#include <stdbool.h>  // bool
#include <stdio.h>  // printf
#include <stdlib.h>  // malloc, free
#include <string.h>  // strcpy
#include <strings.h> // strcasecmp
#include <ctype.h>  // tolower

#include "dictionary.h"  // LENGTH

// Represents a node in a hash table
typedef struct node
{
    char val[LENGTH + 1];  // the value in the node
    struct node *next;  // the next pointer in the node
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z';

int word_count = 0;  // Global variable
node *table[N];  // Hash table

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int wordKey = hash(word);  // Hash the input word to get hash code
    node *trav = table[wordKey];  // Access linked list at the hash code
    
    // Traverse list to look for the word, use `strcasecmp`
    while (trav != NULL)
    {
        // Check if the word matchs the trav value
        if (strcasecmp(trav->val, word) == 0)
        {
            return true;
        }
        
        // If the word does not match the trav value
        trav = trav->next;  // Go to the next node in the list/chain
    }
    
    // If the word is not in the dictionary
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int count = 0;  // Create a counter variable to track word value
    
    // Determines the end of the string
    for (int num = 0; num < strlen(word); num++)
    {
        count += tolower(word[num]);
    }
    
    return (count % N);
}

// Load all the words in the dictionary into memory, 
//   returning true if successful else false
// The hash function will take a word as input, then output a number for which
//   "bucket" to store the word in.
// Need to allocate memory for each new node
// Copy the string (word) from the dictionary one at a time
// Create a new node for every word
// Hash each word to obtain a hash value
// Insert the new node into the hash table at that location
bool load(const char *dictionary)
{
    FILE *dicPtr = fopen(dictionary, "r");  // Read in the dictionary file
    
    // Check edge case to verify the dictionary read in properly
    if (dicPtr == NULL)
    {
        return false;
    }
    
    // Initialize the table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    
    // Create a variable to hold each word
    char newWord[LENGTH + 1];
    
    // Read strings from the file (fscanf returns `EOF` when it gets to the end of the file)
    while (fscanf(dicPtr, "%s", newWord) != EOF)
    {
        // Allocate memory for each new node
        node *tmp = malloc(sizeof(node));
        
        // Verify there is memory to allocate
        if (tmp == NULL)
        {
            return false;
        }
        
        // Copy the string (word) from the dictionary into the new node
        strcpy(tmp->val, newWord);
        
        // Set the next pointer for the new node
        tmp->next = NULL;
        
        // Get the hash for the each word
        int hashcode = hash(newWord);
        
        // If hash node doesn't have any values
        if (table[hashcode] == NULL)
        {
            tmp->next = NULL;  // assign the next pointer to NULL
            table[hashcode] = tmp;  // set the hash_code pointer to new node
        }
        
        // If hash node already has value(s)
        else
        {
            table[hashcode] = tmp;  // set the hash_code pointer to new node
        }
        
        // Increase word count by one to return in a later function
        word_count++;
    }
    
    // Close the dictionary file
    fclose(dicPtr);
    
    // If all is successful
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;  // return the number of words
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate through the hash table to access each linked list
    for (int i = 0; i < N; i++)
    {
        node *trav = table[i];  // Point the trav to hash code in table
        node *temp = trav;  // Point the temp to the same thing as the trav
        
        // Iterate through each linked list in the hash table
        while (trav != NULL)
        {
            trav = trav->next;  // Move trav to next node
            free(temp);  // Delete/free temp
            temp = trav;  // Point temp at new location for trav
        }
    }
    
    return true;  // If successful
}
