import math

"""
Les instructions assert ont été utilisées pour vérifier les préconditions.
Une telle instruction se compose d'une condition (une expression booléenne)
éventuellement suivie d'une virgule et d'une phrase en langue naturelle,
sous forme d'une chaine de caractères.
L'instruction assert teste si sa condition est satisfaite.
Si c'est le cas, elle ne fait rien
sinon elle arrête immédiatement l'exécution du programme en affichant éventuellement la phrase qui lui est associée.
"""

def factorielle1(n):
    """
    >>> factorielle1(0)
    1
    >>> factorielle1(1)
    1
    >>> factorielle1(5)
    120
    >>> factorielle1(50) == 50*factorielle1(49)
    True
    """
    assert n >= 0
    i = 0
    f = 1
    while i <= n :
        i = i+1
        f = f*i
    return f

def factorielle2(n):
    """
    >>> factorielle2(0)
    1
    >>> factorielle2(1)
    1
    >>> factorielle2(5)
    120
    >>> factorielle2(50) == 50*factorielle2(49)
    True
    """
    assert n >= 0
    i = 0
    f = 1
    while i < n :
        i = i+1
        f = f*i
    return f

def factorielle3(n):
    """
    >>> factorielle3(0)
    1
    >>> factorielle3(1)
    1
    >>> factorielle3(5)
    120
    >>> factorielle3(50) == 50*factorielle3(49)
    True
    """
    assert n >= 0
    f = 1
    for i in range(1,n+1):
        f = f*i
    return f

def factorielle4(n):
    """
    >>> factorielle4(0)
    1
    >>> factorielle4(1)
    1
    >>> factorielle4(5)
    120
    >>> factorielle4(50) == 50*factorielle4(49)
    True
    """
    assert n >= 0
    f = 1
    for i in range(n):
        f = f*i
    return f

def factorielle5(n):
    """
    >>> factorielle5(0)
    1
    >>> factorielle5(1)
    1
    >>> factorielle5(5)
    120
    >>> factorielle5(50) == 50*factorielle5(49)
    True
    """
    assert n >= 0
    f = 1
    for i in range(1,n+1):
        f = f*i
    return f

def factorielle6(n):
    """
    >>> factorielle6(0)
    1
    >>> factorielle6(1)
    1
    >>> factorielle6(5)
    120
    >>> factorielle6(50) == 50*factorielle6(49)
    True
    """
    assert n >= 0
    if n > 1:
        return factorielle6(n-1)*n
    else:
        return 1

def factorielle7(n):
    """
    >>> factorielle7(0)
    1
    >>> factorielle7(1)
    1
    >>> factorielle7(5)
    120
    >>> factorielle7(50) == 50*factorielle7(49)
    True
    """
    assert n >= 0
    if n == 1:
        return 1
    else:
        return factorielle7(n-1)*n

def factorielle8(n):
    """
    >>> factorielle8(0)
    1
    >>> factorielle8(1)
    1
    >>> factorielle8(5)
    120
    >>> factorielle8(50) == 50*factorielle8(49)
    True
    """
    assert n >= 0
    if n <= 1:
        return 1
    else:
        factorielle8(n-1)*n

def factorielle9(n):
    """
    >>> factorielle9(0)
    1
    >>> factorielle9(1)
    1
    >>> factorielle9(5)
    120
    >>> factorielle9(50) == 50*factorielle9(49)
    True
    """
    assert n >= 0
    f = 1.
    for i in range(1,n+1):
        f = f*i
    return int(f)

def factorielle10(n):
    """
    basée sur la formule de Stirling
    
    >>> factorielle10(0)
    1
    >>> factorielle10(1)
    1
    >>> factorielle10(5)
    120
    >>> factorielle10(50) == 50*factorielle10(49)
    True
    """
    assert n >= 0
    if n == 0:
        return 1
    else:
        return int( (math.sqrt(2*math.pi*n)*(n/math.e)**n + .5)
                * (1 + 1/(12*n) + 1/(288*n**2) - 139/(51840*n**3)) )

def factorielle11(n):
    """
    basée sur la formule de Ramanujan
    
    
    >>> factorielle11(0)
    1
    >>> factorielle11(1)
    1
    >>> factorielle11(5)
    120
    >>> factorielle11(50) == 50*factorielle11(49)
    True
    """
    assert n >= 0
    if n == 0:
        return 1
    else:
        return int(math.exp(n*math.log(n) - n
                        + (math.log(8*n**3 + 4*n**2 + n + 1/30)) / 6
                        + math.log(math.pi)/2))
if __name__ == "__main__":
    import doctest
    doctest.testmod()