'''
jeu de morpion
'''
import random

def initialisation():
    '''
    afficher la situation de départ
    présentation du jeu, de la version numérisée
    choix au hasard si 'x' ou'o' commence 
    '''
    PrenomJoueur1 = str(input("Quel est le prenom du joueur ayant choisi les croix ?"))
    PrenomJoueur2 = str(input("Quel est le prenom du joueur ayant choisi les cercles ?"))
    
    joueur1 = random.randint(0,1)
    if joueur1 == 0 :
        joueur1 = 'x'
        joueur2 = 'o'
        print('le premier joueur est',PrenomJoueur1,'qui a choisi les croix')
    else :
        joueur1 = 'o'
        joueur2 = 'x'
        print('le premier joueur est',PrenomJoueur2,'qui a choisi les cercles')
    return joueur1

def afficher_grille(liste):
    """
    affiche la grille de jeu
    :param liste:(list) liste de 9 éléments correspondant au contenu
    des cases de liste
    pour le départ, afficher :
    0 | 1 | 2
    --|---|--
    3 | 4 | 5
    --|---|--
    6 | 7 | 8
    
    pour la liste ['x','o','x','o',4,5,6,7,8], afficher :
    x | o | x
    --|---|--
    o | 4 | 5
    --|---|--
    6 | 7 | 8
    
    :effet de bord:affichage de la grille
    """
    for ligne in range(3):
        texte=""
        for colonne in range(3):
            texte=texte+str(liste[3*ligne+colonne])
            if colonne<2:
                texte=texte+" | "
        print(texte)
        if ligne<2:
            print("--|---|--")
    
def choix_joueur():
    '''
    demander le numéro de la case choisie par le joueur
    '''
    case = int(input('quelle case choisissez-vous ?'))
    return case

def changer_symbole(symb):
    """
    permet de passer du symbole de la croix au rond ....
    :param: symb(str)
    >>> changer_symbole('o')
    'x'
    >>> changer_symbole('x')
    'o'
    """
    if symb == 'o' :
        symb = 'x'
    else :
        symb = 'o'
    return symb
    
def verifier_choix(situation,numero):
    """
    verifier si le choix du joueur est possible
    :param: situation(list)
    :param: numero(int)
    
    >>> verifier_choix([0,'x',2,3,4,5,6,7,8],3)
    True
    >>> verifier_choix(['o','x','o','x','x','o',6,7,8],5)
    False
    """
    
    for crt in situation :
        if numero == crt and numero <=8:
            return True
    return False
    
def placer_choix(situation,numero,symbole):
    """
    permet de placer le symbole du joueur au numero choisi
    :param: situation(list)
    :param: numero(int)
    :param: symbole(str)
    
    >>> placer_choix([0,'x',2,3,4,5,6,7,8],3,'o')
    [0, 'x', 2, 'o', 4, 5, 6, 7, 8]
    >>> placer_choix(['o','x','o','x','x','o',6,7,8],8,'x')
    ['o', 'x', 'o', 'x', 'x', 'o', 6, 7, 'x']
    """
    
    situation[numero] = symbole
    return situation
    

def verifier_ligne(situation):
    """
    permet de savoir s'il y a un gagnant sur une ligne
    :param: situation(list)
    return: true si gagnant false sinon
    >>> verifier_ligne(['x','x',2,'o','o','o',6,7,'x'])
    True
    >>> verifier_ligne(['x','x',2,'o','x','o',6,7,'o'])
    False
    """
    
    for loop in range(3) :
        if situation[3*loop] == situation[3*loop+1] == situation[3*loop+2] :
            return True
    return False
    
def verifier_colonne(situation):
    """
    permet de savoir s'il y a un gagnant sur une colonne
    :param: situation(list)
    return: true si gagnant false sinon
    >>> verifier_colonne([0,'x',2,'o','x','o',6,'x',8])
    True
    >>> verifier_colonne([0,'x',2,'o','x','o',6,7,'o'])
    False
    """
    
    for loop in range(3) :
        if situation[loop] == situation[loop+3] == situation[loop+6] :
            return True
    return False
    
    
