#pragma once
#include <iostream>

class Board{
    public:
        Board();     //konstrutkor domyslny
        Board(int, int, int);  //konstruktor ustawiajacy zadane wartosci
        virtual ~Board();    //virtualny destruktor
        virtual int get_geometry(int) const;   //virtualna metoda zwrcacajaca informacje o obszarze gry

        int ustal_x(int);   //metoda pomocnicza sprawdzajaca, czy szerokosc X miesci sie w przedziale [5,20], ze wzgledu na ta sama budowe, wykorzystana do sprawdzenia wysokosci Y
        int ustal_miny(int,int,int);    //metoda pomocnicza, ustalajaca liczbe min
        virtual double get_params(int) const;   //virtualna metoda zwracajaca parametry gry
        int get_wym_x() const{return wymiar_x;} //pomocnicza metoda zwacajaca szerokosc planszy
        int get_wym_y() const{return wymiar_y;} //pomocnicza metoda zwacajaca wysokosc planszy
        int get_l_min() const{return liczba_min;} //pomocnicza metoda zwacajaca liczbe min
    private:
        int wymiar_x;
        int wymiar_y;
        int liczba_min;

};