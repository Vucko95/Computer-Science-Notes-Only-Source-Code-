from tkinter import * # Import tkinter
    
class PopupMenuDemo:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Popup Menu Demo") # Set title

        # Create a popup menu
        self.menu = Menu(window, tearoff = 0)
        self.menu.add_command(label = "Draw a line", 
            command = self.displayLine)
        self.menu.add_command(label = "Draw an oval", 
            command = self.displayOval)
        self.menu.add_command(label = "Draw a rectangle", 
            command = self.displayRect)
        self.menu.add_command(label = "Clear", 
            command = self.clearCanvas)
        
        # Place canvas in window
        self.canvas = Canvas(window, width = 200, 
            height = 100, bg = "white")
        self.canvas.pack()
        
        # Bind popup to canvas
        self.canvas.bind("<Button-3>", self.popup)
        
        window.mainloop() # Create an event loop
        
    # Display a rectangle
    def displayRect(self):
        self.canvas.create_rectangle(10, 10, 190, 90, tags = "rect")
        
    # Display an oval
    def displayOval(self):
        self.canvas.create_oval(10, 10, 190, 90, tags = "oval")
    
    # Display a line
    def displayLine(self):
        self.canvas.create_line(10, 10, 190, 90, tags = "line")
        self.canvas.create_line(10, 90, 190, 10, tags = "line")
    
    # Clear drawings
    def clearCanvas(self):
        self.canvas.delete("rect", "oval", "line")

    def popup(self, event):
        self.menu.post(event.x_root, event.y_root)
    
PopupMenuDemo() # Create GUI