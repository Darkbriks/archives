function I=trapeze(a,b,f)
    %entree: a reel, b reel, f fonction
    %sortie: I reel
    %fonction qui calcule l'integrale de f sur [a,b] par la methode des trapèzes
    I=1/2*(b-a)*(f(a)+f(b));
endfunction