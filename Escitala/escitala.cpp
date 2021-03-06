#include <iostream>
#include <string>
#include<vector>
using namespace std;

class AlgoritmX
{
private:
    int clave[2];

public:
    //constructor de la clase, filas y columnas
    AlgoritmX(int filas, int columnas) {
       clave[0]=filas; clave[1]=columnas;
    }

    //funcion cifrado
    string cifrado(string texto)
    {
      //agregar espacios al string para completar las dimensiones dadas si fuera necesario
      if ((clave[0] * clave[1]) > texto.length())
      {
        for (int aux = 0; aux <= (clave[0] * clave[1]); aux++)
        {
            texto += " ";
        }
      }
      string mensaje_cifrado;
      int j=0;//la variable j para contabilizar columnas
      while(j<clave[1])//j < al numero de columnas
      {   
        int i=j; //la variable i para contabilizar las filas
        while(i<(clave[0]*clave[1] ))
        {
          if(i<(clave[0]*clave[1] ))
          mensaje_cifrado+= texto[i];
          i=i+clave[1];//se le suma el numero de columnas para asi llegar a la posicion de la siguiente letra
        }
        j++;//se le suma 1 para avanzar columna por columna
      }
        return mensaje_cifrado;
    }

  //funcion descifrado
    string descifrado(string texto)
    {
      int j=0;//la variable j para contabilizar filas
      string mensaje_descifrado;
      while(j<clave[0])//j < al numero de filas
      {   
        int i=j; //la variable i para contabilizar las columnas
        while(i<((clave[0] * clave[1])))
        {
          if(i<(clave[0]*clave[1] ))
          mensaje_descifrado+= texto[i];
          i=i+clave[0];//se le suma la cantidad de filas para ubicarse en la posicion de la siguiente letra
        }
        j++;//se le suma 1 para avanzar columna por columna
      }
      return mensaje_descifrado;
    }
};

int main()
{
    cout<<"ingrese mensaje: "<<endl;
    string mensaje;
    getline(cin, mensaje);
    
    AlgoritmX Emisor(3,10);
    string mensaje_c= Emisor.cifrado(mensaje);
    cout<<(mensaje_c)<<endl;;
    string mensaje_d= Emisor.descifrado(mensaje_c);
    cout<<(mensaje_d)<<endl;;

    return 0;
}
