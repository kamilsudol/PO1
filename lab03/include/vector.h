#pragma once
#include <iostream>
#include "matrix.h"


namespace MyStuff{

class matrix;

class vector{
    public:
        friend class matrix;
        friend std::ostream &operator<<(std::ostream &, vector &); //przeladowany operator <<

        vector(int);
        vector(const vector &);
        vector(vector &&);
        //~vector();
        vector():tab(nullptr),siz(0){;}

        int &operator[](int); //przeladowany operator []
        int size(); //pomocnicza metoda zwracajaca rozmiar vectora
        void push_back(int); //metoda dodająca element na koniec vectora
        void pop_back(); //metoda usuwajaca ostatni element vectora
        vector &operator=(const vector &); //przeladowany operator = (kopiujacy)
        vector &operator=(vector &&); //przeladowany operator = (przenoszacy)
        friend vector operator+(const vector&,const vector&); //przeladowany operator dodawania
        friend int bigger(const vector&,const vector&); //pomocnicza funkcja porownujaca rozmiar zadanych vectorow
        friend matrix operator*(const matrix &, const matrix &); //deklaracja przyjażni z przeladowanym operatorem mnozenia macierz
    
    private:
        int *tab;
        int siz;
};
}

