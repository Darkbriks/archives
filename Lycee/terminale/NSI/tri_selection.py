def tri_selection(liste):
    for i in range(len(liste)-1):
        min = i
        for l in range(i+1, len(liste)):
            if liste[l] < liste[min]:
                min = l
        liste[i], liste[min] = (liste[min], liste[i])
    return liste

import random

print([random.randint(0,20) for loop in range(10)])