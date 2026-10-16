function [X] = poisson(n, a)
    X = zeros(1,n);
    for i = 1:n
        k = 0;
        p = exp(-a);
        F = p;
        U = rand;
        while U > F
            k = k + 1;
            p = a*p/k;
            F = F + p;
        endwhile
        X(i) = k;
    endfor
endfunction    