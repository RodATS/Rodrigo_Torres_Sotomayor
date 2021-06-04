ZZ BinaryGCD(ZZ x, ZZ y){
  ZZ g=conv<ZZ>(1);
  while(divi(x,conv<ZZ>(2))==0 && divi(y,conv<ZZ>(2))==0){
	x>>=1;y>>=1;g<<=1;
  }
  while(x!=0){
	while(divi(x,conv<ZZ>(2))==0){
  	x>>=1;
	}
	while(divi(y,conv<ZZ>(2))==0){
  	y>>=1;
	}
	ZZ t=abs(x-y); t>>=1;
	if (x>=y){
  	x=t;
	}
	else{
  	y=t;
	}	
  }
  return g*y;
} 
