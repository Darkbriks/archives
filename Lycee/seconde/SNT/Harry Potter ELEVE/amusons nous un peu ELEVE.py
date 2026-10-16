def est_dans_Harry_Potter(nom):
    """
    Cette fonction a une variable.
    Elle permet de lire le fichier liste.txt,
    elle a pour but de vérifier si un nom est bien cité dans la saga.
    Il faudra donc afficher présent si le personnage est cité
    """
    with open("liste.txt",'r') as texte:
        ligne=texte.readline()
        while ligne!='':
            #testons si la chaine de caractéres nom est présent dans ligne
            if nom in ligne:
                print('present')
            ligne=texte.readline()
    texte.close()
            
def est_dans_Harry_Potter_bis(nom):
    """
    Cette fonction a une variable.
    Elle permet de lire le fichier liste.txt,
    elle a pour but de vérifier si un nom est bien cité dans la saga.
    Il faudra donc afficher présent ou non présent
    """
    with open("liste.txt",'r') as texte:
        ligne=texte.readline()
        while ligne!='':
            #testons si la chaine de caractéres nom est présent dans ligne
            if nom in ligne:
                return 'présent'
            ligne=texte.readline()
    texte.close()
    return 'absent'


def xxxxx(nom):
    with open("liste.txt",'r') as texte:
        ligne=texte.readline()
        while ligne!='':
            #testons si la chaine de caractéres nom est présent dans ligne
            if nom in ligne:
                print(ligne)
            ligne=texte.readline()
    texte.close()
            
