import turtle
from random import randint

turtle.speed(1) # Set turtle speed to slowest

# Draw 16 by 16 lattices
turtle.color("gray") # Color for lattice
x = -80 
for y in range(-80, 80 + 1, 10):
    turtle.penup()
    turtle.goto(x, y) # Draw a horizontal line
    turtle.pendown()
    turtle.forward(160)

y = 80
turtle.right(90)
for x in range(-80, 80 + 1, 10):
    turtle.penup()
    turtle.goto(x, y) # Draw a vertical line
    turtle.pendown()
    turtle.forward(160)
    
turtle.pensize(3)
turtle.color("red")

turtle.penup()
turtle.goto(0, 0) # Go to the center
turtle.pendown()

x = y = 0 # Current pen location at the center of lattice
while abs(x) < 80 and abs(y) < 80:    
    r = randint(0, 3)
    if r == 0:
        x += 10  # Walk east
        turtle.setheading(0)
        turtle.forward(10)      
    elif r == 1:
        y -= 10 # Walk south
        turtle.setheading(270)
        turtle.forward(10)      
    elif r == 2:
        x -= 10 # Walk west
        turtle.setheading(180)
        turtle.forward(10)      
    elif r == 3:
        y += 10 # Walk north
        turtle.setheading(90)
        turtle.forward(10)      

turtle.done() 