from tkinter import * # Import tkinter
import random

class DeckOfCardsGUI:
    def __init__(self):       
        window = Tk() # Create a window
        window.title("Pick Four Cards Randomly") # Set title
        
        self.imageList = [] # Store images for cards
        for i in range(1, 53):
            self.imageList.append(PhotoImage(file = "image/card/" 
                   + str(i) + ".gif"))
        
        frame = Frame(window) # Hold four labels for cards
        frame.pack()
        
        self.labelList = [] # A list of four labels
        for i in range(4):
            self.labelList.append(Label(frame, 
                image = self.imageList[i]))
            self.labelList[i].pack(side = LEFT)
        
        Button(window, text = "Shuffle", 
            command = self.shuffle).pack()
        
        window.mainloop() # Create an event loop

    # Choose four random cards
    def shuffle(self):
        random.shuffle(self.imageList)
        for i in range(4):
            self.labelList[i]["image"] = self.imageList[i]
        
DeckOfCardsGUI() # Create GUI