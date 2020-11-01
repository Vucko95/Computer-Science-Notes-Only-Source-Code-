from BinaryTree import BinaryTree

tree = BinaryTree()
tree.insert("George")
tree.insert("Michael")
tree.insert("Tom")
tree.insert("Adam")
tree.insert("Jones")
tree.insert("Peter")
tree.insert("Daniel")

# Traverse tree
print("Inorder (sorted): ", end = "")
tree.inorder()
print("\nPostorder: ", end = "")
tree.postorder()
print("\nPreorder: ", end = "")
tree.preorder()
print("\nThe number of nodes is " + str(tree.getSize()))

# Search for an element
print("Is Peter in the tree? " + str(tree.search("Peter")))

# Get a path from the root to Peter
print("A path from the root to Peter is: ");
path = tree.path("Peter")
for node in path:
    print(node.element, end = " ")

numbers = [2, 4, 3, 1, 8, 5, 6, 7]
intTree = BinaryTree()
for e in numbers:
    intTree.insert(e)
    
print("\nInorder (sorted): ", end = "")
intTree.inorder()