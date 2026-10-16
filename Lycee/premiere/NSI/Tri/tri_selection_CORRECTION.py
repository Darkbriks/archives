def tri_selection(liste):
    """
    permet de trier une liste d'objet par sélection, la liste est triée sur place
    :param liste :lst
    :return : None
    >>> liste=[1,5,72,3,4]
    >>> tri_selection(liste)
    >>> liste==[1,3,4,5,72]
        True
    >>> liste2=['azerty','az','ab','1a','b']
    >>> tri_selection(liste2)
    >>> liste2
    ['1a', 'ab', 'az', 'azerty', 'b']
    """
    for i in range(len(liste)-1):
        mini=i
        #à partir de l'indice i+1, rechercher si un terme liste[j] est plus petit que liste[i]
        #mini prend alors la valeur j
        #pendant la boucle pour mini peut changer plusieus fois de valeurs ou ne pas changer de valeurs
        for j in range(i+1,len(liste)):
            if liste[j]<liste[mini]:
                mini=j
        #échanger les termes d'indices i et mini
        #le minimum est placé en position i
        (liste[i],liste[mini])=(liste[mini],liste[i])
    
    
def tri_selection2(liste):
    """
    permet de trier une liste d'objet par sélection sans modifier la liste de départ
    :param liste :list
    :return : list, une liste triée
    >>> liste=[1,5,72,3,4]
    >>> tri_selection2(liste)
    [1, 3, 4, 5, 72]
    >>> liste2=['azerty','az','ab','1a','b']
    >>> tri_selection2(liste2)
    ['1a', 'ab', 'az', 'azerty', 'b']
    """
    #voir cours mutabilité, la ligne suivante est nécessaire
    #avec new_liste=liste, liste serait modifiée aussi, les 2 listes seraient liées
    new_liste=list(liste)
    for i in range(len(new_liste)-1):
        mini=i
        #à partir de l'indice i+1, rechercher si un terme liste[j] est plus petit que liste[i]
        #mini prend alors la valeur j
        #pendant la boucle pour mini peut changer plusieus fois de valeurs ou ne pas changer de valeurs
        for j in range(i+1,len(new_liste)):
            if new_liste[j]<new_liste[mini]:
                mini=j
        #échanger les termes d'indices i et mini
        #le minimum est placé en position i
        (new_liste[i],new_liste[mini])=(new_liste[mini],new_liste[i])
    return new_liste
    
import doctest
doctest.testmod(optionflags=doctest.NORMALIZE_WHITESPACE | doctest.ELLIPSIS, verbose=True)