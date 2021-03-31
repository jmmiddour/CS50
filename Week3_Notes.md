# CS50 - Week 3 - Algorithms

## Linear Search: 
[Linear Search by CS50](https://youtu.be/TwsgCHYmbbA)

Searching from left to right until you reach the solution.

Sample Algorithm:  
```
for i from 0 to n-1
    if the i'th element is 50
        return true
else
    return false
```

## Binary Search: 
[Binary Search by CS50](https://youtu.be/T98PIp4omUA)

Keep dividing the problem in two until you reach a solution.

Sample Algorithm:
```
if no items
    return false
if middle item is 50
    return true
else if 50 < middle item
    search left half
else if 50 > middle item
    search right half
```

## Big *O* Notation
"On the Order of"

The "upper bound" of how long it takes to solve a problem

Order of the *O* when logging running time (computational time):  
(The lower in the list below the faster the time)
```
*O*(n^2) == Bubble Sort, Selection Sort, Insertion Sort
*O*(n log n) == Merge Sort
*O*(n) == Linear Search
*O*(log n) == Binary Search
*O*(1) == 
```

## Omega %omega%
The "lower bound" or best case of how long it takes to solve a problem
(The lower in the list below the faster the time)
```
%omega%(n^2) == Selection Sort
%omega%(n log n) == Merge Sort
%omega%(n) == Bubble Sort (n^2 if repeat n-1, n if repeat until no swap), Insertion Sort
%omega%(log n) == 
%omega%(1) == Linear Search, Binary Search
```

## Phata %phata%
If an algorithm has an upper bound and a lower bound that are identical you can describe it using phata
```
%phata%(n^2) == Selection Sort
%phata%(n log n) == Merge Sort
%phata%(n) == 
%phata%(log n) == 
%phata%(1) == 
```

## Bubble Sort  
[Bubble Sort by CS50](https://youtu.be/RT-hUXUWQ2I)

Continue to swap places with the value to right or left based on whether the value is less or more than the other.

Pseudocode:
```
Repeat until no swap
    for i from 0 to n-2
        If the i'th and i+1'th elements out of order
            Swap them
```

## Selection Sort  
[Selection Sort by CS50](https://youtu.be/3hH8kTHFw2A)

Going through the whole list of values, choose the smallest value, move it to the front, take the value that was in that place and move it to where the smallest value was. Keep doing this over the entire list until all values are sorted properly.

Pseudocode:
```
For i from 0 to n-1
    Find the smallest item between i'th and last item
    Swap smallest item with i'th item
```

## Recursion  
[Recursion by CS50](https://youtu.be/mz6tAJMVmfM)

When a function calls itself

Pseudocode:
```
Pick up the phonebook
Open book to middle
Look at page
If Smith is on the page
    Call Mike
Else if Smith is ealier in the book
    Search left half of the book
Else if Smith is later in the book
    Search right half of the book
Else
    Quit
```

## Merge Sort
[Merge Sort by CS50](https://youtu.be/Ns7tGNbtvV4)

Uses Logarithm math to sort list with three steps:
1. Sort left half
2. Sort right half
3. Merge the sorted halves together

Pseudocode:
```
If only one item
    Return
Else
    Sort left half of items
    Sort right half of items
    Merge sorted halves
```

## Logarithm (log)
Keeps dividing something in half until it can not divid anymore.

## Insertion Sort  
[Insertion Sort by CS50](https://youtu.be/O0VbBkUvriI)

Builds the sorted array in place, shifting elements out of the way if necessary to make room as you go/

Pseudocode:
```
Call the 1st element of the array "sorted"
Repeat until all elements are sorted
    Look at the next unsorted element
    Insert into the "sorted" portion by shifting the requisite number of elements.
```

## Algorithms Summary  
[Algorithms Summary by CS50](https://youtu.be/ktWL3nN38ZA)
