#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ Euclides(ZZ num_a, ZZ num_b){
    ZZ a, b, q,r;
    a=num_a;
    b = num_b;
   while(b!=0)
   {
        q = a/b;
        r = a-(b*q);
        a=b;
        b=r;
   }
   return a;

}

int main()
{
    ZZ n_a,n_b;
    cout<<"Ingresa a: "; cin>>n_a;
    cout<<"Ingresa b: "; cin>>n_b;cout<<endl;
    cout<<"Euclides mcd ("<<n_a<<", "<<n_b<<") = "<<Euclides(n_a,n_b)<<endl;
    return 0;
}
