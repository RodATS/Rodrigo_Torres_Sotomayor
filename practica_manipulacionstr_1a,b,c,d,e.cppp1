#include <iostream>
using namespace std;

void separar_texto(string texto, int clave)
{
  
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
  string texto_modificado;
  for(int i=clave;i<texto.length();i=i+clave+1)
    texto.insert(i, "*");
  cout<<texto<<endl;
  
}

int main() {
  cout<<"Ingrese el texto: "<<endl;
  string texto;
  getline(cin, texto);
  cout<<"Ingrese el numero de caracteres por bloques: "<<endl;
  int clave;
  cin>>clave;
  cout<<endl;
  separar_texto(texto, clave);
  
}
