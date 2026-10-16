def grenouille_rec(n):
    '''
    avec de la récursivité, permet de calculer le nombre de façons de monter n barreaux à une échelle
    pour une grenouille avec des sauts de 1 ou 2 barreaux
    :param n:int
    :return : le nombre de façons
    >>> grenouille_rec(0)
    1
    >>> grenouille_rec(1)
    1
    >>> grenouille_rec(12)
    233
    '''
    if n==0:
        return 1
    if n==1:
        return 1
    return grenouille_rec(n-1) + grenouille_rec(n-2)

def grenouille_it(n):
    """
    version non récursive
    """
    a=1
    b=1
    i=1
    while i < n:
        (a, b) = (b, a+b)
        i = i+1
    return b
        

def interface(n):
    """
    permet de choisir le nombre de barreaux de l'echelle
    afficher le résultat pour chaque barreau
    """
    for i in range(0,n+1) :
        print ( "barreau {} : {} façons de monter".format( i, grenouille_it(i) ) )


if __name__== '__main__':
    import doctest
    #doctest.testmod(verbose=True)
    doctest.testmod()