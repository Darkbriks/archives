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

def fin_en_base16(n):
    """
    permet d'avoir le chiffre en base 16 sur la droite
    :param n:int , n positif ou nul, en base 10
    :return : entiers de 0 à 9 ou A ou B ou ...F
    >>> fin_en_base16(302)
    E
    >>> fin_en_base16(11)
    B
    """