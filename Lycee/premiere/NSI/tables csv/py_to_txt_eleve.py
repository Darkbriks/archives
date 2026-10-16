from etudiants import *

def copier():
    """
    copier les noms et prenoms de la liste L_ETUDIANTS dans un fichier.txt
    les deux premières lignes du fichier serait du type :
    nom : KANE, prénom : FABIAN
    nom : DIOP, prénom : MAXIME
    """
    #ATTENTION, SI le fichier fichier_eleves.txt n'existe pas, il sera crée
    modif=open('fichier_eleves.txt','a')
    for elt in L_ETUDIANTS :
        modif.write("nom : " + elt["nom"] + ", prénom : " + elt["prenom"] +"\n")
    modif.close()
    
    
"""
Dans le fichier_eleves.txt,
Combien d’étudiants se prénomment-ils ALEXANDRE ? et Camille ?
Combien y a-t-il de prénoms différents parmi tous les étudiants ?
Quel est le ou les prénom(s) le plus fréquent (il peut y avoir des ex aequo)?
"""

def reperer_prenom(prenom):
    """
    permet de savoir combien d'étudiants ont le prénom : prenom,
    dans fichier_eleves.txt
    retourner le nombre d'étudiants ayant le prénom prenom
    retourner 0 s'il n'y a pas de prenom
    """
    f = open('fichier_eleves.txt','r')  
    txt=f.readline()
    compteur=0
    while txt!='':
        if prenom in txt :
            compteur = compteur + 1
        txt=f.readline()
    f.close()
    return compteur
        
            
        
    