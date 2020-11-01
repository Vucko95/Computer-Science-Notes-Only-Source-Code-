from tkinter import * # Import tkinter

def drawABar(x, percent, color, title):
    canvas.create_line(0, height - 10, width, height - 10)
    canvas.create_rectangle(x, (1 - percent) * (height - 30), x + width / 4.3 - 5, height - 10, fill = color)
    canvas.create_text((x + x + width / 4.3 - 5) / 2, (1 - percent) * (height - 30) - 10,
                        text = title)

window = Tk() # Create a window
window.title("Pyramid") # Set a title

width = 400
height = 150
canvas = Canvas(window, bg = "white", width = width, height = height)
canvas.pack()

x = 10
drawABar(x, 0.4, "red", "Project -- 20%")
  
x += width / 4.3 - 5 + 10  
drawABar(x, 0.1, "blue", "Quizzes -- 10%")

x += width / 4.3 - 5 + 10  
drawABar(x, 0.3, "green", "Midterm -- 30%")

x += width / 4.3 - 5 + 10  
drawABar(x, 0.4, "orange", "Final -- 40%")

window.mainloop() # Create an event loop