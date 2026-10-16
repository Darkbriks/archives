clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal


x = [1, 2, 3, 4, 5, 6, 7, 8];
y = 100*sin(x) + (1/10)*exp(x/100);
P = regresspoly(x, y, 4);
x1 = linspace(0, 9, 100);
y1 = polyval(P, x1);
plot(x, y, '*', x1, y1)