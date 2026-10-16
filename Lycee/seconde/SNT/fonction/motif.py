from turtle import*
 
def carre(long):
    for pas in range(4):
        forward(long)
        right(90)
    forward(10)

def carre_plein(long,couleur):
    fillcolor(couleur)
    begin_fill()
    carre(long)
    end_fill()

def serie_carres(n,couleur):
    for pas in range(n):
        carre_plein(10,couleur)
        
def coingauche():
   up()
   backward(450)
   left(90)       
   forward(390)
   right(90)
   down()

def changemantligne():
   up()
   backward(850)
   right(90) 
   forward(10) 
   left(90)
   down()

def ligne1():
    for pas in range(17):
        carre_plein(10,'blue')
        serie_carres(3,'white')
        carre_plein(10,'red')

def ligne2():
    for pas in range(17):
        serie_carres(2,'white')
        carre_plein(10,'red')
        serie_carres(2,'white')
        
def ligne3():
    for pas in range(17):
        carre_plein(10,'white')
        carre_plein(10,'red')
        carre_plein(10,'blue')
        carre_plein(10,'red')
        carre_plein(10,'white')

def ligne5():
    for pas in range(17):
        carre_plein(10,'red')
        serie_carres(3,'white')
        carre_plein(10,'blue')



def motif():
    speed(10)
    coingauche()
    for pas in range(5):
        ligne1()
        changemantligne()   
        ligne2()  
        changemantligne()
        ligne3()
        changemantligne()
        ligne2()  
        changemantligne()
        ligne5()
        changemantligne()
      