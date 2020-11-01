from tkinter import *

root = Tk()

Button(root, text = "OK").pack(side = LEFT)
Button(root, text = "Cancel").pack(side = LEFT)
Label(root, text = "Enter your name:").pack(side = LEFT)
Entry(root, text = "Type Name").pack(side = LEFT)
Checkbutton(root, text = "Bold").pack(side = LEFT)
Checkbutton(root, text = "Italic").pack(side = LEFT)
Radiobutton(root, text = "Red").pack(side = LEFT)
Radiobutton(root, text = "Yellow").pack(side = LEFT)

forward(200)

root.mainloop()