#implémentation d'une file en utilisant une list Python

class File:
    
    def __init__(self):
        """permet de créer une file vide"""
        self.valeurs=[]
        
    def est_vide(self):
        """permet de savoir si la file est vide ou non"""
        return self.valeurs==[]
        
    def enfiler(self,x):
        """permet d'ajouter un élément en queue de la file
        :param x: élément à ajouter
        """
        return self.valeurs.append(x)
    
    def defiler(self):
        """enlève et renvoie l'élément qui est en tête de la file"""
        if self.valeurs:
            return self.valeurs.pop(0)
    
    def __str__(self):
        """permet d'obtenir un visuel de la file avec  print"""
        file="Tête"
        for elt in self.valeurs:
            file=" {} ".format(elt)+file
        return "Queue"+file

def donner_2(file):
    if file.est_vide():
        return False
    else:
        t=file.defiler()
        if file.est_vide():
            return False
        else:
            second=file.defiler()
    file.enfiler(t)
    return second
    
def copier(file):
    copie1=File()
    copie2=File()
    while not file.est_vide():
        elt=file.defiler()
        copie1.enfiler(elt)
    while not copie1.est_vide():
        elt=copie1.defiler()
        file.enfiler(elt)
        copie2.enfiler(elt)
    return copie2


def first_last(f):
    """ Échange la tête et la queue"""
    # On défile
    tete = f.defiler()
    f2 = File()
    while not f.est_vide():
        queue = f.defiler()
        f2.enfiler(queue)
    # On enfile queue en tête de f
    f.enfiler(queue)
    x=f2.defiler()
    while not f2.est_vide():
        f.enfiler(x)
        x = f2.defiler()
    f.enfiler(tete)

def donner_max(f):
    file=copier(f)
    if file.est_vide():
        return False
    else:
        maxi=file.defiler()
        while not file.est_vide():
            valeur=file.defiler()
            if valeur>maxi:
                maxi=valeur
    return maxi

def placer_max(file):
    maxi=donner_max(file)
    copie=File()
    maximum=File()
    while not file.est_vide():
        elt=file.defiler()
        if elt==maxi:
            maximum.enfiler(elt)
        else:
            copie.enfiler(elt)
    while not copie.est_vide():
        elt=copie.defiler()
        file.enfiler(elt)
    while not maximum.est_vide():
        elt=maximum.defiler()
        file.enfiler(elt)
    
def trier(file):
    resultat=File()
    while not file.est_vide():
        maxi=donner_max(file)
        copie=File()
        maximum=File()
        while not file.est_vide():
            elt=file.defiler()
            if elt==maxi:
                maximum.enfiler(elt)
            else:
                copie.enfiler(elt)
        while not copie.est_vide():
            elt=copie.defiler()
            file.enfiler(elt)
        while not maximum.est_vide():
            elt=maximum.defiler()
            resultat.enfiler(elt)
    return resultat
        
def trier2(file):
    """
    faux
    """
    tampon=File()
    while not file.est_vide():
        tampon.enfiler(file.defiler())
        placer_max(tampon)
    return tampon

        
    
    
if __name__=='__main__':
    import doctest
    doctest.testmod()
    f=File()
    f.enfiler(2)
    f.enfiler(4)
    f.enfiler(8)
    f.enfiler(3)
    print(f)
    
