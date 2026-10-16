class Point:
    """
        définition d'un point géométrique
    """

class Rectangle:
    """
        définition d'un rectangle
    """
    
rect=Rectangle()# On crer une instance de rectangle que l'on nomme rect
rect.largeur=50.0# On creer a rect l'atribut largeur avec pour valeur 50.0
rect.hauteur=35.0# On creer a rect l'atribut hauteur avec pour valeur 35.0
rect.coin=Point()# On creer l'atribut coin qui est une instance de Point
rect.coin.x=12.0# On creer a coin l'atribut x avec pour valeur 12.0
rect.coin.y=27.0# On creer a coin l'atribut y avec pour valeur 27.0