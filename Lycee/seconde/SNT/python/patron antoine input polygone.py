from turtle import *
coté = int(input('quel est le coté'))
nbcoté = int(input('quel est le nombre de coté'))
angle = int(nbcoté/360)
if nbcoté<3 :
    print("trop petit")
else :
    for polygone in range (nbcoté) :
        forward(coté)
        right(angle)
    print(coté*nbcoté)
    