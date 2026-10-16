'''
Découverte des modes de lecture ou d'écriture dans un fichier texte
ouvrez en même temps thony et notepad++ pour observez le fichier : essai1.txt
'''

#ouverture du fichier essai1.txt en mode lecture, 'r' pour read
#le canal pour lire a pour nom entree
entree=open('essai1.txt','r')
#ligne1 sera la première ligne de mon fichier
ligne1=entree.readline()
print('ligne1 : ',ligne1)
#lecture de la deuxième ligne
ligne=entree.readline()
#lecture de la troisième ligne
ligne=entree.readline()
print('ligne3 : ',ligne)
#Remarquez bien que la troisième ligne n'est pas vide, on a un retour à la ligne
#On peut même afficher son caractère ascii : 10
print('ascii troisième ligne : ',ord(ligne))
#ATTENTION, si on ne ferme pas le canal.
#On peut perdre des informations
#fermeure du canal lecture pour ce fichier à la ligne suivante
entree.close()


entree=open('essai1.txt','r')
#texte sera l'ensemble des lignes de essai1
#texte est du type liste
#texte[0] est la première ligne du fichier
texte=entree.readlines()
print('texte est du type : ',type(texte))
print('première ligne :',texte[0])
print('quatrième ligne :',texte[3])
entree.close()


entree=open('essai1.txt','r')
#car1 sera les 6 premiers caractères de essai1
#car1 est du type string
car1=entree.read(6)
print('car1 : ',car1)
#car2 sera les 10 suivants
car2=entree.read(10)
print('car2 : ',car2)
#car3 sera la suite et la fin
car3=entree.read()
print(car3)
#Nous sommes donc à la fin du fichier, tentons quand même de lire à nouveau une ligne
car4=entree.readline()
if car4=='':
    print('car 4 est vide')
#car4 est bien vide, on aurait eu la même chose avec car4=read()
#il ne faut pas confondre car4 qui est vide et ligne3 qui correspond à une ligne vide avec un passage à la ligne
entree.close()







