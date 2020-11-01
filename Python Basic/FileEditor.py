from tkinter import *
from tkinter.filedialog import askopenfilename
from tkinter.filedialog import asksaveasfilename

class FileEditor:
    def __init__(self):
        window = Tk()
        window.title("Simple Text Editor")
        
        # Create a menu bar
        menubar = Menu(window)
        window.config(menu = menubar) # Display the menu bar
        
        # create a pulldown menu, and add it to the menu bar
        operationMenu = Menu(menubar, tearoff = 0)
        menubar.add_cascade(label = "File", menu = operationMenu)
        operationMenu.add_command(label = "Open",  
            command = self.openFile)
        operationMenu.add_command(label = "Save", 
            command = self.saveFile)
        
        # Add a tool bar frame 
        frame0 = Frame(window) # Create and add a frame to window
        frame0.grid(row = 1, column = 1, sticky = W)
        
        # Create images
        opneImage = PhotoImage(file = "image/open.gif")
        saveImage = PhotoImage(file = "image/save.gif")
        
        Button(frame0, image = opneImage, command = 
            self.openFile).grid(row = 1, column = 1, sticky = W)
        Button(frame0, image = saveImage,
            command = self.saveFile).grid(row = 1, column = 2)
        
        frame1 = Frame(window) # Hold editor pane
        frame1.grid(row = 2, column = 1)
        
        scrollbar = Scrollbar(frame1)
        scrollbar.pack(side = RIGHT, fill = Y)
        self.text = Text(frame1, width = 40, height = 20, 
            wrap = WORD, yscrollcommand = scrollbar.set)
        self.text.pack()
        scrollbar.config(command = self.text.yview)
        
        window.mainloop() # Create an event loop

    def openFile(self): 
        filenameforReading = askopenfilename()
        infile = open(filenameforReading, "r")
        self.text.insert(END, infile.read()) # Read all from the file
        infile.close()  # Close the input file
    
    def saveFile(self):
        filenameforWriting = asksaveasfilename()
        outfile = open(filenameforWriting, "w")
        # Write to the file
        outfile.write(self.text.get(1.0, END)) 
        outfile.close() # Close the output file
    
FileEditor() # Create GUI
