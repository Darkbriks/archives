clear all

% Ex1 : afficher le graphe de sin(x) sur l'intervalle [0,pi]
figure(1);
x = linspace(0,pi,100);
y = sin(x);
plot(x,y);
title('sin(x) sur [0,pi]');
xlabel('x');
ylabel('sin(x)');

% Ex3 : L0 pour {0, 1, 2} dans [-1, 3] et droite de la fonction nulle
k=1;
x=[0,1,2];
z=linspace(-1,3,100);
L=zeros(size(z));
for i=1:length(z)
    L(i)=base_lagrange_non_vec(z(i),x,k);
end

figure(2);
hold on;
plot(z,L);
plot(z,zeros(size(z)));
legend({'y=L0(x)','y=0'});
%abscisses intersection : 1, 2
%commentaire : Ces valeurs sont elles cohérentes avec la définition de L0 ?
%Oui, car L0 est défini par L0(x) = (x-1)(x-2) / (0-1)(0-2) = (x-1)(x-2) / 2

% Ex5 : L1 et L2 pour le support {0, 1, 2} dans [-1, 3]. Quelles sont les abscisses des points de L1 et L2 et la fonction nulle ?
L1=base_lagrange(z,x,2);
L2=base_lagrange(z,x,3);

figure(3);

hold on;
plot(z,L1,'');
plot(z,L2,'');
plot(z,zeros(size(z)));
legend({'y=L1(x)','y=L2(x)','y=0'});
xlabel('x');
ylabel('y');
%abscisses intersection : 0, 2 pour L1 et 0, 1 pour L2

% Ex7 :
nx = 100;
z = linspace(0, pi, nx);
x2 = linspace(0, pi, 3);
x5 = linspace(0, pi, 6);

p1 = pol_lagrange(z, sin(x2), x2);
p2 = pol_lagrange(z, sin(x5), x5);
y_exact = sin(z);

figure(4);
hold on;
plot(z,p1);
plot(z,p2,'b','linestyle','none','marker','o');
plot(z,y_exact,'r');
legend({'deg 3','deg 5','exact'});

% Ex8 : fonction de Runge
% a :
nx = 100;
z = linspace(-5, 5, nx);
x3 = linspace(-5, 5, 4);
x4 = linspace(-5, 5, 5);
x5 = linspace(-5, 5, 6);
x10 = linspace(-5, 5, 11);

p3 = pol_lagrange(z, 1./(1+x3.^2), x3);
p4 = pol_lagrange(z, 1./(1+x4.^2), x4);
p5 = pol_lagrange(z, 1./(1+x5.^2), x5);
p10 = pol_lagrange(z, 1./(1+x10.^2), x10);
y_exact = 1./(1+z.^2);

% b :
figure(5);
hold on;
plot(z,p3);
plot(z,p4);
plot(z,p5);
plot(z,p10);
plot(z,y_exact,'r');
legend({'deg 3','deg 4','deg 5','deg 10','exact'});
xlabel('x');
ylabel('y');