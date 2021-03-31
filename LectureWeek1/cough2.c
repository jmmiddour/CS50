// Code to return "cough" n number of times:

#include <stdio.h>

void cough(int n); // <-- called a "prototyope"

int main(void)
{
    cough(3);
}

// Create a function to do the above code:
void cough (int n) // <-- this line is copied and pasted to the top of the code and add `;` at the end.
{
    for (int i = 0; i < n; i++)
    {
        printf("cough\n");
    }
}