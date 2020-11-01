from Graph import Graph

# Create vertices for graph in Figure 16.1
vertices = ["Seattle", "San Francisco", "Los Angeles",
    "Denver", "Kansas City", "Chicago", "Boston", "New York",
    "Atlanta", "Miami", "Dallas", "Houston"]

# Create an edge list for graph in Figure 16.1
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

graph1 = Graph(vertices, edges)
print("The vertices in graph1: " + str(graph1.getVertices()))
print("The number of vertices in graph1: " + str(graph1.getSize()))
print("The vertex with index 1 is " + graph1.getVertex(1))
print("The index for Miami is " + str(graph1.getIndex("Miami")))
print("The degree for Miami is " + str(graph1.getDegree("Miami")))
print("The edges for graph1:")
graph1.printEdges()
    
graph1.addVertex("Savannah")
graph1.addEdge("Atlanta", "Savannah")
graph1.addEdge("Savannah", "Atlanta")
print("\nThe edges for graph1 after adding a new vertex and edges:")
graph1.printEdges()

# List of Edge objects for graph in Figure 16.3(a)
names = ["Peter", "Jane", "Mark", "Cindy", "Wendy"]
edges = [[0, 2], [1, 2], [2, 4], [3, 4]]

# Create a graph with 5 vertices
graph2 = Graph(names, edges)
print("\nThe number of vertices in graph2: " 
      + str(graph2.getSize()))
print("The edges for graph2:")
graph2.printEdges()
