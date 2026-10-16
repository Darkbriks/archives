##########################
# CHIFFREMENT DE VIGENERE#
##########################

Alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"           # mise en mémoire de l'alphabet

def codage_Vigenere(message,clef,sens=True):
    """
    Fonction effectuant le codage de Vigenere du message avec la clef
    (le décodage de Vigenere si sens vaut False)
    """
    msg=''
    message.lower()
    for i in range(len(message)):
        if message[i] !=" ":
            msg = msg + Alphabet[((ord(message[i])-97)+((ord(clef[i%len(clef)])-97)*int((int(sens)-0.5)*2)))%len(Alphabet)]
        else:
            msg = msg + " "
    return msg