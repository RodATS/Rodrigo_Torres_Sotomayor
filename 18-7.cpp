#include <iostream>
#include <string>
using namespace std;


 string cifrado(string mensaje)
  {
    int clave=13;
    string alfabeto=("abcdefghigjlmnopqrstuvwxyz");
    string mensaje_cifrado;
    int aux=0;
    int indice;
    while(aux < mensaje.length())
    {
      if(mensaje[aux]==' ')
        mensaje_cifrado+=mensaje[aux];
      else 
      {
      indice= alfabeto.find(mensaje[aux]);
      if ((indice + clave)>alfabeto.length())
      {
        mensaje_cifrado+= alfabeto[(indice+clave)-alfabeto.length()];
      }
      else
        mensaje_cifrado+= alfabeto[indice+clave];
      }
      aux++;
    }
      return mensaje_cifrado;
  }

string descifrado(string mensaje)
  {
    int clave=13;
    string alfabeto=("abcdefghigjlmnopqrstuvwxyz");
    string mensaje_descifrado;
    int aux=0;
    int indice;
    while(aux < mensaje.length())
    {
    if(mensaje[aux]==' ')
        mensaje_descifrado+=mensaje[aux];
      else 
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


int main() {

  string message;
  getline(cin, message );
  string mensaje_c= cifrado(message);
  cout<<mensaje_c<<endl;
  string mensaje_d= descifrado(mensaje_c);
  cout<<mensaje_d<<endl;

  return 0;

}
