function [X1, X2] = box_muller(n)
    U1 = rand(1,n);
    U2 = rand(1,n);
    X1 = sqrt(-2*log(U1)).*cos(2*pi*U2);
    X2 = sqrt(-2*log(U1)).*sin(2*pi*U2);
endfunction