# lancer tri_fusion avec un tableau d'éléments

def fusion(gauche,droite):
    resultat = []
    index_gauche, index_droite = 0, 0
    #fusion des 2 parties tant qu'une l'une n'est pas vide
    while index_gauche < len(gauche) and index_droite < len(droite):        
        if gauche[index_gauche] <= droite[index_droite]:
            resultat.append(gauche[index_gauche])
            index_gauche = index_gauche+1
        else:
            resultat.append(droite[index_droite])
            index_droite = index_droite+1
    
    #ajout du reste de la sous-partie non vidée
    if gauche:
        resultat.extend(gauche[index_gauche:])
    if droite:
        resultat.extend(droite[index_droite:])
    
    return resultat
     
def decoupage(m):
    #situation d'arrêt
    if len(m) <= 1:
        return m
    #découpage de tableau
    milieu = len(m) // 2
    gauche = m[:milieu]
    droite = m[milieu:]
    gauche = decoupage(gauche)
    droite = decoupage(droite)
    return fusion(gauche, droite)

def tri_fusion(m):
    return decoupage(m)
A = [23, 12, 4, 56, 35, 32, 42, 57, 3]