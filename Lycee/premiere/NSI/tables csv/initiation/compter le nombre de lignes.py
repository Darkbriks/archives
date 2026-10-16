#nombre de lignes
#*********************************************

def compter(fichier):
    #ouvrir fichier en mode lecture
    f = open(fichier,'r')
    #lire la première ligne    
    txt=f.readline()
    compteur=0
    #tester si la ligne n'est pas vide
    while txt!='':
        #ajouter 1 à compteur
        compteur+=1        
        txt=f.readline()
    f.close()
    return compteur

def compterbis(fichier):
    f = open(fichier,'r')
    #lire toutes les lignes du fichier, chaque ligne sera un élément de la liste
    # car total est du type list
    total=f.readlines()  
    f.close()
    return len(total)