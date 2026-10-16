format bank

clear all
close all
clc

a = [3, -1, -4, 1, 2];

M = matricespeciale(a)

M2 = SVDapprox(M, 2)