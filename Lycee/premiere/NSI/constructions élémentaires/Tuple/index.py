"""
Réalisez une fonction nommée indice qui renvoie l’indice de la première occurrence de son premier paramètre dans le tuple passé en second paramètre, s’il existe. Par exemple :
indice (1, (3, 10, 4, 1, 5, 9, 2))
doit renvoyer 3
indice (10, (3, 1, 4, 1, 5, 9, 2))
doit renvoyer -1
Si le premier paramètre n’est pas présent, renvoyer -1.
"""
def presence(valeur,mon_tuple):
    if valeur in mon_tuple:
        return True
    return False


def indice(valeur, mon_tuple):
    for i in range(len(mon_tuple)):
        if valeur==mon_tuple[i]:
            return i
    return -1
            