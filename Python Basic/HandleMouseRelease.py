import turtle

def displaySqaure(x, y):
    turtle.penup()
    turtle.goto(x - 100, y - 100)
    turtle.pendown()
    turtle.begin_fill()
    turtle.circle(50, steps = 4)
    turtle.end_fill()

def main(): 
    # Bind a handler with the mouse-release event
    turtle.onrelease(displaySqaure)
 
    turtle.done() 

main()
