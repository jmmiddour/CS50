# Imports
import cs50
import csv
import sys
from sys import argv, exit

# Create the database
open("students.db", "w").close()

# Instantiate the database
db = cs50.SQL('sqlite:///students.db')

# Create the table
db.execute('''
    CREATE TABLE students (
        id INTEGER PRIMARY KEY AUTOINCREMENT, 
        first VARCHAR(300), 
        middle VARCHAR(300), 
        last VARCHAR(300), 
        house VARCHAR(20), 
        birth INTEGER)
        ''')

# Check for valid arguments in command line
if len(sys.argv) != 2:
    print('Usage: python import.py <database.csv>')
    print('Please try again!')
    exit(1)

# Open a csv file
with open(sys.argv[1], 'r') as studs:
    
    # Read with DictReader
    reader = csv.DictReader(studs)
    
    # Iterate through the csv file
    for row in reader:
        
        # Seperate the name column
        if row['name'] != None:
            name_list = row['name'].split(' ')
            first = name_list[0]
            if len(name_list) == 2:
                last = name_list[1]
                middle = None
            
            else:
                middle = name_list[1]
                last = name_list[2]
            
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                   first, middle, last, row['house'], row['birth'])
