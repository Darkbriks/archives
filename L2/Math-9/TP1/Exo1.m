clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal
A=[1,2,3,4; 5,6,7,8; 9,10,11,12]
[L,U,P] = lu(A)
inv(P)*L*U                % pour verifier que c'est bien A
B=[13;14;15]
X=linsolve(A,B)
A*X                       % pour verifier que c'est bien B