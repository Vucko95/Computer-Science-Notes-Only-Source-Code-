import NearestPoints
from tkinter import * # Import tkinter
       
RADIUS = 2 # Radius of the point
    
class NearestPointsGUI:
    def __init__(self):
        self.points = [] # Store self.points
        window = Tk() # Create a window
        window.title("Find Nearest Points") # Set title
        
        self.canvas = Canvas(window, width = 400, height = 200)
        self.canvas.pack()
        
        self.canvas.bind("<Button-1>", self.addPoint)
        
        window.mainloop() # Create an event loop

    def addPoint(self, event):
        if not self.isTooCloseToOtherPoints(event.x, event.y):
            self.addThisPoint(event.x, event.y)
            
    def addThisPoint(self, x, y):
        # Display this point
        self.canvas.create_oval(x - RADIUS, y - RADIUS,
            x + RADIUS, y + RADIUS)
        # Add this point to self.points list
        self.points.append([x, y]) 
        if len(self.points) > 2:
            p1, p2 = NearestPoints.nearestPoints(self.points)
            self.canvas.delete("line") 
            self.canvas.create_line(self.points[p1][0], 
                self.points[p1][1], self.points[p2][0], 
                self.points[p2][1], tags = "line")
        
    def isTooCloseToOtherPoints(self, x, y):
        for i in range(len(self.points)):
            if NearestPoints.distance(x, y, 
                self.points[i][0], self.points[i][1]) <= RADIUS + 2:
                return True
        
        return False

NearestPointsGUI() # Create GUI
