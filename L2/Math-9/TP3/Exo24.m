clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

A = [0, 0, 1, 1, 3, 0;
    2, 1, 2, 0, 0, 1;
    1, 0, 2, 1, 2, 2;
    3, 4, 1, 1, 0, 0;
    0, 0, 1, 2, 0, 1;
    2, 1, 1, 3, 1, 2];

M = stoch(A);    

disp(M)
disp("")
disp(vectstat(M))
disp("")

G = google(M, 0.85);

disp(G)
disp("")
disp(vectstat(G))