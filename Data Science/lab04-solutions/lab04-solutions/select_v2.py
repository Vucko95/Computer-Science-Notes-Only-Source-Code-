import sys

# Check we have enough arguments
if len(sys.argv) < 3:
	print("Must specify at least two command line arguments")
	# exit the script
	sys.exit()

# Find out what line numbers we want
line_numbers = []
try:
	for s in sys.argv[2:]:
		# convert string to integer
		num = int(s)
		line_numbers.append( num )
except ValueError as e:
	print("Invalid line number specified: %s" % e )
	sys.exit()

# Now read the file
try:
	fin = open(sys.argv[1],"r")
	current_line_number = 0
	for l in fin.readlines():
		# increment the line number 
		current_line_number += 1
		# do we want to print this one?
		if current_line_number in line_numbers:
			print( l.strip() )
except IOError as e:
	print("Unable to read from file: %s" % e )
	sys.exit()

fin.close()