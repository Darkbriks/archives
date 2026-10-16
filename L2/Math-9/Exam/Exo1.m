clear all
close all
clc

format short

M=[0, 1, 1, 2, 0;
   3, 1, 0, 1, 1;
   1, 0, 0, 0, 0;
   0, 2, 1, 0, 2;
   0, 0, 2, 1, 0];
  
S=zeros(size(M));
for n=22:44
  S = S + M^n;
endfor

disp(S(5, 1))
disp("")

disp(stoch(M))
disp("")
disp(vectstat(stoch(M)))