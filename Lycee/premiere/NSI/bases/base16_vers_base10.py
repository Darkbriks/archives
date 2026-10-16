mot16='0123456789abcdef'
liste16=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']
tuple16=('0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f')
#se renseigner sur index et sur find

def valeur_code(code):
    """
    donner la valeur de code en base 10
    code est un chiffre entre 0 et 9 ou une lettre entre a et f
    si code n'a pas de sens en base 16, retourner -1
    ATTENTION, travailler avec mot16. Utiliser les fonctionnalités des string !!
    param code: str
    return : int
    >>> valeur_code('0')
    0
    >>> valeur_code('a')
    10
    >>> valeur_code('A')
    10
    >>> valeur_code('g')
    -1
    """
    
    code=code.lower()
    return (mot16.find(code))
    
def valeur_codeBis(code):
    """
    donner la valeur de code en base 10
    code est un chiffre entre 0 et 9 ou une lettre entre a et f
    si code n'a pas de sens en base 16, retourner -1
    ATTENTION, travailler avec tupple16. Utiliser les fonctionnalités des tuples !!
    Si on travaille avec liste16, le code est-il différent ?
    param code: str
    return : int
    >>> valeur_codeBis('0')
    0
    >>> valeur_codeBis('a')
    10
    >>> valeur_codeBis('A')
    10
    >>> valeur_codeBis('g')
    -1
    """
    code=code.lower()
    if code in tuple16:
        return tuple16.index(code)
    else:
        return -1  
    
def est_base16(mot):
    """
    dire si mot peut représenter un nombre en  base 16
    >>> est_base16('0')
    True
    >>> est_base16('g012jk')
    False
    >>> est_base16('abzf0')
    False
    """
    
    for lettre in mot:
        if valeur_code(lettre)==-1:
            return False
    return True

def base16_to_base10(mot):
    """
    convertir un nombre écrit en base 16 en base 10
    >>> base16_to_base10('fe')
    254
    >>> base16_to_base10('1a')
    26
    >>> base16_to_base10('g17')
    "mot n'est pas écrit en base 16"
    """
    
    somme=0
    if est_base16(mot):
        for i in range(len(mot)):
            nbr=valeur_code(mot[i])
            somme=nbr*16**(len(mot)-1-i)+somme
        return chr(somme)
    else:
        return "mot n'est pas écrit en base 16"
    
def texte16() :
    newtexte = ''
    texte = ['4c','61','20','43','69','67','61','6c','65','20','65','74','20','6c','61','20',
             '46','6f','75','72','6d','69','0a','0a','4c','61','20','43','69','67','61','6c',
             '65','2c','20','61','79','61','6e','74','20','63','68','61','6e','74','65','0a',
             '54','6f','75','74','20','6c','27','65','74','65','2c','0a','53','65','20','74']
    for i in range(len(texte)) :
        nbr = base16_to_base10(texte[i])
        newtexte = newtexte + nbr
    return newtexte
    
    
#import doctest
#doctest.testmod()