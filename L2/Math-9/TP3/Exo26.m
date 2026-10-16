clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

A = [0, 1, 0, 0, 0, 0;
    0, 0, 1, 1, 0, 0;
    0, 0, 0, 0, 1, 0;
    0, 0, 0, 0, 0, 1;
    0, 0, 0, 0, 0, 1;
    0, 0, 0, 0, 1, 0];

M = stoch(A);    
G1 = google(M, 0.6);
G2 = google(M, 0.7);

disp(vectstat(G1))
disp("")
disp(vectstat(G2))