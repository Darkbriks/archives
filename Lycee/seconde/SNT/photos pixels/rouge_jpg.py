def créer1():
    print('format jpg')
    #créeation d'une image de largeur .... et de hauteur ......
    monImage=Image.new("RGB",(4,8))
    for x in range(4):
        for y in range(8):
            monImage.putpixel((x,y),(255,0,0))
            # les pixels seront tous de couleur .........
            #La valeur rouge du pixel est .........
    monImage.save("ImageR.jpg")
    #l'image est enregistrée dans le même dossier que le programme
    #son nom est ........
    #elle est au format .......

    #on ouvre à nouveau l'image que l'on vient d'enregistrer
    img=Image.open("ImageR.jpg")
    for x in range(4):
        for y in range(8):
            (r,g,b)=img.getpixel((x,y))
            # on a récupéré les valeurs rgb des différents pixels.
            print(r,g,b)
            print("*")

#appel de la fonction créer1()
créer1()
            
    # 2) Observer avec soin l'affichage dans la console.
    # 3) Que remarquez vous ?
    # 4) N'y a t-il pas des valeurs surprenantes ?