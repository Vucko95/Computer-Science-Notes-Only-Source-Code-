def main():
    n = eval(input("Find all prime numbers <= n, enter n: "))
    
    primes = []  # Prime number sieve
    
    # Initialize primes[i] to true
    for i in range(n + 1):
        primes.append(True) 
    
    k = 2
    while k <= n / k:
        if primes[k]: 
            for i in range(k, int(n / k) + 1):
                primes[k * i] = False  # k * i is not prime
        k += 1
   
    count = 0  # Count the number of prime numbers found so far
    # Print prime numbers
    for i in range(2, len(primes)):
        if primes[i]:
            count += 1
            if count % 10 == 0:
                print(i)
            else:
                print(str(i) + "  ", end = "")          
    
    print("\n" + str(count) + 
      " prime(s) less than or equal to " + str(n))

main()