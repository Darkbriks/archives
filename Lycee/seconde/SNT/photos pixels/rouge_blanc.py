from PIL import Image



def créer3():
    print('format jpg avec une ligne blanche')
    monImage=Image.new("RGB",(4,8))
    #création d'une ligne de 4 pixels de couleur blanche
    for x in range(4):
            monImage.putpixel((x,0),(255,255,255))
    #création des 7 autres lignes du rectangle de couleur rouge
    for x in range(4):
        for y in range(1,8):
            monImage.putpixel((x,y),(255,0,0))
    #enregistrement de l'image dans le même dossier
    monImage.save("rouge_blanc_jpg.jpg")
    img=Image.open("rouge_blanc_jpg.jpg")
    #Que permet de faire les lignes 19 à 22, notez votre réponse en commentaires
    for x in range(4):
        for y in range(8):
            (r,g,b)=img.getpixel((x,y))
            print(r,g,b)
            print("*")

créer3()


def créer4():
    """
    la fonction créer4 fait la m^me chose que la fonction créer3 mais au fotmat png
    """
    print('format png avec une ligne blanche')
    monImage=Image.new("RGB",(4,8))
    for x in range(4):
            monImage.putpixel((x,0),(255,255,255))

    for x in range(4):
        for y in range(1,8):
            monImage.putpixel((x,y),(255,0,0))

    monImage.save("rouge_blanc_png.png")
    img=Image.open("rouge_blanc_png.png")
    for x in range(4):
        for y in range(8):
            (r,g,b)=img.getpixel((x,y))
            print(r,g,b)
            print("*")



créer4()


