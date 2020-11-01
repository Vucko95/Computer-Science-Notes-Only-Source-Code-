# Create a list of 99 Boolean elements with value False 
isCovered = 99 * [False] 
endOfInput = False
while not endOfInput:
    # Read numbers as a string from the console
    s = input("Enter a line of numbers separated by spaces: ")
    items = s.split() # Extract items from the string
    lst = [eval(x) for x in items] # Convert items to numbers

    for number in lst:
        if number == 0:
            endOfInput = True
        else:
            # Mark its corresponding element covered
            isCovered[number - 1] = True

# Check whether all numbers (1 to 99) are covered
allCovered = True; # Assume all covered initially
for i in range(99):
    if not isCovered[i]:
        allCovered = False  # Find one number not covered
        break;

# Display result
if allCovered:
    print("The tickets cover all numbers")
else:
    print("The tickets don't cover all numbers")