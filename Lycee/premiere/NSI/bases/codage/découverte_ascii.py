##################################################################
#        Découvrir le codage ascii
#        effectuer une recherche sur :
#           - signification de ascii
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
    ' 97 122 65 90 '
    '''
    code=' '
    for lettre in texte :
      code=code+str(ord(lettre))+' '
    return code

def decoder(message):
    """
    donner le texte associé au message, message étant un code ascii en base 10
    conseil : se documenter sur split
    >>> decoder('97 122 65')
    'azA'
    """
   
    code = ''
    lettre = ''
    message = message.split()
    for lettre in message :
      code=code+chr(lettre)
    return code
    
def coder_cesar(mot):
    """
    le code césar correspond à un décallage d'une lettre, donner le mot codé pour mot
    attention ce code n'est pas bon à 100%
    :param mot:str
    :return : code césar de mot (str)
    >>> coder_cesar('ribot')
    'sjcpu'
    """
    code=''
    for lettre in mot :
        nbr=ord(lettre)+1
        new_lettre=chr(nbr)
        if new_lettre == '{' :
            new_lettre = 'a'
        code=code+new_lettre
    return code

def decoder_cesar(mot):
    """
    décoder mot pour le code césar
    :param mot:str
    :return : mot décodé (str)
    >>> decoder_cesar('sjcpu')
    'ribot'
    """
    decode_mot = ''
    for lettre in mot :
        nbr = ord(lettre) - 1
        new_lettre=chr(nbr)
        if new_lettre == '`' :
            new_lettre = 'z'
        decode_mot = decode_mot + new_lettre
    return decode_mot
    
import doctest
doctest.testmod(verbose=True)
 