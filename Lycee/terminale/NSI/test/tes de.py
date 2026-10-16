from random import randint

def de():
    """
    fonction qui simule le lancer d'un de a 6 face
    :param return: int compris entre 1 et 6 inclus
    >>> de()<=6
    True
    
    >>> de()>=1
    True
    
    >>> type(de())==int
    True
    
    >>> n = [de() for loop in range(100)]
    >>> test = [False for nombre in n if 1>nombre or nombre>6]
    >>> False in test
    False
    """
    return randint(1,6)

if __name__=="__main__":
    import doctest
    doctest.testmod(verbose=True)