from WeightedGraph import WeightedGraph 
from WeightedGraph import WeightedEdge
from NineTailModel import NineTailModel
from NineTailModel import NUMBER_OF_NODES
from NineTailModel import getIndex
from NineTailModel import getNode
from NineTailModel import printNode
from NineTailModel import getFlippedNode

class WeightedNineTailModel(NineTailModel):
    # Construct a model 
    def __init__(self):
        NineTailModel.__init__(self) # Invoke superclass constructor
           
        # Create a graph
        vertices = [x for x in range(NUMBER_OF_NODES)]
        graph = WeightedGraph(vertices, getWeightedEdges()); 

        # Obtain a BSF tree rooted at the target node
        self.tree = graph.getShortestPath(511)

    def getNumberOfFlipsFrom(self, u):
        return self.tree.getCost(u)
    
# Create all edges for the graph 
def getWeightedEdges():
    # Store edges
    edges = []

    for u in range(NUMBER_OF_NODES):
      for k in range(9):
        node = getNode(u) # Get the node for vertex u
        if node[k] == 'H':
            v = getFlippedNode(node, k)
            numberOfFlips = getNumberOfFlips(u, v)
          
            # Add edge (v, u) for a legal move from node u to node v
            edges.append([v, u, numberOfFlips])

    return edges

def getNumberOfFlips(u, v):
    node1 = getNode(u)
    node2 = getNode(v)

    count = 0 # Count the number of different cells
    for i in range(len(node1)):
      if node1[i] != node2[i]:
        count += 1

    return count
