import csv
liste_dico_pays = []

with open('pays.csv', newline='') as csvfile:
    spamreader = csv.DictReader(csvfile, delimiter=';')
    for row in spamreader:
        liste_dico_pays.append(dict(row))


#quels sont les liste_dico_pays où le nom de la monnaie est dollar ?
zone_dollar= [p['name'] for p in liste_dico_pays if p['currencyName'] == 'Dollar']
#quels sont les liste_dico_pays européens où la monnaie n'est pas l'euro?
eu_and_non_euro=[p['name'] for p in liste_dico_pays if p['currencyName'] != 'Euro' and p['continent']=='EU']
#somme de 2 populations
pop=int(liste_dico_pays[1]['population'])+int(liste_dico_pays[2]['population'])
#population en europe
population=0
for p in liste_dico_pays:
    if p['continent']=='EU':
        population=population+int(p['population'])
print(population)