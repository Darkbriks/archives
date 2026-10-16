#les listes suivantes ont un ordre logique, en position 0 dans brailles , on a la traduction de l'espace
#en position 1 dans brailles , on a la traduction de ! etc
asciicodes = [' ','!','"','#','$','%','&','','(',')','*','+',',','-','.','/',
          '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@',
          'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
          'r','s','t','u','v','w','x','y','z','[','\\',']','^','_']

brailles = ['⠀','⠮','⠐','⠼','⠫','⠩','⠯','⠄','⠷','⠾','⠡','⠬','⠠','⠤','⠨','⠌','⠴','⠂','⠆','⠒','⠲','⠢',
        '⠖','⠶','⠦','⠔','⠱','⠰','⠣','⠿','⠜','⠹','⠈','⠁','⠃','⠉','⠙','⠑','⠋','⠛','⠓','⠊','⠚','⠅',
        '⠇','⠍','⠝','⠕','⠏','⠟','⠗','⠎','⠞','⠥','⠧','⠺','⠭','⠽','⠵','⠪','⠳','⠻','⠘','⠸']


#Question1
#A partir des deux listes, créer un dictionnaire ascii_to_braille permettant de passer de l'ascii au braille
asciiToBraille = {}
for i in range(len(asciicodes)) :
    asciiToBraille[asciicodes[i]]=brailles[i]
    

#Question2
#A partir du dictionnaire ascii_to_braille, créer un dictionnaire braille_to_ascii
brailleToAscii = {}
for clef in asciiToBraille :
    valeur = asciiToBraille[clef]
    brailleToAscii[valeur] = clef
    
brailleToAscii = {asciiToBraille[clef]:clef for clef in asciiToBraille}


def traduire_ascii(phrase):
    """
    traduire une phrase de l'ascci en braille
    >>> traduire_ascii('bonjour le monde')
    '⠃⠕⠝⠚⠕⠥⠗⠀⠇⠑⠀⠍⠕⠝⠙⠑'
    """
    newPhrase = ""
    for lettre in phrase :
        newPhrase = newPhrase + asciiToBraille[lettre]
    return newPhrase

def traduire_braille(phrase):
    """
    traduire une phrase du braille vers l'ascci
    >>> traduire_braille('⠧⠊⠧⠑⠀⠇⠁⠀⠝⠎⠊')
    'vive la nsi'
    """
    newPhrase = ""
    for lettre in phrase :
        newPhrase = newPhrase + brailleToAscii[lettre]
    return newPhrase

#pour vérifier vos traductions : https://www.lexilogos.com/clavier/braille_conversion.htm