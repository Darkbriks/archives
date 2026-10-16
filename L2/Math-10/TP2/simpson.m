function I=simpson(a,b,f)
    %entree: a reel, b reel, f fonction
    %sortie: I reel
    %fonction qui calcule l'integrale de f sur [a,b] par la methode de simpson
    I=((b-a)/6)*(f(a)+4*f((a+b)/2)+f(b));
endfunction