def compter1(phrase):
    '''
    cette fonction compte le nombre d'espace d'une chaine de caractére
    :param phrase: str
    
    '''
    total=0
    for lettre in phrase :
        if lettre==' ':
            total=total+1
    print('espace(s)  : ', total)
    

def compter2(phrase):
    '''
     cette fonction compte le nombre d'espace d'une chaine de caractére
    :param phrase: str
    '''
    total=0
    pas=0
    while pas < len(phrase):
        if phrase[pas] == ' ':
            total = total + 1
        pas = pas + 1
    return total

