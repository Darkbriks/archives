clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal


X = [-3, -2, -1, 0, 1, 2, 3];
Y = [4, 1, 2, 0, 2, -1, 7];

n = length(X)-1

M = zeros(n+1, n+1);
for i=1:n+1;
  for j=1:n+1;
    M(i, j) = X(i)^((n+1) - j);
  endfor
endfor

B = Y';


Coef = linsolve(M, B);
disp(Coef)

Fx = linspace(-3, 3, 100);
Fy = polyval(Coef', Fx);

plot(X, Y, '*', Fx, Fy)
axis equal