#pragma once
#include <iostream>
#include "vector.h"

namespace MyStuff{

class vector;

class matrix{
    public:
        friend class vector;
        matrix(const int, const int);
        matrix(matrix&&);
        matrix(const matrix&);
        matrix();
        ~matrix();

        friend std::ostream &operator<<(std::ostream &, const matrix&); // przeladowany operator <<
        vector &operator[](int);  //przeladowany operator [] 
        void fill(vector *, int); //metoda wypełniająca macierz elementami z vectora
        matrix &operator=(matrix &&); //przeladowany operator = (przenoszacy)
        matrix &operator=(const matrix &); //przeladowany operator = (kopiujacy)

        friend matrix operator+(const matrix &, const matrix &); //przeladowany operator dodawania
        friend matrix operator*(const matrix &, const matrix &);  //przeladowany operator mnozenia
        friend int bigger_x(const matrix &, const matrix &); //funckja pomocnicza zwracajaca wieksza wartosc M rozmiaru porownywanych macierzy
        friend int bigger_y(const matrix &, const matrix &); //funckja pomocnicza zwracajaca wieksza wartosc N rozmiaru porownywanych macierzy
        friend int min(const matrix &, const matrix &);  //funckja pomocnicza zwracajaca najmniejsza skladowa sposrod rozmiarów porownywanych macierzy

    private:
        int x,y;
        vector *m_ptr;
};

}

