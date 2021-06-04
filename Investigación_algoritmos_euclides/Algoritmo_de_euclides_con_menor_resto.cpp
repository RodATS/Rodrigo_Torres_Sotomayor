#include<iostream>
#include<string>
#include<time.h>
#include <NTL/ZZ.h>
#include<cstdlib>
using namespace std;
using namespace NTL;
ZZ euclides_menor_resto(ZZ a, ZZ b){
    ZZ d,c,r;
    if(a==0){
        c = 0;
    }
    else{
        c = a; d = b;
    }
    while(d!=0){
        r = c - d*(c/d+1/2); //q = (c/d+1/2)
        c = d;
        d = r;
    }
    if(c<0){
        return -c;
    }
    else{
        return c;
    }
} 
