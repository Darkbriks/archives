clear all
close all
clc

N=1000;
gaussien=randn(1, N);

figure(1);
plot(gaussien);
title("Reprédentation graphique d'un processus");
xlabel("Nombre d'échantillons");
ylabel("Valeurs du processus");

M=10;
figure(2);
hist(gaussien, M);

figure(3);
dx = -2.9 : 0.1 : 2.9;
hist(gaussien, dx);

% Les differances entre les figures 2 et 3 sont :
% - L'amplitude de l'axe x de la figure 2 est varible, tandis que celle de la figure 3 est définie de -2.9 a 2.9
% - La largeurs des batons de l'histogramme 2 sont de 1 unitée, tandis que celle de la figure 3 est de 0.1 unitée
 
x = -50:1:50;
m = 0;
theta = 10;
fx = (1/sqrt(2*pi))*exp(-0.5*((x-m)/theta).^2);
figure(4)
plot(x,fx)