function G = google(M, alpha)
  [m, n] = size(M);
  
  P = zeros(n, n);
  P(:, :) = 1/n;
  
  G = alpha*M + (1-alpha) * P;
end