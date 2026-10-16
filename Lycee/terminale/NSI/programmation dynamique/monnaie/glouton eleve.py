euros = [50, 20, 10, 5, 2, 1]
imperial = [30, 24, 12, 6, 3, 1]

def glouton(valeursFaciales, somme):
    i = 0 # index de la pièce qu'on va essayer
    p = len(valeursFaciales) # nombre de valeurs de pièces disponibles
    monnaie = [] # liste des pièces rendues
    while i<p and somme>0:
        if valeursFaciales[i]   .......:
            .......
        else:
            monnaie.append(.......)
            somme = ..............
    if somme==0:
        return monnaie
    else:
        return None
    