def verifier_diagonale(situation):
    """
    permet de savoir s'il y a un gagnant sur une diagonale
    :param: situation(list)
    return: true si gagnant false sinon
    >>> verifier_diagonale(['x','o',2,'o','x','o','o',7,'x'])
    True
    >>> verifier_diagonale(['x',1,'o',3,'o',5,'o',7,'x'])
    True
    >>> verifier_diagonale([0,'o',2,'x','0','o',6,7,'x'])
    False
    """
    for loop in range(2) :
        if situation[2*loop] == situation[4] == situation[8-(2*loop)] :
            return True
    return False
    
def verifier_gagné(situation):
    """
    permet de savoir s'il y a un gagnant sur la grille
    :param: situation(list)
    return: true si gagnant false sinon
    >>> verifier_gagné(['x','o',2,'o','x','o','o',7,'x'])
    True
    >>> verifier_gagné(['w','o',2,'o','x','o','o',7,'x'])
    False
    >>> verifier_gagné(['x','o',2,3,'o','x',6,'o','x'])
    True
    >>> verifier_gagné(['x','x','x',3,'o',5,'o',7,'o'])
    True
    >>> verifier_gagné([0,'o',2,'x','0','o',6,7,'x'])
    False
    """
    if verifier_colonne(situation) or verifier_diagonale(situation) or verifier_ligne(situation) == True :
        return True
    return False
    
    
def afficher_gagnant(situation,symbole):
    """
    permet de voir le symbole qui a gagné ou s'il y a match nul
    :param: situation(list)
    return: 'o' si 'o' a gagné, 'x' si 'x' a gagné , sinon 'égalité
    >>> afficher_gagnant(['x','o',2,'o','x','o','o',7,'x'],'x')
    'x'
    >>> afficher_gagnant(['x','o',2,3,'o','x',6,'o','x'],'o')
    'o'
    """
    if verifier_gagné(situation) == False :
        return 'égalité'
    return symbole
    
    

def verifier_pleine(situation):
    """
    voir si la grille est pleine
    :param: situation(list)
    return: true si gagnant false sinon
    >>> verifier_pleine(['x','o','x','o','x','o','o','o','x'])
    True
    >>> verifier_pleine(['o','o',2,'o','x','o','o',7,'x'])
    False
    """
    GrilleVierge = [0,1,2,3,4,5,6,7,8]
    
    for loop in range(9) :
        if situation[loop] == GrilleVierge[loop] :
            return False
    return True
    

def est_fini(situation):
    '''
    voir si le jeu est fini car il y a un gagnant ou car la grille est pleine
    :param: situation(list)
    return: true si fini, false sinon
    >>> est_fini(['x','o','x','o','x','o','o','o','x'])
    True
    >>> est_fini(['o','o',2,'o','x','o','x',7,'x'])
    False
    >>> est_fini(['o','o','x','x','x','o','o','o','x'])
    True
    '''
    if verifier_gagné(situation) or verifier_pleine(situation) == True :
        return True
    return False
    
    
def jouer():
    """
    jouer au jeu
    """
    situation = [0,1,2,3,4,5,6,7,8]
    symb = initialisation()

    while est_fini(situation) == False :
        afficher_grille(situation)
        print("C'est au tour des",symb,"de jouer")
        numero = choix_joueur()
        while verifier_choix(situation,numero) == False :
            print('choix incorrect, donner une nouvelle case')
            numero = choix_joueur()
            verifier_choix(situation,numero)
        situation = placer_choix(situation,numero,symb)
        est_fini(situation)
        if est_fini(situation) == True :
            afficher_grille(situation)
            if afficher_gagnant(situation,symb) == 'égalité' :
                print("Il n'y a pas de gagnant,vous avez fait égalité")
                return 'PARTIE TERMINEE'
            print("Le gagnant est le joueur qui a choisi les",symb,", Bravo a lui !")
            return 'PARTIE TERMINEE'
        symb = changer_symbole(symb)
        
        
import doctest
doctest.testmod(verbose=True)
