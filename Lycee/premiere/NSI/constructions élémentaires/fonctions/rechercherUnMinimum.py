#on définit une fonction dont le nom est maFonction(x)
def maFonction(x):
  image=3*x*x-12*x+5
  #return permet de retourner, de donner la valeur de l'image
  return image

x=1
#on calcule l'image de x par maFonction
y=maFonction(x)
print(x,y)
xMinimum=x
yMinimum=y
#début de la boucle pour, 10 passages dans la boucle pour
for pas in range(10) :
    x=x+0.2
    y=maFonction(x)
    print(x,y)
    if y<yMinimum :
        yMinimum=y
        xMinimum=x

print('un minimum est en',xMinimum,yMinimum)


#Quel sera l'affichage ?
#Sur quel intervalle, cherche t-on le minimum ?
#Améliorer le programme pour rechercher le minimum à l'aide d'une fonction.
#Améliorer le programme pour rechercher le maximum à l'aide d'une fonction.
#ATTENTION, les affichages devront être décidés par l'utilisateur dans le shell
#Bonus, créer une fonction telle que'on puisse choisir l'intervalle d'étude.
