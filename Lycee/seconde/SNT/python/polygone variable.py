from turtle import *
coté = int(input('quelle est la longuere de votre polygone'))
nbcoté = int(input('quel est le nombre de coté'))
angle = nbcoté/360
for loop in range(nbcoté) :
    forward(coté)
    right(angle)

