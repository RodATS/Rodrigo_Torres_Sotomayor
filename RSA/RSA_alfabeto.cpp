#include <iostream>
#include <stdlib.h>    
#include <time.h> 
#include <math.h>
using namespace std;

class RSA{
  private:
  int p=17;
  int q=13;
  int d=0;
  string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  public:
  int N=0;
  int phi_N=0;
  int e=0;
  int limite_mayor=50;
  int limite_menor=5;

//constructor
  RSA(){}
  
  void limites(int bits){
    int aux = pow(2,bits);
    limite_mayor=aux-1;
    limite_menor=aux/2;
  }
//generar las claves p y q 
  void clave_p(){
    int a=0;
    int si_es=0;
    srand (time(NULL));
    while(si_es==0||a<=1){
      a= limite_menor+rand() % (limite_mayor + 1);
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
    while(si_es==0 || b==p||b<=1){
      b= limite_menor + rand() % (limite_mayor + 1);
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
    while(aux<exponente){
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
//////////////////////////////////////////////////////////
  string digitos(string mensaje){
    string conjunto_digitos;

    int numero = alfabeto.length();
    string letra_importante = to_string(numero);
    int longitud_digito= letra_importante.length();

    for(int indice=0;indice<mensaje.length();indice++){
      int aux = alfabeto.find(mensaje[indice]);
      string indice_letra= to_string(aux);

      while (indice_letra.length()<longitud_digito){
        indice_letra = to_string(0)+indice_letra;
      }
      conjunto_digitos += indice_letra;
    }
    conjunto_digitos += letra_importante;
    return conjunto_digitos;
  }

///////////////////////////////////////////


  string cifrado( string mensaje){
    string conjunto_indices= digitos(mensaje);
    
    
    clave_p();
    cout<<"clave p: "<<p<<endl;
    clave_q();
    cout<<"clave q: "<<q<<endl;
    hallar_N_phi_N();
    cout<<"N: "<<N<<endl;
    cout<<"phi N: "<<phi_N<<endl;
    obtener_e();
    cout<<"e: "<<e<<endl;
    d=inversa(e);
    cout<<"d: "<<d<<endl;

    ////////////////////////////////////////////////
    string tamaño_N = to_string(N);
    int tamaño_para_dividir = tamaño_N.length()-1;

    cout<<conjunto_indices<<endl;
    int tamaño_digitos = conjunto_indices.length();
    int n_bloques= tamaño_digitos / tamaño_para_dividir;
    int bloques[n_bloques]; // aqui estaran los digitos dividio en bloques de n-1

    int indice=0;
    cout<<"divide en bloques de: "<<n_bloques<<endl;
    for(int aux =0; indice < n_bloques; aux= aux+ tamaño_para_dividir, indice++){
      string grupo="";
      grupo = conjunto_indices.substr(aux,tamaño_para_dividir);//para obtener cada bloques
      bloques[indice]=(stoi(grupo));
      cout<<bloques[indice]<<", ";
    }
    cout<<endl;



////////////////////////////////////////////////////
  string codigo_cifrado;

  for(int i=0; i<n_bloques;i++){
    int operacion= calcular(bloques[i],e);
    string ayuda=to_string(operacion);
    while(ayuda.length()<tamaño_N.length()){
      ayuda = to_string(0)+ayuda;
    }
    codigo_cifrado+= ayuda;
  }

    return codigo_cifrado;

  }

  string descifrado( string mensaje_cifrado){
    string mensaje_descifrado;

    string indices_descifrados;
    string tamaño_N = to_string(N);
    int tamaño_de_N = tamaño_N.length();
    for(int aux=0; aux<mensaje_cifrado.length();aux=aux+tamaño_de_N){
      string number = mensaje_cifrado.substr(aux,tamaño_de_N);
      int numero = stoi(number);
      int codigo_descifrado=calcular(numero,d);
      string ayuda= to_string(codigo_descifrado);

      while(ayuda.length()<tamaño_N.length()-1){///completar con 0
        ayuda = to_string(0)+ayuda;
      }

      indices_descifrados+= ayuda;
    }

    cout<<"indices_descifrados: "<<indices_descifrados<<endl;
    ///////////////////////////////saber el mensaje
    int ultimo_numero = alfabeto.length();
    string letra_importante = to_string(ultimo_numero);
    int longitud_letra_importante = letra_importante.length();
    cout<<"Longitud: "<<longitud_letra_importante<<endl;

    
    for(int i=0;i<indices_descifrados.length()-longitud_letra_importante;i=i+longitud_letra_importante){
      string n = indices_descifrados.substr(i,longitud_letra_importante);
      int n_indice = stoi(n);
      cout<<n_indice<<", ";
      mensaje_descifrado+= alfabeto[n_indice];

    }
  cout<<endl;
    return mensaje_descifrado;
  }

};

string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

int main() {
  RSA Emisor;
  Emisor.limites(5);
  string mensaje;
  cout<<"mensaje: ";
  getline(cin,mensaje);
  cout<<endl;
  string m_cifrado=Emisor.cifrado(mensaje);
  cout<<"mensaje cifrado: "<<m_cifrado<<endl;
  cout<<endl;
  
  string m_descifrado=Emisor.descifrado(m_cifrado);
  cout<<"mensaje descifrado: "<<m_descifrado<<endl;

  return 0;
}
