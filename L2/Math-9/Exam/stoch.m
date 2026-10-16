function M = stoch(A)
  [m, n] = size(A);
  M = A;
  
  for i=1:n;
    s = sum(M(1:n, i));
    
    for j=1:m;
      if (s == 0)
        M(j, i) = 1 / n;
      else
        M(j, i) = M(j, i) / s;
      endif
    endfor
  endfor
end