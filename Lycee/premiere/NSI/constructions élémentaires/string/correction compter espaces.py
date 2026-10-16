def compter1(phrase):
    '''
    compter le nombre d espaces dans une chaîne
    :param phrase:str
    : effet de bord : afficher le nbr d'espace
    '''
    total=0
    for lettre in phrase :
        if lettre==' ':
            total=total+1
    print('espace(s) : ', total)
    print('mot(s) : ', total+1)

def compter2(phrase):
    '''
    compter le nombre d'espaces dans une chaîne
    :param phrase:str
    :return : le nbr d'espaces (int)
    '''
    total=0
    pas=0
    while pas < len(phrase):
        if phrase[pas] == ' ':
            total = total + 1
        pas = pas + 1
    return total

def nombre_mot(phrase):
    nombre_espace=compter2(phrase)
    return nombre_espace+1
    #return compter2(phrase)+1

nombre_mot('toto est grand')

