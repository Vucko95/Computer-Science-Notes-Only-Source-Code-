def main():
    # Prompt the user to enter a file
    filename = input("Enter a filename: ").strip()
    infile = open(filename, "r") # Open the file

    wordCounts = {} # Create an empty dictionary to count words
    for line in infile:
        processLine(line.lower(), wordCounts)
     
    pairs = list(wordCounts.items()) # Get pairs from the dictionary   

    items = [[count, word] for (word, count) in pairs] 
    items.sort(reverse = True) # Sort pairs in items
    
    for count, word in items[ : 10]: # Slice the first 10 items
        print(word, count, sep =  '\t')  
  
# Count each word in the line
def processLine(line, wordCounts): 
    line = replacePunctuation(line) # Replace punctuation with space
    words = line.split() # Get words from each line
    for word in words:
        if word in wordCounts:
            wordCounts[word] += 1
        else:
            wordCounts[word] = 1 # Add an item in the dictionary

# Replace punctuation in the line with space
def replacePunctuation(line):
    for ch in line:
        if ch in "~@#$%^&*()_-+=~<>?/,.;:!{}[]|'\"":
            line = line.replace(ch, " ")

    return line

main() # Call the main function
