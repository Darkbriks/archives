#ouverture du fichier en mode écriture
#le fichier nouveau.txt n'existe pas dans le dossier, il est donc automatiquement créé
#new est un canal d'écriture entre le prog et le fichier
new=open('nouveau.txt','w')
new.write("Un nouveau fichier à conserver.\n")
#fermeture du canal
new.close()


#modifier un fichier existant, avec le mode 'a'
modif=open('nouveau.txt','a')
modif.write("Dans notepade++, on voit bien que la première ligne n'a pas été enlevée.\n")
modif.write('on a ajouté deux lignes')
modif.close()