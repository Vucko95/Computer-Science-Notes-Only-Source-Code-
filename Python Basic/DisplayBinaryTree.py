from tkinter import * # Import tkinter
import tkinter.messagebox
from BinaryTree import BinaryTree 
    
def insert():
    k = int(key.get())
    if tree.search(k): # key is in the tree already
        tkinter.messagebox.showinfo("Insertion Status", str(k) + 
                                    " is already in the tree")
    else:
        tree.insert(k) # Insert a new key
        canvas.delete("tree")
        displayTree(tree.getRoot(), width / 2, 30, width / 4)

def delete():
    k = int(key.get())
    if not tree.search(k): # key is in the tree already
        tkinter.messagebox.showinfo("Deletion Status", str(k) + 
                                    " is not in the tree")
    else:
        tree.delete(k) # Delete a key
        canvas.delete("tree")
        displayTree(tree.getRoot(), width / 2, 30, width / 4)

# Display a subtree rooted at position (x, y)
def displayTree(root, x, y, hGap):
    if root == None: return # Empty tree

    # Display the root
    canvas.create_oval(x - radius, y - radius,
                       x + radius, y + radius, tags = "tree")
    canvas.create_text(x, y, 
                       text = str(root.element), tags = "tree")

    if root.left != None:
        # Draw a line to the left node
        connectTwoCircles(x - hGap, y + vGap, x, y)
        # Draw the left subtree recursively
        displayTree(root.left, x - hGap, y + vGap, hGap / 2)
          
    if root.right != None:
        # Draw a line to the right node
        connectTwoCircles(x + hGap, y + vGap, x, y)
        # Draw the right subtree recursively
        displayTree(root.right, x + hGap, y + vGap, hGap / 2)
        
# Connect two circles centered at (x1, y1) and (x2, y2) 
def connectTwoCircles(x1, y1, x2, y2):
    d = (vGap * vGap + (x2 - x1) * (x2 - x1)) ** 0.5
    x11 = x1 - radius * (x1 - x2) / d
    y11 = y1 - radius * (y1 - y2) / d
    x21 = x2 + radius * (x1 - x2) / d
    y21 = y2 + radius * (y1 - y2) / d
    canvas.create_line(x11, y11, x21, y21, tags = "tree")

window = Tk() # Create a window
window.title("DisplayBinaryTree") # Set a title

width = 200
height = 200
radius = 20
vGap = 50
canvas = Canvas(window, width = width, height = height)
canvas.pack()

frame1 = Frame(window) # Create and add a frame to window
frame1.pack()

tree = BinaryTree()
Label(frame1, text = "Enter a key").pack(side = LEFT)
key = StringVar()
entry = Entry(frame1, textvariable = key, 
              justify = RIGHT).pack(side = LEFT)
Button(frame1, text = "Insert", command = insert).pack(side = LEFT)
Button(frame1, text = "Delete", command = delete).pack(side = LEFT)

window.mainloop() # Create an event loop
