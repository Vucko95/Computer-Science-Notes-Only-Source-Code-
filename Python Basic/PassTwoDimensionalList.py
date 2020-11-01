def getMatrix(): 
    matrix = [] # Create an empty list

    numberOfRows = eval(input("Enter the number of rows: "))
    numberOfColumns = eval(input("Enter the number of columns: "))
    for row in range(numberOfRows): 
        matrix.append([]) # Add an empty new row 
        for column in range(numberOfColumns): 
            value = eval(input("Enter a value and press Enter: "))
            matrix[row].append(value) 

    return matrix

def accumulate(m):
    total = 0
    for row in m:
        total += sum(row)

    return total

def main():
    m = getMatrix() # Get an list
    print(m)

    # Display sum of elements
    print("\nSum of all elements is", accumulate(m))

main() # Invoke main function
