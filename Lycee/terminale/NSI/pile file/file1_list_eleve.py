#implémentation d'une file en utilisant une list Python

class File:
    
    def __init__(self):
        """permet de créer une file vide"""
        self.valeurs=[]
    
    def __str__(self):
        """permet d'obtenir un visuel de la file avec  print"""
        file="Tête"
        for elt in self.valeurs:
            file=" {} ".format(elt)+file
        return "Queue"+file
        
    def est_vide(self):
        """permet de savoir si la file est vide ou non"""
        return self.valeurs==[]
        
    def enfiler(self,x):
        """permet d'ajouter un élément en queue de la file
        :param x: élément à ajouter
        """
        return self.valeurs.append(x)
    
    def defiler(self):
        """enlève et renvoie l'élément qui est en tête de la file"""
        if self.valeurs:
            return self.valeurs.pop(0)
    
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
    >>> p.en_tete()
    2
    """
    F.enfiler(x)
    return F

'''f=File()
f.enfiler(2)
f.enfiler(4)
f.enfiler(8)
print(f)
f.defiler()
print(f)'''

if __name__=="__main__":
    import doctest
    doctest.testmod()
