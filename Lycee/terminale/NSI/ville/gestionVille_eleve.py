from ville_eleve import *

liste_ville=[]#creation d'une liste vide
fichier=open('villes.txt','r')#creation d'un canal de lecture (r) pour le fichier "villes.txt"
for ligne in fichier:#on boucle sur le nombre de ligne contenu dans "villes.txt"
    liste=ligne.rsplit(" ")#rsplit(" ") premet de separer tout les element separer par un espace pour les mettre dans une liste
    ville=Ville(liste)#creation d'un objet Ville nommer ville, qui contient les information aquise a la ligne precedante
    liste_ville.append(ville)#ajout de l'objet ville dans la liste liste_ville
fichier.close()#fermeture du canal ouvert a la ligne 4

def min_superficie():
    """
    trouver la ville avec la plus petite superficie dans la liste des villes
    >>> min_superficie()
    'Vincennes'
    """
    mini = liste_ville[0]
    for element in liste_ville:
        if element.superficie < mini.superficie:
            mini = element
    return mini.nom

def ville_departement(n):
    """
    donner la liste des noms des villes du département n dans liste_ville
    >>> ville_departement(62)
    ['Lens', 'Calais', 'Boulogne-sur-Mer', 'Arras']
    """
    liste_nom=[]
    for element in liste_ville:
        if element.numero == str(n):
            liste_nom.append(element.nom)
    return liste_nom

def augmenter_ville(villes,p):
    """
    augmenter de p habitants la population de ville
    """
    villes.setPopulation(int(villes.getPopulation())+p)

def augmenter_population(n,p):
    """
    augmenter de p% la population des villes du departement n
    """
    for element in liste_ville:
        if element.numero == str(n):
            element.population = int(element.population * (1+p/100))
            
"""
Question 2:
    Avec la lecture du fichier, les informations seront de quel type pour un attribut de ville ?
        le type des information sera str
"""