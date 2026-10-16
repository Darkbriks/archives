
from math import *
"""
nombre=int(input("entrez un entier "))
for pas in range(10):
  print(nombre,'x',pas,' = ',pas*nombre)
print("beau travail ?? ")

#par défaut la boucle commencera avec pour valeur : pas=0
#par défaut, la valeur de pas augmentera de 1 en 1
#Attention, le dernier entier n’est pas pris dans la liste !!
#en informatique, il est d'usage de commencer à 0
# 0;1;2;3;4;5;6;7;8;9 : c'est une suite de 10 entiers


nombre=int(input("entrez un entier "))
for pas in range(1,10):
  #notre boucle commencera à 1 et stoppera avant 10
  print(nombre,'x',pas,' = ',pas*nombre)
print("beau travail !! ")


nombre=int(input("entrez un entier "))
for pas in range(1,10,2):
  #notre boucle commencera à 1
  #la valeur de pas augmentera de deux en deux
  #la valeur de pas restera strictement inf à 10
  print(nombre,'x',pas,' = ',pas*nombre)
print("beau travail !! ")

"""

#Prolongement
#1)ecrire un programme qui affiche les 20 premiers multiples non nuls de l'entier choisi
#2)ecrire un programme qui affiche les multiples plus petits que 15 de l'entier choisi de 3 en 3
#3)ecrire un programme qui affiche les 20 premiers multiples de l'entier choisi,
#ajouter une * si le multiple est paire

"""
nombre = int(input("entrez un entier "))
for pas in range(1,21):
    if (nombre * pas) % 2 == 0 :
        print(nombre,'x',pas,' = ',pas*nombre,'*')
    else :
        print(nombre,'x',pas,' = ',pas*nombre)
        
"""        
        
        
        
nombre = int(input("entrez un entier "))
for pas in range(1,21):
    print(nombre,'x',pas,' = ',pas*nombre)
    if (nombre * pas) % 2 == 0 :
        print('*')
    