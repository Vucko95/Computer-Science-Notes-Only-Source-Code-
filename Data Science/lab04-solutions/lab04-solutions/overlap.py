import sys

# Define a new function to read a set of numbers from the specified file
def read_numbers( in_path ):
	numbers = set()
	fin = open(in_path,"r")
	for l in fin.readlines():
		l = l.strip()
		num = int(l)
		numbers.add( num )
	fin.close()
	return numbers

# Check we have enough arguments
if len(sys.argv) != 3:
	print("Must specify two command line arguments")
	# exit the script
	sys.exit()

# Read the first file
numbers1 = read_numbers( sys.argv[1] )

# Read the second file
numbers2 = read_numbers( sys.argv[2] )

# Get the overlap (i.e. the intersection between the two sets)
overlap = numbers1.intersection(numbers2)
print( "Overlap is %s" % overlap )