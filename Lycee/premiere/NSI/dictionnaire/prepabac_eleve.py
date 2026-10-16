import math
grand=math.inf
#ou directement float('inf')

spe2 = {"Alain":("Math",13), "Benoit":("Math",11), "Celine":("SES",2), 'Farid':("Anglais",3), "David":("NSI",19),
"Alex":("NSI",20)}

def mauvais(classe):
    '''
    qui a la moins bonne note
    :param classe : dict, de type spe2
    :return : str, nom du mauvais
    >>> mauvais(spe2)
    'Celine'
    '''
    mini = 20
    mauvais = ''
    for eleve in classe :
        if classe[eleve][1] < mini :
            mini = eleve[1]
            mauvais = classe[eleve]
    return mauvais
    
def trier_matiere(classe):
    '''
    trier les notes de chaque spé pour avoir l'ensemble des notes par spé
    retourner un dico matière : liste des notes
    >>> trier_matiere(spe2)
    {'Math': [13, 11], 'SES': [2], 'Anglais': [3], 'NSI': [19, 20]}
    '''
    tri={}
    
def trier_eleve(classe):
    '''
    trier les élèves par spé,  retourner un dico matière : liste des noms
    >>> trier_eleve(spe2)
    {'Math': ['Alain', 'Benoit'], 'SES': ['Celine'], 'Anglais': ['Farid'], 'NSI': ['David', 'Alex']}
    '''
    tri={}
    
    