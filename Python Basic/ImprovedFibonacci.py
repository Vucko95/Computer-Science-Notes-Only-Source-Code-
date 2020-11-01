def main():
    index = eval(input("Enter an index for the Fibonacci number: "))
    
    # Find and display the Fibonacci number
    print("Fibonacci number at index", index, 
        "is", fib(index))
  
# The function for finding the Fibonacci number 
def fib(n):   
    f0 = 0  # For fib(0)
    f1 = 1  # For fib(1)
    f2 = 1  # For fib(2)
    
    if n == 0: 
        return f0
    elif n == 1: 
        return f1
    elif n == 2: 
        return f2

    for i in range(3, n + 1):
        f0 = f1
        f1 = f2
        f2 = f0 + f1
    
    return f2

main() # Call the main function
