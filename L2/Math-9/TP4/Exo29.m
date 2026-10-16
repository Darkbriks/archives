clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc

I=imread('http://www-lmpa.univ-littoral.fr/~stubbe/AL/image_CL.jpg');

figure
subplot(2, 3, 1)
imshow(I)

subplot(2, 3, 2)
imshow(imageapprox(I, 1))

subplot(2, 3, 3)
imshow(imageapprox(I, 2))

subplot(2, 3, 4)
imshow(imageapprox(I, 3))

subplot(2, 3, 5)
imshow(imageapprox(I, 4))

subplot(2, 3, 6)
imshow(imageapprox(I, 5))