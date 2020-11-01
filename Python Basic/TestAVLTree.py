from AVLTree import AVLTree

def main():
    tree = AVLTree()
    tree.insert(25)
    tree.insert(20)
    tree.insert(5)
    print("After inserting 25, 20, 5:")
    printTree(tree)
    
    tree.insert(34)
    tree.insert(50)
    print("After inserting 34, 50:")
    printTree(tree)
    
    tree.insert(30)
    print("After inserting 30")
    printTree(tree)
    
    tree.insert(10)
    print("After inserting 10")
    printTree(tree)

    tree.delete(34)
    tree.delete(30)
    tree.delete(50)
    print("After removing 34, 30, 50:")
    printTree(tree)

    tree.delete(5)
    print("After removing 5:")
    printTree(tree)

def printTree(tree):
    # Traverse tree
    print("Inorder (sorted): ", end = "")
    tree.inorder()
    print("\nPostorder: ", end = "")
    tree.postorder()
    print("\nPreorder: ", end = "")
    tree.preorder()
    print("\nThe number of nodes is " + str(tree.getSize()))
    print()

main()
