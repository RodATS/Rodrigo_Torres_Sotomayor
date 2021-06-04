ZZ divi(ZZ a, ZZ n){
  ZZ r=a-((a/n)*n);
  if (r<0){
      if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}
