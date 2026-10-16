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



def ajouterMinuteBis(heure,minute):
    minute=minute+1
    while minute > 59 :
        minute = minute - 60
        heure = heure + 1
    return (heure,minute)
