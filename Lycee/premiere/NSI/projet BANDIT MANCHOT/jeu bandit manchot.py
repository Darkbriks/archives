import random


rouleau_1d = 0
rouleau_2d = 0
rouleau_3d = 0

def tirage_class() :
    """
    fonction qui réalise un tirage aléatoire de trois nombres puis qui les retourne
    :param return: tuple
    """
    rouleau_1d = random.randint(0, 9)
    rouleau_2d = random.randint(0, 9)
    rouleau_3d = random.randint(0, 9)
    return (rouleau_1d, rouleau_2d, rouleau_3d)

def tirage_truque() :
    """
    fonction qui réalise un tirage aléatoire truqué de trois nombres puis qui les retourne
    le 1 a deux foix moins de chance de sortir que les autres nombres
    le 9 a deux fois plus de chance de sortir que les autres nombres
    :param return: tuple
    """
    possibiliter = [0,0,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,9,9]
    rouleau_1d = random.choices(possibiliter)
    rouleau_2d = random.choices(possibiliter)
    rouleau_3d = random.choices(possibiliter)
    return (rouleau_1d, rouleau_2d, rouleau_3d)

def calc_gain(f) :
    """
    fonction qui calcule les gains du joueur à partir de trois nombres choisi aléatoirement
    on choisi si on veut un tirage truqué ou non
    :param f: fonction
    :param return: tuple
    """
    (rouleau) = f
    rouleau_1 = rouleau[0]
    rouleau_2 = rouleau[1]
    rouleau_3 = rouleau[2]
    print('Les résultats des trois rouleaux sont:',rouleau_1,'',rouleau_2,'',rouleau_3)
    gain = 0

    if rouleau_1 == rouleau_2 == rouleau_3 == 1 :
        gain = (250)
        return gain

    if rouleau_1 == rouleau_2 == rouleau_3 == 2 :
        gain = (150)
        return gain

    if rouleau_1 == rouleau_2 == rouleau_3 == 3 :
        gain = (80)
        return gain

    if rouleau_1 == rouleau_2 == rouleau_3 == 4 :
        gain = (50)
        return gain

    if rouleau_1 == rouleau_2 == rouleau_3 == 5 :
        gain = (20)
        return gain

    if rouleau_1 == rouleau_2 == 1 or rouleau_1 == rouleau_3 == 1 or rouleau_2 == rouleau_3 == 1 :
        gain = (5)
        return gain

    if rouleau_1 == 1 or rouleau_2 == 1 or rouleau_3 == 1 :
        gain = (2)
        return gain
    return gain

def afficher_gain_class() :
    """
    fonction qui affiche le gain à partir de trois nombres choisis de manière aléatoire
    le tirage n'est pas truqué
    :param return: int
    """
    (gain_total) = calc_gain(tirage_class())
    print('le gain est:')
    print(gain_total)
    return gain_total

def afficher_gain_truque() :
    """
    fonction qui affiche le gain à partir de trois nombres choisis de manière aléatoire
    le tirage est truqué
    :param return: int
    """
    (gain_total) = calc_gain(tirage_truque())
    print('le gain est:')
    print(gain_total)
    return gain_total



def tirage_10_class() :
    """
    fonction qui affiche le résultat de 10 parties
    :param return: int
    """
    new_gain = []
    total = 0
    for loop in range(10) :
        print('_________________________________________________________________________________')
        print('Tirage n°', loop+1)
        new_gain.append(afficher_gain_class())
        total = total + new_gain[loop]
        print('_________________________________________________________________________________')
    print('Le gain total est:')
    return total

def tirage_10_truque() :
    """
    fonction qui affiche le résultat de 10 parties
    :param return: int
    """
    new_gain = []
    total = 0
    for loop in range(10) :
        print('_________________________________________________________________________________')
        print('Tirage n°', loop+1)
        new_gain.append(afficher_gain_truque())
        total = total + new_gain[loop]
        print('_________________________________________________________________________________')
    print('Le gain total est:')
    return total
        
    