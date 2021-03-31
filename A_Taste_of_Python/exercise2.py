# My Code...
# import random

# def guessing_game():
#     n = random.randint(1, 10)
    
#     for i in range(3):
#         user = int(input('Pick a number between 1 and 10: '))
        
#         if user == n:
#             print('Congratulations! You are right!')
#             break
        
#         elif user != n and 0 < i < 4:
#             print('Sorry, wrong number. Please try again!')
#             print(f'You have {2 - i} more guesses.')
        
#         else:
#             print('Game Over. Thank you for playing')
            
# guessing_game()


# Brian's Code...
import random

number = random.randint(1, 10)

for i in range(3):
    guess = int(input('Guess: '))
    
    if guess > number:
        print('Guess is too large')
    
    elif guess < number:
        print('Guess is too small')
        
    else:
        print('Correct!')
        break
