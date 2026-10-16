clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

max_iterartion = 15;
S=zeros(4,4);

M1 = [0,0,0,1;
      1,0,0,0;
      0,1,0,1;
      0,0,0,0];
S1 = M1;

M2 = [0,0,0,1;
      1,0,0,0;
      0,1,0,0;
      0,0,1,0];
S2 = M2;
      
M3 = [0,0,0,1;
      1,0,0,1;
      0,1,0,0;
      0,0,1,0];
S3 = M3;
      
for i=2:max_iterartion;
  S1 = S1 + M1^i;
  S2 = S2 + M2^i;
  S3 = S3 + M3^i;
endfor

S1
S2
S3