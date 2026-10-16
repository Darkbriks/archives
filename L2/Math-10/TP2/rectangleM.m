function I=rectangleM(a,b,f)
    %entree: a reel, b reel, f fonction
    %sortie: I reel
    %fonction qui calcule l'integrale de f sur [a,b] par la methode des rectangles au milieu
    I=(b-a)*f((a+b)/2);
endfunction