#création d'une liste vide, de type list, une liste est toujours entre []
liste=[]

for i in range(10):
    #la boucle commence à 0 jusque 10 exclu, on fait 10 passages dans la boucle
    a=input('entrer un nombre')
    #avec  input la variable est du type string
    a=int(a)
    #a est maintenant au format integer : entier
    #on rentre les différentes valeurs dans la liste
    #on ajoute la liste[a] à liste
    liste=liste+[a]

#plus de décallage, on est sorti de la boucle
#afficher toutes les valeurs de la liste
print("afficher la liste",liste)
#afficher le terme qui est en position 0
print('en position 0',liste[0])
#récupération du terme en position 1
intrus=liste[1]
print(intrus)
#enlever le terme en position 1
del liste[1]
print(liste)
#ajouter l'intrus à la fin de liste,
#la méthode append permet d'ajouter un élément en fin de liste
liste.append(intrus)
print(liste)


b=input('entrer un nombre')
b=int(b)
repetition='pas présent'
for i in range(10):
    #commenter l'utilité des lignes 32 et 33
    if b==liste[i] :
        print("déjà  dit")
        repetition=i
print(repetition)
#Quelle signification de la valeur de repetition ?
#Si repetition vaut 4, quelle interprétation ?



#faire une fonction pour chacune des questions suivantes
#1)si le nombre b est déjà  dans la liste, redemander un autre nombre
#2)afficher le nombre de fois où le nombre b apparait dans la liste.
#Bonus : on veut aussi savoir la dernière apparition de la valeur de b dans la liste.
#3)afficher le minimum de la liste puis le maximum puis la somme
