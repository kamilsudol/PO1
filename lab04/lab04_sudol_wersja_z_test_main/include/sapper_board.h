#pragma once
#include <iostream>
#include "board.h"

//class Board;

class SapperBoard: public Board{
    public:
        SapperBoard();   //konsturkor domyslny
        SapperBoard(int, int, int);  //konsturktor ustawiajacy zadane wartosci
        ~SapperBoard();   //destruktor
        int get_geometry(int) const;    //metoda zwrcacajaca informacje o obszarze gry
        double get_params(int) const;   //metoda zwracajaca parametry gry
        
};