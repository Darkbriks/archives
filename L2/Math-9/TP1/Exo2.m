clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

S=0;
K=0;
L=100;

for i=K:L;
    S=S + (3^K - 2*K)/(K + 2);
    K=K+1;
endfor

disp(S)