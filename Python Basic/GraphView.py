from tkinter import * # Import tkinter
from Graph import Graph

class GraphView(Canvas):
    def __init__(self, graph, container, width = 800, height = 450):
        super().__init__(container, width = width, height = height)
        self.graph = graph
        self.drawGraph()
        
    def drawGraph(self):
        vertices = self.graph.getVertices()    
        for i in range(self.graph.getSize()):
            x = vertices[i].getX()
            y = vertices[i].getY()
            name = vertices[i].getName()
          
            # Display a vertex
            self.create_oval(x - 2, y - 2, x + 2, y + 2, 
                 fill = "black") 
            # Display the name
            self.create_text(x, y - 8, text = str(name))

        # Draw edges for pair of vertices
        for i in range(self.graph.getSize()):
            neighbors = self.graph.getNeighbors(i)
            x1 = self.graph.getVertex(i).getX()
            y1 = self.graph.getVertex(i).getY()
            for v in neighbors:
                x2 = self.graph.getVertex(v).getX()
                y2 = self.graph.getVertex(v).getY()   
                # Draw an edge for (i, v)        
                self.create_line(x1, y1, x2, y2) 
