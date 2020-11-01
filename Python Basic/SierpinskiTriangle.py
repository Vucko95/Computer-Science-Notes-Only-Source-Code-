from tkinter import * # Import tkinter
    
class SierpinskiTriangle:
    def __init__(self):
        window = Tk() # Create a window
        window.title("Sierpinski Triangle") # Set a title
        
        self.width = 200
        self.height = 200
        self.canvas = Canvas(window, 
            width = self.width, height = self.height)
        self.canvas.pack()
        
        # Add a label, an entry, and a button to frame1
        frame1 = Frame(window) # Create and add a frame to window
        frame1.pack()
        
        Label(frame1, 
            text = "Enter an order: ").pack(side = LEFT)
        self.order = StringVar()
        entry = Entry(frame1, textvariable = self.order, 
                      justify = RIGHT).pack(side = LEFT)
        Button(frame1, text = "Display Sierpinski Triangle", 
            command = self.display).pack(side = LEFT)
        
        window.mainloop() # Create an event loop
        
    def display(self):
        self.canvas.delete("line")
        p1 = [self.width / 2, 10]
        p2 = [10, self.height - 10]
        p3 = [self.width - 10, self.height - 10]
        self.displayTriangles(int(self.order.get()), p1, p2, p3)
    
    def displayTriangles(self, order, p1, p2, p3):
        if order == 0: # Base condition
            # Draw a triangle to connect three points
            self.drawLine(p1, p2)
            self.drawLine(p2, p3)
            self.drawLine(p3, p1)
        else:    
            # Get the midpoint of each triangle's edge 
            p12 = self.midpoint(p1, p2)
            p23 = self.midpoint(p2, p3)
            p31 = self.midpoint(p3, p1)
    
            # Recursively display three triangles
            self.displayTriangles(order - 1, p1, p12, p31)
            self.displayTriangles(order - 1, p12, p2, p23)
            self.displayTriangles(order - 1, p31, p23, p3)
    
    def drawLine(self, p1, p2):
        self.canvas.create_line(
            p1[0], p1[1], p2[0], p2[1], tags = "line")
        
    # Return the midpoint between two points
    def midpoint(self, p1, p2):
        p = 2 * [0]
        p[0] = (p1[0] + p2[0]) / 2
        p[1] = (p1[1] + p2[1]) / 2
        return p

SierpinskiTriangle() # Create GUI

