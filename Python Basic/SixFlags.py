from tkinter import * # Import tkinter
from ImageViewer import ImageViewer

window = Tk() # Create a window
window.title("Six Flags") # Set title

imageViewer = ImageViewer(window, "image/ca.gif", 90, 50, 400, 200) # Create a clock

window.mainloop() # Create an event loop