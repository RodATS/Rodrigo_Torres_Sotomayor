#include <iostream>
using namespace std;

int mcd(int a, int b){
  int s,t;
  int s_a=1;
  int s_b=0;
  int t_a=0;
  int t_b=1;
  while(b>0){
    int q=a/b;
    int r=a-q*b;
    a=b;
    b=r;
    s=s_a - q*s_b;
    s_a=s_b;
    s_b=s;
    t=t_a - q*t_b;
    t_a=t_b;
    t_b=t;
  }
  s=s_a;
  t=t_a;
  cout<<"valor de x: "<<s<<"\nvalor de y: "<<t<<endl;
  return a;
}


int main() {
  int a,b;
  cout<<"Ingresa el primer numero: ";cin>>a;
  cout<<"Ingresa el segundo numero: ";cin>>b;
  int valor=mcd(a,b);
  cout<<"El mcd de ("<<a<<", "<<b<<") es: "<<valor<<endl;
}
