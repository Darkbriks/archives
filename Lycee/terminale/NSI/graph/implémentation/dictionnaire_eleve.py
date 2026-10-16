# =============================================================================
# Implementation d'un graphe utilisant des dictionnaires
# =============================================================================

class Graphe() :
    
    def __init__(self, orientation = False) :
        """
        le constructeur de la classe, les noms des sommets sont stockés dans un dictionnaire
        par défaut, le graphe n'est pas orienté, le dictionnaire est vide
        """
        self.sommets = {}
        self.orientation = orientation

    def creation_sommet(self, nom) :
        """
        nom sera une clef du dico self.somme.La valeur de la clef nom sera un dictionnaire,
        ce dictionnaire contiendra les voisins de nom qui seront les clefs du dictionnaire,
        la valeur d'une clef sera la pondération de l'arête entre nom et son voisin
        :param nom : string, nom du sommet
        :return : none
        """
        assert nom not in self.sommets
        self.sommets[ nom ] = {} 


    def creation_arete(self, debut, fin, ponderation = 1) :
        """
        :param debut : string, debut de l'arête
        :param fin : string, fin de l'arête
        :param ponderation : int, ponderation arête
        :returns : none
        """
        assert debut in self.sommets and fin in self.sommets
        self.sommets[ debut ][ fin ] = ponderation
        #expliquer les deux lignes qui suivent
        if not self.orientation :#SI le graphe n'est pas orienté
            self.sommets[ fin ][ debut ] = ponderation#On trace un arete entre la fin est le debuts


    def donne_sommets( self ) :
        """
        donne la liste des sommets
        :returns : retourne la liste des sommets.
        """
        return [key for key in self.sommets.keys()]

    def fonction1(self, nom) :
        """
        donne la liste des voisins d'un point du graphe
        :param nom : string, un sommet du graphe
        :returns : retourne la liste des voisins d'un sommets
        """
        assert nom in self.sommets
        liste = []
        for sommet in self.sommets[ nom ] :
            liste.append( sommet )
        return liste

    def ponderation(self, debut, fin) :
        """
        La fonction retourne la ponderation de l'arete (None si il n'y a pas d arete)
        :param debut : string, sommet du debut de l'arête
        :param fin : string, sommet de la fin de l arete
        :returns : ponderation de l'arete, None si il n'y a pas d'arête
        """
        #utilité de la ligne suivante ??
        assert debut in self.sommets and fin in self.sommets#Permet de s'assurer que debut et fin sont dans le graphe
        #utilité de la ligne suivante ??
        if fin in self.sommets[ debut ] :#Permet de savoir si il y a une arete entre debut et fin
            return self.sommets[debut][fin]
        else :
            return None