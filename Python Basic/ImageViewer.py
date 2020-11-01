from tkinter import * # Import tkinter
   
class ImageViewer:
    def __init__(self, container, imagefile, x, y, width, height):
        caImage = PhotoImage(file = imagefile)
        
        canvas = Canvas(container, width = width, height = height)
        canvas.pack()
        canvas.create_image(x, y, image = caImage)
