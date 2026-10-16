clear all
close all
clc

x1 = linspace(4, 11, 8);
y1 = [7.8, 7.4, 7.9, 5.8, 1.4, -2.0, -5.3, -9.1];

P = regresspoly(x1, y1, 2);
x2 = linspace(2, 12, 100);
y2 = polyval(P, x2);

figure
plot(x1, y1, '+', x2, y2);