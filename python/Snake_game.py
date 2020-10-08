import turtle

import random

import time



# Setting up the Screen

scrn = turtle.Screen()

scrn.bgcolor("grey")

scrn.setup(800, 800)

scrn.title("~ The Snake Game ~")

delay = .1

score = 0

high_score = 0

upper_limit = 380

lower_limit = -380

scrn.tracer(0)                      # To TURN OFF the Screen's Animation when the Food updates its position





# Setting up the Snake's Head

head = turtle.Turtle()

head.shape("circle")

head.turtlesize(.7, 1, 1)

head.speed(0)

head.pu()

head.goto(0, 100)

head.direction = "stop"





# Writer for the screen

pen = turtle.Turtle()

pen.speed(0)

pen.hideturtle()

pen.pu()

pen.goto(0, 360)

pen.write("Score : 0   High Score : 0", align="center", font=('Comic Sans MS', 22, "normal"))

copyright = turtle.Turtle()

copyright.speed(0)

copyright.pu()

copyright.hideturtle()

copyright.goto(300,-380)

copyright.write("By Aman Kala",align = "left", font=("Arial", 8, "bold"))



# Body of the Snake

body = []





# Get Your snake something to eat ;)

colours=['blue', 'magenta', 'yellow', 'red', 'lightgreen', 'lightblue', 'brown', 'black']

food = turtle.Turtle()

food.shape("turtle")

food.color(random.choice(colours))

food.pu()





# Functions for the Movement of the Snake

def goup():

    if head.direction != "down":

        head.direction = "up"



def godown():

    if head.direction != "up":

        head.direction = "down"



def goright():

    if head.direction != "left":

        head.direction = "right"



def goleft():

    if head.direction != "right":

        head.direction = "left"



def write():

    head.pd()



def cheat():

    head.direction = "stop"

    for parts in body:

        parts.goto(8000, 8000)

    body.clear()



def stop_write():

    head.pu()







def move():

    if head.direction == "up":

        y = head.ycor()

        head.sety(y+20)

    if head.direction == "down":

        y = head.ycor()

        head.sety(y-20)

    if head.direction == "right":

        x = head.xcor()

        head.setx(x+20)

    if head.direction == "left":

        x = head.xcor()

        head.setx(x-20)





# Controlling with the Keyboard

scrn.listen()

scrn.onkeypress(goup, "Up")

scrn.onkeypress(godown, "Down")

scrn.onkeypress(goright, "Right")

scrn.onkeypress(goleft, "Left")

scrn.onkeypress(write, "w")

scrn.onkeypress(cheat," space")

scrn.onkeypress(stop_write, "s")







# The Main Loop of the Game

while True:

    scrn.update()



    # Conditions When The Game Ends



    # 1. When the head of the snake collides with the screen border

    if head.xcor() < lower_limit or head.xcor() > upper_limit or head.ycor() < lower_limit or head.ycor() > upper_limit :

        time.sleep(1)

        head.pu()

        head.goto(0, 100)

        head.clear()

        head.direction = "stop"

        food.goto(0,0)



        for parts in body:

            parts.goto(8000,8000)       # End of for loop

        body.clear()

        score = 0

        pen.clear()

        pen.write("Score : {}    High Score : {}".format(score, high_score), align="center",

                  font=('Comic Sans MS', 22, "normal"))        # End of if statement



    # 2. When the head of the snake collides with the body of the snake

    for part in body:

        if part.distance(head) < 20:

            time.sleep(1)

            head.pu()

            head.goto(0, 100)

            head.clear()

            head.direction = "stop"

            food.goto(0,0)



            for parts in body:

                parts.goto(8000, 8000)  # End of for loop

            body.clear()

            score = 0

            pen.clear()

            pen.write("Score : {}    High Score : {}".format(score, high_score), align="center",

                      font=('Comic Sans MS', 22, "normal"))  # End of if statement              # End of if statement



            # To know whether the Snake has eaten the Food or not

    if head.distance(food) < 20:

        x = random.randint(lower_limit, upper_limit)

        y = random.randint(lower_limit, upper_limit)

        food.color(random.choice(colours))

        food.goto(x, y)



        # Increase the size of Snake with every collision with food

        newpart = turtle.Turtle()

        newpart.color("green")

        newpart.shape("square")

        newpart.speed(0)

        newpart.pu()

        body.append(newpart)            # End of if statement



        # Updating the score

        score += 10

        if score > high_score:

            high_score = score



        pen.clear()

        pen.write("Score : {}    High Score : {}".format(score, high_score), align="center",

                  font=('Comic Sans MS', 22, "normal"))



# Adding the body behind the Snake's Head

    size = len(body)



    for i in range(size - 1, 0, -1):

        if i == size - 1:

            body[i].shape("triangle")

            body[i].color("red")

        else:

            body[i].shape("square")

            body[i].color("green")

        x = body[i - 1].xcor()

        y = body[i - 1].ycor()

        body[i].goto(x, y)          # End of For loop



# If We add this IF statement before the for loop then the 1st and the 2nd element of the list 'BODY' will coincide.

# Because we are adding the body segments in reverse order and by doing the above stated we will violate our approach.

    if size > 0:

        x = head.xcor()

        y = head.ycor()

        body[0].goto(x, y)





    time.sleep(delay)

    move()



# To Hold The Screen

turtle.done()

