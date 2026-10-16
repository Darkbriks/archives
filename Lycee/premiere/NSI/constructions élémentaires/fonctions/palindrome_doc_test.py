def comparer_lettre(mot,i):
    """
    comparer les lettres en position i et len(mot)-i-1
    :param: mot(str)
    :param: i (int)
    >>> comparer_lettre('rodos',1)
    True
    >>> comparer_lettre('rodos',0)
    False
    """
    if mot[len(mot)-1-i] == mot[i] :
        return True
    return False
    
    
def miroir_liste(liste):
    """
    miroir(liste) qui modifie un liste t en son miroir.
    Si t contient les valeurs t[0] , t[1] , ..., t[n-1] dans cet ordre,
    alors après exécution de miroir(t) , t contiendra les valeurs :
    t[n-1]  , t[n-2] , ..., t[0]
    :param: liste(list)
    >>> miroir_liste([3,4,0,1,8])
    [8, 1, 0, 4, 3]
    """
    liste_bis = []
    for loop in range(len(liste)) :
        liste_bis = liste_bis + [liste[len(liste)-(loop+1)]]
    return liste_bis

def miroir_chaine(mot):
    """
    miroir(mot) qui modifie un chaine en son miroir.
    :param: mot(str)
    >>> miroir_chaine('azerty')
    'ytreza'
    >>> miroir_chaine('')
    ''
    >>> miroir_chaine('a')
    'a'
    """
    mot_bis = ''
    for loop in range(len(mot)) :
        mot_bis = mot_bis + mot[len(mot)-(loop+1)]
    return mot_bis

def miroir_chaine_bis(mot):
    """
    miroir(mot) qui modifie un chaine en son miroir.
    :param: mot(str)
    >>> miroir_chaine('azerty')
    'ytreza'
    >>> miroir_chaine('')
    ''
    >>> miroir_chaine('a')
    'a'
    """
    miroir = ''
    for lettre in mot :
        miroir = lettre + miroir
    return miroir

def palindrome(liste):
    """
    permet de voir si un mot est un palindrome
    :param: liste(list ou str)
    >>> palindrome([1,2,3])
    False
    >>> palindrome([1,2,1])
    True
    >>> palindrome('kayak')
    True
    >>> palindrome('k')
    True
    >>> palindrome('mot')
    False
    >>> palindrome('')
    True
    """
    if type(liste) == list :
        mot_bis =[]
        for loop in range(len(liste)) :
            mot_bis = mot_bis + [liste[len(liste)-(loop+1)]]
        if mot_bis == liste :
            return True
        return False
    
    
    else :
        mot_bis = ''
    for loop in range(len(liste)) :
        mot_bis = mot_bis + liste[len(liste)-(loop+1)]
    if mot_bis == liste :
        return True
    return False




import doctest
doctest.testmod(verbose=True)