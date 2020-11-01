from math import sqrt

def main():
    n = eval(input("Find all prime numbers <= n, enter n: "))
    NUMBER_PER_LINE = 10  # Display 10 per line
    count = 0  # Count the number of prime numbers
    number = 2  # A number to be tested for primeness

    print("The prime numbers are:")

    # Repeatedly find prime numbers
    while number <= n:
        # Assume the number is prime
        isPrime = True  # Is the current number prime?

        # Test if number is prime
        for divisor in range(2, int(sqrt(number)) + 1): 
            # If true, number is not prime
            if number % divisor == 0:
                isPrime = False  # Set isPrime to false          
                break  # Exit the for loop

        # Print the prime number and increase the count
        if isPrime:
            count += 1  # Increase the count

            if count % NUMBER_PER_LINE == 0:
                # Print the number and advance to the new line
                print(" " + str(number))
            else:
                print(" " + str(number), end = "")

        # Check if the next number is prime
        number += 1
    
    print("\n" + str(count) + " prime(s) less than or equal to " 
        + str(n))

main()
