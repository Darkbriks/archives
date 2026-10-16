def longeur1(string, n=0):
    if string=="":
        return n
    return longeur(string[1:], n+1)

def longeur2(string):
    if string=="":
        return 0
    return 1 + longeur(string[1:])

def binaire(n):
    """
    Cette fonction permet de convertir un nombre de la base 10 vers la base 2
    :param n: int positif(0 inclus)
    :param return: str
    >>> binaire(0)
    0
    >>>binaire(255)
    11111111
    """
    assert type(n) == int and n >= 0, "Le nombre n n'est pas valide"
    if n == 0:
        return 0
    return int(str(binaire(n//2)) + str(n%2))

def Un(n):
    if n == 0:
        return 1
    if n == 1:
        return 1
    return 3*Un(n-1) + Un(n-2)

def ex5(n):
    if n<3:
        return 0
    if n==3:
        return 1
    if n==5:
        return 1
    if n==10:
        return 2
    return ex5(n-3) + ex5(n-5) + ex5(n-10)

def jeu(n, l=[3,5,10]):
    if len(l) == 0:
        return 0
    if n < 0:
        return 0
    if n == 0:
        return 1
    return jeu(n-l[0], l)+jeu(n, l[1:])

VALEUR_ROMAIN = { 'M' : 1000, 'D' : 500, 'C' : 100, 'L' : 50, 'X' : 10, 'V' : 5, 'I' : 1}

def romain_to_arabe(n):
    if len(n)==1:
        return VALEUR_ROMAIN[n[0]]
    
    if VALEUR_ROMAIN[n[0]] >= VALEUR_ROMAIN[n[1]]:
        return VALEUR_ROMAIN[n[0]] + romain_to_arabe(n[1:])
    
    if VALEUR_ROMAIN[n[0]] < VALEUR_ROMAIN[n[1]]:
        return romain_to_arabe(n[1:]) - VALEUR_ROMAIN[n[0]]
    
def repartir(liste):
    if liste == []:
        return liste
    return [(liste[0], liste[i])for i in range(1, len(liste))]+repartir(liste[1:])

def chercher(tableau):
    t=[]
    for i in tableau:
        if tableau[i] == 1:
            return i
    return

def propager(t, n):
    chercher(t)