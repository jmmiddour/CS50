# Imports
from sys import exit
from cs50 import get_int

# Get user input
num = get_int('How tall do you want your pyramid between 1 and 8? ')

# If user input is 1 - 8
if 0 < num < 9:

    # For every number in the range of user input
    for i in range(num):  
        print(' ' * ((num - i) - 1), end='')  # Print beginning spaces
        print('#' * (i + 1))  # Print the # symbol

# If user input is not 1 - 8
else:
    while True:  # While that is true
        # Keep prompting user for input until valid
        num = get_int('How tall do you want your pyramid between 1 and 8? ')

        # Once user enters an integer 1 - 8
        if 0 < num < 9:

            # For every number in the range of user input
            for i in range(num):
                print(' ' * ((num - i) - 1), end='')  # Print beginning spaces
                print('#' * (i + 1))  # Print the # symbol
            exit(0)  # Stop the program
