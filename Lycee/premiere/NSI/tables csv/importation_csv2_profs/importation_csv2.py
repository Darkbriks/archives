import csv
pays = []
'''
nous allons utiliser DictReader qui retourne un dictionnaire pour chaque enregistrement ou chaque ligne du fichier csv,
la première ligne étant utilisée pour nommer les différents champs.

Documentation sur DictReader :
Crée un objet qui opère comme un lecteur ordinaire mais assemble les informations de chaque ligne dans un dictionnaire
dont les clés sont données par le paramètre optionnel fieldnames.
Le paramètre fieldnames est une séquence.
Si fieldnames est omis, les valeurs de la première ligne du fichier f sont utilisées comme noms de champs.

Dans notre cas, il n'y a pas de fieldnames, c'est la première ligne du fichier qui donnera les clefs des dictionnaires.
Sans se soucier de comment sont déterminés les noms de champs, le dictionnaire préserve leur ordre original.
'''
with open('petite_liste_pays.csv', newline='') as fichier_pays:
    #toutes les lignes sont lues et mises dans lignes
    lignes = csv.DictReader(fichier_pays, delimiter=';')
    for row in lignes:
        #chaque ligne est "ajoutée" sous forme d'un dictionnaire à pays
        pays.append(dict(row))
'''
Cette fois,on obtient un tableau de p-uplets représentés sous forme de dictionnaire.
pays est une liste ou un tableau de dictionnaire.
Pour tous les dictionnaires, les clefs sont les mêmes :
>>> pays[0].keys()
dict_keys(['iso', 'name', 'area', 'population', 'continent', 'currency_code', 'currency_name'])
ou
>>> pays[5].keys()
dict_keys(['iso', 'name', 'area', 'population', 'continent', 'currency_code', 'currency_name'])

Que tapez alors pour obtenir les informations concernant Andorre ?
Que tapez alors pour obtenir le nom officiel d Andorre ?
Que tapez alors pour obtenir la liste des noms des pays ?
Quels sont les pays où l’on paye en dollar ? en euro ??
Quels sont les pays européens où la monnaie n'est pas l'euro?
Donner la superficie totale des pays européens ayant l’euro comme monnaie.

'''
