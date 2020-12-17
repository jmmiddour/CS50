// Buggy example for help50

int main(void)
{
    printf("hello, world\n")
}

// run `make buggy0` in the command line and receive an error

// then run `help50 make buggy0` to get help from CS50

// help50 software will then run the make command and look at the errors for you,
    // then when it recognizes an error it will give you a yellow highlighted area and
    // explain the error message and give suggestions on how to correct the error.

// In this example help50 returns:
    // Asking for help...

    // buggy0.c:5:5: error: implicitly declaring library function 'printf' with type 'int (const char *, ...)' [-Werror,-Wimplicit-function-declaration]
    // printf("hello, world\n")

    // Did you forget to #include <stdio.h> (in which printf is declared) atop your file?