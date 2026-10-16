from turtle import*
#Question 1 : que permet de faire ce programme ?
#Question 2 : ajouter des commentaires lignes 6, 8, 12 , 22, 24
width(5)
speed(1)
#permet de poser une questions et de fixée la longueur du bas
longueur_bas=input('entrez la longueur pour le bas')
#permet de convertir la variable au type "int"(entier)
longueur_bas=int(longueur_bas)
fillcolor("blue")
pencolor("red")
begin_fill()
#permet d'avencer
forward(longueur_bas)
right(90)
forward(longueur_bas)
right(90)
forward(longueur_bas)
right(90)
forward(longueur_bas)
right(90)
end_fill()
#on defini une nouvelle variable longueur haut qui est le double de longueur bas

#permet de reculer

pencolor("red")
fillcolor("blue")
begin_fill()

forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)
forward(longueur_bas)

forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)

forward(longueur_bas)
forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)

forward(longueur_bas)
forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)
forward(longueur_bas)
left(120)
end_fill()
