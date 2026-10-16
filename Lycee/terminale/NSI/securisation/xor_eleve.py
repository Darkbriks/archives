texte="Le beau travail fait avec Mr Wozniak! Chouette la NSI !"
texte2="L'été...où est-il, à la mer ? "
secret="NSI"


def chiffrer_xor_iso_latin(msg,clef):
    """
    permet de coder un message avec la méthode xor
    pas d'utilisation d'encodage, on travaille sur les points de code unicode
    :param msg:str, texte à coder
    :param clef: str, clef de codage pour le xor
    :return : str, le texte codé
    >>> code=chiffrer_xor_iso_latin(texte2,secret)
    >>> print(code)
    t :ºg`}&·s,='d'?en³i"2i#6;nli
    >>> chiffrer_xor_iso_latin(code,secret)
    "L'été...où est-il, à la mer ? "
    """
    """code=''
    for i in range(len(msg)):
        code = code + chr(ord(msg[i])^ord(clef[int(i%len(clef))]))
    return code"""
    return "".join([chr(ord(msg[i])^ord(clef[int(i%len(clef))])) for i in range(len(msg))])
    

import doctest
doctest.testmod()
