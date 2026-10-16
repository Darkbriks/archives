function [E,h]=erreurCos(N, quadrature)
    %entree : N entier, quadrature fonction
    %sortie : E reel, h reel
    f=@cos;
    I=methodeComposite(0, 1, N, f, quadrature);
    
    %Calcul de l'erreur
    Iexacte=[sin(1)-sin(0)];
    E=abs(I-Iexacte);
endfunction