#pragma once
#include <iostream>
#include "board.h"
#include "matrix.h"

class Board;

class Game{
    public:
        Game();    //konstruktor domyslny
        virtual ~Game();   //virtualny destruktor
        void new_player(std::string);    //metoda ustawiajaca imie gracza
        virtual void new_board(const Board &);     //virtualna metoda tworzaca nowy obszar gry
        virtual void print_board();     //virtualna metoda wyswietlajaca obszar gry
        virtual bool operator()(int, int);      //virtualny funktor, modyfikujacy obszar gry
        MyStuff::matrix &get_matrix_pl(){return plansza;}  //pomocnicza metoda zwracajaca obszar gry
        MyStuff::matrix &get_matrix_help(){return obszar_pomocniczy;} //pomocnicza metoda zwracajaca obszar pomocniczy gry
    private:
        std::string gracz;
        MyStuff::matrix plansza;
        MyStuff::matrix obszar_pomocniczy;  //pomocniczy obszar o tym samym rozmiarze co plansza, przechowujaca odkryte wspolrzedne

};