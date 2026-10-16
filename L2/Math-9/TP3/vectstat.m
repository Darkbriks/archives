function S = vectstat(M)
  [m, n] = size(M);
  A = ones(n+1, n);
  A(1:n, :) = M - eye(n);
  
  B = zeros(n+1, n);
  B(n+1, n) = 1;
  
  S = linsolve(A, B);
end