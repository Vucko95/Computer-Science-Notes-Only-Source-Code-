def main():
    while True:
        try:
            filename = input("Enter a filename: ").strip()
            infile = open(filename, "r") # Open the file
            break 
        except IOError:
            print("File " + filename + " does not exist. Try again")

    counts = 26 * [0] # Create and initialize counts
    for line in infile:
        # Invoke the countLetters function to count each letter
        countLetters(line.lower(), counts)
    
    # Display results
    for i in range(len(counts)):
        if counts[i] != 0:
            print(chr(ord('a') + i) + " appears " + str(counts[i])
              + (" time" if counts[i] == 1 else " times"))

    infile.close() # Close file
  
# Count each letter in the string 
def countLetters(line, counts): 
    for ch in line:
        if ch.isalpha():
            counts[ord(ch) - ord('a')] += 1

main()

