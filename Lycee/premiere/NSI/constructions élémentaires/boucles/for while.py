import random #permet d'utiliser les fonctions random ensuite : le hasard
'''
nombre=107

print('CAS 1 :boucle tant que')

#TANT QUE la proposition est correcte ou tant que le test est vérifié,  la boucle tourne
while nombre<500:
    # tout ce qui est décallé fait partie du while
    #tirage d'un nombre entier aléatoire entre 1 et 1000
    nombre=random.randint(1, 1000)
    print(nombre)


print("cas 2")
print('boucle pour')

for i in range(9):
    #i prendra 9 valeurs de 0 à 9 non compris
    nombre=random.randint(1, 1000)
    print(nombre)

print("cas 3")
print('boucle pour')

for i in range(1,6):
    #i prendra les valeurs de 1 à 6 non compris
    nombre=random.randint(1, 1000)
    print(nombre)
'''

#Questions
#1) dans le cas 2, combien de nombres seront affichés          il y aura 9 affichage(print)
#   dans le cas 3, combien de nombres seront affichés          il y aura 5 affichage(print)
#2) dans le cas 1, combien de nombres seront affichés          il y aura au moins 1 affichage(print)
#3) tester
#4) faire une boucle pour toujours afficher 10 entiers au hasard entre 1 et 1000
#5) faire un programme où on choisit un entier au hasard entre 1 et 1000
#   si cet entier est strictement inf à 750, afficher cet entier
#   recommencer tant que l'entier au hasard est strictement inf à 750
#6) faire un programme qui affiche les images des entiers de -3 à 3 par la fonction affine f(x)= 1,5x + 0,2
#   vous proposerez plusieurs solutions
#7) on utilisera la fonction affine f(x)= 0,85x + 1
# faire un programme qui affiche les images des entiers  à partir de -10
#tant que les images de ces entiers plus petites ou égale à 30 ;


print('question 4')
for pas in range(10) :
    nombre = random.randint(1, 1000)
    print(nombre)
    

print('question 5')
nombre = random.randint(1, 1000)
while nombre <750 :
    nombre = random.randint(1, 1000)
    if nombre < 750 :
        print(nombre)
    

print('question 6')
for boucle in range(-3,4,1) :
    print('f(',boucle,')=',boucle*1.5+0.2)


print('question 6 bis')
boucle = -3
while boucle < 4 :
    print('f(',boucle,')=',boucle*1.5+0.2)
    boucle = boucle + 1


print('question 7')
nombre = -10
image = nombre * 0.85 + 1
while image <= 30 :
    print('f(',nombre,')=',image)
    nombre = nombre + 1
    image = nombre * 0.85 + 1





















