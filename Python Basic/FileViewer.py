from tkinter import * # Import tkinter
import tkinter.messagebox # Import tkinter.messagebox

# Check if the numbers entered form a valid solution
def validate():
    # Get the numbers from the entries
    values = [[eval(x.get()) 
               for x in cells[i]] for i in range(9)]
    
    if isValid(values):
        tkinter.messagebox.showinfo("Check Sudoku Solution", 
                                    "The solution is valid")
    else:
        tkinter.messagebox.showwarning("Check Sudoku Solution", 
                                    "The solution is invalid")
    
window = Tk() # Create a window
window.title("Pick Four Cards Randomly") # Set title

frame1 = Frame(window) # Hold four labels for displaying cards
frame1.pack()

scrollbar = Scrollbar(frame1)
scrollbar.pack(side = RIGHT, fill = Y)
text = Text(frame1, wrap = WORD, yscrollcommand = scrollbar.set)
text.pack()
scrollbar.config(command = text.yview)

frame2 = Frame(window) # Hold four labels for displaying cards
frame2.pack()

Label(frame2, text = "Enter a filename: ").pack(side = LEFT)
filename = StringVar()
Entry(frame2, width = 40, textvariable = filename).pack(side = LEFT)
Button(frame2, text = "Validate", command = validate).pack()

window.mainloop() # Create an event loop
