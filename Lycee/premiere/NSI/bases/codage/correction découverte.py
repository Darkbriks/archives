

def table_ascii_minuscule():
    '''
    obtenir le code ascci pour l alphabet en minuscule
    :param:None
    effet de bord : affichage de la table ascii
    >>> table_ascii_minuscule()
    97 : a ; 98 : b ; 99 : c ; 100 : d ; 101 : e ; 102 : f ; 103 : g ; 104 : h ; 105 : i ; 106 : j ; 107 : k ; 108 : l ; 109 : m ; 110 : n ; 111 : o ; 112 : p ; 113 : q ; 114 : r ; 115 : s ; 116 : t ; 117 : u ; 118 : v ; 119 : w ; 120 : x ; 121 : y ; 122 : z ;
    '''
    for pas in range(26):
        print(97+pas,':',chr(97+pas),end=' ; ')

def caractere_to_ascii(caractere):
    '''
    obtenir le code ascci de carctère
    :param:str
    :return:int
    >>> caractere_to_ascii('a')
    pour le caractère  a , le code ascci est :  97
    >>> caractere_to_ascii('?')
    pour le caractère  ? , le code ascci est :  63
    '''
    print('pour le caractère ',caractere,', le code ascci est : ', ord(caractere))

def table_ascii_entier():
    '''
    donner la table ascii, en base 10, pour les entiers de 0 à 9
    '''
    zero=ord('0')
    for pas in range(10):
        print(zero+pas,' est le code ascii pour ',chr(zero+pas))

def encoder(texte):
    '''
    donner le codage ascii d'un texte en base 10
    :param texte:str
    >>> encoder('azAZ')
    ' 97 122 65 90 '
    '''
    code=' '
    for lettre in texte :
      code=code+str(ord(lettre))+' '
    return code

def encoderBis(texte):
    '''
    donner le codage ascii d'un texte, caractère par caractère en base 10
    :param texte:str
    >>> encoderBis('az12')
    ' a:97 z:122 1:49 2:50 '
    '''

    code=' '
    for lettre in texte :
      code=code+lettre+':'+str(ord(lettre))+' '
    return code


def decoder(message):
    """
    donner le texte associé au message, message étant un code ascii en base 10
    >>> decoder('97 122 65')
    'azA'
    """
    liste=message.split()
    code=''
    for lettre in liste :
        code=code+chr(int(lettre))
    return code

def coder_cesar(mot):
    """
    le code césar correspond à un décallage d'une lettre
    :param mot:str
    :return code césarde mot (str)
    >>> coder_cesar('ribot')
    'sjcpu'
    >>> coder_cesar('azertYZ')
    'bafsuZA'
    """
    code=''
    for lettre in mot :
        nbr=ord(lettre)+1
        #cas du z
        if nbr==123:
            nbr=97
        #cas du Z
        if nbr==91:
            nbr=65
        new_lettre=chr(nbr)
        code=code+new_lettre
    return code

def decoder_cesar(mot):
    """
    décoder mot pour le code césar
    :param mot:str
    :return : mot décodé (str)
    >>> decoder_cesar('sjcpu')
    'ribot'
    >>> decoder_cesar('azAZ')
    'zyZY'
    """
    code=''
    for lettre in mot :
        nbr=ord(lettre)
        #cas du a
        if nbr==97:
            nbr=122
        #cas du A
        elif nbr==65:
            nbr=90
        
        else:
            nbr=ord(lettre)-1
        #cas des autres lettres
        new_lettre=chr(nbr)
        code=code+new_lettre
    return code
    

import doctest
doctest.testmod()