def fib():
    fn1 = 0 # Current two consecutive fibonacci numbers
    fn2 = 1
    while True:
        current = fn1
        fn1, fn2 = fn2, fn1 + fn2
        yield current

def main():
    iterator = fib()
    # Display all Fibonacci numbers <= 10000
    for i in iterator:
        print(i, end = ' ')
        if i > 1000: break

main()