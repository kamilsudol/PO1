#include "wire.h"

using namespace std;

QuantumWire::QuantumWire(double len, int a){
    wir_len=len;
    liczba=new bool[a];

    for(int i=0; i<a;i++){
        liczba[i]=rand()%2;
    }
}

QuantumWire::QuantumWire(){
    wir_len=0;
    liczba=nullptr;
}
QuantumWire::QuantumWire(const QuantumWire &A){
    wir_len=A.wir_len;
    liczba=A.liczba;
}
QuantumWire::QuantumWire(const QuantumWire &&A){
    wir_len=A.wir_len;
    liczba=A.liczba;
    
    delete [] A.liczba;
}
QuantumWire::~QuantumWire(){
    delete [] liczba;
}

ostream &operator<<(ostream &o, const QuantumWire &A){
    o<< "length: " << A.wir_len << " quanta: ";
    int x=sizeof(A.liczba)/sizeof(bool);
    for(int i=0;i<x;i++){
        o << A.liczba[i] << " ";
    }
    return o;
}

QuantumWire& QuantumWire::operator!(){
    int x=sizeof(liczba)/sizeof(bool);
    for(int i=0;i<x;i++){
        if(liczba[i]){
            liczba[i]=0;
        }else{
            liczba[i]=1;    
        }
        
    }
    return *this;
}
QuantumWire& QuantumWire::operator*(double a,QuantumWire &A){
    wir_len=A.wir_len*a;
    int x=sizeof(liczba)/sizeof(bool);
    liczba=new bool[x];
    liczba=A.liczba;
    return *this;
}
QuantumWire& QuantumWire::operator*=(double a){
    wir_len=wir_len*a;
    return *this;
}
//QuantumWire QuantumWire::perator[](const QuantumWire&);
