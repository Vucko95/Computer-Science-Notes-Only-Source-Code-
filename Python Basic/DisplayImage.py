from tkinter import * # Import tkinter
    
root = Tk() # Create a root window
root.title("Display Image") # Set title

photo = PhotoImage(file = "c:\\book\\image\\us.gif")
Label(root, text = "Blue", image = photo, bg = "blue").pack(fill = BOTH, expand = 1)

root.mainloop() # Create an event loop
