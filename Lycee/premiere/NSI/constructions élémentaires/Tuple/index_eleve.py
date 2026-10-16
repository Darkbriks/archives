def presence(valeur,mon_tuple):
    """
    permet de voir si valeur est dans mon_tuple
    :param valeur: int str float
    :param mon_tuple:tuple
    :return :booleen
    >>> presence(2,(3,6,9))
    False
    >>> presence(3,(5,))
    False
    >>> presence('bonjour',('salut','bonjour'))
    True
    """
    
    for carct in mon_tuple :
        if valeur == carct :
            return True
    return False

    #if valeur in mon_tuple :
        #return True
    #return False


def indice(valeur, mon_tuple):
    """
    renvoie l’indice de la première occurrence de son premier paramètre
    dans le tuple passé en second, renvoie -1 si absent
    :param valeur: int str float
    :param mon_tuple:tuple
    :return :int
    >>> indice (1, (3, 10, 4, 1, 5, 9, 2))
    3
    >>> indice (10, (3, 1, 4, 1, 5, 9, 2))
    -1
    """
    
    for indice in range(len(mon_tuple)-1) :
        if valeur == mon_tuple[indice] :
            return indice
    return -1


def indice_fin(valeur, mon_tuple):
    """
    renvoie l’indice de la dernière occurrence de son premier paramètre
    dans le tuple passé en second, renvoie -1 si absent
    :param valeur: int str float
    :param mon_tuple:tuple
    :return :int
    >>> indice_fin(1, (15, 1, 4, 1, 1, 9, 2))
    4
    >>> indice_fin (10, (3, 1, 4, 1, 5, 9, 2))
    -1
    """
    indice = -1
    for i in range(len(mon_tuple)-1) :
        if valeur == mon_tuple[i] :
            indice = i
    return indice

def nombre_occurence(valeur,mon_tuple):
    """
    renvoie le nombre d'occurrence(s) de son premier paramètre
    dans le tuple passé en second
    :param valeur: int str float
    :param mon_tuple:tuple
    :return :int
    >>> nombre_occurence(1, (7, 1, 4, 1, 1, 9, 2))
    3
    >>> nombre_occurence(10, (3, 1, 4, 1, 5, 9, 2))
    0
    """
    indice = 0
    for i in range(len(mon_tuple)-1) :
        if valeur == mon_tuple[i] :
            indice = indice + 1
    return indice
    
    
mois=('janvier','février','mars','avril', 'mai', 'juin', 'juillet', 'aout',
      'septembre','octobre','novembre','decembre')

def nom_mois(n):
    """
    obtenir le nom du nième mois de l'année
    """
    return mois[n]
    
def inserer(e,i,t):
    """
    renvoie un tuple dans lequel l’élément e a été placé à l’indice i
    dans le tuple t avec e, i et t passés en paramètre.
    >>> inserer(3,0,(1,4,1,5,9))
    (3,1,4,1,5,9)
    >>> inserer(4,2,(3,1,1,5,9))
    (3,1,4,1,5,9)
    >>> inserer(9,5,(3,1,4,1,5))
    (3,1,4,1,5,9)
    """

    #li = []
    #for loop in range(len(t)):
        #if loop == i :
            #li.append(e)
        #li.append(t[loop])
    #new_t = (li)
    #return new_t

    t1 = t[:i]
    t2 = t[i:]
    t3 = (e,)
    return t1+t3+t2

    #return new_tuple = t[:i] + (e,) + t[i:]




def enlever(t,i):
    """
    supprime et renvoie un tuple donné en paramètre contenant tous les éléments de ce tuple t
    sauf celui d’un indice i lui aussi donné en paramètre.
    L'indice i doit être compris entre 0 au sens large et len(t) au sens strict.
    :param t:tuple
    :param i : int
    >>> enlever((5,4,3,2,1),2)
    (5, 4, 2, 1)
    >>> enlever((5,4,3,2,1),0)
    (4, 3, 2, 1)
    >>> enlever((5,4,3,2,1),4)
    (5, 4, 3, 2)
    """
    return t[:i] +t[1+i:]

def renverser(t):
    """
    renvoie un tuple contenant les éléments du tuple t passé en paramètre
    dans l’ordre inverse.
    :param t: tuple
    >>> renverser((1,2,3,4,5))
    (5,4,3,2,1)
    """
    new_t = ()
    for loop in range(len(t)):
        new_t = new_t + (t[-1-loop],)
    return new_t
        
    