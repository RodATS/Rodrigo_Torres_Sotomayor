#include <iostream>
#include <string>
#include<cstring>
using namespace std;

int main() {

  string texto;
  getline(cin,texto);
  for(int i=0;i<texto.length();i++)
  {
    if(texto[i]=='.')
    {
      texto.replace(i,1," ");
    }
  }
  cout<<texto<<endl;
  int longitud = texto.length();
  char*point=new char[longitud+1];
  texto.copy(point, longitud,0);
  point[longitud]='\0';
  char* ptr;
  ptr=strtok(point," ");

  while(point!=NULL)
  {
    cout<<point<<endl;
    point=strtok(NULL," ");
  }

  return 0;
}
