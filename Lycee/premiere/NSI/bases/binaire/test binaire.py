def binaire(a) :
    """
    cette fonction retourne le dernier nombre de l'ecriture en base 2 d'un nombre en base 10
    :param a: int
    
    >>> binaire(2565)
    1
    
    >>> binaire(4560)
    0
    """
    if a % 2 == 0 :
        return 0
    else :
        return 1
    
    

def fin_en_base16(a) :
    """
    permet d'avoir le chiffre en base 16 sur la droite
    :param n:int , n positif ou nul
    :return : eniers de 0 à 9 puis A ou B ou ...F
    >>> fin_en_base16(302)
    'E'
    >>> fin_en_base16(11)
    'B'
    """
    reste = a % 16
    if reste > 9 :
        code = chr(reste + 55)
    return code

def fin_en_base16bis(a) :
    """
    permet d'avoir le chiffre en base 16 sur la droite
    :param n:int , n positif ou nul
    :return : eniers de 0 à 9 puis A ou B ou ...F
    >>> fin_en_base16(302)
    'E'
    >>> fin_en_base16(11)
    'B'
    """
    reste = [0,1,2,3,4,5,6,7,8,9,'a''b''c''d''e''f']
    return reste[a%16]
                
import doctest
doctest.testmod(verbose=True)      