#include <iostream>
#include <string>
using namespace std;


class Cesar{
  private:
  string alfabeto=("abcdefghijklmnopqrstuvwxyz");
  int clave;

  public:

    Cesar(int c){
      clave=c;}
      
  int funcion_modulo(int a, int n)
    {
      int q,r;
      q=a/n;//hallamos el cociente
      r=a%n;//hallamos el residuo
      while(r<0)//mientras que el residuo sea negativo
      {
        q--;//el cociente hallado se reducirá en 1 hasta que el residuo sea positivo
        r=a-(n*q);
      }
      return r;
    }
   //////////////////////////////////////////////////////// 
  string cifrado_cesar(string mensaje)
    {      
      string mensaje_cifrado;
      int aux=0;
      int indice;
      while(aux < mensaje.length())
      {
        if(alfabeto.find(mensaje[aux])<alfabeto.length())
        {
        indice= alfabeto.find(mensaje[aux]);
        if ((indice + clave)>alfabeto.length())
        {
          int aux=funcion_modulo((indice+clave),alfabeto.length());
          if(aux==0)
            mensaje_cifrado+= alfabeto[indice];//cuando la clave sea 26-longitud del alfabeto
          else
            mensaje_cifrado+= alfabeto[aux];
        }
        else
          mensaje_cifrado+= alfabeto[indice+clave];
        }
        aux++;
      }
        return mensaje_cifrado;
    }
////////////////////////////////////////////////////////////
  string descifrado_cesar(string mensaje)
    {
      string mensaje_descifrado;
      int aux=0;
      int indice;
      while(aux < mensaje.length())
      {
      if(alfabeto.find(mensaje[aux])<alfabeto.length())
        {
        indice= alfabeto.find(mensaje[aux]);
        if ((indice - clave)<0)
        {
          mensaje_descifrado+= alfabeto[alfabeto.length()-(clave-indice)];
        }
        else
          mensaje_descifrado+= alfabeto[indice-clave];
        }
        aux++;
      }
        return mensaje_descifrado;
 }
};

int main() {

  string message;
  getline(cin, message );
  Cesar Em(26); //max num 26 clave
  string mensaje_c= Em.cifrado_cesar(message);
  cout<<mensaje_c<<endl;
  string mensaje_d= Em.descifrado_cesar(mensaje_c);
  cout<<mensaje_d<<endl;
  return 0;

}
