class Point:
    """
        définition d'un point géométrique
    """

class Rectangle:
    """
        définition d'un rectangle
    """
    
def affiche_coord(point):
    """
        affiche les coordonnées d'un point
    """
    print("abscisse : ",point.x)
    print("ordonnée : ",point.y)

def trouve_centre(rectangle):
    """
        détermine le centre d'un rectangle
    """
    centre=Point()# On defini une instance de Point que l'on nomme centre
    centre.x=rectangle.coin.x+rectangle.largeur/2.0# On calcule la moitier du segment represantant la largeur, puis on l'afecte a l'atribut x de centre 
    centre.y=rectangle.coin.y+rectangle.hauteur/2.0# On calcule la moitier du segment represantant la hauteur, puis on l'afecte a l'atribut y de centre
    return centre

rect=Rectangle()
rect.largeur=40.0
rect.hauteur=60.0
rect.coin=Point()
rect.coin.x=8.0
rect.coin.y=13.0
print(trouve_centre(rect))