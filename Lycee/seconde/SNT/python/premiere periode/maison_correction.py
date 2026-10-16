from turtle import*
#Question 1 : que permet de faire ce programme ?
#Question 2 : ajouter des commentaires lignes 6, 8, 12 , 22, 24
width(5)
speed(1)

longueur_bas=input('entrez la longueur pour le bas')

longueur_bas=int(longueur_bas)
fillcolor("red")
begin_fill()

forward(longueur_bas)
right(90)
forward(longueur_bas)
right(90)
forward(longueur_bas)
right(90)
forward(longueur_bas)
right(90)
end_fill()

longueur_haut=2*longueur_bas

backward(longueur_bas/2)
pencolor("red")
fillcolor("green")
begin_fill()

forward(longueur_haut)
left(120)
forward(longueur_haut)
left(120)
forward(longueur_haut)
left(120)
end_fill()
