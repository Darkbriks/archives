import random

def PrenomJoueur1():
    '''
    fonction qui demeande le prenom du premier joueur pour pouvoir l'utiliser par la suite
    :param return: string
    '''
    return str(input("Quel est le prenom du premier joueur"))
    
def PrenomJoueur2():
    '''
    fonction qui demeande le prenom du deuxieme joueur pour pouvoir l'utiliser par la suite
    :param return: string
    '''
    return str(input("Quel est le prenom du second joueur"))

def Initialisation(PrenomJoueur1, PrenomJoueur2):
    '''
    fonction qui detaille les regles du jeu, tire au hasard l'ordre des joueurs et retourne le prenom du premier
    :param PrenomJoueur1: string
    :param PrenomJoueur2: string
    :param return: string
    '''
    print('')#regle a detailler
    if random.randint(0,1) == 0 :
        return PrenomJoueur1
    return PrenomJoueur2
    
    
def ChangerJoueur(JoueurActuel, JoueurSuivant):
    '''
    fonction qui echange les joueurs et qui retourne le prenom du joueur a qui cest le tour de jouer
    :param JoueurPrecedant: string
    :param JoueurSuivant: string
    :param return: string
    '''
    
    
    
def AfficherBaton(situation):
    '''
    fonction qui retourne x fois ' /' (un espace suivit d'un slach), x corresspondant au nombre de batons a afficher
    :param NombreBaton: int
    :param return: string
    
    >>> AfficherBaton(20)
    ' / / / / / / / / / / / / / / / / / / / /'
    
    >>> AfficherBaton(5)
    ' / / / / /'
    '''
    Baton = ""
    for loop in range(situation) :
        Baton = Baton + ' /'
    return Baton
    
    
def ChoixJoueur(JoueurActuel):
    '''
    fonction qui retourne le nombre de baton que le joueur souhaite retirer du jeu
    :param JoueurActuel: string
    :param return: int
    '''
    choix = int(input("Combien de baton",JoueurActuel,"Souhaite t-il retirer"))
    return choix
    
def VerifierChoix(ChoixJoueur, situation):
    '''
    fonction qui verifie que le choix du joueur corresspond a la situation et ne depasse pas 3 .
    Elle retourne true ou false
    :param ChoixJoueur: int
    :param situation: int
    :param return: bool (True ou False)
    
    >>> VerifierChoix(5, 20)
    False
    
    >>> VerifierChoix(3, 2)
    False
    
    >>> VerifierChoix(3, 15)
    True
    '''
    
def RetirerChoix(situation, ChoixJoueur):
    '''
    fonction qui retire le nombre de baton equivalent au choix du joueur et retourne la nouvelle situation
    :param situation: int
    :param ChoixJoueur: int
    :param return: int
    
    >>> RetirerChoix(18, 3)
    15
    
    >>> RetirerChoix(9, 1)
    8
    '''
    
def VerifierDernierBaton(situation):
    '''
    fonction qui retourne true s'il reste un baton ou moin, quand il en reste plusieur, elle retourne false
    :param situation: int
    :param return: bool
    
    >>> VerifierDernierBaton(10)
    False
    
    >>> VerifierDernierBaton(1)
    True
    
    >>> VerifierDernierBaton(0)
    False
    '''
    
def VerifierEgalite(nouvelle_situation, ChoixJoueur):
    '''
    fonction qui retourne true si le joueur a pris plusieur baton, dont le dernier, et qui renvoi false le reste du temp
    :param nouvelle_situation: int
    :param ChoixJoueur: int
    :param return: bool
    
    >>> VerifierDernierBaton(10, 3)
    False
    
    >>> VerifierDernierBaton(1,2)
    false
    
    >>> VerifierDernierBaton(0, 1)
    False
    
    >>> VerifierDernierBaton(0, 2)
    True
    '''

def ArretParti(VerifierDernierBaton, VerifierEgalite):
    '''
    fonction qui retoure true si l'une des deux fonction precedante a retourné true, elle rtourne false le reste du temp
    :param VerifierDernierBaton: bool
    :param VerifierEgalite: bool
    :param return: bool
    
    >>> ArretParti(True, False)
    True
    
    >>> ArretParti(False, True)
    True
    
    >>>ArretParti(False, False)
    False
    '''
    
def AfficherResultat(PrenomJoueurActuel, PrenomJoueurSuivant, VerifierDernierBaton, VerifierEgalite):
    '''
    fonction qui affiche le gagnant si il y en a un ou qui affiche qu'il y a egalité entre les deux joueurs
    :param PrenomJoueurActuel: string
    :param PrenomJoueurSuivant: string
    :param VerifierDernierBaton: bool
    :param VerifierEgalite: bool
    :param return: string
    
    >>> AfficherResultat(Titi, Toto, True, False)
    'Le Gagnant est Titi'
    
    >>> AfficherResultat(Titi, Toto, False, True)
    'Titi et Toto on fait egaliter'
    
    >>> AfficherResultat(Toto, Titi, True, False)
    'Le Gagnant est Toto'
    '''
    
def Jouer():
    '''
    jouer au jeu
    '''
    Joueur_1 = PrenomJoueur1()
    Joueur_2 = PrenomJoueur2()
    Joueur_actuel = Initialisation(Joueur_1,Joueur_2)
    print("Le premiers joueur est",Joueur_actuel)

    
    
    

#import doctest
#doctest.testmod(verbose=True)