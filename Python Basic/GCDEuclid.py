# Find gcd for integers m and n 
def gcd(m, n):
    if m % n == 0:
        return n
    else:
        return gcd(n, m % n)
  
def main():
    # Prompt the user to enter two integers
    m = eval(input("Enter first integer: "))
    n = eval(input("Enter second integer: "))
    
    print("The greatest common divisor for", m,
        "and", n, "is", gcd(m, n))

main() # Call the main function
