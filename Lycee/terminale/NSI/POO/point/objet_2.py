class Point:
    """
        définition d'un point géométrique
    """

def affiche_coord(point):
    """
        affiche les coordonnées d'un point
    """
    print("abscisse : ",point.x)
    print("ordonnée : ",point.y)
    
p1=Point()# on defini une instance de la classe Point avec pour nom p1
p1.x=3#on creer un atribut x au quel on donne la valeur 3
p1.y=5
affiche_coord(p1)
