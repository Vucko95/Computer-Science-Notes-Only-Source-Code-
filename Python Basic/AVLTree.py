from BinaryTree import BinaryTree
from BinaryTree import TreeNode

class AVLTree(BinaryTree):
    def __init__(self):
        BinaryTree.__init__(self)

    # Override the createNewNode method to create an AVLTreeNode
    def createNewNode(self, e):
        return AVLTreeNode(e)

    # Override the insert method to balance the tree if necessary 
    def insert(self, o):
        successful = BinaryTree.insert(self, o)
        if not successful:
            return False # o is already in the tree
        else:
            self.balancePath(o) # Balance from o to the root if necessary

        return True # o is inserted

    # Update the height of a specified node 
    def updateHeight(self, node):
        if node.left == None and node.right == None: # node is a leaf
            node.height = 0
        elif node.left == None: # node has no left subtree
            node.height = 1 + (node.right).height
        elif node.right == None: # node has no right subtree
            node.height = 1 + (node.left).height
        else:
            node.height = 1 + max((node.right).height, (node.left).height)

    # Balance the nodes in the path from the specified
    # node to the root if necessary
    def balancePath(self, o):
        path = BinaryTree.path(self, o);
        for i in range(len(path) - 1, -1, -1): 
            A = path[i]
            self.updateHeight(A)
            parentOfA = None if (A == self.root) else path[i - 1]

            if self.balanceFactor(A) == -2:
                if self.balanceFactor(A.left) <= 0:
                    self.balanceLL(A, parentOfA) # Perform LL rotation
                else:
                    self.balanceLR(A, parentOfA) # Perform LR rotation
            elif self.balanceFactor(A) == +2:
                if self.balanceFactor(A.right) >= 0:
                    self.balanceRR(A, parentOfA) # Perform RR rotation
                else:
                    self.balanceRL(A, parentOfA) # Perform RL rotation

    # Return the balance factor of the node 
    def balanceFactor(self, node):
        if node.right == None: # node has no right subtree
            return -node.height
        elif node.left == None: # node has no left subtree
            return +node.height
        else:
            return (node.right).height - (node.left).height

    # Balance LL (see Figure 14.2) 
    def balanceLL(self, A, parentOfA):
        B = A.left # A is left-heavy and B is left-heavy

        if A == self.root:
            self.root = B
        else:
            if parentOfA.left == A:
                parentOfA.left = B
            else:
                parentOfA.right = B

        A.left = B.right # Make T2 the left subtree of A
        B.right = A # Make A the left child of B
        self.updateHeight(A)
        self.updateHeight(B)

    # Balance LR (see Figure 14.2(c)) 
    def balanceLR(self, A, parentOfA):
        B = A.left # A is left-heavy
        C = B.right # B is right-heavy

        if A == self.root:
            self.root = C
        else:
            if parentOfA.left == A:
                parentOfA.left = C
            else:
                parentOfA.right = C

        A.left = C.right # Make T3 the left subtree of A
        B.right = C.left # Make T2 the right subtree of B
        C.left = B
        C.right = A

        # Adjust heights
        self.updateHeight(A)
        self.updateHeight(B)
        self.updateHeight(C)
  
    # Balance RR (see Figure 14.2(b)) 
    def balanceRR(self, A, parentOfA):
        B = A.right # A is right-heavy and B is right-heavy

        if A == self.root:
            self.root = B
        else:
            if parentOfA.left == A:
                parentOfA.left = B
            else:
                parentOfA.right = B

        A.right = B.left # Make T2 the right subtree of A
        B.left = A
        self.updateHeight(A)
        self.updateHeight(B)

    # Balance RL (see Figure 14.2(d)) 
    def balanceRL(self, A, parentOfA):
        B = A.right # A is right-heavy
        C = B.left # B is left-heavy

        if A == self.root:
            self.root = C
        else:
            if parentOfA.left == A:
                parentOfA.left = C
            else:
                parentOfA.right = C

        A.right = C.left # Make T2 the right subtree of A
        B.left = C.right # Make T3 the left subtree of B
        C.left = A
        C.right = B

        # Adjust heights
        self.updateHeight(A)
        self.updateHeight(B)
        self.updateHeight(C)
        
    # Delete an element from the binary tree.
    # Return True if the element is deleted successfully
    # Return False if the element is not in the tree 
    def delete(self, element):
        if self.root == None:
            return False # Element is not in the tree

        # Locate the node to be deleted and also locate its parent node
        parent = None
        current = self.root
        while current != None:
            if element < current.element:
                parent = current
                current = current.left
            elif element > current.element:
                parent = current
                current = current.right
            else:
                break # Element is in the tree pointed by current

        if current == None:
            return False # Element is not in the tree

        # Case 1: current has no left children (See Figure 23.6)
        if current.left == None:
            # Connect the parent with the right child of the current node
            if parent == None:
                root = current.right
            else:
                if element < parent.element:
                    parent.left = current.right
                else:
                    parent.right = current.right

            # Balance the tree if necessary
            self.balancePath(parent.element)
        else:
            # Case 2: The current node has a left child
            # Locate the rightmost node in the left subtree of
            # the current node and also its parent
            parentOfRightMost = current
            rightMost = current.left

            while rightMost.right != None:
                parentOfRightMost = rightMost
                rightMost = rightMost.right # Keep going to the right

            # Replace the element in current by the element in rightMost
            current.element = rightMost.element

            # Eliminate rightmost node
            if parentOfRightMost.right == rightMost:
                parentOfRightMost.right = rightMost.left
            else:
                # Special case: parentOfRightMost is current
                parentOfRightMost.left = rightMost.left
      
            # Balance the tree if necessary
            self.balancePath(parentOfRightMost.element)

        self.size -= 1 # One element deleted
        return True # Element inserted

# AVLTreeNode is TreeNode plus height 
class AVLTreeNode(TreeNode):
    def __init__(self, e):
        self.height = 0 # New data field
        TreeNode.__init__(self, e)