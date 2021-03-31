# # First Pass Solution
# def main():
#     multiply(2, 3)
#     multiply(2, 3)

# def multiply(x, y):
#     product = x * y
#     print(x, '*', y, '=', product)

# main()

# # Cleaner function to get all 2's times table up to 2 * 10
# def main():
#     for i in range(10):
#         multiply(2, i)

# def multiply(x, y):
#     product = x * y
#     print(x, '*', y, '=', product)
    
# main()


# Function to do all multiplication 10 times tables
def main():
    for i in range(10):
        for j in range(10):
            multiply(i, j)

def multiply(x, y):
    product = x * y
    print(x, '*', y, '=', product)
    
main()
