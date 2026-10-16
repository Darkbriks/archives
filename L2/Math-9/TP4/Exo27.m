clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

format short

H = matricehilbert(4);

disp(H)
disp("")
disp(SVDapprox(H, 1))
disp("")
disp(SVDapprox(H, 2))
disp("")
disp(SVDapprox(H, 3))
disp("")
disp(SVDapprox(H, 4))