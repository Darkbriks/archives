clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

M=[0,0,0,1,0,0,0,0,0;
  0,0,1,0,1,0,0,0,0;
  0,0,1,0,0,0,0,0,0;
  1,0,0,0,1,0,1,0,0;
  0,1,0,1,0,1,0,0,0;
  0,0,0,0,1,0,0,0,1;
  0,0,0,1,0,0,0,1,0;
  0,0,0,0,0,0,1,0,1;
  0,0,0,0,0,1,0,1,0];
  
M=M'
  
% Nombre de chemins de longeurs au plus 23 de 7 vers 3
B=M;
for n=2:23;
  B = B + M^n;
endfor

disp(B(3,7))