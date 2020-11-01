def main():
    # Open file for input
    infile = open("Presidents.txt", "r")
    print("(1) Using read(): ")
    print(infile.read())
    infile.close() # Close the input file

    # Open file for input
    infile = open("Presidents.txt", "r")
    print("\n(2) Using read(number): ")
    s1 = infile.read(4)
    print(s1)
    s2 = infile.read(10)
    print(repr(s2))
    infile.close() # Close the input file

    # Open file for input
    infile = open("Presidents.txt", "r")
    print("\n(3) Using readline(): ")
    line1 = infile.readline()
    line2 = infile.readline()
    line3 = infile.readline()
    line4 = infile.readline()
    print(repr(line1))
    print(repr(line2))
    print(repr(line3))
    print(repr(line4))
    infile.close() # Close the input file

    # Open file for input
    infile = open("Presidents.txt", "r")
    print("\n(4) Using readlines(): ")
    print(infile.readlines())
    infile.close() # Close the input file

main() # Call the main function
