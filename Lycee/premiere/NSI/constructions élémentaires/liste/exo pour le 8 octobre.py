import random

liste = []
liste_A = []
liste_B = []

for loop in range(12) :
    liste = [liste + random.randint(0, 10)]
    
    if liste < 5 :
        liste_A = [liste_A + liste[loop]]
    
    else :
        liste_A = [liste_A + liste[loop]]
        
print(liste_A)
print(liste_B)

