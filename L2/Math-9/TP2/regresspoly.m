function P = regresspoly(x, y, k)
  n = length(x);
  A = zeros(n, k+1);
  
  for i=1:n;
    for j=1:k+1;
      A(i, j) = x(i)^((k+1) - j);
    endfor
  endfor

  B = y';

  X = inv(A' * A) * A' * B;
  P = X'; 
end