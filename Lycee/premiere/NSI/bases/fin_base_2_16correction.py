liste16=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']
def fin_en_base2(n):
    """
    permet d'avoir le chiffre en base 2 sur la droite
    :param n:int , n positif ou nul
    :return : int, 1 ou 0
    >>> fin_en_base2(458)
    0
    >>> fin_en_base2(2578947)
    1
    """
    if n%2==1:
        return 1
    return 0

def fin_en_base2BIS(n):
    """
    permet d'avoir le chiffre en base 2 sur la droite
    :param n:int , n positif ou nul
    :return : int, 1 ou 0
    
    """
    return n%2

def fin_en_base16(n):
    """
    permet d'avoir le chiffre en base 16 sur la droite
    :param n:int , n positif ou nul
    :return : eniers de 0 à 9 puis A ou B ou ...F
    >>> fin_en_base16(302)
    'e'
    >>> fin_en_base16(11)
    'b'
    """
    r=n%16
    return liste16[r]
    
import doctest
doctest.testmod(verbose=True)   