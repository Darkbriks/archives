#initiation aux fonctions

#une première fonction sans paramètre
def compte_a_rebours_auto():
    
    #affiche un compte à rebours à partir de 10
    for k in range(11):
        print(10-k)     
    print("boum")   #sort du for

#second exemple avec un paramètre
def compte_a_rebours(valeurDepart):
    """
    affiche un compte à rebours
    :param valeurDepart: (int) valeur de départ du compte à rebours
    """
    for k in range(valeurDepart) :
        print(valeurDepart-k)
    print('boom')

