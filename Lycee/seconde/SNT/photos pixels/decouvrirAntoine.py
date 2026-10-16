from PIL import Image

def manipuler():
    """
    cette fonction n'a pas de variable
    ouvrir l'image poire.jpg pour accéder à toutes ses infos :
    sa largeur, sa hauteur, ses pixels, ....
    cette image est ouverte dans le programme sous le nom ma_photo
    """
    ma_photo=Image.open("admiral trawn.jpg")
    # L'image a une largeur de 489px donc 489 passages dans la boucle
    for x in range(1920):
        #pour chaque abscisse, il faut examiner les différentes valeurs des ordonnées
        #la hauteur est de 612 px donc 612 passages
        for y in range(1200):
            #récuperer le code couleur rgb pour chaque pixel de la photo poire
            (r,v,b)=ma_photo.getpixel((x,y))
            #3 nouvelles variables sont définies, nous échangeons les valeurs du code rgb
            newR=255-r
            newV=255-v
            newB=255-b
            #injecter un nouveau code couleur pour ce pixel
            ma_photo.putpixel((x,y),(newR,newV,newB))
    #montrer l'image ma_photo
    ma_photo.show()

#appel de la fonction
manipuler()