ZZ LehmerGCD(ZZ x, ZZ y){
  int b=10;
  while (y>=b){
    ZZ xn=Str2Num(Num2Str(x)[0]);
    ZZ yn=Str2Num(Completar0s(y, Num2Str(x).size())[0]);
    ZZ A=conv<ZZ>(1),B=conv<ZZ>(0),C=conv<ZZ>(0),D=conv<ZZ>(1),t,T,u;
    while (yn+C!=0 && yn+D!=0){
      ZZ q=(xn+A)/(yn+C);
      ZZ qp=(xn+B)/(yn+D);
      if (q==qp){
        t=A-q*C; A=C; C=t; t=B-q*D; B=D; D=t;
        t=xn-q*yn; xn=yn; yn=t;
      }
      else{
        break;
        }
      }
      if (B==0){
      	T=divi(x,y);
      	x=y; y=T;
        }
      else{
      	T=A*x+B*y; u=C*x+D*y;
      	x=T; y=u;
        }
  }
  ZZ v=Euclides(x,y);
  return v;
