#############################################
#Programme type Python                      #
#auteur : Barbier Wozniak                   #
#############################################

#############################################
#définition locale de fonctions


def ajouterMinute(heure,minute):
    """
    ajouter une minute à un temps exprimée en heure et minut
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
    #appel de la fonction ajouter minute et récupérer les valeurs avec new_heure ...
    #new_minute est la valeur de minute+1
    (new_heure,new_minute)=ajouterMinute(heure,minute)
    if new_minute==60:
        new_minute = 0
        new_heure = new_heure + 1
    return(new_heure,new_minute)
        
    
    
  
    
    
def formaterJour(heure,minute):
    """
    ajouter une minute, utiliser la fonction ajouterMinute
    modifier si besoin le nombre d'heures afin de ne pas avoir 24 0
    Si (heure,minute) est le couple (13,45), afficher (13, 46).
    Si (heure,minute) est le couple (23,59), afficher (0,0).
    :param heure:int (nombre d'heure)
    :param minute:int (nombre de minute)
    
    """
    (heure_bis,minute_bis) = formaterHeure(heure,minute)
    if heure_bis == 24 :
        heure_bis = 0
    return(heure_bis,minute_bis)
        
        
        