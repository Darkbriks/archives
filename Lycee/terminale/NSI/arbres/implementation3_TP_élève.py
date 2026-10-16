from implementation3 import *
from file2_deque import*

vide = ArbreBinaire(None)

def creer_noeud(racine, gauche, droit):
    """
    permet de créer un arbre binaire
    """
    return ArbreBinaire(Noeud(racine, gauche, droit))
    
def creer_feuille(x):
    """
    permet de créer une feuille
    """
    return creer_noeud(x,vide,vide)

#exemple utilisation
feuille=creer_feuille(10)
a1 = creer_noeud(4, creer_noeud(3, creer_feuille(1), vide),creer_feuille(6))
a2 = creer_noeud(12, creer_noeud(9, vide, creer_feuille(11)),creer_feuille(14))
a3 = creer_noeud(8, a1, a2)
assert a3.get_sad().get_sag().get_racine()==9
assert a3.get_sag().get_sag().get_sag().get_racine()==1


def est_feuille(a):
    """
    permet de savoir si a est une feuille
    attention ne pas utiliser l'attribut de a
    ne travailler qu'avec les méthodes de ArbreBinaire
    """
    if a.est_vide() or (a.get_sag().est_vide() and a.get_sad().est_vide()):
        return True
    return False

def taille(a):
    if a.est_vide()==True:
        return 0
    return 1+taille(a.get_sag())+taille(a.get_sad())

def hauteur(a):
    if a.est_vide()==True:
        return -1
    return max(1+hauteur(a.get_sag()), 1+hauteur(a.get_sad()))
    
def afficher_infixe(a):
    if a.est_vide()==False:
        return(afficher_infixe(a.get_sag()), a.get_racine(), afficher_infixe(a.get_sad()))

            
def afficher_largeur(a):
    f=File()
    f.enfiler(a)
    while f.est_vide()==False:
        u=f.defiler()
        if u.est_vide()!=True:
            f.enfiler(u.get_sag())
            f.enfiler(u.get_sad())
            print(u.get_racine())
        
def afficher(arbre,tab=0):
    espace=" "*tab
    if arbre!=vide:
        print(espace,arbre.get_racine())
        if arbre.get_sag()!=vide:
            afficher(arbre.get_sag(),tab+2)
        if arbre.get_sad!=vide:
            afficher(arbre.get_sad(),tab+2)

def compter_feuille(a):
    """
    permet de compter le nombre de feuille
    :param: objet de la classe ArbreBinaire
    >>> compter_feuille(feuille)
    1
    >>> compter_feuille(a3)
    4
    """
    if est_feuille(a)==True:
        return 1
    return compter_feuille(a.get_sag()) + compter_feuille(a.get_sad())
   
def afficher_feuille(a):
    """
    afficher les feuilles d'un arbre par niveau de profondeur croissant
    >>> afficher_feuille(a3)
    6 14 1 11 
    >>> afficher_feuille(a1)
    6 1 
    """
    f=File()
    f.enfiler(a)
    while f.est_vide()==False:
        u=f.defiler()
        if u.est_vide()!=True:
            f.enfiler(u.get_sag())
            f.enfiler(u.get_sad())
            print(u.get_racine())
    

def afficher_feuille2(a):
    """
    afficher les feuiles de a par niveau de profondeur décroissant
    >>> afficher_feuille2(a3)
    1 6 11 14 
    """
    
            
import doctest
doctest.testmod() 