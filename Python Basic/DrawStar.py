import turtle

turtle.color("red", "yellow")

turtle.backward(100)
turtle.begin_fill()
for i in range(22):
    turtle.forward(200)
    turtle.left(125)
turtle.end_fill()
turtle.done()