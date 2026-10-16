import csv
pays = []

with open('petite_liste_pays.csv', newline='') as csvfile:
    lignes = csv.DictReader(csvfile, delimiter=';')
    for row in lignes:
        pays.append(dict(row))
'''
Par exemple, si l’on veut trier les pays par leur superficie,
on doit spécifier la clé 'Area'.
Pour cela, on définit une fonction appropriée.
'''
def clef_superficie2(p):
    return float(p['area'])

pays.sort(key=clef_superficie2, reverse=True)
liste_tri2=[(p['name'], p['area']) for p in pays]

'''
A Faire : obtenir la liste des pays par ordre croissant de la population, puis par odre décroissant de la population

Tri selon plusieurs critères
Supposons maintenant que l’on veut trier les pays selon deux critères :
tout d’abord le continent, puis le nom du pays.
On peut faire cela en définissant une fonction de clé
qui renvoie une paire (continent, pays).
A FAIRE : coder cette fonction clé_combinée.
Que permet-elle d'obtenir ?
A FAIRE : définir une fonction pour obtenir la liste des pays triés par continent dans l'ordre alphabétique
A FAIRE : obtenir la liste des pays triés par continent par ordre croissant de la population
'''
def cle_combinee_1(p) :
    """
    :param pays: dictionnaire de la liste pays
    :param return: tuple avec le nom du continent et le nom du pays
    """
    return (p['continent'], p['name'])

pays.sort(key=cle_combinee_1)
liste_tri_combinee_1 = [(p['continent'], p['name']) for p in pays]

def cle_combinee_2(p) :
    """
    :param pays: dictionnaire de la liste pays
    :param return: tuple avec le nom du continent et la population
    """
    return (p['continent'], float(p['population']))

pays.sort(key=cle_combinee_2)
liste_tri_combinee_2 = [(p['continent'], p['name'], p['population']) for p in pays]



