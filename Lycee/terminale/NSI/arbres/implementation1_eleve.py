import matplotlib.pyplot as plt

""""
Un arbre binaire est
    soit l’arbre vide, noté None ;
    soit un triplet (e, g, d), appelée nœud, dans lequel
        – e est l’élément, ou encore étiquette, de la racine de l’arbre,
        – g est le sous-arbre gauche de l’arbre, et
        – d est le sous-arbre droit de l’arbre.
"""



def est_vide(t):
    """
    savoir si un arbre est vide
    :param t: arbre
    :return : True ou False
    >>> est_vide(None)
    True
    >>> est_vide((4,None,(5,None,None)))
    False
    """
    if t == None:
        return True
    return False

def taille(t):
    """
    calculer la taille d un arbre
    :param t: arbre
    :return :(int)
    >>> petit=(1,None,None)
    >>> taille(petit)
    1
    >>> tree2=(3,(2,petit,None),petit)
    >>> taille(tree2)
    4
    """
    if est_vide(t)==True:
        return 0
    return 1+taille(t[1])+taille(t[2])
    
def hauteur(t):
    """
    calculer la hauteur d un arbre
    :param t: arbre
    :return : int
    >>> petit=(1,None,None)
    >>> hauteur(petit)
    0
    >>> tree2=(3,(2,petit,None),petit)
    >>> hauteur(tree2)
    2
    """
    if est_vide(t)==True:
        return -1
    return max((1+hauteur(t[1])), (1+hauteur(t[2])))


def draw_tree_aux(t, rect, dy, labels):
    if est_vide(t):
        return
    x1, x2, y1, y2 = rect
    xm = (x1 + x2) // 2
    x, t1, t2 = t
    draw_tree_aux(t1, (x1, xm, y1, y2 - dy), dy, labels)
    draw_tree_aux(t2, (xm, x2, y1, y2 - dy), dy, labels)
    if labels:
        plt.text(xm + 10, y2, str(x), fontsize=10, horizontalalignment='left',verticalalignment='bottom')
    if not est_vide(t1):
        a, b = ((xm, (x1 + xm) // 2), (y2, y2 - dy))
        plt.plot(a, b, 'k', marker='s')
    if not est_vide(t2):
        c, d = ((xm, (x2 + xm) // 2), (y2, y2 - dy))
        plt.plot(c, d, 'k', marker='s')


"""
Voici la fonction de tracé. Elle prend un arbre t en paramètre.
Elle initialise un carré adapté à la taille de l'arbre où tracer l’arbre.
Elle calcule la distance idéale entre le tracé de deux niveaux de l’arbre.
Cette distance es liée à la hauteur de l’arbre t.
Enfin elle appelle draw_tree_aux.
"""

def draw_tree(t, labels=True):
    d = 512
    pad = 20
    dy = (d - 2 * pad) / (hauteur(t))
    draw_tree_aux(t, (pad, d - pad, pad, d - pad), dy, labels)
    plt.axis([0, d, 0, d])
    plt.axis('off')
    plt.show()

abr1 = (5, (3, (2, (0, None, (1, None, None)), None), (4, None, None)),
(14, (6, None, (12, (8, (7, None, None), (10, (9, None, None), (11, None, None))),
(13, None, None))), (17, (16, (15, None, None), None), (18, None, (19, None, None)))))

abr2=(9,(4,None,None),None)
abr3=(3,(2,None,None),(5,None,abr2))

#draw_tree(abr1, labels=False)

draw_tree(abr1, labels=True)

a2=(20, (5, None, None), (3, None, None))
a3=(20, (5, (10, None, None), (14, None, None)), (3, None, None))
a4=(20, (5, (10, None, None), (14, None, None)), (3, (22, None, None), (29, None, None)))

if __name__=="__main__":
    import doctest
    doctest.testmod()