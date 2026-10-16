from class_domino import*

class Main:
    def __init__(self, main):
        """
        construire une main de domino, self.main est une liste de Domino 
        """
        self.main=main
        
    def __str__(self):
        message=''
        for elt in self.main:
            message=message+elt.afficher_point()
        return message
    
    def __len__(self):
        """
        redefinir le comportement de la fonction len pour une instance de la classe Main
        sans cette méthode, on ne peut utiliser la fonction len, on aurait un message d'erreur
        avec cette méthode, le code pour la méthode est vide est plus simple
        """
        return len(self.main)
    
    def __add__(self,other):
        """
        redéfinir l'addition pour deux mains 
        >>> main1=Main([Domino(5,1),Domino(6,2)])
        >>> main2=Main([Domino(2,2),Domino(3,3)])
        >>> s=main1+main2
        >>> print(s)
        |5-1| |6-2| |2-2| |3-3| 
        >>> s2=main2+main1
        >>> print(s2)
        |2-2| |3-3| |5-1| |6-2| 
        """
        liste=self.main+other.main
        return Main(liste)
        
    def ajouter_domino(self,domino):
        """
        ajouter un objet de type Domino à un objet de type Main
        """
        self.main.append(domino)

    def enlever_domino(self,i):
        """
        enlever le ième domino à la main et retourner ce domino
        >>> main=Main([Domino(1,0),Domino(3,5),Domino(4,2),Domino(3,3)])
        >>> domino=main.enlever_domino(1)
        >>> print(main)
        |1-0| |4-2| |3-3| 
        >>> domino.afficher_point()
        '|3-5| '
        """
        self.main = [self.main[:i],self.main[i:]]
           
    def est_vide(self):
        '''
        voir si la main est vide
        >>> Main([Domino(1,6),Domino(5,5)]).est_vide()
        False
        >>> d1=Main([])
        >>> d1.est_vide()
        True
        '''
        if len(self)>0:
            return False
        return True
        
            
    def avoir_double_i(self,i):
        """
        vérifier si dans la main on a le domino double i
        >>> Main([Domino(1,6),Domino(5,5)]).avoir_double_i(3)
        False
        >>> Main([Domino(1,6),Domino(5,5)]).avoir_double_i(5)
        True
        """
        for domino in self.main:
            if domino.est_double(i) == True:
                return True
        return False
    
    def avoir_i(self,i):
        """
        voir si l'un des dominos de main a le nombre i
        >>> Main([Domino(1,6),Domino(5,5)]).avoir_i(2)
        False
        >>> Main([Domino(1,6),Domino(2,5)]).avoir_i(2)
        True
        """
        for domino in self.main:
            if domino.g==i or domino.d==i:
                return True
        return False
        
    def est_compatible(self, domino):
        '''
        voir si on peut ajouter un domino de main à gauche ou à droite de domino
        '''
        for d in self.main:
            if d.droite==domino.gauche or d.droite==domino.droite:
                return True
        return False
    
    
    
if __name__== '__main__':
    main=Main([])
    (self.main).append(Domino(3,7))
    self.main=self.main+[Domino(4,6),Domino(5,5)]
    main=Main([Domino(1,6),Domino(5,5)])
    main.ajouter_domino(Domino(2,4))
    print(main)
    main.enlever_domino(1)
    print(main)
    main=Main([Domino(1,0),Domino(3,5),Domino(4,2),Domino(3,3)])
    print(main)
    import doctest
    doctest.testmod()