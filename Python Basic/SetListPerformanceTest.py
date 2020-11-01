import random
import time

NUMBER_OF_ELEMENTS = 10000

# Create a list
lst = list(range(NUMBER_OF_ELEMENTS))
random.shuffle(lst)

# Create a set from the list
s = set(lst)

# Test if an element is in the set
startTime = time.time() # Get start time
for i in range(NUMBER_OF_ELEMENTS):
    i in s
endTime = time.time() # Get end time
runTime = int((endTime - startTime) * 1000) # Get test time
print("To test if", NUMBER_OF_ELEMENTS, 
    "elements are in the set\n",
    "The runtime is", runTime, "milliseconds")

# Test if an element is in the list
startTime = time.time() # Get start time
for i in range(NUMBER_OF_ELEMENTS):
    i in lst
endTime = time.time() # Get end time
runTime = int((endTime - startTime) * 1000) # Get test time
print("\nTo test if", NUMBER_OF_ELEMENTS, 
    "elements are in the list\n",
    "The runtime is", runTime, "milliseconds")

# Remove elements from a set one at a time
startTime = time.time() # Get start time
for i in range(NUMBER_OF_ELEMENTS):
    s.remove(i)
endTime = time.time() # Get end time
runTime = int((endTime - startTime) * 1000) # Get test time
print("\nTo remove", NUMBER_OF_ELEMENTS, 
    "elements from the set\n",
    "The runtime is", runTime, "milliseconds")

# Remove elements from a list one at a time
startTime = time.time() # Get start time
for i in range(NUMBER_OF_ELEMENTS):
    lst.remove(i)
endTime = time.time() # Get end time
runTime = int((endTime - startTime) * 1000) # Get test time
print("\nTo remove", NUMBER_OF_ELEMENTS, 
    "elements from the list\n",
    "The runtime is", runTime, "milliseconds")
