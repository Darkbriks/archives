function p=pol_lagrannge(z,y,x)
    %entree: z vecteur, y vecteur y(i) contient f(x(i)), x vecteur
    %sortie: p vecteur
    p=zeros(size(z));
    for i=1:length(x)
        Liz=base_lagrange(z,x,i);
        p=p+y(i)*Liz;
    end
endfunction