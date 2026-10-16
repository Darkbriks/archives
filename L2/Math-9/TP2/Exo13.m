clear all                 % effacer toutes les variables précédantes
close all                 % fermer toutes les fenêtres précédantes
clc                       % effacer l'ecran du terminal


A = csvread('covid.csv');
x=[1:1:180];
y=A;

y_log = log(y);

P = regresspoly(x, y_log, 2);

x1 = linspace(0, 180, 360);
y1 = polyval(P, x1);


figure

subplot(2, 1, 1);
plot(x, y_log, x1, y1);

subplot(2, 1, 2);
plot(x, y, x1, exp(y1));

%%%%%%%%%%
S=0;
for i=1:365;
  S=S+exp(polyval(P, i));
endfor
disp('En 1 ans, la france aurait connue ')
disp(S)
disp('contaminations')
disp('')

T=0;
j=0;

while T < 67000000;
  T=T+exp(polyval(P, j));
  j=j+1;
endwhile
disp('Il aurait fallu ')
disp(j)
disp('jours pour contaminer tous les français')