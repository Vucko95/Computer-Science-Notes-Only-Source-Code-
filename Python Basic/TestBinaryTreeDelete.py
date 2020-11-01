from BinaryTree import BinaryTree

def main():
    tree = BinaryTree()
    tree.insert("George")
    tree.insert("Michael")
    tree.insert("Tom")
    tree.insert("Adam")
    tree.insert("Jones")
    tree.insert("Peter")
    tree.insert("Daniel")
    printTree(tree)

    print("\nAfter delete George:")
    tree.delete("George")
    printTree(tree)

    print("\nAfter delete Adam:")
    tree.delete("Adam")
    printTree(tree)

    print("\nAfter delete Michael:")
    tree.delete("Michael")
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

main()
