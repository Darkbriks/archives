import csv
pays = []
'''
Si csvfile est un fichier, il doit être ouvert avec newline=''.
Si newline='' n'est pas spécifié,
les caractères de fin de ligne embarqués dans des champs délimités par des guillemets ne seront pas interprétés correctement ;
sur les plateformes qui utilisent \r\n comme marqueur de fin de ligne, un \r sera ajouté.
Vous devriez toujours spécifier sans crainte newline='', puisque le module csv gère lui-même les fins de lignes (universelles).
csvfile est le nom du canal de lecture du fichier petite_liste_pays.csv
'''
with open('petite_liste_pays.csv', newline='') as csvfile:
    #reader renvoie un objet lecteur de la bibliothéque csv
    #il itérera sur les lignes de l'objet csvfile donné
    #lignes contient toutes les lignes de petite_liste_pays.csv
    lignes= csv.reader(csvfile, delimiter=';')
    for l in lignes:
        pays.append(l)
        
'''
documentation : https://docs.python.org/fr/3/library/csv.html#id3
Les résultats ou données ou informations sont stockés sous forme d’un tableau de tableaux.
Tester, par exemple :
pays[0]
pays[1]
dans le shell
On s’aperçoit que lors de la lecture du ﬁchier, la première ligne n’a pas été utilisée comme descriptions des champs.
Le premier enregistrement,concernant Andorre,apparaît dans pays[1].
Plus gênant,le lien entre les valeurs du tableau pays[1] et le nom
des enregistrements,contenus dans pays[0],n’est pas direct.
Si on fait afficher pays[1], on ne sait pas que 468.0 est une superficie, 'EU' est pour l'euro ou le continent européen ?
'''