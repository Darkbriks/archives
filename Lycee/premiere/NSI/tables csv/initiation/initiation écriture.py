'''
Découverte du modes d'écriture dans un fichier texte
ouvrez en premier notepad++ pour observez le fichier : creation.txt
il contient les caractères azerty
'''
#ouverture du fichier en mode écriture
# SI le fichier creation1 n'existe pas, il est automatiquement créé
#ATTENTION, SI le fichier creation1.txt existe, il sera remplacé 
texte=open('creation1.txt','w')
#écriture d'une ligne
texte.write("L'anglais, c'est très bien aussi pour le numérique.")
#écriture d'une ligne à la suite
texte.write('\n\n')
texte.write('Un beau trio !!!')
#écriture de plusieurs lignes
texte.writelines(['oui! oui!!\n',"On a de l'avenir ainsi !!!!",' MAIS.\nIl faut travailler !\n'])
texte.close()

#Observez à nouveau dans notepade++ creation.txt
#Notre fichier a été modifié, azerty a disparu !!!!



