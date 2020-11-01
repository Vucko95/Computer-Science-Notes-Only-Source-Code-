def main():
    x = 1
    print("Before the call, x is", x)
    increment(x)
    print("After the call, x is", x)

def increment(n): 
    n += 1
    print("\tn inside the function is", n)

main() # Call the main function
