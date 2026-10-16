from turtle import *
speed(1)

rayon=input('quelle est la longueur du rayon?')
rayon=int(rayon)

if rayon>40 :
    circle(rayon)

if rayon<40 :
    write('trop petit!!')
