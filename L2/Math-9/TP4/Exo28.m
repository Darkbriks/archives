clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc 

% I=imread('http://www-lmpa.univ-littoral.fr/~stubbe/AL/image_BW.jpg');
% size(I)
% I;
% imshow(I)
% [L, P, U] = lu(I);
% imshow(U)

% I=imread('http://www-lmpa.univ-littoral.fr/~stubbe/AL/image_CL.jpg');
% size(I)
% figure(1)
% imshow(I)
% R=I(:, :, 1);
% G=I(:, :, 2);
% B=I(:, :, 3);
% figure(2)
% imshow(R)
% figure(3)
% imshow(G)
% figure(4)
% imshow(B)

I=imread('http://www-lmpa.univ-littoral.fr/~stubbe/AL/image_CL.jpg');
I=double(I);
R=I(:, :, 1);
R=SVDapprox(R, 20);
G=I(:, :, 2);
G=SVDapprox(G, 20);
B=I(:, :, 3);
B=SVDapprox(B, 20);
J=zeros(size(I));
J(:, :, 1) = R;
J(:, :, 2) = G;
J(:, :, 3) = B;
J=uint8(J);
imshow(J)