#include<time.h>
#include <chrono>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <NTL/ZZ.h>
#include <Windows.h>
#include <fstream>
using namespace std;
using namespace NTL;
ZZ divi(ZZ a, ZZ n){
  ZZ r=a-((a/n)*n);
  if (r<0){
      if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
long long divi(long long a, long long n){
  long long r=a-((a/n)*n);
  if (r<0){
        if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
bool par(ZZ n){
    ZZ r=n-((n>>1)<<1);
    if (r==0) return true;
    return false;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ BinaryGCD(ZZ x, ZZ y){
  ZZ g=conv<ZZ>(1);
  while(par(x) && par(y)){
    x>>=1;y>>=1;g<<=1;
  }
  while(x!=0){
    while(par(x)){
      x>>=1;
    }
    while(par(y)){
      y>>=1;
    }
    ZZ t=abs(x-y); t>>=1;
    if (x>=y){
      x=t;
    }
    else{
      y=t;
    }
  }
  return g*y;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ Euclides(ZZ a, ZZ b){//mcd
  while(b>0){
  ZZ r=divi(a,b);
  a=b;
  b=r;
  }
  return a;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
vector<ZZ> ExtendedBinaryGCD(ZZ x, ZZ y){
  ZZ g=conv<ZZ>(1);
  while(par(x) && par(y)){
    x>>=1;y>>=1;g<<=1;
  }
  ZZ u=x,v=y,A=conv<ZZ>(1),B=conv<ZZ>(0),C=conv<ZZ>(0),D=conv<ZZ>(1);
  while(u!=0){
    while(par(u)){
      u>>=1;
      if (par(A) && par(B)){
        A>>=1;B>>=1;
      }
      else{
        A+=y;A>>=1;
        B-=x;B>>=1;
      }
    }
    while(par(v)){
      v>>=1;
      if (par(C) && par(D)){
        C>>=1;D>>=1;
      }
      else{
        C+=y;C>>=1;
        D-=x;D>>=1;
      }
    }
    if (u>=v){
      u-=v;A-=C;B-=D;
    }
    else{
      v-=u;C-=A;D-=B;
    }
  }
  vector<ZZ> result{g*v,C,D};
  return result;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
vector<ZZ> Euclides_ext(ZZ a, ZZ b){//YA NO LA LLAMA Euclides extendido
  ZZ x0=conv<ZZ>(1),y0=conv<ZZ>(0),x=conv<ZZ>(0),y=conv<ZZ>(1);
  while(b>0){
  ZZ aux=x;
  ZZ q=a/b;
  ZZ r=divi(a,b);
  x=x0-q*x;
  x0=aux;
  aux=y;
  y=y0-q*y;
  y0=aux;
  a=b;
  b=r;
  }
  ZZ result[]={a,x0,y0};
  vector<ZZ>p(result,result+3);
  return p;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ inversa(ZZ a, ZZ b){//función inversa (pregunta si el mcd es 1)
  vector<ZZ> dxy = Euclides_ext(a,b);
  ZZ mcd=dxy.at(0);
  ZZ inv=dxy.at(1);
  if(mcd==1){
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
  }
  ZZ r;
  r=0;
  return r;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ inversa_1(ZZ a, ZZ b){//función inversa (asumiendo que el mcd es 1)
  ZZ inv=Euclides_ext(a,b).at(1);
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
}
ZZ Euler(int seed){ //NO LA LLAMA
  srand (seed);
  ZZ n=divi(conv<ZZ>(rand()),conv<ZZ>(40));
  return n*n+n+41;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ exponenciacion(long e){
    if (e==0) return ZZ(1);
  ZZ A=conv<ZZ>(1);
    return A<<e;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
string Num2Str(ZZ a){
    ostringstream str;
    str<<a;
    return str.str();
}
string Num2Str(long a){
    ostringstream str;
    str<<a;
    return str.str();
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ Str2Num(string a){
    istringstream num(a);
    ZZ n;
    num>>n;
    return n;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
long Str2Int(string a){
    istringstream num(a);
    long n;
    num>>n;
    return n;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ Str2Num(char a){
    return ZZ(a-'0');
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
string Completar0s(ZZ n, int digs){
    string num = Num2Str(n);
    int n_ceros = digs-num.size();
    if (3>n_ceros&&n_ceros>0){
    string ceros(n_ceros,'0');
    num = ceros+num;}
    return num;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
string Completar0s(int n, int digs){
    string num = Num2Str(n);
    int n_ceros = digs-num.size();
    if (3>n_ceros&&n_ceros>0){
    string ceros(n_ceros,'0');
    num = ceros+num;}
    return num;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
string Completar_datos(string d, int digs){
    int n_chars = 1 * digs;
    while (d.size()<n_chars){
        d+=d;
    }
    return d;
}
////////////////////////////////////////////
vector<long long> criba3(long long n) {
vector<long long> primes3;
primes3.push_back(2);
primes3.push_back(3);
for (long long i=5; i<n; i=i+2) {if (divi(i,3)!=0) primes3.push_back(i);}
for (long long i=2; (primes3[i]*primes3[i])<n; i++) {
for (long long k=i+7; k<primes3.size(); k++) {if (divi(primes3[k],primes3[i])== 0){
primes3.erase(primes3.begin()+k);primes3.resize(primes3.size());primes3.shrink_to_fit();}
}
}
return primes3;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
int ReadFile() { //NO LA LLAMA
	fstream datos;
	datos.open("datos.txt", ios::out);
	if (!datos) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		datos.close();
	}
	return 0;
}
/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
vector<ZZ> ReadFile(string nombre_buscado){ //NO LA LLAMA
	ifstream archivo_entrada;
	archivo_entrada.open("datos.txt");
	string linea;
	while(!archivo_entrada.eof())
        {archivo_entrada>>linea;
        int esp=linea.find(' ');
        string nombre = linea.substr(0,esp);
        ZZ n, e;
        int esp2=linea.find_first_of(' ',esp+1);
        int esp3=linea.find_first_of(' ',esp2+1);
        n= conv<ZZ>(Str2Num(linea.substr(esp,esp2)));
        e= conv<ZZ>(Str2Num(linea.substr(esp2,esp3)));
        if(nombre==nombre_buscado){
            ZZ claves[] = {n,e};
            vector<ZZ>cl(claves,claves+2);
            archivo_entrada.close();
            return cl;
        }
        else{
            vector<ZZ>cl(2,conv<ZZ>(0));
            archivo_entrada.close();
            return cl;
            }
    }
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
void WriteFile(string nombre, ZZ N, ZZ e, string correo){ //NO LA LLAMA
	ofstream file;
	file.open("datos.txt", ios::app);
	file<<"\n"<<nombre<<" "<<N<<" "<<e<<" "<<correo;
	file.close();
}
/////////////////////////////////////////// /////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
unsigned char* BinSeq(ZZ num){ //NO LA LLAMA
    unsigned char* pp = new unsigned char[NumBytes(num)];
    BytesFromZZ(pp, num, NumBytes(num));
    return pp;
}

string Num2Bits(ZZ num, int t){
 ostringstream bits;
 for (;t>=0;t--){
 if (num!=0){
    bits << (par(num));
    num>>=1;
 }
/*else{
    bits << 0;
}*/
 }
 return bits.str();
}

//////////////////////////////// ////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////
ZZ right2left_binary_modexp(ZZ g, ZZ e, ZZ n){
  ZZ A=conv<ZZ>(1), S=g;
  while (e!=0){
    if (!par(e))
      A=divi(A*S,n);
    e>>=1;
    if (e!=0)
      S=divi(S*S,n);
  }
  return A;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ right2left_binary_exp(ZZ g, ZZ e){
  ZZ A=conv<ZZ>(1), S=g;
  while (e!=0){
    if (!par(e))
      A=A*S;
    e>>=1;
      S=S*S;
  }
  return A;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
const int tam = 2;
bool Primos_Entre_Si(ZZ* Primos, ZZ tam) {

    for (int i = 0; i < tam; i++) {

        for (int j = i + 1; j < tam; j++) {
            if (Euclides(Primos[i], Primos[j]) != 1 || Primos[i] == Primos[j]) {

                //cout << Primos[i] << " y " << Primos[j] << " no son primos relativos" << endl;
                return false;
            }
        }
    }

    return true;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ Resto_Chino(ZZ* ai, ZZ* pi) {

    ZZ X = conv<ZZ>(0), P = conv<ZZ>(1);
    ZZ Pi[tam],qi[tam],x0[tam];

    if (Primos_Entre_Si(pi, ZZ(tam)) == 1) {
        for (int i = 0; i < tam; i++) {
            P *= pi[i];
        }

        for (int i = 0; i < tam; i++) {
            Pi[i] = P / pi[i];
            qi[i] = inversa(Pi[i], pi[i]);
        }

        for (int i = 0; i < tam; i++) {
            x0[i] = divi(ai[i] * Pi[i] * qi[i], P);
        }

        for (int i = 0; i < tam; i++) {
            X += x0[i];
        }
        X = divi(X, P);
    }
    return X;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ pyq[2];
ZZ Expmod_rchino(ZZ b, ZZ e, ZZ m){
  ZZ a1=right2left_binary_modexp(b,divi(e,pyq[0]-1),pyq[0]);
  ZZ a2=right2left_binary_modexp(b,divi(e,pyq[1]-1),pyq[1]);
  ZZ as[]={a1,a2};
  ZZ mods[]={pyq[0],pyq[1]};
  ZZ mod = Resto_Chino(as,mods);
  return mod;
}
//////////////////////////////////// ////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////
ZZ bitz, exp_bitsminus1, expbits_minus1, expbits, intervalo;
ZZ binary2ZZ(string binario){
    ZZ decimal, multiplicador = conv<ZZ>(1);
    for(int i=0;i<bitz;i++){
        char dig = binario[i];
        if(dig=='1'){
            decimal+=multiplicador;
        }
        multiplicador<<=1;
    }
    return decimal;
}
//////////////////////////////////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
uint64_t nanoseconds(){
    uint64_t seconds;
    auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return nanoseconds;
}
static uint64_t t_seed = nanoseconds();
uint64_t splitmix() {
	uint64_t z = (t_seed += 0x9e3779b97f4a7c15);
	z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
	z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
	return z ^ (z >> 31);
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ random(ZZ bits){
    ZZ randomn = ZZ(splitmix());
    randomn = exp_bitsminus1 + divi(randomn,intervalo);
    return abs(randomn);
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ seed_generator(ZZ bits)
{
    POINT P;
    GetCursorPos(&P);

    ZZ seed;
    seed = P.x * P.y +1;
    seed =exp_bitsminus1 + divi(seed,intervalo);

    return seed;
}


/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ random_blum_prime(ZZ bits){
    ZZ newnum;
    newnum = random(expbits);
    while(newnum < exp_bitsminus1||divi(newnum,conv<ZZ>(4))!=3){
        newnum = random(expbits);
    }
    return newnum;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ random_numberBBS(ZZ bits){
    ZZ p,q,n,seed,nextRandNum;
    string resultado="";
    p = random_blum_prime(bits);
    q = random_blum_prime(bits);
    seed = seed_generator(bits);
    n = p*q;
    resultado += "1";
    while(bits != 1){
        nextRandNum = divi((seed*seed),n);
        seed = nextRandNum;
        resultado += Num2Str(par(nextRandNum));
        bits--;
    }
    return binary2ZZ(resultado);}

    /////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
bool miller_rabin(ZZ n,long t){
    if (n<2) return false;
    if (n==2 || n==3) return true;
    //if(par(n)) return false;//ahorrar trabajo si es par
    ZZ a,y,i,j,s,r;
    s=0;
    r=n-1;
    while(r>1 && par(r)){
        r>>=1;
        s++;
    }
    for(i=1;i<=t;i++){
        a=ZZ(2)+divi(seed_generator(bitz), n-3);
        y=right2left_binary_modexp(a,r,n);
        if(y!=1 && y!=n-1)
        {
            j=1;
            while(j<=s-1 && y!=n-1)
            {
                y=divi(y*y,n);
                if(y==1)return false;
                j++;
            }
            if(y!=n-1)return false;
        }
    }
    return true;
}

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
ZZ GenPrimo(long bits){
    ZZ p;
    p=random_numberBBS(bitz);
    bool es_primo=miller_rabin(p,2);
    cout<<p<<endl<<es_primo<<endl;
    while(!es_primo){
        p=random_numberBBS(bitz);
        cout<<p<<endl;
        es_primo=miller_rabin(p,2);
        cout<<es_primo<<endl;
    }
return p;
}
