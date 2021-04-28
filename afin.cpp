#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;


class Afin{
  private:
  string alfabeto="abcdefghijklmnopqrstuvwxyz";
  int clave_a;
  int clave_b=rand()%26;

  public:
    Afin(){}
//////////////////////////////
  void generar_clave_a(){
    int aux=euclides(rand()%30,alfabeto.length());
    while(aux!=1)
      {aux=euclides(rand()%30,alfabeto.length());}
    clave_a=aux;
  }
    int obtener_claves_a(){
      return clave_a;
    }
    int obtener_claves_b(){
      return clave_b;
    }
//////////////////////////////////////////////
      int funcion_modulo(int a, int n)
      {
        int q,r;
        q=a/n;
        r=a%n;
        while(r<0)
        {
          q--;
          r=a-(n*q);
        }
        return r;
      }
////////////////////////////////////////////////
    int euclides(int a,int b)
      {
        int r;
        if(a%b==0){
          return b;}
        else{
          r=a%b;
          a=b;
          b=r;
          return euclides(a,b);

        }
      }
/////////////////////////////////////////////
    int euclides_extendido(int a, int b){
      int s,t;
      int s_a=1;
      int s_b=0;
      int t_a=0;
      int t_b=1;
      while(b>0){
        int q=a/b;
        int r=a-q*b;
        a=b;
        b=r;
        s=s_a - q*s_b;
        s_a=s_b;
        s_b=s;
        t=t_a - q*t_b;
        t_a=t_b;
        t_b=t;
      }
      s=s_a;
      t=t_a;
      return s;
    }
///////////////////////////////////////////
  int inversa(int a){
    int mcd=euclides(a,alfabeto.length());
    int x=euclides_extendido(a,alfabeto.length());
    if(mcd==1){
      if(x<0){
        return funcion_modulo(x, alfabeto.length());
      }
      return x;
    }
    return 1;
  }


///////////////////////////////////////////
  string cifrado(string mensaje){
    generar_clave_a();
    string mensaje_cifrado;
    for(int i=0;i<mensaje.length();i++){
      if(alfabeto.find(mensaje[i])<alfabeto.length()){
        int indice = alfabeto.find(mensaje[i]);
        int aux= (clave_a*indice)+clave_b;
        int nueva_pos= funcion_modulo(aux, alfabeto.length());
        mensaje_cifrado+= alfabeto[nueva_pos];
      }
    }
    return mensaje_cifrado;
  }
////////////////////////////////////////////////////
  string descifrado(string mensaje, int c_a, int c_b){
    string mensaje_descifrado;
    for(int i=0;i<mensaje.length();i++){
      if(alfabeto.find(mensaje[i])<alfabeto.length()){
        int indice = alfabeto.find(mensaje[i]);
        int aux= inversa(c_a)*(indice-c_b);
        int nueva_pos= funcion_modulo(aux, alfabeto.length());
        mensaje_descifrado+= alfabeto[nueva_pos];
      }
    }
    return mensaje_descifrado;
  }
};



int main() {
  Afin emisor;
  Afin receptor;
  
  string mensaje;
  cout<<"Ingrese su mensaje: ";
  getline(cin,mensaje);

  string mensaje_c= emisor.cifrado(mensaje);
  cout<<mensaje_c<<endl;

  string mensaje_d=receptor.descifrado(mensaje_c, emisor.obtener_claves_a(), emisor.obtener_claves_b());
  cout<<mensaje_d<<endl;

}
