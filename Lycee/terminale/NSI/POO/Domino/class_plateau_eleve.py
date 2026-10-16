from class_main_eleve import*

class Plateau:
    def __init__(self, plateau):
        self.plateau=plateau
        
    def __str__(self):
        message=''
        for elt in self.plateau:
            message=message+elt.afficher_point()
        return message
    
        
    def donner_gauche(self):
        """
        donner la valeur à la gauche du plateau
        déclencher une assertion dans le cas où le plateau est vide
        >>> plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
        >>> plateau.donner_gauche()
        1
        """
        #assert len(plateau.plateau)>=1
        return plateau.plateau[0].gauche
        
    def donner_droite(self):
        """
        donner la valeur à la droite du plateau
        """
        #assert len(plateau.plateau)>=1
        return plateau.plateau[-1].droite
    
    def donner_extremites(self):
        """
        donner les valeurs aux extremités du plateau
        >>> plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
        >>> plateau.donner_extremites()
        (1, 3)
        """
        assert len(plateau.plateau)>=1
        return (plateau.donner_gauche(), plateau.donner_droite())
      
    def verifier_ajout(self,domino):
        """
        vérifier si on peut ajouter domino au plateau à gauche ou à droite
        :param domino : Domino
        :return :tuple de booléens
        >>> plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
        >>> plateau.verifier_ajout(Domino(1,7))
        (True, False)
        >>> plateau.verifier_ajout(Domino(8,7))
        (False, False)
        >>> plateau.verifier_ajout(Domino(3,7))
        (False, True)
        >>> plateau.verifier_ajout(Domino(1,3))
        (True, True)
        """
        if domino.gauche in self.donner_extremites() and domino.droite in self.donner_extremites():
            return (True, True)
        else:
            if domino.gauche==self.donner_extremites()[0] or domino.droite==self.donner_extremites()[0]:
                return (True, False)
            if domino.gauche==self.donner_extremites()[-1] or domino.droite==self.donner_extremites()[-1]:
                return (False, True)
            return (False, False)
    
    
    def placer_gauche(self, domino):
        """
        ajouter domino sur la gauche du plateau
        >>> plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
        >>> plateau.placer_gauche(Domino(1,5))
        >>> print(plateau)
        |5-1| |1-0| |0-5| |5-2| |2-3| 
        >>> plateau.placer_gauche(Domino(7,7))
        'impossible à gauche'
        """
        if domino.droite==self.donner_gauche():
            self.plateau = [domino] + self.plateau
        if domino.gauche==self.donner_gauche():
            self.plateau = [Domino(domino.droite, domino.gauche)] + self.plateau
        if domino.droite!=self.donner_gauche() and domino.gauche!=self.donner_gauche():
            return 'impossible à gauche'
            
    def placer_droite(self, domino):
        if domino.gauche==self.donner_droite():
            self.plateau = self.plateau + [domino]
        if domino.droite==self.donner_droite():
            self.plateau = self.plateau + [Domino(domino.droite, domino.gauche)]
        if domino.droite!=self.donner_droite() and domino.gauche!=self.donner_droite():
            return 'impossible à droite'
        
if __name__=='__main__':
    plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
    #print(self.plateau[0])
    plateau.donner_extremites()
    import doctest
    doctest.testmod(verbose=False)
    