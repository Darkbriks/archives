# =============================================================================
# Implementation d un graphe utilisant les matrices d adjacence.
# =============================================================================
'''
étudier avec soin ce code
Questions :
1)expliquer avec soin les lignes : (33 et 34), (45 et 46)
2)coder les fonctions donner_sommets et voisinage
3)expliquer l'utilité de la fonction surprise et son fonctionnement
'''

class Graphe() :
    """
    La classe représente un graphe. On l'implemente via una matrice d'adjacence.
    """
    def __init__(self, orientation = False) :
        """
        constructeur de la classe
        """
        # Le nom des sommets va être stocké dans un dictionnaire,
        #la valeur d'une clef est l'ordre d'arrivée du sommet dans le dictionnaire
        self.noms = {}
        # Les arretes dans une matrice d'adjacence.
        self.arretes = []
        self.orientation = orientation

    def creation_sommet(self, nom) :
        """
        :param nom : string (nom du sommet)
        """
        assert nom not in self.noms
        self.noms[nom] = len(self.noms)
        for ligne in self.arretes :#pour chaque liste de la matrice
            ligne.append(0)#on rajoute un 0 a la fin de la liste
        self.arretes.append([0] * len( self.noms ) )


    def creation_arrete(self, debut, fin, ponderation = 1) :
        """
        debut : string, debut de l'arete
        fin : string, fin de l'arete
        ponderation : int, Ponderation de l arete
        """
        assert debut in self.noms and fin in self.noms
        self.arretes[self.noms[debut]][self.noms[fin]] = ponderation#on definit l'arete entre debut et fin a ponderation
        if self._orientation == False :#si le graphe est non-orienté
            self.arretes[self.noms[fin]][self.noms[debut]] = ponderation

    def donne_sommets( self ) :
        """
        Donne la liste des sommets
        """
        return list(self.nom.keys())
    
    def voisinage(self, nom_sommet) :
        """
        donne la liste des sommets voisins au sommet de nom donne.        
        """
        

    def surprise(self, debut, fin) :
        """
        ?????
        """
        assert debut in self.noms and fin in self.noms

        if self.arretes[self.noms[debut]][self.noms[fin]] != 0 :
            return self.arretes[self.noms[debut]][self.noms[fin]]
        else :
            return None