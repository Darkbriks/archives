############################################################################################################
#S'il vous en faut plus :
#    https://culturemath.ens.fr/thematiques/lycee/voyage-au-coeur-de-la-cryptographie
############################################################################################################

def generer_clefs(a1,b1,a2,b2):
    """
    donne un couple (clef_publique,clef_privée)
    """
    m=int(a1*b1-1)
    e=int(a2*m+a1)
    d=int(b2*m+b1)
    n=int((e*d-1)/m)
    return ((e,n),(d,n))

def chiffrer(msg,clef_pub):
    """
    >>> chiffrer('b',(41,437))
    [85]
    >>> chiffrer('bof, la purée',(41,437))
    [85, 181, 249, 56, 1, 58, 44, 1, 222, 427, 304, 376, 208]
    """
    return [clef_pub[0]*ord(i)%clef_pub[1] for i in msg]
        

def dechiffrer(code,clef_privee):
    """
    >>> dechiffrer([85],(32,437))
    'b'
    >>> dechiffrer([85, 181, 249, 56, 1, 58, 44, 1, 222, 427, 304, 376, 208],(32,437))
    'bof, la purée'
    """
    return ''.join([chr(clef_privee[0]*i%clef_privee[1]) for i in code])

