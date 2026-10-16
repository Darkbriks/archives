class Ville :
    def __init__(self,carateristique_ville):
        self.nom=carateristique_ville[0]
        self.numero=carateristique_ville[1]
        self.population=carateristique_ville[2]
        self.superficie=carateristique_ville[3]
        self.rang=carateristique_ville[4]

    def getRang(self):
        """
        donner le rang d'une ville
        >>> versailles=Ville(['Versailles',78,85761,26.2,46])
        >>> versailles.getRang()
        46
        """
        return self.rang
        
    def getSuperficie(self):
        """
        donner la superficie d'une ville
        >>> versailles=Ville(['Versailles',78,85761,26.2,46])
        >>> versailles.getSuperficie()
        26.2
        """
        return self.superficie

    def getPopulation(self):
        """
        donner la population d'une ville
        >>> versailles=Ville(['Versailles',78,85761,26.2,46])
        >>> versailles.getPopulation()
        85761
        """
        return self.population
        
    def afficherNom(self):
        print(self.nom)
        
    def setPopulation(self,p):
        """
        fixer l'attribut poupulation à la valeur p
        >>> versailles=Ville(['Versailles',78,85761,26.2,46])
        >>> versailles.setPopulation(92701)
        >>> versailles.getPopulation()
        92701
        """
        assert type(p)==int,"p est invalide"
        self.population = p

    def getDepartement(self):
        """
        >>> versailles=Ville(['Versailles',78,85761,26.2,46])
        >>> versailles.getDepartement()
        78
        """
        return self.numero
        
    def getNom(self):
        """
        obtenir le nom de la ville
        """
        return self.nom
        
    def afficherVille(self):
        """
        afficher les renseignements d'une ville
        >>> ouve=Ville(['Ouve',62,450,1.32,10000001])
        >>> ouve.afficherVille()
        nom Ouve
        département : 62, population:450, superficie:1.32 km²
        """
        print("nom {}\ndépartement : {}, population:{}, superficie:{} km²".format(self.nom, self.numero, self.population, self.superficie))
        
    def comparerSuperficie(self,other):
        """
        comparer les superficies de deux villes
        renvoyer True si la superficie de self est plus petite que other
        >>> ouve=Ville(['Ouve',62,450,1.32,10000001])
        >>> versailles=Ville(['Versailles',78,85761,26.2,46])
        >>> ouve.comparerSuperficie(versailles)
        True
        >>> versailles.comparerSuperficie(ouve)
        False
        """
        if self.superficie < other.superficie :
            return True
        return False


if __name__ == '__main__':
    import doctest
    doctest.testmod()
    