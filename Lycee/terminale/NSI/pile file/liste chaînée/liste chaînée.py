from maillon_élève import*

class Liste:
    """
    objet liste chaînée
    """
    #constructeur
    def __init__(self):
        self.tete=None
        
        
    def __len__(self):
        """
        méthode spéciale pour obtenir la longuer de la liste
        """
        return longueur(self.tete)
    
    def est_vide(self):
        """
        voir si la liste est vide
        :param self:Liste
        :return : booleen
        """
        return self.tete is None
    
    
    def __getitem__(self, n):
        """
        obtenir l élément en position n dans la liste chaînée
        """
        return renvoyer_elt_n(self.tete,n)
    
    def ajouter(self,x):
        """
        ajouter en tete de la liste l element x
        """
        self.tete=Maillon(x,self.tete)
        
    def enlever(self):
        """
        enlever élément en tête de liste
        """
        assert self is None, 'liste vide'
        self.tete=self.tete.suivant
        
    def __str__(self):
        return afficher_maillon(self.tete)
    
    def __add__(self,other):
        pass

def last_cellule(maillon):
    """
    retourne la derniere cellule de maillon
    """
    if maillon.suivant.est_vide() == True:
        return maillon
    return last_cellule(Maillon(maillon.suivant))
    
if __name__== '__main__':
    import doctest
    doctest.testmod()
    ma_liste=Liste()
    ma_liste.ajouter(3)
    ma_liste.ajouter(9)
    ma_liste.ajouter(27)
    petite=Liste()
    petite.ajouter(0)
    