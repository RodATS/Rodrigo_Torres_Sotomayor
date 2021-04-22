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


void vulnerar(string);

void vulnerar_fuerza_bruta(string);


int main() {
  cout<<"ingresa el mensaje:"<<endl;
  string message;
  getline(cin, message );
  Cesar Em(5);
  string mensaje_c= Em.cifrado_cesar(message);
  cout<<mensaje_c<<endl;
  /*
  string mensaje_d= Em.descifrado_cesar(mensaje_c);
  cout<<mensaje_d<<endl;
*/
  vulnerar_fuerza_bruta(mensaje_c);
  return 0;

}


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


void vulnerar_fuerza_bruta(string texto_cifrado){
  int clave=0;
  string mensaje_descifrado[26];
  string alfabeto=("abcdefghijklmnopqrstuvwxyz");
  while(clave<26)
  {
    string mensaje;
    int aux=0;
    while(aux<texto_cifrado.length())
    {
      if(alfabeto.find(texto_cifrado[aux])<alfabeto.length())
        {
          int indice= alfabeto.find(texto_cifrado[aux]);   
          int pos=funcion_modulo((indice+(alfabeto.length()-clave)),alfabeto.length());
          mensaje+= alfabeto[pos];
          
        }
      aux++;
    }
    mensaje_descifrado[clave]=mensaje;
    clave++;
  }
  bool continuar=1;
  int i=0;
  while(continuar==1)
  {
    cout<<"con clave: "<<i<<": "<<mensaje_descifrado[i]<<endl;
    cout<<"continuar 0(NO) 1(SI): ";cin>>continuar;cout<<endl;
    i++;
  }
}
