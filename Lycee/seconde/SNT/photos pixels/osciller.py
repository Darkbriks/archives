
from time import sleep
from PIL import Image

def melanger():
    img=Image.open("pomme.jpg")
    pas=0
    while pas<5:
        for x in range(250):
            for y in range(250):
                r,v,b=img.getpixel((x,y))
                x2=x+250
                y2=y+250
                r2,v2,b2=img.getpixel((x2,y2))
                img.putpixel((x2,y2),(r,v,b))
                img.putpixel((x,y),(r2,v2,b2))
        for x in range(250):
            for y in range(250):
                r,v,b=img.getpixel((x+250,y))
                r2,v2,b2=img.getpixel((x,y+250))
                img.putpixel((x+250,y),(r2,v2,b2))
                img.putpixel((x,y+250),(r,v,b))
        img.show()
        sleep(0.1)
        pas=pas+1

