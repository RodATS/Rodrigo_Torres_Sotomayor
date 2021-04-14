#include <iostream>
#include <string>
using namespace std;

int main() {

  string texto;
  cout<<"Ingresa un texto:"<<endl;
  getline(cin,texto);
  string simbolos="******";
  int pos=texto.length()/2;
  texto.insert(pos,simbolos);
  cout<<texto<<endl;
  
  return 0;
}
