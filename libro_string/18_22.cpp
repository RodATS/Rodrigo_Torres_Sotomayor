#include <iostream>
#include <string>
using namespace std;

int main() {

  string texto;
  getline(cin,texto);
  string::const_iterator iterador= texto.end();
  while(iterador !=texto.begin())
  {
    cout<<*iterador;
    iterador--;
  }
  cout<<*iterador<<endl;
  return 0;
}
