function [E,h]=testCompositeBaseCanonique(a, b, N, quadrature)
    I=zeros(1, 5);
    f=@eZero;
    I(1)=methodeComposite(a, b, N, f, quadrature);
    f=@e1;
    I(2)=methodeComposite(a, b, N, f, quadrature);
    f=@e2;
    I(3)=methodeComposite(a, b, N, f, quadrature);
    f=@e3;
    I(4)=methodeComposite(a, b, N, f, quadrature);
    f=@e4;
    I(5)=methodeComposite(a, b, N, f, quadrature);
    
    %Pas de discretisation
    h=methodeComposite(a, b, N, f, quadrature);

    %Calcul de l'erreur
    Iexacte=[1, 1/2, 1/3, 1/4, 1/5];
    E=abs(I-Iexacte);
endfunction