def signe(code):
    """
    permet de déterminer le signe du nombre binaire donné en paramètre
    :param:(str) représentation binaire d'un entier signé
    :effet de bord: affiche le signe du nombre
    >>> signe('011')
    'positif'
    >>> signe('101')
    'négatif'
    """
    if code[0] == '0' :
        return 'positif'
    return 'négatif'
    
def cp1(code):
    '''
    Renvoie les bits inversés de code
    Entrée : chaîne de caractères d'un code binaire
    Sortie : chaîne de caractères de même longueur
    >>> cp1('110101')
    '001010'
    >>> cp1('01001')
    '10110'
    '''
    new_code = ''
    for loop in range(len(code)) :
        if code[loop] == '1' :
            new_code = new_code + '0'
        if code[loop] == '0' :
            new_code = new_code + '1'
    return new_code
    
    
def cp2(code):
    '''
    fonction qui, en s'appyent sur cp1, transforme un nombre en son oppose.
    si il est positif, elle le transforme en negatif
    si il est negatif, elle le transforme en positif
    :param code: str
    :param return: str
    
    >>> cp2('011')
    '101'
    
    >>> cp2('101')
    '011'
    '''
    j=len(code)#j prend la valeur de la longeur de code
    code_cp1 = cp1(code)#code_cp1 prend la valeur de code apres passage dans la fonction cp1
    retenue = 1#retenue prend la valeur 1
    code_cp2 = ""#on cree un variable code_cp2 de type str
    while j > 0:#tan que j est plus grand que 0, on fait les intruction suivante, ce qui reviens a faire un passage par 
        j=j-1
        if retenue == 1:
            if code_cp1[j] == '0':
                code_cp2 = '1' + code_cp2
                retenue = 0
            else:
                code_cp2 = '0' + code_cp2
        else:
            code_cp2 = code_cp1[j] + code_cp2
    return code_cp2
