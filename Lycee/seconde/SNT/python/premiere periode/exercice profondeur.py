from turtle import*
speed(10)
pencolor("blue")
coté=input('entrer le coté')
coté=int(coté)

pencolor("blue")

for loop in range(250) :
    up()
    forward(5)
    left(90)
    forward(5)
    right(180)
    down()

    coté=int(coté+10)
    
    for loop in range(4) :
        forward(coté)
        right(90)
   

