#include "board.h"

Board::Board():wymiar_x{0},wymiar_y{0},liczba_min{0}{;}  //konstrutkor domyslny, ustawiajacy wartosci na 0
Board::Board(int a, int b, int c):wymiar_x{a},wymiar_y{b},liczba_min{c}{;}   //konstruktor ustawiajacy zadane wartosci
Board::~Board(){;}  //destruktor

int Board::get_geometry(int k) const {return 0;} //metoda zwrcacajaca informacje o obszarze gry (nie jest wykorzystywana)

double Board::get_params(int k) const {return 0;}  //metoda zwracajaca parametry gry (nie jest wykorzystywana)

int Board::ustal_x(int a){ //metoda pomocnicza sprawdzajaca, czy szerokosc X miesci sie w przedziale [5,20], ze wzgledu na ta sama budowe, wykorzystana do sprawdzenia wysokosci Y
    if(a<5){
        a=5;
    }else if(a>20){
        a=20;
    }
    return a;
}

int Board::ustal_miny(int a, int b, int c){  //metoda pomocnicza, ustalajaca liczbe min
    if(c < 2){
        c=2;
    }else if(c > a*b/3){ //sprawdzenie, czy liczba nie przekracza 1/3 planszy
        c = a*b/3;
    }
    return c;
}