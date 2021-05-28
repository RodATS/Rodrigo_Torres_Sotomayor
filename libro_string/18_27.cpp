#include <iostream>
#include <string>
using namespace std;
#include<iomanip>
using std::setw;
//prototipos

void ordenamientoSeleccion( string [], const int, bool (*)(string,string));
bool ascendente(string, string);
bool descendente(string, string);

int main()
{
  const int tamanioArreglo = 10;
  int orden;
  int contador;
  string a[tamanioArreglo]={"hola","como","ayuda","baila","nieto","lapiz","pasa","llama","cancion","mama"};
  cout<<"Escriba 1 para orden ascendete,\nEscriba 2 para orden descendete: ";
  cin>>orden;
  cout<<"Elementos de datos en el orden original\n";

  //impresion
  for(contador=0;contador<tamanioArreglo;contador++)
    cout<<setw(4)<<a[contador]<<"  ";

  if(orden==1)
  {
    ordenamientoSeleccion(a, tamanioArreglo, ascendente);
    cout<<"\nElementos datos en orden ascendente\n";
  }
  else{
    ordenamientoSeleccion(a,tamanioArreglo,descendente);
    cout<<"\nElementos en orden descendente\n";
  }
  //impresion
  for(contador=0;contador<tamanioArreglo;contador++)
    cout<<setw(4)<<a[contador]<<"  ";
  cout<<endl;

  return 0;
}

void ordenamientoSeleccion(string trabajo[], const int tamanio, bool (*compara)(string,string))
{
  int menorOMayor;
  for(int i=0; i<tamanio-1;i++)
  {
    menorOMayor=i;
    for(int index=i+1;index<tamanio;index++)
      if(!(*compara)(trabajo[menorOMayor],trabajo[index]))
        menorOMayor =index;

    trabajo[menorOMayor].swap(trabajo[i]);
  }
}

bool ascendente(string a, string b)
{
  return a<b;
}

bool descendente(string a, string b)
{
  return a>b;
}
