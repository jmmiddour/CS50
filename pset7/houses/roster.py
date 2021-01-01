# Imports
import cs50
import sys
from sys import argv, exit

# Check for valid arguments in command line
if len(sys.argv) != 2:
    print('Usage: python roster.py <House Name>')
    print('Please try again!')
    exit(1)

else:
    # Instantiate the database
    db = cs50.SQL('sqlite:///students.db')
    
    result = db.execute(f'''
        SELECT first, middle, last, birth
        FROM students
        WHERE house = "{sys.argv[1]}"
        ORDER BY last, first
        ''')
    
    # Test my code
    # print(result)
    
    for row in result:
        if row['middle'] == None:
            name = row['first'] + ' ' + row['last']
            born = row['birth']
            print(f'{name}, born {born}')

        else:
            name = row['first'] + ' ' + row['middle'] + ' ' + row['last']
            born = row['birth']
            print(f'{name}, born {born}')