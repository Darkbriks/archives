from class_domino_eleve import *
import random

liste_domino=[]
for i in range(1,7):
    liste_domino.append(Domino(6,i))
    liste_domino[i-1].afficher_point()
    liste_domino[i-1].valeur()
    
"""
faire une liste avec tous les dominos de
0-0 0-1 0-2 ......0-6
1-1 1-2 .....1-6
.
.
5-5 5-6
6-6
mélanger la liste
afficher le premier et le dernier domino de la liste mélangée
combien de dominos en tout
partager les dominos mélangés en 4 mains de 6 pour 4 joueur a b c et d
comment voir si un joueur a le domino 6-6
le premier à jouer est celui qui a le double 6 ou le double le plus grand 
"""
def creation_domino():
    for g in range(0,7):
        for d in range(g,7):
            jeu.append(Domino(g,d))
    return jeu

def melange():
    random.shuffle(jeu)
    return jeu

def repartition(a, b, c, d):
    for i in range(6):
        a.append(jeu.pop(0))
        b.append(jeu.pop(0))
        c.append(jeu.pop(0))
        d.append(jeu.pop(0))
    return (a, b, c ,d)

def premier_joueur():
    for i in range(6, 0, -1):
        for j in range(6):
            if a[j].est_double(i) == True:
                return "Le joueur A commence"
            if b[j].est_double(i) == True:
                return "Le joueur B commence"
            if c[j].est_double(i) == True:
                return "Le joueur C commence"
            if d[j].est_double(i) == True:
                return "Le joueur D commence"
    return "Aucun joueur ne possede de double"

jeu=[]
a=[]
b=[]
c=[]
d=[]
def initialisation():
    creation_domino()
    melange()
    repartition(a, b, c, d)
    print("A = ", [a[i].afficher_point() for i in range(6)])
    print("B = ", [b[i].afficher_point() for i in range(6)])
    print("C = ", [c[i].afficher_point() for i in range(6)])
    print("D =", [d[i].afficher_point() for i in range(6)])
    print("Pioche = ", [domino.afficher_point() for domino in jeu])
    print(premier_joueur())

initialisation()
    