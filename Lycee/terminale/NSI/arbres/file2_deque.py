#implémentation d'une file avec le module deque de collections
from collections import deque

#méthode append et popleft (enlever à gauche)

class File:
    def __init__(self):
        """permet de créer une file vide"""
        self.valeurs=deque([])
    
    def __str__(self):
        """permet d'obtenir un visuel de la file avec  print"""
        file="Tête"
        for elt in self.valeurs:
            file=" {} ".format(elt)+file
        return "Queue"+file
        
    def est_vide(self):
        """permet de savoir si la file est vide ou non"""
        if len(self.valeurs)==0:
            return True
        return False
        
    def enfiler(self,x):
        """permet d'ajouter un élément en queue de la file
        :param x: élément à ajouter
        """
        return self.valeurs.append(x)
    
    def defiler(self):
        """enlève et renvoie l'élément qui est en tête de la file"""
        if self.valeurs:
            return self.valeurs.popleft()
    
    def en_tete(self):
        """permet d'obtenir l'élément situé en tête de file"""
        if self.valeurs:
            return self.valeurs[0]
    
    def taille(self):
        """permet d'obtenir le nombre d'éléments de la file"""
        return len(self.valeurs)

def cons(x,F):
    """constructeur de files
    >>> p=cons(1,cons(2,File()))
    >>> p.enTete()
    2
    """
    F.enfiler(x)
    return F