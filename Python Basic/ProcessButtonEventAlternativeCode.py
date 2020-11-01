from tkinter import * # Import tkinter

class ProcessButtonEvent:
    def __init__(self):
        window = Tk() # Create a window
        btOK = Button(window, text = "OK", fg = "red", 
                      command = self.processOK) 
        btCancel = Button(window, text = "Cancel", bg = "yellow", 
                          command = self.processCancel) 
        btOK.pack() # Place the button in the window
        btCancel.pack() # Place the button in the window

        window.mainloop() # Create an event loop
        
    def processOK(self):
        print("OK button is clicked")
     
    def processCancel(self):
        print("Cancel button is clicked")
        
ProcessButtonEvent() # Create an object to invoke __init__ method