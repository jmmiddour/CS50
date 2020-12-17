// Buggy example for help50

#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}

// run `make buggy1` in the command line and receive an error

// then run `help50 make buggy1` to get help from CS50

// help50 software will then run the make command and look at the errors for you,
    // then when it recognizes an error it will give you a yellow highlighted area and
    // explain the error message and give suggestions on how to correct the error.
    // help50 will always return the first error it defines only.

// In this example help50 returns:
    // Asking for help...

    // buggy1.c:7:5: error: use of undeclared identifier 'string'; did you mean 'stdin'?

    // By "undeclared identifier," clang means you've used a name string on line 7 of buggy1.c which hasn't been defined. Did you forget to #include <cs50.h> (in which string is defined) atop your file?