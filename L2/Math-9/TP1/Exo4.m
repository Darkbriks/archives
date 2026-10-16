M = [1,4,1,0; 0,0,0,3; 0,2,0,0; 1,0,0,2];

% Nombre de chemins de longeurs 7 de 4 vers 2
B = M^7;
B(2,4)

% Nombre de chemins de longeurs au plus 15 de 4 vers 2
B=M;
for n=2:15;
  B = B + M^n;
endfor

B(2,4)

% Nombre de chemins de longeurs entre 117 et 213 de 4 vers 2
B=zeros(4,4);
for n=117:213;
  B = B + M^n;
endfor

B(2,4)