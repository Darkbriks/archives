#vérificateur de bon parenthésage d'expression mathématiques
#appeler la fonction lanceur pour lancer le programme

from pile1_list import *

def verif_parentheses(expression):
    """
    vérifie qu'il y autant de parenthèses ouvrantes que fermantes
    :param:(str) expression mathématique
    :return: True ou False
    >>> verif_parentheses("(2+3)*5/(1+3)")
    True
    >>> verif_parentheses("(2+3)*(5-1/(1+3)")
    False
    """
    pile=Pile()
    for i in expression:
        if i == '(':
            pile.empiler('(')
        if i == ')':
            if pile.est_vide()==False:
                pile.depiler()
            else:
                return False
    if pile.est_vide()==False:
        return False
    return True

def lanceur():
    expression=input("Donner l'expression mathématique à controler : ")
    return verif_parentheses(expression)


if __name__=="__main__":
    import doctest
    doctest.testmod()