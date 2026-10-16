def compter1(phrase):
    '''
    cette fonction compte le nombre d'espace d'une chaine de caractére
    il y a un effet de bord et pas de return
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
    il y a un return
    :return : le nombre d'espace(int)
    :param phrase: str
    '''
    total=0
    pas=0
    while pas < len(phrase):
        if phrase[pas] == ' ':
            total = total + 1
        pas = pas + 1
    return total

def compter_mot(chaine) :
    espace = compter2(chaine)
    return espace+1
    
# ou

def compter_mot_bis(chaine) :
    return compter2(chaine)+1
    






