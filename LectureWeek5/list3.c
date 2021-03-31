// Implements a list of numbers with linked list

#include <stdio.h>  // printf
#include <stdlib.h>  // malloc, free

// Represents a node
typedef struct node
{
    int number;  // value
    struct node *next;  // pointer
}
node;

int main(void)
{
    // List of size 0
    node *list = NULL;  // initializes the "list" variable

    // Add number to list
    node *n = malloc(sizeof(node));  // allocates memory double block for a new node
    if (n == NULL)  // checks if the memory location is NULL
    {
        return 1; // stops the program if out of memory
    }
    n->number = 1;  // adds a value to the new node
    n->next = NULL;  // creates a new NULL pointer for the new node
    list = n;  // tells list to point at the new node

    // Add number to list
    n = malloc(sizeof(node));  // reuse the "n" variable to allocate memory for a new node
    if (n == NULL)  // check if there is memory available
    {
        return 1;  // stops program if there is no more memory
    }
    n->number = 2;  // adds a value to the new node
    n->next = NULL;  // creates a new NULL pointer for the new node
    list->next = n;  // tells the 1st value in the list to point to the new node

    // Add number to list
    n = malloc(sizeof(node));  // reuse the "n" variable to allocate memory for a new node
    if (n == NULL)  // check if there is memory available
    {
        return 1;  // stops program if there is no more memory
    }
    n->number = 3;  // adds a value to the new node
    n->next = NULL;  // creates a new NULL pointer for the new node
    list->next->next = n;  // tells the 2nd value in the list to point to the new node
                           // would not conventional code it this way,
                           // would use some kind of loop to iterate through the list to get to the last node
                           // and have it then point to the new node

    // Print list
    // Use a for loop to iterate through the linked list
    // for (<initializer>; <condition>; <update>)
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);  // print the value in each node
    }

    // Free list using a while, makes it cleaner
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
