from cent_mille_milliards_de_poemes import CENT_MILLE_MILLIARDS
from random import randint

def length_longest(t):
    """
    prend en paramètre un tuple de chaînes de caractères
    retourne la longueur de la plus grande chaîne dans le tuple
    si le tuple est vide, elle renvoie -1.
    :param t:tuple
    :return : int
    >>> length_longest(("Cher-e-s étudiant-e-s,", "", "Vous programmez très bien !"))
    27
    >>> length_longest(())
    -1
    """
    max=-1
    for element in t:
        max=len(element)
    return max
    
def dash_line(n):
    """
    retourne une chaîne de caractères composée d'un espace suivi par n tirets
    :param n : int:
    :effet de bord : affiche uneligne de tirest
    >>> dash_line(29)
      -----------------------------
    """
    print(' ',n*'-')

def msg_line(chaine,largeur):
    """
    retourne une chaîne de caractères débutant par un | et suivi d'un espace
    puis de la chaîne msg écrite sur largeur caractères
    (des espaces sont ajoutés à la fin, si nécessaire), suivie par un espace et un |.
    >>> msg_line("Cher-e-s étudiant-e-s,", 27)
    | Cher-e-s étudiant-e-s,      |
    """
    

if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose = True)
