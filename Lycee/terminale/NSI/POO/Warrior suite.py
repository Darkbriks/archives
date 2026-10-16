class Prof:
    pass

wozniak=Prof()

class Warrior:
    def __init__(self, vie, attaque, magique=False):
        self.vie = vie
        self.attaque = attaque
        self.magique = magique
        self.vivant = True

    def perdre_vie(self, points):
        self.vie = self.vie - points
        if self.vie <= 0:
            self.vivant = False
            self.vie = 0

    def attaquer(self, autre):
        if self.magique == False:
            autre.perdre_vie(self.attaque)
        
    def attaquer2(self, autre):
        if autre.magique==True:
            self.perdre_vie(self.attaque)
        else:
            autre.perdre_vie(self.attaque)


gentil=Warrior(12,1)
mechant=Warrior(4,5)
magicien=Warrior(20, 12, True)

"""
>>> gentil.attaquer2(mechant)
>>> mechant.attaquer2(magicien)
>>> gentil.vivant
True
>>> mechant.vivant
False
>>> gentil.vie
12
"""