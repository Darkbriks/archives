def rechercheMinMax(tab):
    dic={'min': None, 'max': None}
    if len(tab)==0:
        return dic
    mi, ma=tab[0], tab[0]
    for element in tab:
        if element < mi:
            mi=element, element
        if element > ma:
            ma=element, element
    dic['min'], dic['max'] = mi, ma
    return dic

class Carte:
    """Initialise Couleur (entre 1 à 4), et Valeur (entre 1 à 13)"""
    def __init__(self, c, v):
        assert 0<=c<=3, 'La couleur est invalide'
        assert 1<=v<=13, 'La couleur est invalide'
        self.Couleur = c
        self.Valeur = v
    """Renvoie le nom de la Carte As, 2, ... 10, Valet, Dame, Roi"""
    def getNom(self):
        if ( self.Valeur > 1 and self.Valeur < 11):
            return str( self.Valeur)
        elif self.Valeur == 11:
            return "Valet"
        elif self.Valeur == 12:
            return "Dame"
        elif self.Valeur == 13:
            return "Roi"
        else:
            return "As"

    """Renvoie la couleur de la Carte (parmi pique, coeur, carreau, trefle"""
    def getCouleur(self):
            return ['pique', 'coeur', 'carreau', 'trefle' ][self.Couleur]

class PaquetDeCarte:
    def __init__(self):
        self.contenu = []

    """Remplit le paquet de cartes"""
    def remplir(self):
        [ [self.contenu.append(Carte(i, j)) for j in range(1, 14, 1)] for i in range(0,4,1)]

    """Renvoie la Carte qui se trouve à la position donnée"""
    def getCarteAt(self, pos):
        assert 1<=pos<=52, "La position n'est pas valide"
        return self.contenu[pos-1]
