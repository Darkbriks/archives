def hauteur_max_immeuble_rec(liste):
    if len(liste)==0:
        return None
    if len(liste)==1:
        return liste[0][2]
    return max(hauteur_max_immeuble_rec(liste[1:]),liste[0][2])