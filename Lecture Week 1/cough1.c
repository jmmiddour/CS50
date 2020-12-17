// Code to return "cough" 3 times using a created function:

#include <stdio.h>

void cough(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        cough();
    }
}

// Create a function to do the above code:
void cough (void) // <-- this line is copied and pasted to the top of the code and add `;` at the end.
{
    printf("cough\n");
}
