#include "matrix.h"

/*
Z gory moge powiedziec, ze zdaje sobie sprawe z wystepowania wyciekow pamieci w moim rozwiazaniu.
Niestety nie jestem w stanie wychwicic momentu wycieku, a kazdorazowa proba ratunku 
sytuacji konczy sie wieksza iloscia dealokacji, niz alokacji. 
*/

namespace MyStuff{

matrix::matrix(const int a, const int b):x{a},y{b}{
    m_ptr = new vector[y];
    for(int i=0;i<y;i++){                             //konsturktor matrix tworzacy pusta macierz o zadanych wymiarach
        *(m_ptr+i)=vector(x);
    }
}

matrix::matrix():x{0},y{0},m_ptr{nullptr}{;}  //konstruktor matrix domyslny

matrix::~matrix(){
    for(int i=0;i<y;i++){
        delete [] (m_ptr+i)->tab;         //destruktor domyslny
    }
    delete [] m_ptr;
}


matrix::matrix(matrix &&A){
    m_ptr=std::__exchange(A.m_ptr,nullptr);
    x=std::__exchange(A.x,0);                   //konstruktor matrix przenoszacy
    y=std::__exchange(A.y,0);
}

matrix::matrix(const matrix &A){
    m_ptr = new vector[A.y];
    for(int i=0;i<A.y;i++){
        (m_ptr+i)->tab = new int[A.x];   //konstruktor matrix kopiujacy
        m_ptr[i] = A.m_ptr[i];
    }
    x=A.x;
    y=A.y;
}

std::ostream &operator<<(std::ostream &out, const matrix &A){
    for(int i=0;i<A.y;i++){
        out << *(A.m_ptr+i) << std::endl;     //przeladowany operator << dla klasy matrix, wykorzystujacy przeladowany operator << dla klasy vector
    }
    out << std::endl;
    return out;
}

vector &matrix::operator[](int i){
    return *(m_ptr +i);               //przeladowany operator [], zwracajacy vector o zadanym indeksie
}

matrix operator+(const matrix &A, const matrix &B){ //przeladowany operator dodawania
    matrix new_matrix(bigger_x(A,B),bigger_y(A,B)); //utworzenie nowej macierzy o odpowiednich wymiarach

    for(int i=0;i<new_matrix.y;i++){
        if(i<min(A,B)){   //zadbanie, aby przy iteracji nie wyjsc poza zakres macierzy A badz B
            new_matrix.m_ptr[i]=A.m_ptr[i]+B.m_ptr[i]+new_matrix.m_ptr[i];
        }else if(A.y>B.y){ //jezeli macierz A jest wieksza, to konczymy iterowanie po niej
            new_matrix.m_ptr[i]=A.m_ptr[i]+new_matrix.m_ptr[i];
        }else{ //w przeciwnym wypadku po B
            new_matrix.m_ptr[i]=B.m_ptr[i]+new_matrix.m_ptr[i];
        }
    }
    
    return new_matrix;
}


matrix &matrix::operator=(const matrix &A){ //przeladowany operator = (kopiujacy)
    if(this==&A){ //sprawdzenie, czy nie otrzymalimsy tego samego obiektu
        return *this;
    }else{
        m_ptr = new vector[A.y];
        for(int i=0;i<A.y;i++){
            (m_ptr+i)->tab = new int[A.x];  //proces kopiowania
            m_ptr[i] = A.m_ptr[i];
        }
        x=A.x;
        y=A.y;
        return *this;
    }
}

matrix &matrix::operator=(matrix &&A){ //przeladowany operator = (przenoszacy)
    if(this == &A){  //sprawdzenie, czy nie otrzymalimsy tego samego obiektu
        return *this;
    }else{
        m_ptr=std::__exchange(A.m_ptr,nullptr);
        x=std::__exchange(A.x,0);            //proces przenoszenia
        y=std::__exchange(A.y,0);
        return *this;
    }
}

matrix operator*(const matrix &A, const matrix &B){  //przeladowany operator mnozenia macierzy
    if(A.x != B.y){  //sprawdzenie zgodnosci wymiarow macierzy
        std::cout << "Bledne wymiary macierzy!"<<std::endl;
        return matrix(); //zwrocenie pustej macierzy
    }else{
        int sum=0;  //zmienna pomocnicza
        matrix new_matrix(B.x,A.y);
        for(int i=0; i<new_matrix.y;i++){
            for(int j=0; j<new_matrix.x;j++){
                for(int k=0;k<A.x;k++){
                    sum += A.m_ptr[i].tab[k]*B.m_ptr[k].tab[j]; //ustalenie wyniku mnozenia elementow macierzy
                }
                new_matrix.m_ptr[i].tab[j] = sum; //przypisanie wyniku
                sum=0;                            //wyzerowanie zmiennej pomocniczej
            }
        }
        return new_matrix;
    }
}

void matrix::fill(vector *A, int iter){
    for(int i=0;i<iter;i++){
        for(int j=0;j<(A+i)->siz;j++){       //metoda wypelniajaca macierz, wykorzystujaca tablice vectorow
            m_ptr[i][j]=(A+i)->tab[j];
        }
    }
}

int bigger_x(const matrix &A, const matrix &B){ //funckja pomocnicza zwracajaca wieksza wartosc M rozmiaru porownywanych macierzy
    if(A.x>B.x){
        return A.x;
    }else{
        return B.x;
    }
}

int bigger_y(const matrix &A, const matrix &B){ //funckja pomocnicza zwracajaca wieksza wartosc N rozmiaru porownywanych macierzy
    if(A.y>B.y){
        return A.y;
    }else{
        return B.y;
    }
}

int min(const matrix &A, const matrix &B){ //funckja pomocnicza zwracajaca najmniejsza skladowa sposrod rozmiarów porownywanych macierzy
    if(A.y>B.y){
        return B.y;
    }else{
        return A.y;
    }
}

}