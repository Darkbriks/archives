def pourcentage(score, total):
    '''
    permet de calculer le pourcentage de bonnes réponses à un test
    A COMPLETER
    Ajouter des tests
    Ajouter des assertions
    >>> type(pourcentage(10, 10))==float
    True
    
    >>> pourcentage(10, 10)==100.0
    True
    
    >>> pourcentage(0, 10)==0.0
    True
    '''
    assert type(score) == int and type(total) == int, "Le score ou le total rentré n'est pas valide"
    assert 0<=score<=total , "Le score rentré est superieur au total"
    return (score/total*100)

def moyenne(a, b):
    """
    Calcule la moyenne de a et b (entiers strictement positifs)
    A COMPLETER
    Ajouter des tests et assertions
    
    >>> moyenne(10, 20)==15
    True
    """
    assert a>=0 and b>=0, "Les nombres a et/ou b ne sont pas valide"
    return (a+b)/2
    
    

if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose = True)