# Imports
import re
import sys
from sys import argv, exit
import csv
import pandas as pd

# Get command line arguements
if len(sys.argv) != 3:
    print('Usage: python dna.py <database.csv> <sequence.txt>')
    print('Please try again!')
    exit(1)

else:
    # Read in csv file into a dataframe
    dna = pd.read_csv(sys.argv[1])

    # Open and read in the TXT file
    s = open(sys.argv[2])  # Open txt
    seq = s.read().rstrip('\n')  # read txt

# # Test that files read in correctly
# print(dna)
# print(seq)


# Define a function to iterate thru string to get max sequence for substring
def max_sub_str(seq, sub):

    res = [0] * len(seq)  # list to store results (count of seqs) == seq length

    # Iterate over the string from right to left
    for i in range(len(seq) - len(sub), - 1, - 1):

        # Check if location in string equals substring
        if seq[i: i + len(sub)] == sub:

            # Check if I am at the end of the string - len of substring
            if i + len(sub) > len(seq) - 1:
                res[i] = 1  # result will be a value of 1

            # If I am not at the end of the string - len of substring
            else:
                res[i] = 1 + res[i + len(sub)]  # Increase the result val by 1

    return int(max(res))  # Return the max result of longest seq for substring


# Pull out the sequence values from the dna dataframe 
seqs = dna.columns.tolist()[1:]

# # Test my code
# print(seqs)

# Iterate through txt file to get max seq count using list comprehension
max_seq = [max_sub_str(seq, i) for i in seqs]

# # Test my code
print(max_seq)

name = []
# seq_max = []

# Iterate thru dna dataframe rows to get values needed
# for i in range(len(dna)):
    
# Pull out the name for each row
for i, row in dna.iterrows():
    name.append([row[0]])
    
# # Checking my work
print(name)

# Transpose my dataframe, drop name column, convert to a dictionary
dnaT = dna.drop('name', axis=1).T.to_dict('list')

# # Test my code
# print(dnaT)

# Get values for each row
seq_max = list(dnaT.values())

# # Test my code
print(seq_max)

for row in seq_max:
    print(row)
    if max_seq == row:  # If the seq values from csv matches txt file
        for i in range(len(name)):
            print(name[i])  # Return the name
            exit(0)  # Exit the program sucessfully

else:
    print('No match')  # If no match is found

# Close the txt file
s.close()
