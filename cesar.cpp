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
        if(clave<=alfabeto.length()){
          if ((indice + clave)>=alfabeto.length())
          {
            int aux=funcion_modulo((indice+clave),alfabeto.length());
              mensaje_cifrado+= alfabeto[aux];
          }
          else
            mensaje_cifrado+= alfabeto[indice+clave];
          }
        
        else{
          if(indice+clave>alfabeto.length()*2)
          mensaje_cifrado+= alfabeto[(clave-indice)-(alfabeto.length()-indice)];

          else mensaje_cifrado+= alfabeto[(indice+clave)-alfabeto.length()];
        }
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
          int pos=funcion_modulo((indice+(alfabeto.length()-clave)),alfabeto.length());
          mensaje_descifrado+= alfabeto[pos];
          
        }
        aux++;
      }
        return mensaje_descifrado;
 }
};

int main() {
  cout<<"ingresa el mensaje:"<<endl;
  string message;
  getline(cin, message );
  Cesar Em(5);
  string mensaje_c= Em.cifrado_cesar(message);
  cout<<mensaje_c<<endl;
  string mensaje_d= Em.descifrado_cesar(mensaje_c);
  cout<<mensaje_d<<endl;
  return 0;

}
