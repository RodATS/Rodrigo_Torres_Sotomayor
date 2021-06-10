#include <iostream>
using namespace std;

int funcion_modulo(int a, int n)
{
  int q,r;
  q=a/n;//hallamos el cociente
  r=a-(n*q);//hallamos el residuo
  while(r<0)//mientras que el residuo sea negativo
  {
    q--;//el cociente hallado se reducirá en 1 hasta que el residuo sea positivo
    r=a-(n*q);
  }
  cout<<"cociente: "<<q<<endl;
  cout<<"residuo: ";
  return r;
}
int main() {
  cout<<funcion_modulo(-255, 11);
}
