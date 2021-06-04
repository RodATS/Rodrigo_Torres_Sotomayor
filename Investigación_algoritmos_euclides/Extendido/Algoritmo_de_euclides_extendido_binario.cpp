vector<ZZ> ExtendedBinaryGCD(ZZ x, ZZ y){
  ZZ g=conv<ZZ>(1);
  while(divi(x,conv<ZZ>(2))==0 && divi(y,conv<ZZ>(2))==0){
	x>>=1;y>>=1;g<<=1;
  }
  ZZ u=x,v=y,A=conv<ZZ>(1),B=conv<ZZ>(0),C=conv<ZZ>(0),D=conv<ZZ>(1);
  while(u!=0){
	while(divi(u,conv<ZZ>(2))==0){
  	u>>=1;
  	if (divi(A,conv<ZZ>(2))==divi(B,conv<ZZ>(2))&&divi(B,conv<ZZ>(2))==0){
    	A>>=1;B>>=1;
  	}
  	else{
  	  A+=y;A>>=1;
    	B-=x;B>>=1;
  	}
	}
	while(divi(v,conv<ZZ>(2))==0){
  	v>>=1;
  	if (divi(C,conv<ZZ>(2))==divi(D,conv<ZZ>(2))&&divi(D,conv<ZZ>(2))==0){
    	C>>=1;D>>=1;
  	}
  	else{
    	C+=y;C>>=1;
    	D-=x;D>>=1;
      }
	}
	if (u>=v){
  	u-=v;A-=C;B-=D;
	}
	else{
  	v-=u;C-=A;D-=B;
	}
  }
  vector<ZZ> result{C,D,g*v};
  return result;
}
