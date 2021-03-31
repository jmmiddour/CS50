# My code...
def main():
    user_num = int(input('How big do you want your column? '))
    mario_blocks(user_num)

def mario_blocks(n):
    for i in range(n):
        print(n * '#')
        
main()


# # Brian's code...
# n = int(input('n: '))

# for i in range(n):
#     for j in range(n):
#         print('#', end='')
    
#     print()
