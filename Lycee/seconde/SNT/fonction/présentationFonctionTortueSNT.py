#LA TORTUE PYTHON
#1)vous devez ajouter des commentaires
#faire des recherches si besoin
#   a) Dans le shell, tapez carre(50), observez
#   b) Dans le shell, tapez carre_fixe(), observez


from turtle import*
#Examiner avec SOIN la tabulation
def carre(long):#Il FAUT un ":" !!!
    """
    la fonction carre a une variable
    la variable a pour nom : long
    long est une variable de type int
    la fonction carre permet de tracer un carré de côté long
    """    
    #début de la boucle pour, pas prendra les valeurs : 0 , 1 , 2 , 3 donc 4 valeurs différentes
    for pas in range(4):
        forward(long)
        right(90)
        #fin de la boucle pour
    #fin de la fonction


#une fonction qui n'a pas de variable
def carre_fixe():
    """
    la fonction carre n'a pas de variable
    On laisse les parenthéses () MAIS, il n'y rien entre les parenthéses
    la fonction carre permet de tracer un carré de côté 30
    """
    for pas in range(4):
        forward(30)
        right(90)
        #fin de la boucle pour
    #fin de la fonction
        
def carre_couleur(long, couleur):
    """
    documenter la fonction carre_couleur
    """
    pencolor(couleur)
    carre(long)

'''
QUESTIONS
2)créer une fonction qui permet de tracer des triangles équilatéraux
dont on peut choisir la longueur
3)créer une fonction qui permet de tracer des triangles équilatéraux
de côté 20px dont on peut choisir la couleur
4)faire un programme qui trace 15 carrés avec des tailles
de plus en plus petites pour chaque figure
5)faire un programme qui permet de tracer 8 fois de suite :
        un carré rouge puis un triangle vert
        dimensions (à vous de choisir)
6)2)créer une fonction qui permet de tracer des triangles équilatéraux
dont on peut choisir la longueur, la couleur et l'épaisseur
'''
