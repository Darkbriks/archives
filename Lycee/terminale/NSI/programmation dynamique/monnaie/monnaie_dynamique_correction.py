from math import inf

euros = [50, 20, 10, 5, 2, 1]
imperial = [30, 24, 12, 6, 3, 1]

def monnaie_recursif(valeursFaciales, somme):
    if somme < 0:
        return inf
    elif somme == 0:
        return 0
    mini = inf
    for x in valeursFaciales:
        if somme >= x:
            mini = min(mini, 1 + monnaie_recursif(valeursFaciales, somme - x))
    return mini

def dynMemoise(valeursFaciales, somme):
    f = [0] * (somme + 1)
    for s in range(1, somme + 1):
        f[s] = inf
        for x in valeursFaciales:
            if s >= x:
                f[s] = min(f[s], 1 + f[s - x])
    return f[somme]

def dynMemoise2(valeursFaciales, somme):
    f,g = [0] * (somme + 1),[0] * (somme + 1)
    for s in range(1, somme + 1):
        f[s] = inf
        for x in valeursFaciales:
            if s >= x and f[s] > 1+f[s-x]:
                f[s], g[s] = 1+f[s-x], s-x
    monnaie, s = [], somme
    while s>0:
        monnaie.append(s-g[s])
        s = g[s]
    return monnaie