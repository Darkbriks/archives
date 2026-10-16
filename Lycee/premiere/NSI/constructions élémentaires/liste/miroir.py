def miroir(mot) :
    mot_bis = ''
    for loop in range(len(mot)) :
        mot_bis = mot_bis + mot[len(mot)-(loop+1)]
    return mot_bis

def palindrome(mot) :
    mot_bis = miroir(mot)
    if mot_bis == mot :
        return True
    return False