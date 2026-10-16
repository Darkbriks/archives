function plotErreurCos(quadrature)
  N=2:10;
  sizeN=length(N);
  E=zeros(1,sizeN);
  h=zeros(1,sizeN);
  for k=1:sizeN
    NN=N(k);
    [EE,hh]=erreurCos(NN,quadrature);
    E(k)=EE;
    h(k)=hh;
  end
  plot(log(h),log(E),'lineWidth',3)
  hold on
end