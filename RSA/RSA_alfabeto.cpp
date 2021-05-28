 #include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <math.h>
using namespace std;

class RSA{
  private:
  string alfabeto="abcdefghijklmnopqrstuvwxyz";
  int p=17;
  int q=13;
  int d=0;
  public:
  int N=0;
  int phi_N=0;
  int e=0;

//constructor
  RSA(){}

//generar las claves p y q 
  void clave_p(){
    int a=0;
    int si_es=0;
    srand (time(NULL));
    while(si_es==0){
      a= rand() % (50 + 1);
      for(int aux=2;aux<10;aux++)
      {
        si_es=(a%aux);
        if(a%aux==0){
        si_es=(a%aux);
        break;
        }
      }
    }
    p= a;
  }

  void clave_q(){
    int b=0;
    int si_es=0;
    srand (time(NULL));
    while(si_es==0 || q==p){
      b= rand() % (55 + 1);
      for(int aux=2;aux<10;aux++)
      {
        si_es=(b%aux);
        if(b%aux==0){
        si_es=(b%aux);
        break;
        }
      }
    }
    q=b;
  }

///para inversa de e
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

//Obtener los valores N y phi de N
  void hallar_N_phi_N(){
    N=p*q;
    phi_N=(p-1)*(q-1);
  }


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

///Hallar e
  void obtener_e(){
    int aux=0;
    srand (time(NULL));
    int resultado=0;
    while(resultado!=1){
      int  aux= rand() % (phi_N + 1);
      resultado=euclides(aux, phi_N);
      e=aux;
    }
    cout<<endl;
    
  }


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

///inversa de e
  int inversa(int a){
    int mcd=euclides(a,phi_N);
    int x=euclides_extendido(a,phi_N);
    if(mcd==1){
      if(x<0){
        return funcion_modulo(x, phi_N);
      }
      return x;
    }
    return 1;
  }


  int calcular(int numero, int exponente){
    int n= exponente;
    int resultado_mod=numero;
    int elevado_cuadrado=numero;
    int aux=1;
    while(aux<numero){
      if (aux>1){
        int potencia=pow(elevado_cuadrado,2);
        elevado_cuadrado=funcion_modulo(potencia, N);
      }
      int mod = funcion_modulo(n, 2);
      if(mod==1&&aux>1){
        int multi=resultado_mod*elevado_cuadrado;
        resultado_mod= funcion_modulo(multi, N);
      }
      n=n/2;
      aux=aux*2;
    }
    return resultado_mod;
  }




  string cifrado( string letra){
    int codigo_cifrado=0;
    string mensaje_cifrado;
    int ubicacion = alfabeto.find(letra);
    cout<<"ubicacion: "<<ubicacion<<endl;
    
   clave_p();
    cout<<"clave p: "<<p<<endl;
    clave_q();
    cout<<"clave q: "<<q<<endl;
    hallar_N_phi_N();
    cout<<"N: "<<N<<endl;
    cout<<"phi N: "<<phi_N<<endl;
    obtener_e();
    
    d=inversa(e);
    cout<<"e: "<<e<<endl;
   cout<<"d: "<<d<<endl;
    codigo_cifrado=calcular(ubicacion,e);
    int aux= codigo_cifrado;
    cout <<"aux: "<<aux<<endl;
    while(aux>alfabeto.length())
    {
      aux=funcion_modulo(aux, alfabeto.length());
    }
    
    cout <<"aux: "<<aux<<endl;
    mensaje_cifrado=alfabeto[aux];
    return mensaje_cifrado;

  }

  string descifrado( string letra_cifrada){
    int indice=alfabeto.find(letra_cifrada);
    string mensaje_descifrado;
    int codigo_cifrado=calcular(indice,d);
     int aux= codigo_cifrado;
    cout <<"aux: "<<aux<<endl;
    while(aux>alfabeto.length())
    {
      aux=funcion_modulo(aux, alfabeto.length());
    }
    
    cout <<"aux: "<<aux<<endl;
    mensaje_descifrado=alfabeto[aux];
    return mensaje_descifrado;
  }

};

int main() {
  RSA Emisor;
  string mensaje="u";
  cout<<"mensaje: "<<mensaje<<endl;
  string m_cifrado=Emisor.cifrado(mensaje);
  cout<<"mensaje cifrado: "<<m_cifrado<<endl;
  cout<<endl;
  string m_descifrado=Emisor.descifrado(m_cifrado);
  cout<<"mensaje descifrado: "<<m_descifrado<<endl;;

}