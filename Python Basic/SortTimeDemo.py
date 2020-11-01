import random
import time

n = eval(input("Enter the number of elements to sort: "))
lst = list(range(n))
random.shuffle(lst)

startTime = time.time()
lst.sort()
print("Sort time in Python is", int(time.time() - startTime), "seconds")