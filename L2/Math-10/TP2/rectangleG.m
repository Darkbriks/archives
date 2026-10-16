function I=rectangleG(a,b,f)
    %entree: a reel, b reel, f fonction
    %sortie: I reel
    %fonction qui calcule l'integrale de f sur [a,b] par la methode des rectangles a gauche
    I=(b-a)*f(a);
endfunction