import csv
arbres = []
with open('arbres.csv', newline='') as csvfile:
    lignes = csv.DictReader(csvfile, delimiter=';')
    for row in lignes:
        arbres.append(dict(row))
        
'''
Calculer ensuite la hauteur moyenne des arbres
'''
def est_viel(arbre):
    """
    déterminer si un arbre a été planté avant 1800 ou si la date de plantation n'est pas connue
    >>> est_viel(arbres[8])
    True
    >>> est_viel(arbres[0])
    False
    >>> est_viel(arbres[26])
    True
    """
    if arbre['PLANTATION'] == "" or float(arbre['PLANTATION']) < 1800 :
        return True
    return False

def lister_vieux():
    '''
    obtenir la liste des vieux arbres de paris
    cette liste donnera les couples( gps, année de plantation)
    '''
    liste_vieux_arbres = []
    for a in arbres :
        if est_viel(a) == True :
            liste_vieux_arbres.append({a['GEOPOINT'] : a['PLANTATION']})
    return liste_vieux_arbres
    
    
def denombrer_especes():
    """
    obtenir la liste des différentes espèces d'arbres et l'effectif pour une espèce
    quel type de variable faut il envisager ?
    """
    liste_espece = {}
    for a in arbres :
        if a['ESPECE'] in liste_espece :
            liste_espece[a['ESPECE']] = liste_espece[a['ESPECE']] + 1
        else :
            liste_espece[a['ESPECE']] = 1
    return liste_espece

def moyenne() :
    """
    Calcule la hauteur moyenne des arbres
    """
    moyenne = 0
    for a in arbres :
        if a['HAUTEUR'] != '' :
            moyenne = (moyenne + float(a['HAUTEUR'])) / 2
    return moyenne
    
    
    
    
    
    
import doctest
doctest.testmod()