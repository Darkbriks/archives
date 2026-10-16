from random import randint

def machine():
    """
    simuler le bandit manchot
    """
    resultat=[]
    for i in range(3):
        resultat.append(randint(1,9))
    return resultat

def afficher_machine(triplet):
    """
    afficher le résultat du bandit manchot
    :param triplet: liste
    >>> afficher_machine([0,8,2])
    --------------------
    |   0    8    2   |
    --------------------
    """
    print('--------------------\n|  ',triplet[0],'  ',triplet[1],'  ',triplet[2],'  |')
    print('--------------------')


def gain_1(triplet):
    """
    afficher le gain associé à triplet
    :param triplet: liste
    >>> gain_1([1,1,1])
    250
    >>> gain_1([2,2,2])
    150
    >>> gain_1([3,3,3])
    80
    >>> gain_1([4,4,4])
    50
    >>> gain_1([5,5,5])
    20
    >>> gain_1([0,1,1])
    5
    >>> gain_1([3,8,1])
    2
    >>> gain_1([0,8,2])
    """    
    if triplet==[1,1,1]:
        return 250
    #le test de la ligne 37 est vrai si LES 3 conditions sont VRAIES réalisées car on a un ET
    if triplet[0]==2 and triplet[1]==2 and triplet[2]==2 :
        return 150
    if triplet[0] == triplet[1] == triplet[2] == 3 :
        return 80
    if triplet[0] == triplet[1] == triplet[2] == 4 :
        return 50
    if triplet[0] == triplet[1] == triplet[2] == 5 :
        return 20
    #avec un OU, si UNE condition est VRAIE, l'ensemble est VRAI
    #count : permet de compter le nombre de 1
    if triplet.count(1)==2:
        return 5
    if triplet[0]==1 or triplet[1]==1 or triplet[2]==1:
        return 2
   

def gain_10():
    pass


nbr=randint(1,10)
if nbr==10:
    nbr=9

import doctest
doctest.testmod()

