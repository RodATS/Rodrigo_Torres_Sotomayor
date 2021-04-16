#include <iostream>
using namespace std;

void imprimir(string texto[], int cantidad)
{
  for(int i=0;i<cantidad;i++)
    cout<<texto[i]<<endl;
}

int main() {
  cout<<"Ingrese el texto: "<<endl;
  string texto;
  getline(cin, texto);
  cout<<"Ingrese el numero de caracteres por bloques: "<<endl;
  int clave;
  cin>>clave;
  cout<<endl;
  int cantidad;
  if(texto.length()%clave==0)
  {
    cantidad=texto.length()/clave;
  }
  else {
    for(int i=0;i<texto.length()%clave;i++)
      texto+="X";
    cantidad=texto.length()/clave;
  }

  string bloques[cantidad];
  int indice=0;
  for(int indice_bloque=0; indice_bloque<cantidad;indice_bloque++)
    {
      for(int aux=0;aux<clave;aux++, indice++)
        bloques[indice_bloque]+=texto[indice];
    }
  
  imprimir(bloques, cantidad);
}
