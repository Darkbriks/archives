from turtle import *
speed(10)
pencolor("blue")

coté=input('entrer le coté')
coté=int(coté)

forward(coté)
for loop in range(500) :
left(90)
coté=int(coté+5)
forward(coté)
