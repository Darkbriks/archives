from class_main import*

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
        #assert len(self.plateau)>0, 'le plateau ne peut être vide'
        domino_gauche=self.plateau[0]
        gauche=domino_gauche.gauche
        return gauche
    
    def donner_droite(self):
        """
        donner la valeur à la droite du plateau
        """
        domino_droite=self.plateau[-1]
        droite=domino_droite.droite
        return droite
    
    
    def donner_extremites(self):
        """
        donner les valeurs aux extremités du plateau
        >>> plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
        >>> plateau.donner_extremites()
        (1, 3)
        """
        gauche=self.donner_gauche()
        droite=self.donner_droite()
        return (gauche,droite)
    
      
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
        gauche=False
        droite=False
        (g,d)=self.donner_extremites()
        if g in (domino.droite,domino.gauche):
            gauche=True
        if d in (domino.droite,domino.gauche):
            droite=True
        return (gauche,droite)
    
    
    
    def placer_gauche(self, domino):
        """
        ajouter domino sur la gauche du plateau
        >>> plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
        >>> plateau.placer_gauche(Domino(1,5))
        >>> print(plateau)
        |5-1| |1-0| |0-5| |5-2| |2-3| 
        >>> plateau.placer_gauche(Domino(7,7))
        impossible à gauche
        """

        if self.verifier_ajout(domino)[0]:
            if domino.droite==self.donner_gauche():
                self.plateau=[domino]+self.plateau
            else:
                domino.intervertir1()
                self.placer_gauche(domino)
        else:
            print('impossible à gauche')
    
    def placer_droite(self, domino):
        if self.verifier_ajout(domino)[1]:
            if domino.gauche==self.donner_droite():
                self.plateau=self.plateau+[domino]
            else:
                domino.intervertir1()
                self.placer_droite(domino)      
    
        
if __name__=='__main__':
    plateau=Plateau([Domino(1,0),Domino(0,5),Domino(5,2),Domino(2,3)])
    #print(self.plateau[0])
    print(plateau.donner_extremites())
    plateau.placer_droite(Domino(5,3))
    print(plateau)
    import doctest
    doctest.testmod()
    