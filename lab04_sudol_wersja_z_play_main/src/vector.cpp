#include "vector.h"

namespace MyStuff{

vector::vector(int a):siz{a}{  //konstruktor vector tworzacy wektor o zadanym rozmiarze, wypelniony zerami
    tab=new int[a] {0};
    
}

vector::vector(const vector &A):siz(A.siz){ //konstukror vector kopiujacy
        tab=new int[siz];
        for(int i=0;i<siz;i++){
            tab[i]=A.tab[i];
    }
}

vector::vector(vector &&A){  //konstruktor vector przenoszacy
    tab=std::__exchange(A.tab,nullptr);
    siz=std::__exchange(A.siz,0);
}


vector::~vector(){  //destruktor vector domyslny
    delete tab;
}

std::ostream &operator<<(std::ostream &out, vector &A){ //przeladowany operator <<
    for(int i=0;i<A.size();i++){
        out << A.tab[i]<< " ";
    }
    return out;
}


int &vector::operator[](int a){ //przeladowany operator [], zwracajacy element spod zadanego indeksu
    return tab[a];
}

vector &vector::operator=(const vector &A){ //przeladowany operator = (kopiujacy)
    if(this == &A){  //sprawdzenie, czy nie otrzymalimsy tego samego obiektu
        return *this;
    }else{
        siz = A.siz;
        tab = new int[siz];
        for(int i=0;i<siz;i++){  //proces kopiowania 
            tab[i]=A.tab[i];
        }
        return *this;
    }
}

vector operator+(const vector &A,const vector &B){ //przeladowany operator dodawania
    int iter = bigger(A,B); //ustalenie liczby krokow iteracji
    vector new_vec(iter);   //stworzenie nowego vectora o ustalonym rozmiarze
    for(int i=0; i<iter;i++){
        if(A.tab[i] && B.tab[i]){ //warunek sprawdzajacy, czy nie wyszlismy poza zakres vectora A i B
            new_vec.tab[i]=A.tab[i] + B.tab[i];
        }else if(A.tab[i]){ //iterowanie po vektorze A w przypadku wyjscia poza zakres vectora B
            new_vec.tab[i]=A.tab[i];
        }else{              //iterowanie po vektorze B w przypadku wyjscia poza zakres vectora A
            new_vec.tab[i]=B.tab[i];
        }
    }
    return new_vec;
}

vector &vector::operator=(vector &&A){  //przeladowany operator = (przenoszacy)
    if(this == &A){  //sprawdzenie, czy nie otrzymalimsy tego samego obiektu
        return *this;
    }else{
        delete [] tab;
        tab=std::__exchange(A.tab,nullptr);  //proces przenoszenia
        siz=std::__exchange(A.siz,0);
        
        return *this;
    }
}

int vector::size(){ //pomocnicza metoda zwracajaca rozmiar wektora
    return siz;
}

void vector::push_back(int a){ //metoda dodajaca element na koniec wektora
    int new_size=siz+1;  //ustalenie nowego rozmiaru
    int *temp = new int[size()+1]; //stworzenie pomocniczej tablicy
    for(int i=0;i<size();i++){
        temp[i]=tab[i];  //przepisanie elementow do tablicy pomocniczej
    }
    delete [] tab;  //wyczyszczenie starego vectora
    temp[new_size-1]=a; //przypisanie nowego elementu na koniec vectora
    
    tab=temp;  //przypisanie wskaznika
    siz=new_size;   //zaktualizowanie rozmiaru
}

void vector::pop_back(){ // metoda usuwajaca ostatni element wektora
    int *temp = new int[size()-1]; //stworzenie pomocniczej tablicy
    for(int i=0;i<size()-1;i++){
        temp[i]=tab[i];  //przepisanie elementow do tablicy pomocniczej
    }
    int new_size=siz-1; //ustalenie nowego rozmiaru
    delete [] tab; //wyczyszczenie starego vectora
    tab = temp;   //przypisanie wskaznika
    siz=new_size;   //zaktualizowanie rozmiaru
    
}

int bigger(const vector &A,const vector &B){ //pomocnicza funkcja porownujaca rozmiar zadanych vectorow
    if(A.siz>B.siz){
        return A.siz;
    }else{
        return B.siz;
    }
}



}