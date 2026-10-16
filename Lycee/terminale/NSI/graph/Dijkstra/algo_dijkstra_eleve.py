class Graphe:
    """classe graphe définie par un dictionnaire sommets : liste d'adjacence avec poids"""
    def __init__(self,graphe):
        self.graphe = graphe

    def liste_voisins(self, sommet):
        if self.graphe[sommet] == []:
            return []
        return [i for i in self.graphe[sommet]]

    def liste_sommets(self):   #la liste des sommets
        return [i for i in self.graphe]



g1 = Graphe ({'A':[('B',15),('C',4)],'B':[('E',5)],'C':[('D',2),('E',11)],'D':[('E',3)],'E':[]})

g2 = Graphe({'A':[('B',2),('C',4),('D',6)],'B':[('A',2),('C',4)],'C':[('A',4),('B',4),('D',1),('E',5)],'D':[('A',6),('C',1),('E',2)],'E':[('D',2),('C',5)]})

g3 = Graphe({'A':[('B',2),('C',1)],'B':[('A',2),('C',2),('D',1)],'C':[('A',1),('B',2),('D',4),('E',3),('F',5)],'D':[('B',1),('C',4),('E',3),('F',6),('G',5)],'E':[('B',3),('C',3),('D',3),('F',1)],'F':[('E',1),('C',5),('D',6),('G',2)],'G':[('D',5),('F',2)]})

def min_dico(dico,L):
    """
    dico: dictionnaire pour les clefs, les valeurs sont des tuples (nom d'une clef, int)
    L : une liste de clefs de L
    fonction qui retourne la clef (un sommet) de dico qui n'est pas dans la liste L ayant la plus petite valeur
    """
    m = float('inf')
    for (i,j) in dico.items():  
        if i not in L:
            if j[0] <= m:  
                m = j[0]
                s = i      
    return s
    
     
    
#fonction qui retourne un dictionnaire dont les clefs sont les sommets et les valeurs sont (poids, parent)
def tableau_dijkstra(graphe,depart):
    """
    >>> tableau_dijkstra(g1,'A')
    {'A': (0, None), 'B': [15, 'A'], 'C': [4, 'A'], 'D': [6, 'C'], 'E': [9, 'D']}
    """
    visites = []  #sommets déjà  selectionnés
    poids_total = 0
    # dictionnaire dont les clefs sont les sommets et les valeurs sont (poids, parent).
    #+oo pour  tous les sommets pour l'initialiser
    dico_chemin_dijkstra = {i:[float('inf'),None] for i in graphe.liste_sommets()}
    dico_chemin_dijkstra[depart]=[0,None]
    while len(visites)!=len(graphe.liste_sommets()):
        s=min_dico(dico_chemin_dijkstra,visites)
        visites.append(s)
        poid_total=dico_chemin_dijkstra[s][0]
        liste_voisin=[i for i in graphe.liste_voisins(s) if i[0] not in visites]
        for (i,j) in liste_voisin:
            if poid_total+j < dico_chemin_dijkstra[i][0]:
                dico_chemin_dijkstra[i][0]=poid_total+j
                dico_chemin_dijkstra[i][1]=s
    return dico_chemin_dijkstra
    
    
def chemin_dijkstra(graphe,start,end):
    """
    fonction qui détermine le chemin de poids min. entre start et end
    >>> chemin_dijkstra(g1,'A','E')
    (['A', 'C', 'D', 'E'], 9)
    """
    #récupérer le tableau de dijkstra, qui est un dictionnaire
    tableau, l, s = tableau_dijkstra(graphe, start), [], end
    while s != start:
        l.append(s)
        s=tableau[s][1]
    l.append(start)
    l.reverse()
    return (l, tableau[end][0])

g5 = Graphe ({'A':[('B',1),('D',10)],'B':[('A',1),('C',1)],'C':[('B',1),('D',10),('E',1)],'D':[('A',10),('C',10),('E',10)],'E':[('D',10),('C',1),('F',1)],'F':[('E',1)]})