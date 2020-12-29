# Printing command-line arguments, indexing into argv

from sys import argv  # have to import to get argv

for i in range(len(argv)):  # to get argc (count of arguments)
    print(argv[i])
