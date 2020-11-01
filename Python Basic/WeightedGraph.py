from Graph import Graph
from Graph import Tree
from WeightedEdge import WeightedEdge
from Heap import Heap # Heap is covered in Chapter 11

MAX_VALUE = 1e+308 # Infinity

class WeightedGraph(Graph):
    def __init__(self, vertices, edges):
        Graph.__init__(self, vertices, getEdges(edges))
        self.queues = self.getQueueForWeightedEdge(edges)     
             
    def getQueueForWeightedEdge(self, edges):
        queues = []
        for i in range(len(self.getVertices())):
            # Each element in the queue is a heap
            queues.append(Heap()) 
            
        for i in range(len(edges)):
            u = edges[i][0]
            v = edges[i][1]
            weight = edges[i][2]
            # Insert an edge into the heap
            queues[u].add(WeightedEdge(u, v, weight)) 

        return queues
    
    #Display edges with weights 
    def printWeightedEdges(self):
        for i in range(len(self.queues)):
            print(str(self.getVertex(i)) 
                  + " (" + str(i), end = "): ")
            for edge in self.queues[i].getLst():
                print("(" + str(edge.u) + ", " + str(edge.v) 
                      + ", "  + str(edge.weight), end = ") ")
            print()

    # Get the edges from the weighted graph 
    def getWeightedEdges(self):
        return self.queues
  
    # Clears the weighted graph 
    def clear(self):
        Graph.vertices.clear()
        Graph.neighbors.clear()
        self.queues.clear()
  
    # Add vertices to the weighted graph 
    def addVertex(vertex):
        Graph.addVertex(vertex)
        queues.add(Heap())

    # Add edges to the weighted graph 
    def addEdge(u, v, weight):
        Graph.addEdge(u, v);
        queues[u].add(WeightedEdge(u, v, weight))

    # Get a minimum spanning tree rooted at vertex 0 */
    def getMinimumSpanningTree(self):
        return self.getMinimumSpanningTreeAt(0)
    
    # Get a minimum spanning tree rooted at a specified vertex 
    def getMinimumSpanningTreeAt(self, startingIndex):
        # T initially contains the startingVertex;
        T = [startingIndex]
    
        numberOfVertices = len(self.vertices) # Number of vertices
        # Initially set the parent of all vertices to -1
        parent = numberOfVertices * [-1] # Parent of a vertex
    
        totalWeight = 0 # Total weight of the tree thus far
    
        # Clone the queues, so to keep the original queue intact
        queues = deepClone(self.queues);
    
        # All vertices are found?
        while len(T) < numberOfVertices:
            # Search for the vertex with the smallest edge 
            # adjacent to a vertex in T
            v = -1
            smallestWeight = MAX_VALUE;
            for u in T:
                while not queues[u].isEmpty() and \
                    queues[u].peek().v in T:
                    # Remove the edge from queues[u] if the adjacent
                    # vertex of u is already in T
                    queues[u].remove()
        
                if queues[u].isEmpty():
                    continue # Consider the next vertex in T
        
                # Current smallest weight on an edge adjacent to u
                edge = queues[u].peek()
                if edge.weight < smallestWeight:
                    v = edge.v
                    smallestWeight = edge.weight
                    # u is the parent for v 
                    parent[v] = u
    
            if v != -1: 
                T.append(v) # Add a new vertex to the tree
            else: 
                # The tree is not connected, a partial MST is found
                break 
          
            totalWeight += smallestWeight
    
            return MST(startingIndex, parent, T, 
                   totalWeight, self.vertices)

    # Find single source shortest paths 
    def getShortestPath(self, sourceIndex):
        # T stores the vertices whose path found so far
        T = [sourceIndex]
    
        numberOfVertices = len(self.vertices)
    
        # parent[v] stores the previous vertex of v in the path
        # The parent of source is set to -1
        parent = numberOfVertices * [-1]
    
        # costs[v] stores the cost of the path from v to the source
        # Initial cost set to infinity
        costs = numberOfVertices * [MAX_VALUE]
        costs[sourceIndex] = 0 # Cost of source is 0
    
        # Get a copy of queues
        queues = deepClone(self.queues)
    
        # Expand T
        while len(T) < numberOfVertices:
            v = -1 # Vertex to be determined
            smallestCost = MAX_VALUE # Set to infinity
            for u in T:
                while (not queues[u].isEmpty() and 
                           queues[u].peek().v in T):
                    # Remove the vertex in queue for u
                    queues[u].remove() 
            
                if queues[u].isEmpty():
                    # All vertices adjacent to u are in T
                    continue
        
                e = queues[u].peek()
                if costs[u] + e.weight < smallestCost:
                    v = e.v
                    smallestCost = costs[u] + e.weight
                    # now u is the parent for v
                    parent[v] = u
        
            T.append(v) # Add a new vertex to T
            costs[v] = smallestCost
    
        # Create a ShortestPathTree
        return ShortestPathTree(sourceIndex, parent, T, costs, 
                                self.vertices)

# Clone queues 
def deepClone(queues):
    copiedQueues = []

    for i in range(len(queues)):
        copiedQueues.append(Heap())
        for e in queues[i].getLst():
            copiedQueues[i].add(e)

    return copiedQueues

# MST is a subclass of Tree, defined in the preceding chapter
class MST(Tree):
    def __init__(self, startingIndex, parent, T, 
                 totalWeight, vertices):
        Tree.__init__(self, startingIndex, parent, T, vertices)
        # Total weight of all edges in the tree
        self.totalWeight = totalWeight 

    def getTotalWeight(self):
        return self.totalWeight

# ShortestPathTree is an inner class in WeightedGraph 
class ShortestPathTree(Tree):
    def __init__(self, sourceIndex, parent, T, costs, vertices):
        Tree.__init__(self, sourceIndex, parent, T, vertices)
        self.costs = costs

    # Return the cost for a path from the root to vertex v 
    def getCost(self, v):
        return self.costs[v]

    # Print paths from all vertices to the source 
    def printAllPaths(self):
        print("All shortest paths from " 
            + str(self.vertices[self.root]) + " are:")
        for i in range(len(self.costs)):
            self.printPath(i) # Print a path from i to the source
            print("(cost: " + str(self.costs[i]) + ")") # Path cost

def getEdges(edges):
    edgeList = []
            
    for i in range(len(edges)):
        u = edges[i][0]
        v = edges[i][1]
        # Insert an edge into the heap
        edgeList.append([u, v]) 
        
    return edgeList
