class Domino:
    """
    La classe Domino.
    On utilise une majuscule pour définir la classe
    La définition de la classe se terminera quand on reviendra à l indentation de départ.
    Pas besoin de parenthése.
    dans le shell, tapez Domino puis Type(Domino)
    création d un attribut de classe, la variable point est communes à toutes les instances
    la valeur d un point de domino est de 0,50 euros
    la variable de classe "point" sera communes pour toutes les instances
    """
    point=0.50
    def __init__(self, g=0,d=0):
        """
        on définit une méthode, self est toujours le premier paramètre, self est obligatoire
        self désigne l'objet lui même
        __init__ est une méthode spéciale appelée constructeur
        elle permet de créer un objet de type domino : instanciation d'un domino de la classe Domino
        le double __ est réservé aux "magic method"
        les deux lignes suivantes définissent deux attributs d'instances
        ces deux variabes d'instances seront spécifiques à chaque instance
        la valeur à gauche ou à droite d'un domino peut varier
        elles ont des valeurs par défaut : 0 pour les deux
        """
        self.gauche=g
        self.droite=d
        
    def __str__(self):
        """
        de nouveau une magic méthod avec les doubles _
        elle permet de redefinir le fonctionnement de la fonction print pour un objet domino
        tenter un print(domino) , effet garanti
        """
        #message='---------\n| '+str(self.gauche)+' | '+str(self.droite)+' |\n---------'
        message='---------\n| {} | {} |\n---------'.format(str(self.gauche),str(self.droite))
        return message
            
    
    def afficher_point(self):
        """
        une autre méthode, self est toujours le premier paramètre, self est obligatoire
        dans la classe, on utilise self.chose pour accéder à un attribut
        cette méthode est différente de __str__
        le résultat retourné avec la méthode __str__ n'est pas utilisable dans d'autres méthodes
        avec afficher_point, on pourra se servir du renvoi
        """
        return '|'+str(self.gauche)+'-'+str(self.droite)+'|'
        
    def valeur(self):
        """
        valeur en euro du domino
        """
        print('valeur du domino : ',(self.gauche+self.droite)*self.point)
        
    def est_double(self,i):
        """
        une autre méthode,self est obligatoire en premier paramètre
        i est un deuxième paramètre
        >>> Domino(3,4).est_double(3)
        False
        >>> Domino(3,3).est_double(3)
        True
        >>> Domino(4,4).est_double(3)
        False
        """
        if self.gauche==i and self.droite==i:
            return True
        return False
        
    
    def f1(self):
        """
        permet de faire "pivoter" le domino a 180 degres
        ainsi, si on a le domino 5 | 1, on obtiendra le domino 1 | 5
        """
        temp=self.gauche
        self.gauche=self.droite
        self.droite=temp
        
    def f2(self):
        """
        permet de faire "pivoter" le domino a 180 degres
        ainsi, si on a le domino 5 | 1, on obtiendra le domino 1 | 5
        """
        self.gauche=self.gauche+self.droite
        self.droite=self.gauche-self.droite
        self.gauche=self.gauche-self.droite

d1=Domino(3,1)
d2=Domino(2,6)
d3=Domino(1,1)
   
if __name__== '__main__':
    import doctest
    doctest.testmod(verbose=True)
    #doctest.testmod()
    
        
    
        
        
        