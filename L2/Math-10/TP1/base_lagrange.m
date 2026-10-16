function y=base_lagrange(z, x, k)
    %entree: z vecteur, x vecteur, k entier
    %sortie: y vecteur
    %k=1 correspond a L0, k=2 a L1, etc.
    y = ones(size(z));
    for i=1:length(x)
        if i~=k
            y = y.*(z-x(i))/(x(k)-x(i));
        end
    end
endfunction