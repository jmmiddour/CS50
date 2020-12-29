# Imports
import re
from cs50 import get_string


# Create a function to count the letters in the text
def cnt_ltrs(text):
    # Create a counter for number of characters
    num_char = 0

    # Iterate through characters to get count of letters only
    for c in range(len(text)):
        if re.match(r'[A-Za-z]', text[c]):
            num_char += 1

    return num_char

# # Test my function for functionality
# test_char_cnt = cnt_ltrs('I love cats@!')
# print(test_char_cnt)


# Create a function to count the words in the text
def cnt_words(text):
    words = text.split(' ')
    return len(words)

# # Test my function for functionality    
# test_wrd_cnt = cnt_words('I love cats@!')
# print(test_wrd_cnt)


# Create a function to get sentance count
def sent_cnt(text):
    sents = list(map(str.strip, re.split(r'[.!?](?!$)', text)))
    return len(sents)

# # Test my function for functionality    
# test_sent_cnt = sent_cnt('I love cats@! Dogs are great too.')
# print(test_sent_cnt)


# Prompt user to enter some text
text = get_string('Text: ')

ltrs = cnt_ltrs(text)  # get letter count
wrds = cnt_words(text)  # get word count
sents = sent_cnt(text)  # get sentance count

# Get L and S for Coleman-Liau Index formula
L = ltrs / wrds * 100
S = (sents + 1) / wrds * 100

# Apply the Coleman-Liau Index formula
index = (0.0588 * L) - (0.296 * S) - 15.8

# Get the grade level rounded
grade = round(index)

if grade < 1:
    print('Before Grade 1')

elif grade >= 16:
    print('Grade 16+')

else:
    print(f'Grade {grade}')
