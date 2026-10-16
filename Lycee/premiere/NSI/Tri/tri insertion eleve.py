def ranger_dernier(liste):
    """
    tous les éléments de liste sont déjà triés sauf le dernier
    on veut insérer à sa place le dernier dans liste
    :param liste: (lst) tableau d'objets étant tous de même type
    >>> ranger_dernier(['1a', 'az', 'azerty', 'b', 'ab'])
    ['1a', 'ab', 'az', 'azerty', 'b']
    >>> ranger_dernier([1,5,7,13,2])
    [1, 2, 5, 7, 13]
    """
    k = len(liste)-1
    clef = liste[k]
    
    while clef < liste[k-1] and k > 0:
        liste[k] = liste[k-1]
        k = k-1
    liste[k] = clef
    return liste
        
    
    
def tri_insertion(liste):
    """
    permet de trier une liste d'objets par insertion
    :param liste: (list) tableau d'objets étant tous de même type
    >>> liste=[1,5,72,3,4]
    >>> tri_insertion(liste)
    [1, 3, 4, 5, 72]
    
    >>> liste2=['azerty','az','ab','1a','b']
    >>> tri_insertion(liste2)
    ['1a', 'ab', 'az', 'azerty', 'b']
    """
    #for loop in range(len(liste)):
     #   ranger_dernier(liste[:loop])
    #return liste

    for loop in range(1, len(liste)+1) :
        new_liste = list(liste[:loop])
        ranger_dernier(new_liste)
        liste[:loop] = list(new_liste)
    return liste
        
        
    
    

import doctest
doctest.testmod(optionflags=doctest.NORMALIZE_WHITESPACE | doctest.ELLIPSIS, verbose=True)