function [X] = normale(n, m, theta)
    [X1, X2] = box_muller(n);
    X = m + theta*X1;
endfunction