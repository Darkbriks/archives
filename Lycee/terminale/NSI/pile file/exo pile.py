from pile1_list import *

def copier(pile):
    aux = Pile()
    copie = Pile()
    
    while pile.est_vide == False:
        aux.empiler(pile.depiler())
    
    while aux.est_vide == False:
        x=aux.depiler()
        copie.empiler(x)
        pile.empiler(x)
    
    return copie

def est_present(pile, elt):
    aux=copier(pile)
    while aux.est_vide == False:
        if aux.sommet() == elt:
            return True
        aux.depiler()
    return False

def copierSansDouble(pile):