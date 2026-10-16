from pile1_list import *

def trier_wagons(train):
    """
    >>> T=trier_wagons('a 4 5 z e r t y 8 7') 
    >>> print(T)
    sommet
    a
    z
    e
    r
    t
    y
    7
    8
    5
    4 
    """
    list_train=train.split()
    pileFin=Pile()
    pile=Pile()
    for i in list_train:
        if i.isdigit() == True:
            pileFin.empiler(i)
        else:
            pile.empiler(i)
    while pile.est_vide() == False:
        pileFin.empiler(pile.depiler())
    return pileFin
                
import doctest
doctest.testmod()
    