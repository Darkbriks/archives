function [I,h]=methodeComposite(a,b,N,f,quadrature)
    z=linspace(a,b,N+1);
    h=z(2)-z(1);
    I=0;
    for k=1:N
        Itemp=quadrature(z(k),z(k+1),f);
        I=I+Itemp;
    end
end