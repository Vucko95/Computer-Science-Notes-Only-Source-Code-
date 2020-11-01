import RandomCharacter

NUMBER_OF_CHARS = 175 # Number of characters to generate
CHARS_PER_LINE = 25 # Number of characters to display per line

# Print random characters between 'a' and 'z', 25 chars per line
for i in range(NUMBER_OF_CHARS):
    print(RandomCharacter.getRandomLowerCaseLetter(), end = "")
    if (i + 1) % CHARS_PER_LINE == 0:
        print()  # Jump to the new line
