vector<ZZ> euclides_extendido(ZZ N_a, ZZ N_b){
    ZZ a, b, q,r, x, y, x_a, x_b, y_a, y_b, d; //x_a = x1; x_b=x2;  y_a=y1;  y_b=y2

    a = N_a;
    b = N_b;
    x_b=1;
    x_a=0;
    y_b=0;
    y_a=1;

   while(b>0)
   {
       q = a/b;
       r = a-(b*q);
       //x
       x=x_b-(x_a*q);
       x_b=x_a;
       x_a=x;
       //y
       y=y_b-(y_a*q);
       y_b=y_a;
       y_a=y;

       a=b;
       b=r;
   }
   d=a;
   vector<ZZ> res={d,x_b,y_b};
   return res;
}
