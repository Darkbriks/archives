clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal


x1 = linspace(-10, 10, 200);
y1 = sin(x1);
%plot(x1, y1)
%axis equal

x2 = linspace(-10, 10, 10);
y2 = sin(x2);
%plot(x2, y2)
%axis equal

x3 = [-10, -8, -3, 4, 8];
y3 = [0.2, 0.5, 1, -1, 0];
%plot(x3, y3, 'o')
%axis equal

%plot(x1, y1, x2, y2, x3, y3, 'o')
%axis equal

P = [3, 0, 5, -2, 4];

a = 8;
b = polyval(P, a)

x4 = linspace(-3, 3, 60);
y4 = polyval(P, x4);
%plot(x5, y5)
%axis equal



figure

subplot(2, 2, 1)
plot(x1, y1)
axis equal

subplot(2, 2, 2)
plot(x2, y2)
axis equal

subplot(2, 2, 3)
plot(x1, y1, x2, y2, x3, y3, 'o')
axis equal

subplot(2, 2, 4)
plot(x4, y4)
axis equal