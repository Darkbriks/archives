def sommeListe (liste) :
    somme = 0
    for element in liste :
        somme = somme + element
    return somme

def verifierLigne (carre) :
    a = sommeListe(carre[0])
    for loop in range(1,len(carre)) :
        if a != sommeListe(carre[loop]) :
            return False
    return True

def verifierColone (carre) :
    colone = [[element[a] for element in carre]for a in range(len(carre))]
    
    a = sommeListe(colone[0])
    for loop in range(1,len(colone)) :
        if a != sommeListe(colone[loop]) :
            return False
    return True

def verifierDiagonale (carre) :
    n = len(carre)
    if sommeListe(([carre[loop][loop]for loop in range(n)])) == sommeListe(([carre[loop][-loop]for loop in range(n)])) :
        return True
    return False
        
def tousDifferent(carre):
    new_carre = [carre[loop][loop]for loop in range(len(carre))]
    for i in range(len(new_carre)):
        for i2 in range(len(new_carre)):
            if i != i2:
                if new_carre[i] == new_carre[i2]:
                    return False
    return True

def carre (carre) :
    if verifierLigne(carre) == True and verifierColone(carre) == True and verifierDiagonale(carre) == True and tousDifferent(carre) == True :
        return True
    return False

        
    

