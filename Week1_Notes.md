# CS50 - Week 1 - Learning **C**

- Files that contain your code in **C** need to have the extension `.c` to let the computer know this is a code file.
- Need to add a `;` at the end of the code to let the computer know that is the end of a statement/function.

## `#include <stdio.h>`
- Need this at the start of every **C** command document.
- The `#include` directive tells the **C** preprocessor to include the contents of the file specified in the input stream to the compiler and then continue with the rest of the original file.
- `stdio.h` = Standard input/output function which contains `printf()`, `scanf()`, functions.

## `#include <cs50.h>`
- This is where the functionallity is for `string` and `get_string` is stored.
- When using this library, have to specify it in the terminal when compiling the file.
  - In the terminal need to run the code as `clang -o `executable file` `*.c file` -lcs50`
  - The `-lcs50` tells the computer to link it to the library "cs50"

## `int main(void)`
- A function that needs to be included in **C** only once for whole file at the top under the libraries.
- `int main` means that our function needs to return some integer at the end of the execution and we do so by returning 0 at the end of the program.
  - 0 is the standard for "successful execution of the program".
- `int main()` can be called with any number of arguments.
  - If a function signature doesn't specify any argument, it means that the function can be called with any number of parameters or without any parameters at all.
- `int main(void)` can only be called without any argument. 
  - Considered technically better. 
  - It clearly specifies that main can only be called without any parameter.
  - `void` means it can run without any parameters/arguments.

## `printf()`
- One of the main **C** output functions.
- Stands for "print formatted" and contains a string input.
- Can pass in just a "string" to print out as the function.
- Can also pass other operators, such as:
  - `\n` = create a new line. Should add this at the end of every string to move the command prompt to the next line in the terminal for better readability within the terminal.
  - `, variable` will assign variable to the `%*` placeholder. 
    - Variables need to be assigned in the same order as where the placeholder is in the string.

## Some Common Functions:
- `string variable = ` This tells the computer that this variable is a string.
  - When you create a variable you has to specify to **C** what the data type will be.
- `get_string("Your question here?\n")` function to ask the user a question.
- `int variable = ` This tells the computer that this variable is an integer or number.
- `variable = variable + 1;` Will increament the variable, already created prior to this syntex, by 1.
- `variable += 1;` Same as code `variable = variable + 1`
- `variable++;` also does the same thing as `variable = variable + 1` but this is the most common way to write the code.

```
if (x < y)
{
    printf("x is less than y\n");
}
else
{
    printf("x is not less than y\n");
}
```

- The above is an "if" and "else" conditional statement in **C**

```
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

- The above code is an "if else if" conditional statement in **C**

```
while (true)  <-- While the statement below is (true), repeat, or stop if false.
{
    printf("Hello, World\n");
}
```

- The above code will keep repeating as long as something is true and stops when false.

```
int i = 0;  <-- Assigns the interger of 0 to "i" variable.
while (i < 50)
{
    printf("Hello World\n");
    i++;  <-- Increaments i by 1 each time it goes through this loop.
}
```

- The above code will loop over itself 50 times.

```
for(int i = 0; i < 50; i++)
{
    printf("Hello, World\n");
}
```

- The above code does the same thing as the while loop above it but with less lines of code.
 - The `for (int * = 0; * < **; *++)` loop take 3 agruments: 
  - The "start" variable, which needs to be assigned if no already done so. 
  - The conditional statement.
  - The increamenting statement.

## Terminal Commands:
- `clang` The name of a program used to compile your code and turn it into binary for the computer to be able to understand.
- `clang ` followed by your `*.c` file creates an executable file for the code with a default name.
- `clang -o ` followed by what you want to the executable file to be named and then your `*.c` file.
- `clang -o `executable file` `*.c file` -lcs50` links the library `cs50` or replace with an other library you need to link to the code aside from the one already recongnize `stdio.h`.
- `make ` followed by the name of your `*.c` file without the `.c` will also create the executable file with the libraries you have included in your source code.
- `./` followed by your executable file will return the function in your `*.c` file.
- If you rewrite any of your code the file will automatically save but will need to re-run the complier `clang` to update the executable file that was created for the code file.
- `ls` shows you a list of the files in the current directory (folder). 
  - An * at the end of the file name and is green, indicates the file is an executable file.
  - An / at the end of the file name and it is blue, indicates the file is a directory/folder.
- `rm ` followed by a file name will remove that file from the current directory.
  - When you run `rm` it will prompt you to confirm with a "y" or "yes" or "n" or "no".
  - `rm -f <filename>` `-f` stands for "force" and will not prompt you to confirm deletion.
  - `rm -r <directory>` will delete the entire directory.
  - You can combine the two flags as `rm -rf <directory>`.
- `mv <source> <destination>` Short for "move", will allow you to effectively rename a file, moving it from the <source> to the <destination>.
- `mkdir` creates a new directory.
- `rmdir` removes a directory.
- `cd ` followed by the directory/folder you want to change to, will put your terminal in that directory so you can now access those files via your terminal.
  - When you use `cd ` you have to specify it as follows: `cd ~/first_dir/sec_dir/third_dir` etc.
- `cd ..` will move you back up one directory.
- `cd` by itself will return you to the default/root directory.
- `pwd` (Print Working Directory) will show what the path is to the current directory you are working in.
- Typing ctrl + c will stop the program from running.
- Typing ctrl + l will clear your terminal window.
- `cp <source> <destination>` will allow you to create a duplicate of the file you specify as <source>, which it will then save in <destination>.
- `cp -r <source dir> <destination dir>` the `-r` means recursive, tells cp to dive down into the dir and copy everything inside of it (including any subdirectories it might contain).
- A fun command `figlet ` followed by anything, will print it in bubble like letters called ASCII art. This is included on some systems but not all.
- Another fun command `say ` followed by what you want to computer to say, will actually say audiably what you typed. This is included on some systems but not all.
- `chmod`
- `ln`
- `touch`
- `man`
- `diff`
- `sudo`
- `clear`
- `telnet`

## Data Types in **C**
- bool = boolean (True or False)
- char = Character (only 1 character, such as "Y" or "N" for yes or no)
- double = A float that can have an infinite number of digits after the decimal point.
- float = Floating point number (a number with a decimal point)
- int = Interger (a whole number up to 4 billion)
- long = BigInteger (a whole number larger than 4 billion)
- string = One or more characters inside " "
- If you need to assign more than one variable of the same type you can include them all on the same line.
  - Examples: `int height, width, number;` or `float sqrt2, sqrt3, pi;` 
  - In general, it is good practice to ONLY DECLARE variables when you need it.
- Only need to declare the type of a variable once then you just need to enter the variable by itself, no data type. 

## Functions in the `cs50` library
- get_char
- get_double
- get_float
- get_int
- get_long
- get_string

## Placeholders - Need to have one placeholder for each variable.
- `%s` = placeholder for a string variable. 
- `%c` = placeholder for a character variable.
- `%f` = placeholder for a float or double variable.
- `%i` = placeholder for an interger variable.
- `%li` = placeholder for a long variable.

## Common operators:
- `//` Anything after is a comment and does not add any functionallity to the code.
- `*` multiplication
- `/` division
- `%` divide and gives the remainder (modulus operator)
- `-` subtraction
- `+` addition
- `==` equal to / equality
- `=` assigns to a value.
- `||` or
- `&&` and
- `;` ends a function
- `<` less than
- `>` greater than
- `<=` less than or equal to
- `>=` greater than or equal to
- `++` added to the end of a variable will increase the variable by 1
- `--` added to the end of a variable will decrease the variable by 1
- `+=` after a variable will increase variable by whatever interger you specify after it
- `*=` times equals (`x *= 5`) creates the same operation as `x = x * 5`
- `!` means NOT, example `!=` is NOT equal to.

