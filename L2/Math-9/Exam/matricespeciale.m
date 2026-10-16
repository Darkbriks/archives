function M = matricespeciale(a)
  [m,n] = size(a);
  M = zeros(n, n);
  
  for i=1:n;
    for j=1:n;
      M(j, i) = (3*(a(i)^(i+j))) / (j+1);
    endfor
  endfor
end