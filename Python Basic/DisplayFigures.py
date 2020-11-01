from tkinter import * # Import tkinter
from FigureCanvas import FigureCanvas

class DisplayFigures:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Display Figures") # Set title
        
        figure1 = FigureCanvas(window, "line", width = 100, height = 100) 
        figure1.grid(row = 1, column = 1)
        figure2 = FigureCanvas(window, "rectangle", False, 100, 100) 
        figure2.grid(row = 1, column = 2)
        figure3 = FigureCanvas(window, "oval", False, 100, 100) 
        figure3.grid(row = 1, column = 3)
        figure4 = FigureCanvas(window, "arc", False, 100, 100) 
        figure4.grid(row = 1, column = 4)
        figure5 = FigureCanvas(window, "rectangle", True, 100, 100) 
        figure5.grid(row = 1, column = 5)
        figure6 = FigureCanvas(window, "oval", True, 100, 100) 
        figure6.grid(row = 1, column = 6)
        figure7 = FigureCanvas(window, "arc", True, 100, 100) 
        figure7.grid(row = 1, column = 7)
        
        window.mainloop() # Create an event loop

DisplayFigures() # Create GUI