def taille(arbre, lettre):
    if arbre[lettre][0] == "" and arbre[lettre][1] == "":
        return 1
    if arbre[lettre][0] != "" and arbre[lettre][1] == "":
        return 1 + taille(arbre, arbre[lettre][0])
    if arbre[lettre][0] == "" and arbre[lettre][1] != "":
        return 1 + taille(arbre, arbre[lettre][1])
    return 1 + taille(arbre, arbre[lettre][0]) + taille(arbre, arbre[lettre][1])
    

"""def tri_iteratif(tab):
    for k in range( ... , 0, -1):
        imax = ...
        for i in range(0 , ... ):
            if tab[i] > ... :
                imax = i
        if tab[max] > ... :
            ... , tab[imax] = tab[imax] , ...
    return tab"""

a = {'F':['B','G'], 'B':['A','D'], 'A':['',''], 'D':['C','E'],'C':['',''], 'E':['',''], 'G':['','I'], 'I':['','H'],'H':['','']}