clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

M = [0, 0, 2/3;
    1/2, 0, 1/3;
    1/2, 1, 0];
    
V1 = [1; 0; 0];
V2 = [0; 1; 0];
V3 = [0; 0; 1];
V4 = [1/3; 1/3; 1/3]

disp("Partie 1")
disp(M*V1)
disp("")
disp((M^2)*V1)
disp("")
disp((M^3)*V1)

disp("")
disp("Partie 2")
disp((M^100)*V1)
disp("")
disp((M^100)*V2)
disp("")
disp((M^100)*V3)

disp("")
disp("Partie 3")
disp(M*V4)
disp("")
disp((M^3)*V4)
disp("")
disp((M^5)*V4)

disp("")
disp("Partie 4")
disp(vectstat(M))
disp("")
disp(M * vectstat(M))