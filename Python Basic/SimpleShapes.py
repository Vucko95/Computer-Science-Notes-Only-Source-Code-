import turtle

turtle.pensize(3)
turtle.penup()
turtle.goto(-200, -50)
turtle.pendown()
turtle.circle(40, steps = 3) # Draw a triangle

turtle.penup()
turtle.goto(-100, -50)
turtle.pendown()
turtle.circle(40, steps = 4) # Draw a square

turtle.penup()
turtle.goto(0, -50)
turtle.pendown()
turtle.circle(40, steps = 5) # Draw a pentagon

turtle.penup()
turtle.goto(100, -50)
turtle.pendown()
turtle.circle(40, steps = 6) # Draw a hexagon

turtle.penup()
turtle.goto(200, -50)
turtle.pendown()
turtle.circle(40) # Draw a circle

turtle.done() 