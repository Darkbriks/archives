def entiers_it(n):
    s=0
    for i in range(n+1):
        s=s+i
    return s

#version récursive
def entier_rec(n):
    #arrêt pour n nul
    if n==0:
        return 0
    else:
        return n+entier_rec(n-1)
    #la terminaison est vérifiée car n-1<n,
    #on est de plus en plus proche de l'arrêt