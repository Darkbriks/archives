#recherche de la valeur maximale dans une liste d'entiers

def par_balayage(liste):
    """
    détermine la valeur maximale dans une liste
    :param liste: tableau de nombres
    :return: le plus grand élément de la liste
    >>> par_balayage([1,2,3])
    3
    >>> par_balayage([7,2,1,5])
    7
    >>> par_balayage([1,5,3])
    5
    """
    maxi=liste[0]#creation de la variable 'maxi' avec pour valeur le premier element de 'liste' 
    for k in range(1,len(liste)):#on boucle sur l'ensemble des element de 'liste'
        if maxi<liste[k]:#si 'maxi' est plus petit que 'liste[k]'...
            maxi=liste[k]#... on assigne la valeur 'liste[k]' a 'maxi'
    return maxi#on retourne 'maxi'

def par_div_regner(liste):
    """
    détermine la valeur maximale dans une liste
    :param liste: tableau de nombres
    :return: le plus grand élément de la liste
    >>> par_div_regner([1,2,3])
    3
    >>> par_div_regner([7,2,1,5])
    7
    >>> par_div_regner([1,5,3])
    5
    """
    if len(liste)==1:
        return liste[0]
    return min(par_div_regner(liste[:len(liste)//2]), par_div_regner(liste[len(liste)//2:]))

par_div_regner([5,71,23,42,28,98,63])

################################
# mesure des temps d'exécution #
################################
"""
from timeit import timeit
from matplotlib import pyplot
from random import randint

def mesure_temps(n):
    ""
    mesure du temps d'exécution en secondes
    :param n:(int) taille du tableau
    ""
    tableau=[randint(0,1000) for i in range(n)]
    for f in (par_balayage, par_div_regner):
        temps = timeit(lambda:f(tableau), number=10000)
        print("{} : {} secondes".format(f,temps))

def graphe_comparatif_temps():
    ""
    affiche le graphe des temps d'exécution
    
    :effect de bord: affichage du graphe
    ""
    #listes des coordonnées des points
    x, yboucle, yrec=[], [], []
    #création des échantillons
    for k in range(100,2000,100):
        tableau=[randint(0,1000) for i in range(k)]
        x.append(k)
        yboucle.append(timeit(lambda:par_balayage(tableau), number=1000))
        yrec.append(timeit(lambda:par_div_regner(tableau), number=1000))
    pyplot.title("comparatif vitesses d'exécution")
    pyplot.xlabel('taille tableau')
    pyplot.ylabel('vitesse')
    pyplot.scatter(x,yboucle,s=5,c="blue")
    pyplot.scatter(x,yrec,s=5,c="red")
    
    pyplot.legend(["boucle","recursif"])
    pyplot.show()
    
    
if __name__== '__main__':
    import doctest
    doctest.testmod()
    """