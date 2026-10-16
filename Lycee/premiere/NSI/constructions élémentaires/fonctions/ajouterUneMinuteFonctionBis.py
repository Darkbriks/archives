#############################################
#Programme type Python                      #
#auteur : Barbier Wozniak                   #
#############################################

#############################################
#définition locale de fonctions


def ajouterMinute(heure,minute):
    """
    ajouter une minute à un temps exprimé en heure et minute
    :param heure:int (nombre d'heure)
    :param minute:int (nombre de minute)
    """
    minute=minute+1
    return (heure,minute)

def formaterHeure(heure,minute):
    """
    ajouter une minute, utiliser la fonction ajouterMinute
    modifier si besoin le nombre d'heures afin de ne pas avoir 13 60
    Si (heure,minute) est le couple (13,45), le couple sera changé en (13,46).
    Si (heure,minute) est le couple (13,59), le couple sera changé en (14,0).
    :param heure:int (nombre d'heure)
    :param minute:int (nombre de minute)
    """
    minute=minute+1
    if minute > 59 :
        minute = 00
        heure = heure + 1
    return (heure,minute)
    
    
    
    
def formaterJour(heure,minute):
    """
    ajouter une minute,
    modifier si besoin le nombre d'heures afin de ne pas avoir 24 0
    Si (heure,minute) est le couple (13,45), afficher (13,46).
    Si (heure,minute) est le couple (23,59), afficher (0,0).
    :param heure:int (nombre d'heure)
    :param minute:int (nombre de minute)
    
    """
    minute=minute+1
 
    if minute > 59 :
        minute = minute - 60
        heure = heure + 1

    if heure > 23 :
        heure = heure -24
    return (heure,minute)

