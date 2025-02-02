# import turtle

# win = turtle.Screen()
# win.bgcolor("black")
# t = turtle.Turtle()
# t.shape("turtle")
# t.speed(10)



# colors=["red","blue","yellow","green","orange","purple","white","gray"]

# def draw_star(size):
#     for i in range(5):
#         t.forward(size)
#         t.right(144)
        
# def draw_star_pattern():
#     for i in range(18):
#         t.color(colors[i%len(colors)])
#         draw_star(100)
#         t.right(20)

# draw_star_pattern()

# t.hideturtle()
# win.exitonclick()

from turtle import *
from random import random

for i in range(100):
    steps = int(random() * 100)
    angle = int(random() * 360)
    turtle.right(angle)
    turtle.fd(steps)

turtle.mainloop()
