SIZE = 8 # The size of the chessboard
queens = [-1, -1, -1, -1, -1, -1, -1, -1] # Queen positions 

# Check if a queen can be placed at row i and column j 
def isValid(row, column):
    for i in range(1, row + 1):
        if (queens[row - i] == column # Check column
            or queens[row - i] == column - i # Check upleft diagonal
            or queens[row - i] == column + i): # Upright diagonal
            return False # There is a conflict
    return True # No conflict

def findPosition(k):
    start = queens[k] + 1 # Search for a new placement

    for j in range(start, 8):
        if isValid(k, j):
            return j # (k, j) is the place to put the queen now

    return -1

# Search for a solution starting from a specified row 
def search():
    # k - 1 indicates the number of queens placed so far
    # We are looking for a position in the kth row to place a queen
    k = 0
    while k >= 0 and k <= 7:
        # Find a position to place a queen in the kth row
        j = findPosition(k)
        if j < 0:
            queens[k] = -1
            k -= 1 # back track to the previous row
        else:
            queens[k] = j
            k += 1
    
    if k == -1:
      return False # No solution
    else:
      return True # A solution is found

search() # Search for a solution 

# Display solution in queens
from tkinter import * # Import tkinter
window = Tk() # Create a window
window.title("Eight Queens") # Set a title

image = PhotoImage(file = "image/queen.gif")
for i in range(8):
    for j in range(8):
        if queens[i] == j:
            Label(window, image = image).grid(row = i, column = j)
        else:
            Label(window, width = 5, height = 2, bg = "red") \
                .grid(row = i, column = j)
        
window.mainloop() # Create an event loop    
