from PIL import Image

def decouperCoin():
    #
    img=Image.open("pomme.jpg")
    #
    #
    #
    monImage=Image.new("RGB",(150,100))
    # 
    for x in range(150):
        #
        for y in range(100):
            #
            (r,v,b)=img.getpixel((x,y))
            #
            monImage.putpixel((x,y),(r,v,b))
    monImage.show()


