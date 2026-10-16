clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal

M = [1,4,1,0; 0,0,0,3; 0,2,0,0; 1,0,0,2];
disp(stoch(M))

A = randi([1, 99], 10, 10);
M = stoch(A);
k = randi(10);
sum(M(:, k));