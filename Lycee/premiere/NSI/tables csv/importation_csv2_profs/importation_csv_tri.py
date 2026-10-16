import csv
pays = []
#ouverture du fichier 'petite_liste_pays.csv'
with open('petite_liste_pays.csv', newline='') as csvfile:
    #toutes les lignes sont lues et mises dans lignes
    lignes = csv.DictReader(csvfile, delimiter=';')
    for row in lignes:
        #chaque ligne est "ajoutée" au dico
        pays.append(dict(row))

for i in range(6):
    print(pays[i]['name'],pays[i]['area'])
'''
TRIER
Par exemple, si l’on veut trier les pays par leur superficie.
Pour cela, on définit une fonction appropriée.
Elle retournera pour une nation sa superficie
'''

def clef_superficie(p):
    """
    permet de retourner la superficie de p
    p étant un pays de pays
    """
    return p['area']

'''
sort permet de trier, reverse=True : du plus grand au plus petit
sort permet de faire des tris.
Oui, mais on trie comment ? Selon la population , Selon la superficie ?
Pour choisir, nous devons préciser une clef de tri c'est à dire un critère de tri.
Observer avec soin les affichages dans la console, les pays ne sont plus dans le même ordre.
Sont-ils triés dans le bon ordre ???
VOIR importation_csv_tri2.py
'''
pays.sort(key=clef_superficie, reverse=True)
print('liste triée')
for i in range(6):
    print(pays[i]['name'],pays[i]['area'])
liste_tri1=[(p['name'], p['area']) for p in pays]
