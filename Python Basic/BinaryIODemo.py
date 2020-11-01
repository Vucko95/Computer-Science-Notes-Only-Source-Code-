import pickle

def main():
    # Open file for writing binary
    outfile = open("pickle.dat", "wb")
    pickle.dump(45, outfile)
    pickle.dump(56.6, outfile)
    pickle.dump("Programming is fun", outfile)
    pickle.dump([1, 2, 3, 4], outfile)
    outfile.close() # Close the output file

    # Open file for reading binary
    infile = open("pickle.dat", "rb")
    print(pickle.load(infile))
    print(pickle.load(infile))
    print(pickle.load(infile))
    print(pickle.load(infile))
    infile.close() # Close the input file

main() # Call the main function
