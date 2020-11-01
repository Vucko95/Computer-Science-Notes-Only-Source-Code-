# ? Question 2 & 3 of lab 4
# ? Write a Python script select.py which reads in a text file, line by line,
# ? and only displays the specified lines. The input filename and one or more
# ? line numbers should be specified as command line arguments.
# ? Example usage:
# ? > python select.py names.txt 1 3 12
# ? Lucas
# ? Abigail
# ? Michael
# ? > python select.py names.txt 6 14
# ? Lily
# ? Zoe

import sys

lines = []

# arguments - how many arguments you get
# range is a for loop

for i in range(len(sys.argv)):
    if i >= 1:
        lines.append(sys.argv[i])
# arguments = sys.argv[i]
nameOfFile = sys.argv[1]
print("name of the file is ", nameOfFile, " and lines to choose are ", lines)
counter = 0

# Read in the name of the file
# Check if file exists
try:
    fileChosen = open("./name.txt", "r").readlines()
    fileChosen = open(nameOfFile, "r").readlines()
except:
    print("Does not exist")

for num in fileChosen:
    counter = counter + 1
    try:
        if counter == lines.index(str(counter)):
            print(num),
    except:
        pass
