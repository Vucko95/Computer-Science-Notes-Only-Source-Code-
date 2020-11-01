from tkinter import * # Import tkinter
import tkinter.messagebox # Import tkinter.messagebox
from CheckSudokuSolution import isValid # Defined in Listing 11.7

class SudokuGUI:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Check Sudoku Solution") # Set title
        
        frame = Frame(window) # Hold entries 
        frame.pack()
        
        self.cells = [] # A list of variables tied to entries
        for i in range(9):
            self.cells.append([])
            for j in range(9):
                self.cells[i].append(StringVar())
        
        for i in range(9):
            for j in range(9):
                Entry(frame, width = 2, justify = RIGHT, 
                    textvariable = self.cells[i][j]).grid(
                        row = i, column = j)
        
        Button(window, text = "Validate", 
            command = self.validate).pack()
        
        window.mainloop() # Create an event loop

    # Check if the numbers entered form a valid solution
    def validate(self):
        # Get the numbers from the entries
        values = [[eval(x.get()) 
                   for x in self.cells[i]] for i in range(9)]
        
        if isValid(values):
            tkinter.messagebox.showinfo("Check Sudoku Solution", 
                                        "The solution is valid")
        else:
            tkinter.messagebox.showwarning("Check Sudoku Solution", 
                                        "The solution is invalid")

SudokuGUI() # Create GUI