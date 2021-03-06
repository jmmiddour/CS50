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
# print('seqs:\n', seqs)

# Iterate through txt file to get max seq count using list comprehension
max_seq = [max_sub_str(seq, i) for i in seqs]

# # Test my code
# print('max_seq:\n', max_seq)

# Transpose my dataframe, drop name column, convert to a dictionary
dnaT = dna.T.to_dict('list')

# # Test my code
# print('dnaT:\n', dnaT)

# Seperate the dictionary by key and value
key, val = zip(*dnaT.items())

# # Test my code
# print('Keys:\n', key, '\nValues:\n', val)

# Iterate thru values to get names
name = []  # Empty list to store names only
for i in range(len(val)):  # get index number
    name.append(val[i][0])  # use index num to get the names and add to list

# # Test my code 
# print('Names: ', name)

# Iterate thru values to get sequences for each person
vals = []  # Empty list to store the sequences
for i in range(len(val)):  # get index number
    vals.append(val[i][1:])  # uses index num to get the seq and add to list

# # Tets my code
# print('Values: ', vals)

# Iterate thru names and vals to compare vals and seqs
for i in range(len(name)):  # get index number
    if vals[i] == max_seq:  # check if there is a match
        print(name[i])  # if a match, print the name
        exit(0)  # stop the program, completed

else:  # If there is no match
    print('No match')  # print no match

s.close()  # close the txt file