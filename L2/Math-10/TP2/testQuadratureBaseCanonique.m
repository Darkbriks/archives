function E=testQuadratureBaseCanonique(a, b, quadrature)
    I=zeros(1, 5);
    f=@eZero;
    I(1)=quadrature(a, b, f);
    f=@e1;
    I(2)=quadrature(a, b, f);
    f=@e2;
    I(3)=quadrature(a, b, f);
    f=@e3;
    I(4)=quadrature(a, b, f);
    f=@e4;
    I(5)=quadrature(a, b, f);

    %Calcul de l'erreur
    Iexacte=[1, 1/2, 1/3, 1/4, 1/5];
    E=abs(I-Iexacte);
endfunction