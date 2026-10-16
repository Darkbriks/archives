from turtle import *


def trace_immeuble(building,couleur):
    colormode(255)
    (debut,fin,hauteur)=building
    largeur=fin-debut
    forward(debut)
    fillcolor(couleur)  #Change la couleur de remplissage à couleur
    begin_fill()  #Précise le début du remplissage
    forward(largeur)
    left(90)
    forward(hauteur)
    left(90)
    forward(largeur)
    left(90)
    forward(hauteur)
    end_fill()#Précise la fin du remplissage
    left(90)
    setposition(0,0)
    

ville=[(0,10,50),(20,40,100),(30,50,70),(30,80,20),(70,90,40)]

def trace_ville(town):
    reset()
    long=len(town)
    pas=int(255/long)
    color=[255,0,255]
    for building in town :
        trace_immeuble(building,color)
        color=(color[0]-pas,color[1]+pas,color[2]-pas)
    
   
        
def trace_skyline(skyline):
    reset()
    for elt in skyline:
        setposition(elt)
    
    
    
    
test_skykine=[(0,0),(0,50),(10,50),(10,0),(20,0),(20,100),(40,100),(40,70),(50,70),(50,20),(70,20),(70,40),(90,40),(90,0)]  

def hauteur_max_immeubles_rec(liste,n):
    if len(liste)==0:
        return None
    if n==0 or len(liste) == 1:
        return liste[0]
    else:
        m = hauteur_max_immeubles_rec(liste[1:],n-1)
        return m if m > liste[0] else liste[0]
    
    
def hauteur_max_immeubles_rec2(liste):
    if len(liste)==0:
        return None
    if len(liste) == 1:
        return liste[0]
    else:
        m = hauteur_max_immeubles_rec2(liste[1:])
        if m < liste[0]:
            m=liste[0]
        return m
    
    
def dictionnaire_bords_immeubles(ville):
    """à partir d une liste de triplets (x,y,h) ...."""
    dico={}
    for numero in range (len(ville)):
        (dbt,fin)=(ville[numero][0],ville[numero][1])
        if dbt in dico.keys():
            dico[dbt]=dico[dbt]+[numero]
        else:
            dico[dbt] = [numero]
        if fin in dico.keys():
            dico[fin]=dico[fin]+[numero]
        else:
            dico[fin] = [numero]
    return dico