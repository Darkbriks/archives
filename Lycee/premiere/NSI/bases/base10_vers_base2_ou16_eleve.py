tuple16=('0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f')

def base10_to_base2 (base10) :
    """
    permet de passer de la base 10 à la base 2
    :param base10 : entier en base 10
    :return : entier en base 2 au format str
    >>> base10_to_base2(5)
    '101'
    >>> base10_to_base2(15)
    '1111'
    """
    base2 = ''
    while base10 >= 2 :
        base2 = str(base10 % 2) + base2 
        base10 = base10 // 2
    base2 = str(base10) + base2 
    return base2
    
    

def base10_to_base16 (base10) :
    """
    permet de passer de la base 10 à la base 16
    :param base10 : entier en base 10
    :return : entier en base 16 au format str
    >>> base10_to_base16(5)
    '5'
    >>> base10_to_base16(15)
    'f'
    >>> base10_to_base16(254)
    'fe'
    """
    base16 = ''
    while base10 >= 16 :
        base16 = tuple16[base10 % 16] + base16 
        base10 = base10 // 16
    base16 = tuple16[base10] + base16 
    return base16



    
#import doctest
#doctest.testmod()