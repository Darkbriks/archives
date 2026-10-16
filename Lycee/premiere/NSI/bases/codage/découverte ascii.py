##################################################################
#        Découvrir le codage ascii
#        effectuer une recherche sur :
#           - signification de ascii :L'American Standard Code for Information Interchange
#            (Code américain normalisé pour l'échange d'information)
#           - la fonction ord
#           - la fonction chr
##################################################################


def table_ascii_minuscule():
    '''
    donnne la table ascii des lettre minuscule sous la forme : 97  a ;
    :param: none
    '''
    for pas in range(26):
        print(97+pas,' ',chr(97+pas),end=' ; ')
        
def caractere_to_ascii(caractere):
    '''
    donne le code ascii associe a un carcatére
    :param caratere:str
    :effet de bord : affichage d'un message
    '''
    print('pour le caractère ',caractere,', le code ascii, en base 10, est : ', ord(caractere))
    
    
def table_ascii_entier():
    '''
    donner la table ascii, en base 10, pour les entiers de 0 à 9
    '''
    
    for pas in range(10):
        print(48+pas,' ',chr(48+pas),end=' ; ')
        
        
        
def encoder(texte):
    '''
    donner le codage ascii d un texte en base 10
    :param texte:str
    >>> encoder('azAZ')
    [97, 122, 65, 90]
    '''
    newtexte = []
    for pas in range(len(texte)) :
        newtexte.append(ord(texte[pas]))
    print(newtexte)
    
    
def decoder(message):
    """
    donner le texte associé au message, message étant un code ascii en base 10
    conseil : se documenter sur split
    >>> decoder('97 122 65')
    'azA'
    """
    newtexte = []
    for pas in range(len(message)) :
        newtexte.append(chr(message[pas]))
    print(newtexte)
    
def coder_cesar(mot):
    """
    le code césar correspond à un décallage d'une lettre
    :param mot:str
    :return code césarde mot (str)
    >>> coder_cesar('ribot')
    'sjcpu'
    """
    code=''
    for lettre in mot :
        nbr=ord(lettre)+1
        new_lettre=chr(nbr)
        code=code+new_lettre
    return code
    
import doctest
doctest.testmod(verbose=True)
 