function y=base_lagrange_non_vec(z, x, k)
    %entree: z reel, x vecteur, k entier
    %sortie: y reel
    %k=1 correspond a L0, k=2 a L1, etc.
    y=1;
    for i=1:length(x)
        if i!=k
            y=y*(z-x(i))/(x(k)-x(i));
        end
    end
endfunction