from Displayable import Displayable

class City(Displayable):
    def __init__(self, name, x, y):
        self.name = name
        self.x = x
        self.y = y
    
    # Override the getX method
    def getX(self):
        return self.x
    
    # Override the getY method
    def getY(self):
        return self.y
    
    # Override the getName method
    def getName(self):
        return self.name

vertices = [City("Seattle", 75, 50), City("San Francisco", 50, 210),
    City("Los Angeles", 75, 275), City("Denver", 275, 175),
    City("Kansas City", 400, 245),
    City("Chicago", 450, 100), City("Boston", 700, 80),
    City("New York", 675, 120), City("Atlanta", 575, 295),
    City("Miami", 600, 400), City("Dallas", 408, 325),
    City("Houston", 450, 360)]

# Edge array for graph in Figure 19.1
edges = [
    [0, 1], [0, 3], [0, 5],
    [1, 0], [1, 2], [1, 3],
    [2, 1], [2, 3], [2, 4], [2, 10],
    [3, 0], [3, 1], [3, 2], [3, 4], [3, 5],
    [4, 2], [4, 3], [4, 5], [4, 7], [4, 8], [4, 10],
    [5, 0], [5, 3], [5, 4], [5, 6], [5, 7],
    [6, 5], [6, 7],
    [7, 4], [7, 5], [7, 6], [7, 8],
    [8, 4], [8, 7], [8, 9], [8, 10], [8, 11],
    [9, 8], [9, 11],
    [10, 2], [10, 4], [10, 8], [10, 11],
    [11, 8], [11, 9], [11, 10]
  ]

from tkinter import * # Import tkinter
from GraphView import GraphView
from Graph import Graph
    
window = Tk() # Create a window
window.title("US Map") # Set title

graph = Graph(vertices, edges)
view = GraphView(graph, window, 750, 410)
view.pack()

window.mainloop() # Create an event loop