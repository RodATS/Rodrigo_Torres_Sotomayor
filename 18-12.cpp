#include <iostream>
#include <string>
using namespace std;

string cifrado(string mensaje)
{
  string mensaje_cifrado;
  for(int i=0;i<mensaje.length();i++)
    mensaje_cifrado+="X";
  return mensaje_cifrado;
}

int main() {

  string cuerpo = ("O/|\\/ \\");
  string palabra="amigo";
  string palabra_cifrada= cifrado(palabra);
  char letra;
  int vidas=0;
  while(vidas<8)
  {
    if(palabra==palabra_cifrada)
      break;
    
    else{
      cout<<"Adivina la palabra: "<<palabra_cifrada<<endl;
      cout<<"letra: ";
      cin>>letra;
    if(palabra.find(letra)!=-1)
      {
        int pos=palabra.find(letra);
        while(pos<palabra.length())
        {
          if(palabra[pos]==letra)
          {
            palabra_cifrada[pos]=letra;
          }
          pos++;
        }
      }
    else
    {
      for(int i=0;i<=vidas;i++)
      {
      if(i==0)
        cout<<" "<<cuerpo.at(i)<<endl;
      else
      if(i==1||i==2||i==5||i==4)
       cout<<cuerpo.at(i);
      else if(i==3||i==7)
        cout<<"\\"<<endl;
      }
      vidas++;
    }
    }
    cout<<endl;
  }
  if(palabra==palabra_cifrada)
   cout<<"Felicidades la palabra es: "<<palabra<<endl;
  else
    cout<<"La palabra era: "<<palabra<<"\n Suerte para la otra"<<endl;

  return 0;

}
