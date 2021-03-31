## CS50 - Week 4 - Memory

### Hexadecimal System
[Hexadecimal by CS50](https://youtu.be/u_atXp-NF6w)

This is the sytem that computer memory locations are writen in.

This system is *base-16* which is a much more concise way to express the data on a computer's system vs the decimal system we use as humans (the decimal system we use is *base-10* meaning once you get to 9 you essensially start over).
* 0 1 2 3 4 5 6 7 8 9 a b c d e f (not case sensitive)

It makes this --^ mapping easy because a group of four binary digits (bits) is able to have 16 different combinations, vs 10 (human) or 2 (computer), and each of those combinations map to a single hexadecimal digit.

| Decimal | Binary | Hexadecimal|
| --- | --- | --- |
| 0 | 0000 | 0x0 |
| 1 | 0001 | 0x1 |
| 2 | 0010 | 0x2 |
| 3 | 0011 | 0x3 |
| 4 | 0100 | 0x4 |
| 5 | 0101 | 0x5 |
| 6 | 0110 | 0x6 |
| 7 | 0111 | 0x7 |
| 8 | 1000 | 0x8 |
| 9 | 1001 | 0x9 |
| 10 | 1010 | 0xa |
| 11 | 1011 | 0xb |
| 12 | 1100 | 0xc |
| 13 | 1101 | 0xd |
| 14 | 1110 | 0xe |
| 15 | 1111 | 0xf |

Always prefix hexademical values with `0x`. This actually means nothing to the computer but makes it easier for us as humans to understand that it is a hexidecimal number.

If you have a string of numbers or letters after the `0x` that is a hexadeciaml number but it is not read like we would normally read it. 
* Example:
  * If you have `0x397`...
    - In *base-10* we would read this as three hundred ninety-seven
    - In *base-16* (hexadecimal) this is actually a lot larger number:
      - You read this from right to left...
      - The right most digit (7), this is the ones place, would be 16^0 which is 7
      - The second to the right digit (9), this is the sixteenth place, would be 16^1 which is
      - The one to the right of the x (3), this is the 256th place, would be 16^2 which is 
      - and so on...

The way the hexidecimal system places digits similar to how we do but instead of multiplying each place to the left by 10, it multiplies by 16.
* Example:
  * If you have 5 digits to the right of `0x` the place values would be:
  
    | 16^4 | 16^3 | 16^2 | 16^1 | 16^0 | 
    | --- | --- | --- | --- | --- |
    | 65,536 | 4,096 | 256 | 16 | 1 |

  * So the above example of `0x397` would actually be `(3*256)+(9*16)+(7*1)` which makes this number now `768 + 144 + 7 = 919`

#### Converting Binary to Hexadecimal

- Binary: 01000110101000101011100100111101
- Break it down to groups of 4: 0100 0110 1010 0010 1011 1001 0011 1101
  - Each group of four corresonds to a Hexadecimal digit
- Still reading right to left, start with the right most group and break it down:
  
  |  1  |  1  |  0  |  1  |                   |
  | --- | --- | --- | --- |       ---            |
  | B8  | B4  | B2  | B1  |  <== Binary placeholders |
  |  8  |  4  |  0  |  1  |  <== Add all binary values together = 13 = 0xd |
  
- Break down the whole binary string:
  
  | 0100 | 0110 | 1010 | 0010 | 1011 | 1001 | 0011 | 1101 |
  | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
  | B=4  | B=6  | B=10 | B=2  | B=11 | B=9  | B=3  | B=13 |
  | H= 4 | H= 6 | H= a | H= 2 | H= b | H= 9 | H= 3 | H= d |
  
- So the binary string converts to `0x46a2b93d` in hexadecimal.
- To get the real number you would break it down as so:
  
  |  4  |  6  |  a  |  2  |  b  |  9  |  3  |  d  |                   |
  | --- | --- | --- | --- | --- | --- | --- | --- |          ---         |
  |16^7 |16^6 |16^5 |16^4 |16^3 |16^2 |16^1 |16^0 |  <== Hexadecimal place values |
  |268,435,456|16,777,216|1,048,576|65,536|4,096|256|16|1| <== place values converted |
  |1,073,741,824|100,663,296|10,485,760|131,072|45,056|2,304|48|13|                 |
  
- So to do the math you would add all the place values together to get to real number:
  - 1,073,741,824 + 100,663,296 + 10,485,760 + 131,072 + 45,056 + 2,304 + 48 + 13 = 1,185,069,373

## Pointers
[Pointers by CS50](https://youtu.be/XISnO2YhnsY)

A pointer is the address of a value in the computer's memory.

* When you create a variable the computer is just making a copy of the data that is held in that variable and does not actually change the data on the hard drive itself.

* Using pointers actually give you the ability to change the value and not just a copy of a value to whatever you specify.

* Every file on your computer lives on your disk drive (hard disk drive (HDD) and/or solid-state drive (SSD))

* Disk drives are just storage space; we can't directly work there. Manipulation and use of data can only take place in RAM (Random Access Memory), so data has to move there.

* Memory (RAM) is basically a huge array of 8-bit wide bytes.

* Once we turn off our computer, all the data stored in RAM is destroyed, so that is why we need to have a HDD and/or SDD to hold (store) the data for use at a later time.

* When setting a pointer if you do not immediately know it's value you need to set it to NULL, which will point to nothing but needs to be assigned to the pointer variable.

* You can check if a pointer is NULL using the equality operator `==`.

* Another way to create a pointer is to simply extract the address of an already existing variable using the address extraction operator `&`.

* The main purpose of a pointer is to allow us to modify or inspect the location to which it points. We do this by *dereferencing* the pointer.

* The `*` is known as the *dereference operator* in this context. It will actually take you to the location of that data and allow you to manipulate it at will vs making a copy with a variable and then having to merge the 2 data structures back together.

## Define Custom Types
[Defining Custom Types by CS50](https://youtu.be/crxfzK3Oc9M)

* You can define your own data type by using `typedef`

* The basic idea is to first define a type in the normal way, then alias it to something else.

* Example:
  - `typedef <old name> <new name>;`
  - `typedef unsigned char byte;`
  - In this example `unsigned char` data type can now be typed as just `byte`
  - In CS50 string is actually done the same way to make it easier
    - `typedef char* string;`
    - `char*` refers to an array of characters and ends with the `\0` ending place holder.

* Two examples using struct to build a structure then defining it as a type:
  ```
  struct car
  {
      int year;
      char model[10];
      char plate[7];
      int odometer;
      double engine_size;
  }
  
  typedef struct car car_t;
  ```

  ```
  typedef struct car
  {
      int year;
      char model[10];
      char plate[7];
      int odometer;
      double engine_size;
  }
  car_t;
  ```
## Dynamic Memory Allocation
[Dynamic Memory Allocation by CS50](https://youtu.be/9uhSYDY4sxA)

Memory that is allocated as your program is running.

- We can use pointers to get access to a block of **dynamically-allocated memory** at runtime.

- Dynamically allocated memory comes from a pool of memory known as the **heap**.
  - Generally when you do not give a variable a name, which happens in dynamically-allocated memory, it lives on the heap.
  - The heap starts at the top of the memory and works it's way down.

- Prior to this point, all memory we've been working with has been coming from a pool of memory known as the **stack**. 
  - Generally when you give a variable a name it lives on the stack.
  - The stack starts at the bottom of the memory and works it's way up.

- To get this dynamically-allocated memory you need to make a call to the C standard library (stdio.h) function `malloc()`, memory allocator, and pass in the number of bytes you require.

- After obtaining memory for you (if it can), `malloc()` will return a pointer to that memory

- What if `malloc()` **can't** give you memory?
  - It will hand you back a NULL pointer.
  - When you have a NULL pointer and try to dereference it, you will get a segmention fault error and your program will crash.
  - Need to verify if you got back a NULL pointer before moving forward.

- The difference between statically/dynamically obtaining an integer:
  - // statically: `int x;`
  - // dynamically: `int *px = malloc(4);` - or - `int *px = malloc(sizeof(int));`

- Statically:
  - // get an interer from the user
    `int x = GetInt();`
  - // array of floats on the stack
    `float stack_array[x];`

- Dynamically:
  - // array of floats on the heap
    `float* heap_array = malloc(x * sizeof(float));`

- Here's the trouble: Dynamically-allocated memory is not automatically returned to the system for later use when the function in which it's created finished execution.

- Failing to return memory back to the system when you're finished with it results in a **memory leak** which can compromise your system's performance.

- When you finish working with dynamically-allocated memory, you must `free()` it.

- Three golden rules when using dynamically-allocated memory:
  1. Every block of memory that you `malloc()` must subsequently be `free()`d.
  2. Only memory that you `malloc()` should be `free()`d.
  3. Do not `free()` a block of memory more than once.

- Can use in the command line `valgrind ./<the compiled file name>` to view a summary of the memory usage and leakage as well as other useful information. 

- If you prefix the above with help50 (`help50 valgrind ./<the compiled file name>`) it will break down what all of that information means in easier to understand terms.

## Memory Allication on your Machine:
Your computer is not just randomly picking where to get the memory you use. It actually is mythodically getting memory from certain areas of the overall memory based on the type of files accessing the memory.

Example of how your computer uses your memory:

|    Machine Code    |  
|         ---        |
| ================== |
|  Global Variables  |  
| ================== |  
|         Heap       |  
|          v         |  
|          v         |  
|                    |  
|                    |  
|                    |   
|          ^         |  
|          ^         |  
|        Stack       | 

Inside the Stack (when you call a function using "local variables"):

| Inside the stack |
|       ---        |
| ================ |
|                  |
|                  |
|         ^        |
|   ...and so on   |
| ---------------- |
|    function 2    |
| ---------------- |
|    function 1    |
| ---------------- |
|       main       |

* Arrays are already pointers so there is no need to create a pointer for them.
* Variables always need an assigned pointer.

## Call Stacks:
[Call Stacks by CS50](https://youtu.be/aCPkszeKRa4)

A "frame" of memory the computer puts aside for you to use when writing functions. 

* Each function will have it's own "stack frame" but only one function will operate at a time. 

* The frame with the most recently called function is always on the top of the "stack".

* When a new function is called, a new frame is "pushed" onto the top of the stack and becomes the active frame.

* When a function finishes, it's frame is "popped" off the stack and the frame immediately below it becomes the new active function / frame on the top of the stack.

## File Pointers
[File Pointers by CS50](https://youtu.be/bOF-SpEAYgk)

The ability to read data from and write data to files in the primary means of storing **persistent data**, data that does not disappear when your program stops running.

* The file manipulation functions all live in `<stdio.h>`
  - All accept `FILE*` (the file pointer) as one of their parameters, except for `fopen()`, which is used to get a file pointer in the first place.
* Some of the most common file input/output (I/O) functions that we will be working with are:
  - `fopen()` = opens the file and returns a file pointer to it.
    - Always check the return value to make sure you don't get back NULL.
    - Example: `FILE* ptr = fopen(<filename>, <operation>);`
      - filename == the full name of the file, including the .extension
      - operation == what do you want it to do:
        - "r" = read, 
        - "w" = write (if file already exists, it will overwrite the whole file), 
        - "a" = append (if file already exists, it will add on to the end of the file)

  - `fclose()` = closes the file 
    - Example: `fclose(<file pointer>);` in this example the file pointer = `ptr`

  - `fgetc()` = get character from file 
    - Reads and returns the next character from the file pointed to.
    - NOTE: the operator of the file pointer passed in as a parameter must be "r" for read, or you will suffer an error.
    - Example: `char ch = fgetc(<file pointer>);`
    - Can use this to read all the characters in that file with a while loop:
      ```
      char ch;
      while((ch = fgetc(ptr)) != EOF)  // EOF = special value in stdio.h - End Of File
         printf("%c", ch);
      ```

  - `fputc()` = writes or appends the specified character
    - NOTE: the operator of the file pointer passed in as a parameter must be "w" for write or "a" for append, or you will suffer an error.
    - Example: `fgetc(<character>, <file pointer>);`
    - Can use this to read all the characters in that file with a while loop and write them to another file:
      ```
      char ch;
      while((ch = fgetc(ptr)) != EOF)  // EOF = special value in stdio.h - End Of File
         fputc(ch, ptr2);
      ```

  - `fread()` = Reads the file and stores data in an array to be used based on specifications
    - NOTE: the operator of the file pointer passed in as a parameter must be "r" for read, or you will suffer an error.
    - Example: `fread(<buffer>, <size>, <qty>, <file pointer>);`
      - `<buffer>` = pointer to the location of where to store the data, usually an array.
      - `<size>` = how large each unit of data will be.
      - `<qty>` = how many units of data do we want.
      - `<file pointer>` = the pointer to the file we are getting the data from.
      - i.e.:
        ```
        int arr[10];  <== creating a pointer for the first element of an array.
        fread(arr, sizeof(int), 10, ptr);
        ```
      - Can also dynamically create a buffer:
        ```
        double* arr2 = malloc(sizeof(double) *80);
        fread(arr2, sizeof(double), 80, ptr);
        ```

  - `fwrite()` = Writes to the file from an array that stores data based on specifications
    - NOTE: the operator of the file pointer passed in as a parameter must be "w" for write or "a" for append, or you will suffer an error.
    - Example: `fwrite(<buffer>, <size>, <qty>, <file pointer>);`
      - `<buffer>` = pointer to the location of where get the stored data from, usually an array.
      - `<size>` = how large each unit of data will be.
      - `<qty>` = how many units of data do we want.
      - `<file pointer>` = the pointer to the file we writing the data to.
      - i.e.:
        ```
        int arr[10];  <== creating a pointer for the first element of an array.
        <...>  <== Need to add the data here, into the arr, that will be written to the file
        fread(arr, sizeof(int), 10, ptr);
        ```
      - Can also dynamically create a buffer:
        ```
        double* arr2 = malloc(sizeof(double) *80);
        <...>  <== Need to add the data here, into the arr2, that will be written to the file
        fread(arr2, sizeof(double), 80, ptr);
        ```

* A few o-ther useful functions in <stdio.h> that you may want to use:

|  Function  | Description |
|  --------  | ----------- |
|   fgets()  | Reads a full string from a file. |
|   fputs()  | Writes a full string to a file. |
|  fprintf() | Writes a formatted string to a file. |
|   fseek()  | Allows you to rewind / fast-forward within a file. |
|   ftell()  | Tells you at what (byte) position you are at within a file. |
|    feof()  | Tells you whether you've read to the end of a file. |
|  ferror()  | Indicates whether an error has occurred in working with a file. |