clear all
close all
clc

X = poisson(1000, 5);
figure(1)
hist(X, 50)