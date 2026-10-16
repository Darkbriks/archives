class Noeud:
    def __init__(self, valeur, gauche, droit):
        self.r = valeur
        self.g = gauche
        self.d = droit
    
class ArbreBinaire:
    def __init__(self, c):
        """
        permet de créer un arbre, n est de type Noeud ou None
        """
        self.n = c

    def est_vide(self):
        """
        renvoie True si l'arbre est vide, sinon renvoie False (si n est differant de None)
        """
        return self.n is None
    
    def get_racine(self):
        """
        renvoie la racine d'un arbre non-vide
        """
        assert not(self.est_vide()), 'Arbre vide'
        return self.n.r
    
    def get_sag(self):
        """
        renvoie le sous arbre gauche d'un arbre non vide
        """
        assert not(self.est_vide()), 'Arbre vide'
        return self.n.g
    
    def get_sad(self):
        """
        renvoie le sous arbre droit d'un arbre non vide
        """
        assert not(self.n is None), 'Arbre vide'
        return self.n.d

    def afficher(self, tab=0):
        espace=" "*tab
        if not(self.est_vide()):
            print(espace,self.n.r)
        if not(self.n.g.est_vide()):
            self.n.g.afficher(tab+2)
        if not(self.n.d.est_vide()):
            self.n.d.afficher(tab+2)