## Create a function in **C**
```
void name_of_your_function(void)
{
   'Your function hear'
}
```
  
- If you want to run this function in the same `.c` file, the only part that needs to be above where you are running it is the `void name_of_your_function(void)` line. All of the other lines can be placed below the code(s) you are running.
- In the above function the first `void` is the type of output, `name_of_your_function` is self explainatory - what you want to call your function, `(void)` is the type of input - in this scenario it is void meaning it does not take any input.

## Interger Overflow:
- If you have a number that goes beyond the amount of bits (places/characters) available to the computer, it will throw an error message and just start return 0 because it can only provide number lengths that it has the available bits for.
- Examples:
  - If you only have 8 bits available and you are increasing by one every loop, once you get to 99999999 the computer will throw and error and default back to 00000000 because it does not have room to add another bit of information to be able to carry over to. In this example you would expect 100000000 but the computer does have limitations.
  - The same for if you only have 4 bits available... increasing the number by 10, when you get to 9990, you would expect to see 10000 next, but the computer hit its limit and will throw and error message and then only return 0 from that point on.

## Contionals:
- `if` statement = If ... is true, do this ...
- `if else` statement = If ... is true, do this ... if False (`else`), do this ...
- `else if` statement = Would be in a chain of multiple conditions. You would first have the `if` statement, if that is false it would move down the chain to the next statement which would be `else if`, meaning if this evaluates to true the chain breaks and this condition is applied, else it will keep moving down the chain. You can have multiple `else if` statements in the "meat" of the sandwich, but the "top piece of bread", the first condition will be `if` and the "bottom piece of bread", the last condition will be `else`.
- You can have multiple `if` statements before the `else` statement and could meet all of them but the `else` statement only applies to the closest `if` if it is false.
- `switch()` statement = a condition that permits enumeration of discrete cases, instead of relying on Boolean expressions.
  - It is important to (`break;`) between each case, or you will "fall through" each case (unless that is the desired behavior). This means that if you do not include the `break;` the computer will continue through all the cases from the case the user initialized all the way to the bottom of the code and preform each function for all those cases. The `break;` tells the computer to only do the function for the case that the user initialized.
- Another way to preform and `if else` statement is with `?` and `:` called "ternary operator"
  - `?` is equivalent to using `if`
  - `:` is equivalent to using `else`
  - Example `int x = (some_expression) ? 5 : 6;` states: 
    - If `some_expression` == 5 then x = 5, 
    - Else `some_expression` != 5, then x = 6.

## Loops:
- `while` infinite loop that will iterate over and over until the condition becomes false or you stop it from running by typing ctrl + c at the same time.
  - *Use Case:* When you want a loop to repeat an unknown number of times, and possibly not at all.
- `do while` This loop will execute all lines of code between the curly braces once, and then, if the boolean-expression evaluates to true, will go back and repeat that process until boolean-expression evaluates to false.
  - *Use Case:* When you want a loop to repeat an unknown number of times, but at least once.
- `for` This loop takes 3 arguements: 
  - The counter variable (ie `int i = 0;`) - this is the first number in the loop.
  - The Boolean expression (ie `i < 10;`)
    - if evaluates to true, the body of the loop executes.
    - if evaluates to false, the body of the loop does not execute.
  - The counter variable is incremented (ie `i++`) and then the Boolean express is checked again.
  - *Use Case:* When you want a loop to repeat a discreate number of times, though tou may not know the number at the moment the program is compiled.