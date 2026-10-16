from class_main_eleve import*
from class_domino import*
from class_plateau_eleve import*
import random

def initialisation():
    jeu=[]
    for g in range(0,7):
        for d in range(g,7):
            jeu.append(Domino(g,d))
    random.shuffle(jeu)
    a=Main([jeu.pop() for loop in range(6)])
    b=Main([jeu.pop() for loop in range(6)])
    c=Main([jeu.pop() for loop in range(6)])
    d=Main([jeu.pop() for loop in range(6)])
    
    for i in range(6, 0, -1):
        if a.avoir_double_i(i) == True:
            return premier_tour(a, 'a')
        if b.avoir_double_i(i) == True:
            return premier_tour(b, 'b')
        if c.avoir_double_i(i) == True:
            return premier_tour(c, 'c')
        if d.avoir_double_i(i) == True:
            return premier_tour(d, 'd')
        
def premier_tour(main, nom):
    print("Le premier joueur est {}. Il dispose des domino {}".format(nom, main))
    p=int(input("Quel domino souhaiter vous utiliser ?"))
    plateau=Plateau(main.pop(p+1))   
        
def tour(main, plateau, nom):
    print("Le plateau actuel est :", plateau.plateau)
    print("C'est au  joueur {} de comencer. Il dispose des domino {}".format(nom, main))
    #if main.avoir_i(plateau.donner_droite())==True or main.avoir_i(plateau.donner_droite())==True:
        #p=[int(input("Quel domino souhaiter vous utiliser ?")), str(input("Voulez vous le placer a droite ou a gauche ?"))]
        
        
        
        
        
        