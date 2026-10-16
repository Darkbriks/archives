from implementation3 import *
from file2_deque import*

vide = ArbreBinaire(None)


def creer_noeud(valeur, gauche, droit):
    return ArbreBinaire(Noeud(valeur, gauche, droit))
    
def creer_feuille(x):
    return creer_noeud(x, vide, vide)
    
def taille(a):
    if a.est_vide():
        return 0
    else:
        return 1 + taille(a.get_sag()) + taille(a.get_sad())

def hauteur(a):
    if a.est_vide():
        return -1
    else:
        return 1 + max(hauteur(a.get_sag()), hauteur(a.get_sad()))
    
def afficher_infixe(a):
    if not a.est_vide():
        afficher_infixe(a.get_sag())
        print(a.get_racine(),end=' ')
        afficher_infixe(a.get_sad())
        
def est_feuille(a):
    if a.est_vide():
        return False
    else:
        if a.get_sag().est_vide() and a.get_sad().est_vide():
            return True
    return False

def afficher_largeur(a):
    f=File()
    f.enfiler(a)
    while not f.est_vide():
        tree=f.defiler()
        if not tree.est_vide():
            print(tree.get_racine(),end=' ')
            f.enfiler(tree.get_sag())
            f.enfiler(tree.get_sad())
     
def afficher(arbre,tab=0):
    espace=" "*tab
    if arbre!=vide:
        print(espace,arbre.get_racine())
        if arbre.get_sag()!=vide:
            afficher(arbre.get_sag(),tab+2)
        if arbre.get_sad!=vide:
            afficher(arbre.get_sad(),tab+2)
            
#exemple utilisation
feuille=creer_feuille(10)
a1 = creer_noeud(4, creer_noeud(3, creer_feuille(1), vide),creer_feuille(6))
a2 = creer_noeud(12, creer_noeud(9, vide, creer_feuille(11)),creer_feuille(14))
a3 = creer_noeud(8, a1, a2)
assert a3.get_sad().get_sag().get_racine()==9
assert a3.get_sag().get_sag().get_sag().get_racine()==1


def compter_feuille(a):
    """permet de compter le nombre de feuille
    :param: objet de la classe ArbreBinaire
    >>> compter_feuille(feuille)
    1
    >>> compter_feuille(a3)
    4
    """
    if a.est_vide():
        return 0
    if est_feuille(a):
        return 1
    else:
        return compter_feuille(a.get_sag())+compter_feuille(a.get_sad())


def afficher_feuille(a):
    """afficher les feuilles d'un arbre par niveau de profondeur croissant
    >>> afficher_feuille(a3)
    6 14 1 11 
    >>> afficher_feuille(a1)
    6 1 
    """
    f=File()
    f.enfiler(a)
    while not f.est_vide():
        tree=f.defiler()
        if not tree.est_vide():
            if est_feuille(tree):
                print(tree.get_racine(), end=' ')
            else:
                f.enfiler(tree.get_sag())
                f.enfiler(tree.get_sad())

def afficher_feuille2(a):
    """afficher les feuiles de a par niveau de profondeur décroissant
    >>> afficher_feuille2(a3)
    1 6 11 14 
    """
    if not a.est_vide():
        if est_feuille(a):
            print(a.get_racine(), end=' ')
        else:
            afficher_feuille2(a.get_sag())
            afficher_feuille2(a.get_sad())
            
            
import doctest
doctest.testmod()