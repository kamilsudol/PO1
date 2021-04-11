#pragma once
#include <iostream>
#include "game.h"
#include <cstdlib>

//class Game;
class Board;

class Sapper : public Game{
    public:
        Sapper();   //konstruktor domyslny
        ~Sapper();  //destruktor
        void new_board(const Board&);  //metoda tworzaca nowy obszar gry
        void print_board();     //metoda wyswietlajaca obszar gry
        bool operator()(int, int);      //funktor modyfikujacy obszar gry
        void board_prepare(int, int);   //metoda ustalajaca wartosci na obszarze gry na podstawie rozmieszczenia min
};