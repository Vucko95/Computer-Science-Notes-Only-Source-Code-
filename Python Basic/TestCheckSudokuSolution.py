from CheckSudokuSolution import isValid

def main():
    # Read a Sudoku solution
    grid = readASolution()

    if isValid(grid):
        print("Valid solution")
    else:
        print("Invalid solution")
  
# Read a Sudoku solution from the console 
def readASolution():
    print("Enter a Sudoku puzzle solution:")
    grid = []
    for i in range(9):
        line = input().strip().split()
        grid.append([eval(x) for x in line])
    
    return grid

main() # Call the main function
