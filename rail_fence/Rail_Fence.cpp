#include <iostream>
#include <string>
#include<vector>
using namespace std;

class AlgoritmX
{
private:
    int clave[2];

public:
    AlgoritmX(int fila, int columna) {
       clave[0]=fila; clave[1]=columna;
    }
//////////////////////////////////////////////////////
    string cifrado(string texto)
    {
      string mensaje_cifrado;
      int j=0; //dar la apariencia de que baja fila por fila
      int aux=2;//ayudara al momento de saber cuanto tiene que desplazarse el indice
      int desplazamiento=0;//indice
      while(j<clave[0]-1)
      {
        if(j==0)//cuando esta en la primera fila
        {
          while(desplazamiento<clave[1])
          {
            if(desplazamiento<clave[1])
            {
            mensaje_cifrado += texto[desplazamiento];
            }
            desplazamiento+=(clave[0]*2)-aux;//se utiliza la misma cantidad para desplazarse
          }
        }
        
        else{
          
        desplazamiento=j;
          while(desplazamiento<clave[1])//filas entre la primera y la ultima
          {
            if(desplazamiento<clave[1])
              {
              mensaje_cifrado += texto[desplazamiento];
             }
            desplazamiento+=(clave[0]*2)-aux;//1er desplazamiento, 3er desplazamiento, este disminuye cada vez que se acerca a la ultima fila
            if(desplazamiento<clave[1])
              {
              mensaje_cifrado += texto[desplazamiento];
              }
            desplazamiento += (aux-2);// 2do desplazamiento, 4to desplazamiento, este aumenta cada vez que se acerca a la ultima fila
          }
        }
        

        aux=aux+2;
        j++;//aumento de filas
      }
      desplazamiento=j;
      while(desplazamiento<clave[1])//por problemas en el codigo tuve que colocar estas lineas las cuales concatenan las letras de la ultima fila
          {
            if(desplazamiento<clave[1])
            {
            mensaje_cifrado += texto[desplazamiento];
            }
            desplazamiento += (aux-2);
          }

      return mensaje_cifrado;
    }


/////////////////////////////////////////////////////////////
    string descifrado(string mensaje_c)
    {
      string mensaje_descifrado;
      for(int indice=0; indice< mensaje_c.size(); indice++)//rellenamos el strring prar que tenga las mismas dimensiones que el mensaje cifrado
      {
        mensaje_descifrado+="-";
      }
      int indice=0;//indice del mensaje codificado
      int aux=2;//ayudara para indicar el aumento del desplazamiento del indice
      int pos=0;//indice del mensaje decifrado
      int j=0;//da la apariencia de que baja fila por fila

      while(j<clave[0]-1)
      {
        if(j==0)
        {
          while(indice<clave[1])//primera fila
          {
            if(indice<clave[1])
            {
            mensaje_descifrado[indice]=mensaje_c[pos];//para ir colocando cada elemento donde corresponde
            pos++;//para ir avanzando en el mensaje codificado
            }
            indice+=(clave[0]*2)-aux;//el indice aumenta de igual manera en la primera fila
            
          }
        }
////////////
        else{
          indice=j;
          while(indice<clave[1])//para las filas entre la ultima y la primera
          {
            if (indice<clave[1])
            {
              mensaje_descifrado[indice]= mensaje_c[pos];//
              pos++;
            }
            indice+=(clave[0]*2)-aux;//1er desplazamiento, 3er desplazamiento, este disminuye cada vez que se acerca a la ultima fila
            if(indice<clave[1])
            {
              mensaje_descifrado[indice]= mensaje_c[pos];// 2do desplazamiento, 4to desplazamiento, este aumenta cada vez que se acerca a la ultima fila
              pos++;
            }
            indice += (aux-2);
            
          }
        }
        aux=aux+2;
        j++;//bajar fila por fila
      }
 ///////////////////     
      indice=j;
      while(indice<clave[1])//ultima fila
          {
            if(indice<clave[1])
            {
              mensaje_descifrado[indice]= mensaje_c[pos];
              pos++;
            }
            indice += (aux-2);
            
          }
      return mensaje_descifrado;
      
    }
    
};


////////////////////////////////////////////////////////////
int main()
{
    
    string mensaje;
    //ingreso del mensaje
    cout<<"Mensaje: ";
    getline(cin, mensaje);
    //creacionde la clase
    AlgoritmX Emisor(5,mensaje.length());
    string mensaje_c= Emisor.cifrado(mensaje);
    cout<<"Mensaje cifrado: "<<(mensaje_c)<<endl;;
   
    string mensaje_d= Emisor.descifrado(mensaje_c);
    cout<<"Mensaje descifrado: "<<(mensaje_d)<<endl;;

    return 0;
} 
