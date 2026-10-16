function X = SVDapprox(A, k)
  [U, S, V] = svd(A);
  X = zeros(size(A));
  for i=1:k;
    X = X + S(i, i) * U(:, i) * (V(:, i))';
  endfor
endfunction