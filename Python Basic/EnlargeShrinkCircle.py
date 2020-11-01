from tkinter import * # Import tkinter

class EnlargeShrinkCircle:
    def __init__(self):
        self.radius = 50
                
        window = Tk() # Create a window
        window.title("Control Circle Demo") # Set a title
        self.canvas = Canvas(window, bg = "white", 
            width = 200, height = 200)
        self.canvas.pack()
        self.canvas.create_oval(
            100 - self.radius, 100 - self.radius, 
            100 + self.radius, 100 + self.radius, tags = "oval")
        
        # Bind canvas with mouse events
        self.canvas.bind("<Button-1>", self.increaseCircle)
        self.canvas.bind("<Button-3>", self.decreaseCircle)
        
        window.mainloop() # Create an event loop
        
    def increaseCircle(self, event):
        self.canvas.delete("oval")
        if self.radius < 100:
            self.radius += 2
        self.canvas.create_oval(
            100 - self.radius, 100 - self.radius, 
            100 + self.radius, 100 + self.radius, tags = "oval")
        
    def decreaseCircle(self, event):
        self.canvas.delete("oval")
        if self.radius > 2:
            self.radius -= 2
        self.canvas.create_oval(
            100 - self.radius, 100 - self.radius, 
            100 + self.radius, 100 + self.radius, tags = "oval")

EnlargeShrinkCircle() # Create GUI