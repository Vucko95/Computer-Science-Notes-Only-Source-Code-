from Graph import Graph
from Graph import Tree

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

graph = Graph(vertices, edges)

dfs = graph.dfs(graph.getIndex("Chicago"))

searchOrders = dfs.getSearchOrders()
print(str(dfs.getNumberOfVerticesFound()) +
    " vertices are searched in this DFS order:")
for i in range(len(searchOrders)):
    print(graph.getVertex(searchOrders[i]), end = " ")
print();

for i in range(len(searchOrders)):
    if dfs.getParent(i) != -1:
        print("parent of " + graph.getVertex(i) +
            " is " + graph.getVertex(dfs.getParent(i)))