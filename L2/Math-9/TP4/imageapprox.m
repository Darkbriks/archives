function J = imageapprox(I, k)
  I=double(I);
  R=I(:, :, 1);
  R=SVDapprox(R, k);
  G=I(:, :, 2);
  G=SVDapprox(G, k);
  B=I(:, :, 3);
  B=SVDapprox(B, k);
  J=zeros(size(I));
  J(:, :, 1) = R;
  J(:, :, 2) = G;
  J(:, :, 3) = B;
  J=uint8(J);
endfunction