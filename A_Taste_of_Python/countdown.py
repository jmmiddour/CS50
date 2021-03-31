# # Count down from 10 to wish Happy New Year
# for i in range(10):
#     print(10 - i)

# print('Happy New Year!')


# # Define a main function
# def main():
#     countdown()
#     print('Happy New Year!')

# # Define a function
# def countdown():
#     for i in range(10):
#         print(10 - i)

# # Call the main function   
# main()


# # Define a main function
# def main():
#     countdown(5)
#     print('Happy New Year!')

# # Define a function
# def countdown(n):
#     for i in range(n):
#         print(n - i)

# # Call the main function   
# main()


# # Import time library to use `sleep`
# import time

# # Define a main function
# def main():
#     countdown(5)
#     print('Happy New Year!')

# # Define a function
# def countdown(n):
#     for i in range(n):
#         print(n - i)
#         time.sleep(1)  # Pauses the loop for 1 second

# # Call the main function   
# main()


# Import time library to use `sleep`
import time

# Import random to use randint
import random

# Define a main function
def main():
    number = random.randint(5, 15)
    countdown(number)
    print('Happy New Year!')

# Define a function
def countdown(n):
    for i in range(n):
        print(n - i)
        time.sleep(1)  # Pauses the loop for 1 second

# Call the main function   
main()