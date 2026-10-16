from cent_mille_milliards_de_poemes import CENT_MILLE_MILLIARDS
import random
TUX = "   \\\n    \\\n        .--.\n       |o_o |\n       |:_/ |\n      //   \\ \\\n     (|     | )\n    /'\_   _/`\\\n    \___)=(___/"
yoda = "   __.-._
    *-._¨7*
     / .-c
     |  /T
    _|_/LI"


def length_longest(_tuple):
    """
    fonction qui, pour chaque chaine de _tuple, verifie si sa longeur est plus grande que le _max actuel,
    qui est defini a -1 dans le que on l'on aurait un tuple vide et retourne le _max
    
    :param _tuple: tuple
    :param return: int
    
    >>> length_longest(())
    -1
    
    >>> length_longest(("Cher-e-s étudiant-e-s,", "", "Vous programmez très bien !"))
    27
    """
    
    _max = -1
    for chaine in _tuple :
        if len(chaine) > _max :
            _max = len(chaine)
    return _max

def dash_line (n) :
    """
    fonction qui teste si n est egal a -1. Si c'est le cas, elle retourne " ---"(en effet, si n = -1, cela signifie que
    le tuple est vide, et, dans ce cas on renvois simplement"?")
    sinon, elle affiche un espase suivi de n + 2 "-"(le correspond au fait que dans la fonction msg_line, on ajoute
    deux espace a la chaine
    
    :param n: int
    :param return: str
    
    >>> dash_line(29)
    ' -------------------------------'
    
    >>> dash_line(1)
    ' ---'
    
    >>> dash_line(-1)
    '  -'

    """
    ligne = " "
    if n == -1 :
        return "  -"
    for loop in range(n + 2) :
        ligne = ligne + "-"
    return ligne

def msg_line (chaine, _max) :
    """
    fonction qui, pour un chaine de caractére, renvoie "| " suivie de la chaine de caractére,
    suivi _max - len(chaine) espace, suivie de " |"
    
    :param chaine: str
    :param _max: int
    :param return: str
    
    >>> msg_line("Cher-e-s étudiant-e-s,", 27)
    '| Cher-e-s étudiant-e-s,      |'
    """
    debut = "| "
    fin = " |"
    return debut + chaine +( _max - len(chaine)) * " " + fin

def poeme() :
    """
    crée un sonnet constituer de vers aleatoire
    """
    poesie = ()
    for loop in range(2) :
        for v in range(4) :
            poesie = poesie + (CENT_MILLE_MILLIARDS[random.randint(0+(10*v)+(40*loop),10+(10*v)+(40*loop))],)
        poesie = poesie + ("",)
        
    for loop in range(2) :
        for v in range(3) :
            poesie = poesie + (CENT_MILLE_MILLIARDS[random.randint(80+(10*v)+(30*loop),90+(10*v)+(30*loop))],)
        poesie = poesie + ("",)
    return poesie
             

def tux_say_poeme () :
    """
    faire parler le manchot
    si le tuple est vide, la bulle contient "?"
    
    :param _tuple:
    """
    _tuple = (poeme())
    _max = length_longest(_tuple)
    print(dash_line(_max))
    if not _tuple :
        print(msg_line("?", _max))
    else :
        for chaine in _tuple :
            print(msg_line(chaine, _max))
    print(dash_line(_max))
    print(TUX)
    
if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose = True)