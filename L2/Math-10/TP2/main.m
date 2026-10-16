% Question 1
% Les valeurs exactes d integrales sont:
% f(x) = 1 => 1
% f(x) = x => 1/2
% f(x) = x^2 => 1/3
% f(x) = x^3 => 1/4
% f(x) = x^4 => 1/5

clear all; clc; clf;
function y=eZero(x)
y=1;
end
function y=e1(x)
y=x;
end

% Question 3
function y=e2(x)
y=x^2;
end

function y=e3(x)
y=x^3;
end

function y=e4(x)
y=x^4;
end

% Partie 1 : Fonction de quadratures classiques

% Question 2
a=0;
b=1;
I=zeros(1,2);
%rectangleG
f=@eZero;
I(1)=rectangleG(a,b,f);
f=@e1;
I(2)=rectangleG(a,b,f);
%calculs erreur
Iexacte=[1,1/2];
E=abs(I-Iexacte);
disp('calcul d erreur')
disp('rectangle a gauche')
disp(E)

% Question 4
%rectangleG
quadrature=@rectangleG;
E=testQuadratureBaseCanonique(a,b,quadrature);
disp('calcul d erreurs')
disp('rectangle a gauche')
disp(E)

% Question 5
%rectangleM
quadrature=@rectangleM;
E=testQuadratureBaseCanonique(a,b,quadrature);
disp('rectangle au milieu')
disp(E)

%trapeze
quadrature=@trapeze;
E=testQuadratureBaseCanonique(a,b,quadrature);
disp('trapeze')
disp(E)

%simpson
quadrature=@simpson;
E=testQuadratureBaseCanonique(a,b,quadrature);
disp('simpson')
disp(E)

% Partie 2 : Fonctions compsites

% Question 1
a=0; b=1; N=3;
z=linspace(a,b,N);
disp('Exemple definissant deux sous-intervalles')
disp(z)

% Question 3
%formules composites
a=0; b=1; N=1;
disp(['Formules composites N=' num2str(N)])
%rectangleG
quadrature=@rectangleG;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('rectangleG composite')
disp(E)
%rectangleM
quadrature=@rectangleM;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('rectangleM composite')
disp(E)
%trapeze
quadrature=@trapeze;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('trapeze composite')
disp(E)
%simpson
quadrature=@simpson;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('simpson composite')
disp(E)

% Question 4
%formules composites
N=2;
disp(['Formules composites N=' num2str(N)])
%rectangleG
quadrature=@rectangleG;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('rectangleG composite')
disp(E)
%rectangleM
quadrature=@rectangleM;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('rectangleM composite')
disp(E)
%trapeze
quadrature=@trapeze;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('trapeze composite')
disp(E)
%simpson
quadrature=@simpson;
E=testCompositeBaseCanonique(a,b,N,quadrature);
disp('simpson composite')
disp(E)

% Partie 3 : Ordre de convergence

% Question 3
plotErreurCos(rectangleG)