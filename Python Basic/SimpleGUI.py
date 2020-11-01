from tkinter import * # Import tkinter

root = Tk() # Create a root window
label = Label(root, text = "Welcome to Python") # Create a label
button = Button(root, text = "Click Me") # Create a button
label.pack() # Display the label in the window
button.pack() # Display the button in the window

root.mainloop() # Create an event loop