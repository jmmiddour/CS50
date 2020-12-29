# Imports
from cs50 import get_float
from sys import exit

# Prompt user for input
chg = get_float('How much change is owed? ')

# If user enters invalid imput, re-prompt
while chg < 0:
    chg = get_float('How much change is owed? ')

# If user input is valid
else:
    q, d, n, p = 0, 0, 0, 0  # Assign counters for each coin
    cents = chg * 100  # Turn into integers to avoid errors
    
    q += cents // 25  # increase q the number of times 25 goes into cents
    cents %= 25  # get the remainder of cents left
    
    d += cents // 10  # increase d the number of times 10 goes into cents
    cents %= 10  # get the remainder of cents left
    
    n += cents // 5  # increase n the number of times 5 goes into cents
    cents %= 5  # get the remainder of cents left
    
    p += cents  # increase p by the number cents remaining
    
    print('Change owed: %.2f' % chg)  # Print change owed in the proper format
    
    coins = (q + d + n + p)  # add up all the counters for the coins
    
    print('%d' % coins)  # Return the least amount of coins to make change
