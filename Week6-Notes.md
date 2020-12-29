## CS50 - Week 6 - [Python](https://youtu.be/fL308_-Kbt0)

Data types in Python:
- `bool` = `True` or `False`
- `float` = a floating point number
- `int` = a whole number / integer
- `str` = a string of characters
- `range` = a sequence of numbers
- `list` = a sequence of "mutable values" (values that can be changed, the size can be changed too) 
- `tuple` = a sequence of "immutable values" (values that can not be changed)
- `dict` = collection of key/value pairs
- `set` = collection of unique values (throws away duplicate values)

[Python Docs](http://docs.python.org)

A Pythonic way of writing code to cough 3 times:
  `print('cough\n' * 3)`
  
`input()` returns a string

`int(input())` returns an integer

Integers can not be overflowed in python like they can in C.

If you want to get `argv` in Python you have to:
  `from sys import argv`

To get the number of arguments in `argv` in Python (called `argc` in C):
  `len(argv)`
  
To simulate `return 1;` (error) in Python, you have to:
  `from sys import exit` then `exit(1)`
  - same for `return 0;` (sucess) in Python `exit(0)`

