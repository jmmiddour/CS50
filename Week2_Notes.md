# CS50 - Week 2 - Arrays

4 steps `clang` or `make` do in **C**:
- Preprocessing: First thing that C does is goes into the "libraries" that you add at the top of your code with `#include` and pulls out the functions needed to run all your code.

- Compiling: Then all of the code is then changed into "assembly code".

- Assembling: Takes the "assembly code" and converts it to binary.

- Linking: Links all the libraries and your code together to make one large binary file that executes your code file.

## `help50` is a tool that CS50 provides you with to help debug any errors you may encouter.

Examples of using `help50`:
- `buggy0.c`
- `buggy1.c`
- `buggy2.c`

## IDE - Another Programming Environment
- I = Intergrated
- D = Development
- E = Environment

CS50 IDE has a tab on the right of the screen that is called "Debugger" that you can use to help debug your code errors.
- Look in `buggy2.c` for notes on how to use the debugger.

## An Array

Data types and the amount of space they use:
- bool   = 1 byte
- char   = 1 byte
- int    = 4 bytes
- float  = 4 bytes
- long   = 8 bytes
- double = 8 bytes
- string = ? bytes

In C you are required to use " " for strings but only ' ' for char (characters).

If you have a variable that is not going to change throughout your code, you can create a constent variable at the top of your code as `const int N = n;`. Good rule of thumb is to capitalize any constent variables your assign.

In C you have to actually tell the array it's length with a variable because the array does not store it's own length.

In a string, if you broke it down like an array it would look like this:

| H | I | ! | \0 |
|---|---|---| ---|
| 0 | 1 | 2 |  3 |

The 4th (3) value in the array, which is \0 lets the machine know that this is the end of the string. It is called a "null terminating character" and means all 8 bits (or 1 byte) are 0 value.

[ASCII decimal chart](https://asciichart.com/)

Command-line argument is just an argument that you type in the command line after a command, such as `clang -o hello hello.c`. The `-o` is the command-line argument telling the machine to output "hello" as the machine file vs "a.out" which is the default.

## Calculating Readability

L = avg number of letters per 100 words in text
S = avg number of sentences per 100 words in text

### Coleman-Liau Index
index = 0.0588 * L - 0.296 * S - 15.8

Steps needed:
1. Get the number of letters.
    - By way of letter ASCII codes
    - 65-90 (A-Z) and 97-122 (a-z)
2. Get the number of words.
    - By way of the "space" ASCII code
    - 32 (space)
3. Get the number of sentences.
    - By way of the ., !, and ?  ASCII codes
    - 46 (.), 33 (!), and 63 (?)
4. Calculate the index with the formula above.