class Prof:
    pass

wozniak=Prof()

class Warrior:
    def __init__(self, vie, attaque):
        self.vie = vie
        self.attaque = attaque
        self.vivant = True

    def perdre_vie(self, points):
        self.vie = self.vie - points
        if self.vie <= 0:
            self.vivant = False
            self.vie = 0

    def attaquer(self, autre):
        autre.perdre_vie(self.attaque)


gentil=Warrior(12,1)
mechant=Warrior(4,5)