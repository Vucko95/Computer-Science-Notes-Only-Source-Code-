import pickle

def main():
    # Open file for writing binary
    outfile = open("numbers.dat", "wb")
    
    data = eval(input("Enter an integer (the input exits " + 
        "if the input is 0): "))
    while data != 0:
        pickle.dump(data, outfile)
        data = eval(input("Enter an integer (the input exits " + 
            "if the input is 0): "))

    outfile.close() # Close the output file

    # Open file for reading binary
    infile = open("numbers.dat", "rb")
    
    end_of_file = False
    while not end_of_file:
        try:
            print(pickle.load(infile), end = " ")
        except EOFError:
            end_of_file = True

    infile.close() # Close the input file

    print("\nAll objects are read")
    
main() # Call the main function
