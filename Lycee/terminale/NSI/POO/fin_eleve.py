class Warrior:
    def __init__(self, nom,vie, attaque,magique=False):
        self.nom=nom
        self.vie = vie
        self.attaque = attaque
        self.magique = magique

    def get_nom(self):
        """
        retourner le nom
        """
        return self.nom
    
    def get_vie(self):
        """
        retourner la vie
        """
        return self.vie   
    
    def get_attaque(self):
        """
        retourner l'attaque
        """
        return self.attaque
    
    def get_magique(self):
        """
        retourner le magique
        """
        return self.magique
    
    def set_nom(self,x):
        """
        fixer le nom
        """
        if type(x)==str:
            self.nom=x
    
    def set_vie(self,x):
        """
        fixer la vie
        """
        if type(x)==int or type(x)==float:
            self.vie=x
    
    def set_attaque(self,x):
        """
        fixer l'attaque
        """
        if type(x)==int or type(x)==float:
            self.attaque=x
    
    def set_magique(self,x):
        """
        fixer le magique
        """
        if type(x)==bool:
            self.magique=x
    
    def perdre_vie(self, points):
        self.vie = self.vie - points
        if self.vie <= 0:
            self.vie = 0
 
    def attaquer(self, autre):
        """
        on ne peut attquer que si on a un attrubut vie strictement positif
        si on attaque un magicien, vous perdez vos propres points d attaque
        """
        if self.vie<=0:
            return
        if autre.magique==True:
            self.perdre_vie(self.attaque)
        else:
            autre.perdre_vie(self.attaque)
                
    def pacifier(self, autre):
        """
        si un magicien rencontre un warrior qui n'est pas magicien, l'attribut attaque de ce warrior devient nulle
        """
        if self.magique==True and autre.magique==False:
            set_attaque(autre, 0)
        

def trier_vivant(liste,vivant=[]):
    """
    obtenir les warriors vivants de liste, à coder en récursif si possible
    :param liste: list, contient des objets de type Warrior
    :param vivant: liste, éléments de type str
    :return :list, les éléments sont de type str
    """
    if len(liste)==0:
        return liste
    if liste[1].vie>0:
        vivant.append(liste[1].nom)
    return trier_vivant(liste[1:], vivant.append(liste[1].nom))
    
gentil=Warrior('gentil',5,2)
mechant=Warrior('mechant',8,14)
magicien_blanc=Warrior('blanc',5,10,True)
magicien_noir=Warrior('dark',5,20,True)
mort=Warrior('perdu',40,60)
mort.set_vie(0)
gentil.attaquer(mechant)
mechant.attaquer(magicien_blanc)
mort.attaquer(gentil)
liste_warriors=[gentil,mechant,magicien_blanc,mort]