# def main():
#     score = int(input('Score: '))
    
#     for i in range(score):
#         print('#', end='')  # Prints all in range on same line
    
#     print('')    
        
# main()


# def main():
#     score1 = int(input('Score 1: '))
#     score2 = int(input('Score 2: '))
#     score3 = int(input('Score 3: '))
    
#     for i in range(score1):
#         print('#', end='')  # Prints all in range on same line
        
#     for i in range(score2):
#         print('#', end='')  # Prints all in range on same line
        
#     for i in range(score3):
#         print('#', end='')  # Prints all in range on same line
    
#     print('')    
        
# main()


def main():
    score1 = int(input('Score 1: '))
    score2 = int(input('Score 2: '))
    score3 = int(input('Score 3: '))
    
    print_score(score1)
    print_score(score2)
    print_score(score3)
    

def print_score(n):
    for i in range(n):
        print('#', end='')
        
    print('')
    
    
main()
