"""
Deuxième présentation
une cellule ou maillon est :
    soit la valeur None
    soit un objet de la classe Maillon dont l attribut suivant contient lui même un maillon
"""

class Maillon:
    
    #le constructeur
    def __init__(self,v,s=None):
        self.valeur=v
        #l'attribut valeur désigne la valeur de l'élément
        self.suivant=s
        #l'attribut suivant désigne le maillon suivant de la liste chaînée
        #None est là lorsqu'il n'y a pas de valeur pour suivant

#création d'une fonction
def longueur(maillon):
    """
    >>> longueur(Maillon(1,Maillon(2,Maillon(4))))
    3
    """
    
    if maillon is None:
        return 0
    else:
        return 1+ longueur(maillon.suivant)


    
def longueur_boucle(maillon):
    """
    version de longueur avec une boucle
    >>> m1=Maillon(1,Maillon(2,Maillon(4)))
    >>> longueur_boucle(Maillon(0,m1))
    4
    """

def afficher_maillon(maille):
    """
    permet d obtenir une représentation de typr str pour un maillon
    """
    texte=''
    while maille is not None:
        texte= texte+str(maille.valeur)+' '
        maille=maille.suivant
    return texte


def renvoyer_elt_n(maille,n):
    """
    obtenir l élément en position n dans maille
    :param mailla: Maillon
    :param n : int
    >>> renvoyer_elt_n(Maillon(1,Maillon(2,Maillon(4))),1)
    2
    """
    assert (maille is not None and n>=0), 'indice non valide'
    #plus élégant avec la levée d'une exception, n'est pas au programme
    #if maille is None or n<0:
    #    raise IndexError('indice non valide')
    if n==0:
        return maille.valeur
    else:
        return renvoyer_elt_n(maille.suivant,n-1)
    
def listeN(n):
    """
    reçoit un argument n, renvoie la liste des entiers de 1 à n
    :param n :int, positif ou nul
    >>> listeN(0)
    >>> afficher_maillon(listeN(3))=='1 2 3 '
    True
    """
    assert(n>=0),' n positif ou nul' 
    maille=None
    while n> 0:
        maille=Maillon(n,maille)
        n=n-1
    return maille

def listeN_bis(n):
    maille=None
    for i in range(n):
        maille=Maillon(n-i,maille)
    return maille

def listeN_inv(n):
    """
    reçoit un argument n, renvoie la liste des entiers de n à 1
    :param n :int, positif ou nul
    >>> listeN_inv(0)
    >>> afficher_maillon(listeN_inv(3))=='3 2 1 '
    True
    """
    maille=None
    c=1
    if n==0:
        return maille
    while c <= n:
        maille=Maillon(c,maille)
        c=c+1
    return maille
    
    
if __name__== '__main__':
    import doctest
    doctest.testmod()
    m1=Maillon(8,Maillon(3,Maillon(9)))
    m2=Maillon(0,m1)