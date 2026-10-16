from PIL import Image

def créer2():
    print('format png')
    monImage=Image.new("RGB",(4,8))
    for x in range(4):
        for y in range(8):
            monImage.putpixel((x,y),(255,0,0))

    monImage.save("ImageR.png")
    img=Image.open("ImageR.png")
    for x in range(4):
        for y in range(8):
            (r,g,b)=img.getpixel((x,y))
            # on a
            print(r,g,b)
            print("*")

créer2()


