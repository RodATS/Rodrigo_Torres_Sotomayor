vector<ZZ> ExtendedEuclidGCD(ZZ a, ZZ b){
  if (b==0){
	vector<ZZ>p{a,conv<ZZ>(1),conv<ZZ>(0)};
	return p;
  }
  ZZ q=divi(a,b);
  ZZ r=(a-q)/b;
  vector<ZZ>p=ExtendedEuclidGCD(b, q);
  ZZ k=p[1], l=p[2];
  p[1]=l;
  p[2]=k-l*r;
  return p;
}
