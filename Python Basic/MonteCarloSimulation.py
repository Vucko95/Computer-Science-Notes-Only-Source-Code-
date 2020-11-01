import random

NUMBER_OF_TRIALS = 100000 # Constant
numberOfHits = 0

for i in range(NUMBER_OF_TRIALS):
    x = random.random() * 2 - 1
    y = random.random() * 2 - 1

    if x * x + y * y <= 1:
        numberOfHits += 1

pi = 4 * numberOfHits / NUMBER_OF_TRIALS

print("PI is", pi)
