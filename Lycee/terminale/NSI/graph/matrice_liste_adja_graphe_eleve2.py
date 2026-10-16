graphe = dict()    # création d'un dictionnaire vide 
graphe["A"] = ["B","C","E","F","H"] # liens de A vers les sommets listés
graphe["B"] = ["A","D","H"]
graphe["C"] = ["A","F", "G","H"]
graphe["D"] = ["B","H"]
graphe["E"] = ["A","H"]
graphe["F"] = ["A","C"]
graphe["G"] = ["C","H"]
graphe["H"] = ["A","B","C","D","E","G"]
#graphe est un graphe non pondéré, non orienté
carte={'Lorin': [('Magis', 30), ('Outa', 35)],
       'Magis': [('Lorin', 30), ('Nolin', 97), ('Permi', 45)],
       'Nolin': [('Magis', 97), ('Outa', 51), ('Permi', 59)],
       'Outa': [('Lorin', 35), ('Nolin', 51), ('Permi', 40)],
       'Permi': [('Magis', 45), ('Nolin', 59), ('Outa', 40)]}
#carte est une graphe pondéré, non orienté
#le nombre de sommets du graphe ou ordre du graphe
#le nombre de sommets du graphe ou ordre du graphe
def ordre(g):
    #return len(g.keys())
    return len(g)

#le nombre d’arêtes du graphe
def nbr_aretes(g):
    """
    >>> nbr_aretes(graphe)
    13
    """
    nbr=0
    for clef in g.keys():
        nbr=nbr+len(g[clef])
    return int(nbr/2)

#degré d'un sommet
def degre_sommet(g,s):
    """
    >>> degre_sommet(graphe,'A')
    5
    >>> degre_sommet(graphe,'G')
    2
    """
    return len(g[s])


def degre(g):
    """
    permet d avoir un dico qui donne pour un sommet son degré
    :param g:dict
    :return : dict
    >>> degre(graphe)
    {'A': 5, 'B': 3, 'C': 4, 'D': 2, 'E': 2, 'F': 2, 'G': 2, 'H': 6}    
    """
    deg={}
    for clef in g:
        deg[clef]=len(g[clef])
    return deg
    
#sommet de plus haut degré
def haut_degre(g):
    """
    >>> haut_degré(graphe)
    'H'
    """
    maxi=0
    for clef in g.keys():
        if degre_sommet(g,clef)>maxi:
            maxi=degre_sommet(g,clef)
            s=clef
    return s

#les voisins d’un sommet
def voisins(g,s):
    """
    >>> voisins(graphe,'B')
    ['A', 'D', 'H']
    """
    return g[s]

def dico_to_matrice(g):
    """
    :param g : graphe au format dict
    >>> dico_to_matrice(graphe)
    [[0, 1, 1, 0, 1, 1, 0, 1], [1, 0, 0, 1, 0, 0, 0, 1], [1, 0, 0, 0, 0, 1, 1, 1], [0, 1, 0, 0, 0, 0, 0, 1], [1, 0, 0, 0, 0, 0, 0, 1], [1, 0, 1, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 1], [1, 1, 1, 1, 1, 0, 1, 0]]
    """
    n = ordre(g)
    clef = sorted(g.keys())
    matrice = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(n):
            if clef[j] in g[clef[i]]:
                matrice[i][j] = 1
    #return matrice
    for l in matrice:
        print(l)

def dico_to_matrice2(g):
    """
    les clés sont les sommets et les valeurs sont une liste de tuples au format ("sommets",temps)
    on a un graphe pondéré
    :param g : graphe au format dict
    """
    n = ordre(g)
    clef = sorted(g.keys())
    matrice = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(n):
            if clef[j] in g[clef[i]][0]:
                matrice[i][j] = g[clef[i]][1][1]
    return matrice
                
def matrice_to_dico(mat,liste):
    """
    renvoie un dictionnaire,les clés sont les sommets,
    les valeurs sont une liste de tuples au format ("nom_sommet", poids)
    :param mat: une matrice d'adjacence de type d'un tableau de tableaux, matrice qui contient les poids du graphe pondéré
    :param : liste de chaînes de caractères qui correspond aux noms des sommets
    >>> m=[[0,30,0,35,0],[30,0,97,0,45],[0,97,0,51,59],[35,0,51,0,40],[0,45,59,40,0]]
    >>> l=["Lorin", "Magis", "Nolin", "Outa","Permi"]
    >>> dico=matrice_to_dico(m,l)
    >>> dico["Lorin"]
    [('Magis', 30), ('Outa', 35)]
    >>> dico["Permi"]
    [('Magis', 45), ('Nolin', 59), ('Outa', 40)]   
    """
    dic = {}
    for i in range(len(liste)):
        dic[liste[i]] = []
        for l in range(len(mat[i])):
            if mat[i][l] != 0:
                dic[liste[i]].append((liste[l], mat[i][l]))
    return dic