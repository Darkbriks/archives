#implémentation d'une pile en utilisant une list Python

class Pile:
  
    def __init__(self):
        """permet de créer une pile vide"""
        self.valeurs=[]
    
    def __str__(self):
        """permet d'obtenir un visuel de la pile avec print"""
        pile=""
        for elt in self.valeurs:
            pile="{}\n".format(elt)+pile
        return "sommet\n"+pile
        
    def est_vide(self):
        """permet de savoir si la pile est vide ou non"""
        return self.valeurs==[]
        
    def empiler(self,x):
        """permet d'ajouter un élément au sommet de la pile
        :param x: élément à ajouter
        """
        return self.valeurs.append(x)
    
    def depiler(self):
        """enlève et renvoie l'élément qui est au sommet de la pile"""
        if self.valeurs:
            return self.valeurs.pop()
    
    def sommet(self):
        """permet d'obtenir l'élément situé au sommet de la pile"""
        if self.valeurs:
            return self.valeurs[-1]
        
    def taille(self):
        """permet d'obtenir le nombre d'éléments de la pile"""
        return len(self.valeurs)

def cons(x,P):
    """constructeur de piles
    >>> p=cons(1,cons(2,Pile()))
    >>> p.sommet()
    1
    """
    P.empiler(x)
    return P



if __name__=="__main__":
    import doctest
    doctest.testmod()
    p=Pile()
    p.empiler(1)
    p.empiler(2)
    p.empiler(3)
    print(p)
    p.depiler()
    print(p)
