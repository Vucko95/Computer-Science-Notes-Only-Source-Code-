print("          Multiplication Table")
# Display the number title
print("  |", end = '')
for j in range(1, 10):
    print("  ", j, end = '')
print() # Jump to the new line
print("-----------------------------------------")

# Display table body
for i in range(1, 10):
    print(i, "|", end = '')
    for j in range(1, 10): 
        # Display the product and align properly
        print(format(i * j, '4d'), end = '')
    print()# Jump to the new line
