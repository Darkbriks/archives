from math import*
from collections import Counter

table = [(6.5, 5.6, 'bleu'), (3.16, 7.44, 'vert'), (0.92, 2.34, 'vert'), (-1.24, 5.71, 'vert'), (-5.81, 5.46, 'bleu'), (-4.21, 2.87, 'vert')]

pokemon = [(49, 49, 'eau'), (53, 51, 'eau'), (59, 63, 'eau'), (64, 66, 'eau'), (50, 70, 'eau'), (71, 73, 'eau'), (75, 75, 'eau'), (90, 75, 'eau'), (65, 80, 'eau'), (80, 80, 'eau'), (55, 84, 'eau'), (70, 92, 'eau'), (80, 92, 'eau'), (95, 100, 'eau'), (75, 105, 'eau'), (85, 105, 'eau'), (45, 30, 'psy'), (50, 70, 'psy'), (50, 95, 'psy'), (50, 150, 'psy'), (50, 180, 'psy'), (60, 25, 'psy'), (60, 45, 'psy'), (70, 55, 'psy'), (75, 50, 'psy'), (75, 125, 'psy'), (76, 25, 'psy'), (80, 45, 'psy'), (95, 23, 'psy'), (100, 100, 'psy'), (106, 110, 'psy'), (106, 150, 'psy'), (106, 190, 'psy'), (110, 65, 'psy')]

def calcul_distance_euclidienne(pointA, pointB) :
    """
    cette fonction permet de calculer la distance euclidienne entre un point a et un point b
    :param pointA: tuple de deux float(coordonée du point)
    :param pointB: tuple de deux float(coordonée du point)
    :param return: float
    >>> calcul_distance_euclidienne((1, 1), (4, 5))
    5.0
    >>> calcul_distance_euclidienne((1, 1), (5, 5))
    5.657
    """
    return round(sqrt(((pointA[0] - pointB[0])**2) + ((pointA[1] - pointB[1])**2)),3)


def recherche_k_voisin(k, a, table) :
    """
    cette fonction permet de retrouver les k plus proche voisins d'un point a
    :param k: int (nombre de voisins a trouver)
    :param a: tuple de deux float(coordonée du point)
    :param table: liste de tuple de deux float (chaque tuple represantant un point)
    :param return: liste des k plus proche voisins
    
    >>> recherche_k_voisin(5, (1, 1), table)
    [(-5.81, 5.46, 'bleu'), (6.5, 5.6, 'bleu'), (3.16, 7.44, 'vert'), (-4.21, 2.87, 'vert'), (-1.24, 5.71, 'vert')]
    >>> recherche_k_voisin(3, (1, 1), table)
    [(-5.81, 5.46, 'bleu'), (6.5, 5.6, 'bleu'), (3.16, 7.44, 'vert')]
    >>> recherche_k_voisin(1, (1, 1), table)
    [(-5.81, 5.46, 'bleu')]
    """
    new_table = list(sorted(table, key=lambda x: calcul_distance_euclidienne(a, x), reverse=True))
    return new_table[:k]

def prediction(k, a, table) :
    """
    cette fonction permet de faire la prediction de la classe d'un element a par rapport a ses k plus proche voisin
    :param k: int (nombre de voisins a trouver, il est recommender de mettre un nombre impair)
    :param a: tuple de deux float(coordonée du point)
    :param table: liste de tuple de deux float et une string (les int du tuple représente les coordonées du point, et la string sa classe)
    :param return: str representant la classe predite pour l'element a
    
    >>> prediction(3, (1, 1), table)
    'bleu'
    >>> prediction(5, (1, 1), table)
    'vert'
    """
    voisins = recherche_k_voisin(k, a, table)
    classe = [element[2] for element in voisins]
    prediction_classe = Counter(classe).most_common(1)
    return prediction_classe#[0][0]


import doctest
doctest.testmod(verbose=True)