import csv
pays = []
'''
nous allons utiliser DictReader qui retourne un dictionnaire pour chaque enregistrement,
la première ligne étant utilisée pour nommer les différents champs1.
'''
with open('petite_liste_pays.csv', newline='') as csvfile:
    spamreader = csv.DictReader(csvfile, delimiter=';')
    for row in spamreader:
        pays.append(dict(row))
'''
liste pays, voir http://www.geonames.org
tri : https://docs.python.org/fr/3/howto/sorting.html
Cette fois,on obtient un tableau de p-uplets représentés sous forme de dictionnaire.
Que tapez alors pour obtenir les informations concernant Andorre ?

Que tapez alors pour obtenir le nom officiel d Andorre ?
pays[0]['name']

Que tapez alors pour obtenir la liste des noms des pays ?
for nation in pays :
    print(nation['name'])
ou
>>> [p['name'] for p in pays]
'''

#quels sont les pays où l’on paye en dollar ?
zone_dollar= [p['name'] for p in pays if p['currency_code'] == 'XCD']

#ou pour l'euro
zone_euro=[]
for nation in pays:
    if nation['currency_code']=='EUR':
        zone_euro.append(nation['name'])
#Quels sont les pays européens où la monnaie n'est pas l'euro?
liste=[p['name'] for p in pays if p['currency_code'] != 'EUR' and p['continent']=='EU']
#Donner la superficie totale des pays européens ayant l’euro comme monnaie.
superficie=0
for nation in pays:
    if nation['currency_code']=='EUR':
        superficie= superficie+float(nation['area'])