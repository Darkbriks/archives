graphe={"A":["B","D","E"],"B":["A"],"C":["D"],"D":["A","C","E"],
       "E":["A","D","F","G"],"F":["G"],"G":["E","F"],"H":["G"]}

G=dict()
G['a']=['b','c']
G['b']=['a','d','e']
G['c']=['a','d']
G['d']=['b','c','e']
G['e']=['b','d','f']
G['f']=['e']
G['g']=['h']
G['h']=['g']

petit={"A":["B","C"],"B":["A","C",'D'],"C":["A","B"],"D":["B"]}

def p1(g,s):
    """
    parcour en largeur d'un graphe
    :param g: dict, graphe étudié avec la liste des voisins ou des successeurs 
    :param s: un sommet du graphe étudié
    """
    visités = []#creation d'une liste vide
    a_voir=[s]#creation d'une liste a un element qui equivault au sommet etudier
    while a_voir:#on execute le boucle tant que a_voir n'est pas vide
        S = a_voir.pop(0)#on prend le premier element de a_voir et on le stocke
        if S not in visités:#si le sommet S n'a pas encore ete visiter
            visités.append(S)#on l'ajoute a la fin de la liste visité
        
        for T in g[S]:#pour chaque voisins T du sommet S
            
            if T not in visités:#si le voisin T n'a pas encore ete visite
                
                a_voir.append(T)#on ajoute le voisin T a la fin de la liste des sommets a voir
    return visités#on retourne la liste des sommets visité

p1(G,'b')


def d(g,s) :
    """
    parcour en profondeur
    :param graphe: dict, graphe étudié avec la liste des voisins ou des successeurs 
    :param sommet: un sommet du graphe étudié
    """
    couleur=dict()#creation d'un dictionnaire vide
    for v in g :#pour chaque sommet v dans le graphe g
        couleur[v]='blanc'#on cré la cle v avec pour valeur blanc
    P=dict()#creation d'un dictionnaire vide
    P[s]=None#on atribut a la cle s qui represente le sommet etudie la valeur None
    couleur[s]='gris'#on atribut a la cle s qui represente le sommet etudie la valeur gris
    Q=[s]#creation d'une liste avec pour element le sommet s
    while Q :#tant que la liste Q n'est pas vide
        u=Q[-1]#on atribut a u la derniere valeur de Q
        R=[y for y in g[u] if couleur[y]=='blanc']
        if R :
            v=R[0]
            couleur[v]='gris'
            P[v]=u
            Q.append(v)
        else :
            Q.pop()
            couleur[u]='noir'
    return P

def parcourir(g, vus, s):
    """
    parcourir le graphe g depuis s en récurrence, en ...........
    au départ, il faut partir de s, donc, vus est une liste vide
    le premier sommet à ajouter à vus est s, le parcours commence en s
    le parcours en prrofondeur depuis s est s plus le parcours en profondeur depuis un des voisins de s
    :param g: dict
    :param vus:list, liste des sommets visités
    :return : list
    >>> parcourir(G, [],'e')
    ['e', 'b', 'a', 'c', 'd', 'f']
    >>> parcourir(G, [],'g')
    ['g', 'h']
    """
    if s not in vus:
        vus.append(s)
        for voisin in g[s]:#cas d'arret --> quand s n'a plus de voisin
            parcourir(g,vus, voisin)
    return vus



def existe_chemin(g,s1,s2):
    """
    permet de savoir s il y a un chemin entre s1 et s2
    >>> existe_chemin(G,'e','g')
    False
    >>> existe_chemin(G,'e','c')
    True
    >>> existe_chemin(graphe,'E','H')
    False
    """
    return s2 in parcourir(g,[],s1)

def montrer_chemin(dico, d, f):
    """
    par rapport à un dico donnant le parcours de graphe depuis d,
    pour une clef, la valeur est l'extrémité de l'arrête aboutissant à la clef
    >>> ex_dico={'d':'d','b': 'd', 'a': 'b', 'c': 'd', 'e': 'b', 'f': 'e'}
    >>> montrer_chemin(ex_dico,'d','c')
    ['d', 'c']
    >>> montrer_chemin(ex_dico,'d','f')
    ['d', 'b', 'e', 'f']
    """
    chemin = []
    sommet = f
    while sommet is not d:
        chemin.append(sommet)
        sommet = dico[sommet]
    chemin.append(d)
    return chemin.reverse()
    
def parcourir_ch(g, vus, origine, s):
    """
    idem parcourir mais on rentre les sommets visités depuis s  dans un dico
    la liste des clefs de dico donnerait le parcours en profondeur
    >>> parcourir_ch(G, {},None,'e')
    {'e': None, 'b': 'e', 'a': 'b', 'c': 'a', 'd': 'c', 'f': 'e'}
    >>> parcourir_ch(G, {},None,'a').keys()
    dict_keys(['a', 'b', 'd', 'c', 'e', 'f'])
    """
    if s not in vus:
        vus[s]=origine
        for voisin in g[s]:
            parcourir_ch(g,vus, s, voisin)
    return vus  

def trouver_chemin(g, u, v):
    """
    >>> trouver_chemin(G,'e','h')
    >>> trouver_chemin(G,'e','c')
    ['e', 'b', 'a', 'c']
    >>> trouver_chemin(graphe,'F','D')
    ['F', 'G', 'E', 'A', 'D']
    >>> trouver_chemin(graphe,'F','E')
    ['F', 'G', 'E']
    """
    vus=parcourir_ch(g,{},None,u)
    if v not in vus :
        return None
    chemin=[]
    s=v
    while s is not None:
        chemin.append(s)
        s=vus[s]
    chemin.reverse()
    return chemin 


def court_chemin(g,debut,fin):
    """
    Parcours d'un graphe non pondéré, en largeur, pour le + court chemin de d à f sachant qu'il existe
    >>> court_chemin(G, 'f','c')
    ['f', 'e', 'd', 'c']
    >>> court_chemin(graphe, 'F','E')
    ['F', 'G', 'E']
    """
    visités = [debut]
    #origine est un dictionnaire, pour une clef, la valeur est l'extrémités de l'arrête aboutissant à clef
    origine={}
    origine[debut]=debut
    #partir de debut, a_voir de type file
    a_voir=[debut]
    while a_voir:
        #défiler a_voir, on le note S
        S=a_voir.pop(0)
        
        if S not in visités:
            visités.append(S)
        #est-on sur fin ?
        if S==fin:
            return montrer_chemin(origine,debut,fin)
        else:
            #parcourir les voisins de S
            for voisin in g[S]:
            
                #ajouter si besoin ces voisins aux sommets à voir
                if voisin not in visités:
                    a_voir.append(voisin)
                #pour ces voisins, il faut dire d'où on vient
                    origine[voisin] = S


