# Question 1 of lab 4
# Read in both number files
# Find numbers which overlap and print them out in increasing order
# Store numbers which do overlap in an array

# To read in command line arguments

import sys
# Step1: Read in both files
# Create function which takes in a number and compares it against the second file


def findOverlap(numbers1, numbers2):
    result = []
    found = False
    for num in numbers2:
        found = False
    try:
        overlapping_number = numbers1.index(num)
        found = True
    except:
        pass
    if found:
        result.append(num)
        return result


# To variables to hold the text file being passed
# to the program
numbers1 = open(sys.argv[1], "r").readlines()
numbers2 = open(sys.argv[2], "r").readlines()

output = findOverlap(numbers1, numbers2)
end = []

for i in range(len(output)):
    end.append(int(output[i]))
    end.sort()
    print("Overlap is {"),
    for num in end:
        print(num, ","),
        print("}"),
