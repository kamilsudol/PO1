#include "game.h"

Game::Game():gracz{"noname"}{;} //konstruktor domyslny
Game::~Game(){;}  //destruktor

void Game::new_player(std::string name){  //metoda ustawiajaca imie gracza
    gracz = name;
}

void Game::new_board(const Board &A){;} //metoda tworzaca nowy obszar gry (nie jest wykorzystywana)

bool Game::operator()(int a, int b){  //funktor, modyfikujacy obszar gry (nie jest wykorzystywany)
    return false;
}

void Game::print_board(){;}  //metoda wyswietlajaca obszar gry (nie jest wykorzystywana)