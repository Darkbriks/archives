
from time import sleep
from PIL import Image

def changer():
    pas=0
    while pas <10:
        img1=Image.open("pomme.jpg")
        img2=Image.open("poire.jpg")
        img1.show()
        sleep(2)
        img2.show()
        sleep(1)


'''
1) avec la fonction changer, combien d'images sont affichées (sans lancer le programme)?

2) Modifier le code de la fonction changer:
    Travailler avec 3 images
    pause de 1s entre l'image1 et l'image2
    pause de 2s entre l'image2 et l'image3
    pause de 4s entre l'image3 et l'image1
'''